#ifndef SGL_DETAIL_GENERIC_DRAWABLE_H__
#define SGL_DETAIL_GENERIC_DRAWABLE_H__

#include <sgl/rect.h>
#include <sgl/color.h>
#include <sgl/cpp/variant.h>

namespace sgl::detail::draw_items {
	struct filled_rect {
		rect geom;
		color color;
	};

	using any = variant<filled_rect>;
}

#endif
