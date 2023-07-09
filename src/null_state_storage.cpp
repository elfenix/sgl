#include <sgl/null_state_storage.h>

using namespace sgl;

namespace {
	void no_deletion(void*, void*) {}
}

null_state_storage::ptr null_state_storage::clone()
{
	return make_storage_ptr(get_ptr(), no_deletion, nullptr);
}

null_state_storage::ptr null_state_storage::ref()
{
	return clone();
}

null_state_storage::ptr null_state_storage::find_subtree(token subtree)
{
	return make_storage_ptr(nullptr, no_deletion, nullptr);
}


null_state_storage::ptr null_state_storage::start_subtree(token subtree)
{
	throw out_of_range{"no subtree"};
}


null_state_storage* null_state_storage::get_ptr()
{
	static null_state_storage v;
	return &v;
}


null_state_storage::null_state_storage()
{
}
