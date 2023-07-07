#include <sgl/version.h>
#include <iostream>

int main(int, char**)
{
	std::cout << "SGL " << sgl::version_major << "." << sgl::version_minor << "." << sgl::version_micro;
	return 0;
}