#ifndef SGL_EXCEPT_H__
#define SGL_EXCEPT_H__

#if __has_include(<sgl/overrides/stdexcept.h>)
#include <sgl/overrides/stdexcept.h>
#else

#include <stdexcept>

namespace sgl
{
	namespace features { constexpr bool has_except = true; }

	using std::exception;
	using std::runtime_error;
	using std::out_of_range;
	using std::bad_alloc;
	using std::range_error;
	using std::invalid_argument;
	using std::logic_error;
}

#endif
#endif
