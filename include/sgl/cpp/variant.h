#ifndef SGL_VARIANT_H__
#define SGL_VARIANT_H__

#if __has_include(<sgl/overrides/string_view.h>)
#include <sgl/overrides/variant.h>
#else

#include <variant>

namespace sgl
{
	namespace features { constexpr bool has_variant = true; }
	using std::variant;
	using std::visit;
}

#endif
#endif
