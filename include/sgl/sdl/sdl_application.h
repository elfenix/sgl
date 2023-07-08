#include <sgl/application.h>
#include <sgl/cpp/memory.h>

namespace sgl
{
	class sdl_application : public application {
	public:
		sdl_application();
		~sdl_application() noexcept;

		void create_window(const char* title, int x, int y, int w, int h, uint32_t flags);
		void destroy_window();

		context next_transform() override;

	private:
		struct impl;
		unique_ptr<impl> _p;
	};
}
