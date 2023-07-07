#ifndef SGL_UTILITY_H__
#define SGL_UTILITY_H__

#if __has_include(<sgl/overrides/utility.h>)
#include <sgl/overrides/utility.h>
#else

#include <utility>

namespace sgl
{
	namespace features { constexpr bool has_utility = true; }

	using std::pair;
}

#endif
#endif
