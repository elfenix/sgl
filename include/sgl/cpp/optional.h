#ifndef SGL_OPTIONAL_H__
#define SGL_OPTIONAL_H__

#if __has_include(<sgl/overrides/optional.h>)
#include <sgl/overrides/optional.h>
#else

#include <optional>

namespace sgl
{
	namespace features { constexpr bool has_optional = true; }

	using std::optional;
	using std::nullopt_t;
	using std::nullopt;
}

#endif
#endif
