#ifndef SGL_STRINGVIEW_H__
#define SGL_STRINGVIEW_H__

#if __has_include(<sgl/overrides/string_view.h>)
#include <sgl/overrides/string_view.h>
#else

#include <string_view>

namespace sgl
{
	namespace features { constexpr bool has_string_view = true; }

	namespace string_view_literals = std::string_view_literals;
	using namespace string_view_literals;

	template<typename CharT>
	using basic_string_view = std::basic_string_view<CharT>;

	using std::string_view;
	using std::u8string_view;
	using namespace std::string_view_literals;
}

#endif
#endif
