#ifndef SGL_OVERLOAD_H_
#define SGL_OVERLOAD_H_

namespace sgl {
	template<class... Ts>
	struct overloaded : Ts... { using Ts::operator()...; };
	// explicit deduction guide (not needed as of C++20)
	template<class... Ts>
	overloaded(Ts...) -> overloaded<Ts...>;
}

#endif
