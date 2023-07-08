#include <sgl/application.h>
#include <sgl/any_event.h>
#include <sgl/null_state_storage.h>

namespace sgl_test {
	using namespace sgl;

	class mock_application : public application {
	public:
		context next_transform() { return context{
			null_state_storage::instance(), 
			events::noop{},
			null_state_storage::instance() }; }
	};
}
