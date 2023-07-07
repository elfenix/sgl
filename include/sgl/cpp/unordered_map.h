#ifndef SGL_UNORDERED_MAP_H__
#define SGL_UNORDERED_MAP_H__

#if __has_include(<sgl/overrides/unordered_map.h>)
#include <sgl/overrides/unordered_map.h>
#else

#include <unordered_map>

namespace sgl
{
	namespace features { constexpr bool has_unordered_map = true; }

	using std::unordered_map;
}

#endif
#endif
