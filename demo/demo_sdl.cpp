#include <sgl/sdl/sys_info.h>
#include <sgl/sdl/sdl_application.h>
#include <sgl/overloaded.h>
#include <sgl/any_event.h>
#include <sgl/context.h>

#include <SDL2/SDL.h>
#include <iostream>

using namespace sgl;

class demo_sdl {
public:
	int operator()(context& ctx) {
		int result = application::continue_run;

		visit(overloaded{
				[&result](const events::quit_request& q) { std::cout << "Quit Request" << std::endl;  result = application::exit_run; },
				[&ctx](const events::mouse_motion& ex) {
					if (ctx.is_drawing()) {
						ctx.draw_list().add_filled_rect(rect{ ex.pos, size{10, 10} }, color{ 255, 0, 0 });
					}
				},
				[](const events::noop&) { std::cout << "Noop Event" << std::endl; }
			}, ctx.get_trigger());

		return result;
	}
};

int main(int argc, char** argv)
{
	sgl::sdl_application application;
	demo_sdl this_demo;

	application.create_window("SGL Demo for SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	application.run(this_demo);

	return 0;
}
