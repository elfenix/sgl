#ifndef SGL_CPP_SPAN_H__
#define SGL_CPP_SPAN_H__

#if __has_include(<sgl/overrides/span.h>)
#include <sgl/overrides/span.h>
#else

#include <span>

namespace sgl {
	using std::span;
}

#endif
#endif
