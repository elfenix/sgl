#include <sgl/state_storage_heap.h>
#include <sgl/state.h>
#include <sgl/overloaded.h>

using namespace sgl;

namespace {
	void c_deleter_fn(void* data, void* impl) {
		state_storage_heap* h = reinterpret_cast<state_storage_heap*>(data);
		delete h;
	}
}


state_storage_heap::ptr state_storage_heap::create()
{
	return make_ptr(new state_storage_heap{});
}


state_storage_heap::state_storage_heap()
	: _tree{ make_shared<dict_type>() }
{
}


state_storage_heap::~state_storage_heap() noexcept
{
}


state_storage_heap::ptr state_storage_heap::clone()
{
	auto cloned_tree = clone(_tree);
	return make_ptr(new state_storage_heap{ cloned_tree });
}


state_storage_heap::ptr state_storage_heap::ref()
{
	return make_ptr(new state_storage_heap{ _tree });
}


state_storage_heap::ptr state_storage_heap::find_subtree(token subtree)
{
	auto find_iter = _tree->find(subtree);
	if (find_iter == _tree->end()) { return make_ptr(nullptr); }
	if (!holds_alternative<dict_ptr>(find_iter->second.data)) { return make_ptr(nullptr); }
	return make_ptr(new state_storage_heap{ get<dict_ptr>(find_iter->second.data) });
}


state_storage_heap::ptr state_storage_heap::start_subtree(token subtree)
{
	auto new_dict = make_shared<dict_type>();
	auto res = make_ptr(new state_storage_heap{ new_dict });

	auto& storage_entry  = (*_tree)[subtree];
	if (!holds_alternative<nullopt_t>(storage_entry.data)) {
		throw state::already_exists{};
	}

	storage_entry.data = new_dict;
	return res;
}


state_storage_heap::ptr state_storage_heap::make_ptr(state_storage_heap* pt)
{
	return state_storage::make_storage_ptr(pt, c_deleter_fn, nullptr);
}


state_storage_heap::dict_ptr state_storage_heap::clone(dict_ptr src)
{
	auto storage = make_shared<storage_type>();
	auto new_dict_ptr = make_shared<dict_type>();
	auto& new_dict = *new_dict_ptr;
	storage->data = new_dict_ptr;
	for (auto& entry : *src) {
		new_dict[entry.first] = visit([](auto v) -> storage_type { return clone(v); }, entry.second.data);
	}
	return new_dict_ptr;
}


state_storage_heap::storage_type state_storage_heap::clone(const nullopt_t& src)
{
	return storage_type{};
}
