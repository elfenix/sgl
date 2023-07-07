#ifndef SGL_MEMORY_H__
#define SGL_MEMORY_H__

#if __has_include(<sgl/overrides/memory.h>)
#include <sgl/overrides/memory.h>
#else

#include <memory>
#include <new>

namespace sgl
{
	namespace features { constexpr bool has_memory = true; }

	using std::shared_ptr;
	using std::make_shared;

	using std::unique_ptr;
	using std::make_unique;

	using std::launder;
}

#endif
#endif
