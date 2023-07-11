#ifndef SGL_RECT_H_
#define SGL_RECT_H_

#include <sgl/point.h>
#include <sgl/size.h>

namespace sgl {
	class rect {
	public:
		constexpr rect(const point& top_left, const size& size)
			: _top_left{ top_left }
			, _size{ size }
		{
		}

		constexpr auto operator<=>(const rect&) const = default;
		constexpr bool operator!() const { return !(_size._x > 0 && _size._y > 0); }
		constexpr explicit operator bool() const { return _size._x > 0 && _size._y > 0; }

		constexpr point top_left() const { return _top_left; }
		constexpr point top_right() const { return point{ _top_left._x + _size._x, _top_left._y }; }
		constexpr point bottom_right() const { return _top_left + _size; }
		constexpr point bottom_left() const { return point{ _top_left._x, _top_left._y + _size._y }; }
		constexpr sgl::size size() const { return _size; }

		constexpr coord x() const { return _top_left._x; }
		constexpr coord y() const { return _top_left._y; }
		constexpr coord w() const { return _size._x; }
		constexpr coord h() const { return _size._y; }

		point _top_left;
		sgl::size _size;
	};
}

#endif
