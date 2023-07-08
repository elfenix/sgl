#ifndef SGL_POINT_H__
#define SGL_POINT_H__

#include <sgl/platform/coord.h>

namespace sgl {
	class point {
	public:
		constexpr point(coord x, coord y)
			: x{ x }
			, y{ x } 
		{
		}

		coord x;
		coord y;
	};
}

#endif
