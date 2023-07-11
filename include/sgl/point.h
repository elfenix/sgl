#ifndef SGL_POINT_H__
#define SGL_POINT_H__

#include <sgl/platform/coord.h>

#include <compare>

namespace sgl {
	class point {
	public:
		constexpr point(coord x, coord y)
			: _x{ x }
			, _y{ y }
		{
		}

		constexpr coord x() const { return _x; }
		constexpr coord y() const { return _y; }

		constexpr auto operator<=>(const point& other) const = default;

		coord _x;
		coord _y;
	};

	constexpr point operator+(const point& a, const point& b) { return point{ a._x + b._x, a._y + b._y }; }
	constexpr point operator-(const point& a, const point& b) { return point{ a._x - b._x, a._y - b._y }; }

}

#endif
