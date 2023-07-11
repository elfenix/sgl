#include <sgl/draw_list_vector.h>

namespace sgl {
	draw_list_vector::draw_list_vector(owner* owner)
		: _owner{owner}
	{
	}

	draw_list_vector::~draw_list_vector()
	{
	}

	draw_list::owner* draw_list_vector::get_owner() const
	{
		return _owner;
	}

	void draw_list_vector::add_filled_rect(const rect& geometry, const color& fill)
	{
		_value.push_back(detail::draw_items::filled_rect{geometry, fill});
	}
}
