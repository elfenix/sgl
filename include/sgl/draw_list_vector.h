#ifndef SGL_DRAW_LIST_VECTOR_H__
#define SGL_DRAW_LIST_VECTOR_H__

#include <sgl/draw_list.h>
#include <sgl/detail/draw_items.h>

#include <sgl/cpp/vector.h>
#include <sgl/cpp/variant.h>

namespace sgl {
	class draw_list_vector : public draw_list {
	public:
		using vector_type = std::vector<detail::draw_items::any>;
		using iterator = vector_type::iterator;

		class vector_owner : public draw_list::owner {
		public:
			virtual ~vector_owner() {}
			virtual void release(draw_list* dl) noexcept { return release(static_cast<draw_list_vector*>(dl)); }
			virtual void release(draw_list_vector* dl) noexcept = 0;
		};

		draw_list_vector(owner* owner);
		~draw_list_vector();

		owner* get_owner() const;
		void add_filled_rect(const rect& geometry, const color& fill) override;

		iterator begin() { return _value.begin(); }
		iterator end() { return _value.end(); }

	private:
		owner* _owner;
		vector_type _value;
	};
}

#endif
