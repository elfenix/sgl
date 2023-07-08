#include <sgl/sdl/sdl_application.h>
#include <SDL2/SDL.h>

#include <sgl/null_state_storage.h>

#include "sgl_translate.h"

using namespace sgl;

struct sdl_application::impl {
	SDL_Window* window = nullptr;
	SDL_Event ev;
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
}


void sdl_application::destroy_window()
{
	if (!_p->window) { return; }

	SDL_DestroyWindow(_p->window);
	_p->window = nullptr;
}


context sdl_application::next_transform()
{
	SDL_Event e;

	if (SDL_WaitEvent(&e) == 0) {
		return context{ null_state_storage::instance(), events::noop{}, null_state_storage::instance() };
	}

	any_event trigger{ events::noop{} };

	switch (e.type) {
	case SDL_MOUSEMOTION:
		trigger = sdl::fromSDL(e.motion);
		break;

	case SDL_QUIT:
		trigger = events::quit_request{};
		break;
	}

	return context{ null_state_storage::instance(), trigger, null_state_storage::instance() };
}
