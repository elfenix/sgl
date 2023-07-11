#ifndef SGL_SIZE_H_
#define SGL_SIZE_H_

#include <sgl/point.h>

namespace sgl {
	class size : public point {
	public:
		explicit constexpr size(const point& pt) : point{ pt } {}
		constexpr size(coord x, coord y) : point{ x, y } {}

		constexpr coord w() const { return _x; }
		constexpr coord h() const { return _y; }
	};
}

#endif
