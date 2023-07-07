#ifndef SGL_FUNCTIONAL_H__
#define SGL_FUNCTIONAL_H__

#if __has_include(<sgl/overrides/functional.h>)
#include <sgl/overrides/functional.h>
#else

#include <functional>

namespace sgl
{
	namespace features { constexpr bool has_functional = true; }

	using std::reference_wrapper;
	using std::ref;
	using std::cref;
	using std::bind;
	using std::hash;
}

#endif

#endif
