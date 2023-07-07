#include <sgl/sdl/sys_info.h>

#include <SDL_version.h>

namespace sgl::sdl {
	const char* get_version() {
		return SDL_GetRevision();
	}
}
