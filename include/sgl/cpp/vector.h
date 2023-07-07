#ifndef SGL_VECTOR_H__
#define SGL_VECTOR_H__

#if __has_include(<sgl/overrides/vector.h>)
#include <sgl/overrides/vector.h>
#else

#include <vector>

namespace sgl
{
	namespace features { constexpr bool has_vector = true; }

	template<typename T>
	using vector = std::vector<T>;
}

#endif
#endif
