#ifndef SGL_DRAW_LIST_H_
#define SGL_DRAW_LIST_H_

#include <sgl/color.h>
#include <sgl/rect.h>
#include <sgl/cpp/memory.h>

namespace sgl {
	class draw_list {
	public:
		class owner {
		public:
			virtual ~owner() {}
			virtual void release(draw_list* dl) noexcept = 0;
		};

		class local_delete {
		public:
			local_delete() {}

			virtual void operator()(draw_list* d) const noexcept {
				if (!d) { return; }
				auto owner_ptr = d->get_owner();
				owner_ptr->release(d);
			}
		};

		using ptr = unique_ptr<draw_list, local_delete>;

		static ptr make_ptr(draw_list* dl) {
			return ptr{ dl, local_delete{} };
		}

		draw_list();

		virtual owner* get_owner() const = 0;
		virtual void add_filled_rect(const rect& geometry, const color& fill) = 0;

	protected:
		virtual ~draw_list() noexcept;
	};
}

#endif
