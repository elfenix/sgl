#ifndef SGL_STATE_STORAGE_H_
#define SGL_STATE_STORAGE_H_

#include <sgl/cpp/memory.h>
#include <sgl/token.h>

namespace sgl {
	class state_storage {
	public:
		state_storage(const state_storage&) = delete;
		state_storage& operator=(const state_storage&) = delete;

		class deleter {
		public:
			typedef void (*delete_fn)(void* inst, void* impl);

			void operator()(state_storage* st) const {
				_fn(reinterpret_cast<void*>(st), _impl);
			}

			deleter(const deleter&) = default;
			deleter& operator=(const deleter&) = default;

		private:
			delete_fn _fn;
			void* _impl;

			deleter(delete_fn fn, void* impl) : _fn{ fn }, _impl{ impl } {}

			friend class state_storage;
		};


		using ptr = unique_ptr<state_storage, deleter>;

		virtual ptr clone() const = 0;
		virtual ptr find_subtree(token subtree) = 0;
		virtual ptr start_subtree(token subtree) = 0;

	protected:
		state_storage() {}

		static ptr make_storage_ptr(state_storage* ss, deleter::delete_fn fn, void* impl) {
			return ptr{ ss, deleter{fn, impl} };
		}
	};
}

#endif
