#include <sgl/sdl/sdl_application.h>
#include <SDL2/SDL.h>

#include <sgl/draw_list_vector.h>
#include <sgl/state_storage_heap.h>
#include <sgl/null_state_storage.h>
#include <sgl/overloaded.h>

#include "sgl_translate.h"

using namespace sgl;

namespace {
	class sdl_draw_list_owner : public draw_list_vector::vector_owner {
	public:
		void release(draw_list_vector* dl) noexcept {
			delete dl;
		}
	};
}

struct sdl_application::impl {
	impl()
		: window{ nullptr }
		, render{ nullptr }
		, last_state{ null_state_storage::instance() }
	{
	}

	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Event ev;

	sdl_draw_list_owner dl_owner;
	state_storage::ptr last_state;
};


sdl_application::sdl_application()
	: _p{new impl}
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);
}


sdl_application::~sdl_application() noexcept
{
	destroy_window();

	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}


void sdl_application::create_window(const char* title, int x, int y, int w, int h, uint32_t flags)
{
	_p->window = SDL_CreateWindow(title, x, y, w, h, (Uint32)flags);
	if (!_p->window) { throw runtime_error{"Unable to create window"}; }
	_p->render = SDL_CreateRenderer(_p->window, -1, SDL_RENDERER_ACCELERATED);
	if (!_p->render) {
		std::string sdl_error{SDL_GetError()};
		SDL_DestroyWindow(_p->window);
		_p->window = nullptr;
		throw runtime_error{sdl_error};
	}
}


void sdl_application::destroy_window()
{
	if (!_p->window) { return; }

	SDL_DestroyRenderer(_p->render);
	SDL_DestroyWindow(_p->window);
	_p->window = nullptr;
}


context sdl_application::next_transform()
{
	SDL_Event e;

	if (SDL_WaitEvent(&e) == 0) {
		return context{ this, _p->last_state->ref(), events::noop{}, state_storage_heap::create(), nullptr};
	}

	any_event trigger{ events::noop{} };

	switch (e.type) {
	case SDL_MOUSEMOTION:
		trigger = sdl::mouseMotionFromSDL(e.motion);
		break;

	case SDL_QUIT:
		trigger = events::quit_request{};
		break;
	}

	auto dl = draw_list::make_ptr(new draw_list_vector{ &_p->dl_owner });
	return context{ this, _p->last_state->ref(), trigger, state_storage_heap::create(), std::move(dl) };
}


void sdl_application::complete_transform(context& completed)
{
	// Check gauarantees known types later!
	if (completed.get_parent() != this) { throw runtime_error{"mismatched context"}; }

	_p->last_state = completed.out_state().get_ptr();

	auto dl_ptr = completed.release_draw_list();
	if (dl_ptr) {
		auto& dlvector = static_cast<draw_list_vector&>(*dl_ptr.get());
		auto render = _p->render;
		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		SDL_RenderClear(render);

		for (auto& fig : dlvector) {
			using namespace sgl::detail::draw_items;
			visit(overloaded{
				[&render](const filled_rect& f)
				{
					SDL_Rect r = sdl::toSDL_Rect(f.geom);
					sdl::render_set_color(render, f.color);
					SDL_RenderFillRect(render, &r);
				}
				}, fig);
		}

		SDL_RenderPresent(render);
	}
}
