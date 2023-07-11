#ifndef SGL_TRANSLATE_H_
#define SGL_TRANSLATE_H_

#include <sgl/point.h>
#include <sgl/events/mouse_motion.h>
#include <sgl/color.h>
#include <sgl/rect.h>
#include <SDL2/SDL.h>

namespace sgl::sdl {
	constexpr token tokenFromSDL_mouseWhich(Uint32 which) {
		return token{ which, 0 };
	}

	constexpr point pointFromSDL(Sint32 x, Sint32 y) {
		return point{ static_cast<coord>(x), static_cast<coord>(y) };
	}

	constexpr point pointFromSDL(const SDL_Point& pt) {
		return point{ static_cast<coord>(pt.x), static_cast<coord>(pt.y) };
	}

	constexpr SDL_Point toSDL_Point(const point& pt) {
		return SDL_Point{ static_cast<Sint32>(pt._x), static_cast<Sint32>(pt._y) };
	}

	constexpr SDL_Rect toSDL_Rect(const rect& rc) {
		return SDL_Rect{ static_cast<Sint32>(rc._top_left._x),
						 static_cast<Sint32>(rc._top_left._y),
						 static_cast<Sint32>(rc._size._x),
						 static_cast<Sint32>(rc._size._y) };
	}

	events::mouse_motion mouseMotionFromSDL(const SDL_MouseMotionEvent& ev) {
		point pos = pointFromSDL(ev.x, ev.y);
		point rel = pointFromSDL(ev.xrel, ev.yrel);
		return events::mouse_motion{tokenFromSDL_mouseWhich(ev.which), pos, rel};
	}

	void render_set_color(SDL_Renderer* render, const color& color) {
		SDL_SetRenderDrawColor(render, color.r8(), color.g8(), color.b8(), color.a8());
	}
}

#endif
