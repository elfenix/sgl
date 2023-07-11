#include <sgl/application.h>
#include <sgl/any_event.h>
#include <sgl/null_state_storage.h>

namespace sgl_test {
	using namespace sgl;

	class mock_application : public application {
	public:
		context next_transform() { return context{
			this,
			null_state_storage::instance(), 
			events::noop{},
			null_state_storage::instance(),
			draw_list::make_ptr(nullptr)}; }

		void complete_transform(context& completed) {}
	};
}
