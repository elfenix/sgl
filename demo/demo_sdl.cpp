#include <sgl/sdl/sys_info.h>

int main(int argc, char** argv)
{
	auto rev = sgl::sdl::get_version();
	return (rev != nullptr) ? 0 : -1;
}
