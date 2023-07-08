#include <sgl/version.h>
#include <sgl/cpp/string_view.h>
#include <sgl/cpp/span.h>
#include <iostream>

using namespace sgl;

int main(int, char**)
{
	std::cout << "SGL "sv << sgl::version_major << "." << sgl::version_minor << "." << sgl::version_micro;
	return 0;
}