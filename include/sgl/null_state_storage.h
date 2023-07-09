#ifndef SGL_NULL_STATE_STORAGE_H__
#define SGL_NULL_STATE_STORAGE_H__

#include <sgl/state_storage.h>

namespace sgl {
	class null_state_storage final : public state_storage {
	public:
		static ptr instance()
		{
			return get_ptr()->clone();
		}

		ptr clone() override;
		ptr ref() override;
		ptr find_subtree(token subtree) override;
		ptr start_subtree(token subtree) override;

	private:
		static null_state_storage* get_ptr();

		null_state_storage();
	};
}

#endif
