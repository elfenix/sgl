#ifndef SGL_APPLICATION_H__
#define SGL_APPLICATION_H__

#include <sgl/context.h>
#include <sgl/cpp/stdint.h>

namespace sgl {
	class application {
	public: 
		static constexpr int exit_run = 0;
		static constexpr int continue_run = 1;

		typedef int (*transformer)(void*, uintptr_t);

		virtual ~application() noexcept;

		virtual void run(transformer xform, uintptr_t user);
		virtual context next_transform() = 0;

		template<typename T>
		void run(T&& fn);

	private:
		template<typename Tptr>
		struct priv_call {
			static int c_fn(void* erased_ctx, uintptr_t user) {
				context* ctx = reinterpret_cast<context*>(erased_ctx);
				return (*reinterpret_cast<Tptr>(user))(*ctx);
			}
		};
	};

	template<typename T>
	void application::run(T&& fn) {
		using Tptr = decltype(&fn);
		return run(priv_call<Tptr>::c_fn, reinterpret_cast<uintptr_t>(&fn));
	}
}

#endif
