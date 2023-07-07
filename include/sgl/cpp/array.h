#ifndef SGL_ARRAY_H__
#define SGL_ARRAY_H__

#if __has_include(<sgl/overrides/array.h>)
#include <sgl/overrides/array.h>
#else

#include <sgl/cpp/stdint.h>
#include <array>

namespace sgl
{
	namespace features { constexpr bool has_array = true; }

	using std::array;
}

#endif
#endif
