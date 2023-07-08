#ifndef SGL_TRANSLATE_H_
#define SGL_TRANSLATE_H_

#include <sgl/point.h>
#include <sgl/events/mouse_motion.h>
#include <SDL2/SDL.h>

namespace sgl::sdl {
	constexpr token fromSDL_mouseWhich(Uint32 which) {
		return token{ which, 0 };
	}

	constexpr point fromSDL(Sint32 x, Sint32 y) {
		return point{ static_cast<coord>(x), static_cast<coord>(y) };
	}

	constexpr point fromSDL(const SDL_Point& pt) {
		return point{ static_cast<coord>(pt.x), static_cast<coord>(pt.y) };
	}

	events::mouse_motion fromSDL(const SDL_MouseMotionEvent& ev) {
		point pos = fromSDL(ev.x, ev.y);
		point rel = fromSDL(ev.xrel, ev.yrel);
		return events::mouse_motion{fromSDL_mouseWhich(ev.which), pos, rel};
	}
}

#endif
