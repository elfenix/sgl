#ifndef SGL_STATE_STORAGE_HEAP_H__
#define SGL_STATE_STORAGE_HEAP_H__

#include <sgl/state_storage.h>
#include <sgl/cpp/memory.h>
#include <sgl/cpp/variant.h>
#include <sgl/cpp/optional.h>
#include <sgl/cpp/unordered_map.h>
#include <sgl/cpp/stdint.h>

namespace sgl {
	class state_storage_heap : public state_storage {
	public:
		state_storage_heap();
		~state_storage_heap() noexcept;

		static ptr create();

		ptr clone() override;
		ptr ref() override;
		ptr find_subtree(token subtree) override;
		ptr start_subtree(token subtree) override;

	private:
		struct storage_type;
		using dict_type = unordered_map<token, storage_type>;
		using dict_ptr = shared_ptr<dict_type>;

		struct storage_type {
			storage_type(dict_ptr ptr) : data{ ptr } {}
			storage_type() : data{ nullopt } {}
			variant<nullopt_t, dict_ptr> data;
		};

		state_storage_heap(dict_ptr ref) : _tree{ ref } {}
		static ptr make_ptr(state_storage_heap* pt);

		static dict_ptr clone(dict_ptr src);
		static storage_type clone(const nullopt_t& src);

		dict_ptr _tree;
	};
}

#endif
