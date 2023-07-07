#ifndef SGL_BIT_H_
#define SGL_BIT_H_

#include <bit>

namespace sgl
{
	using std::endian;
	using std::bit_cast;
	using std::has_single_bit;
	using std::bit_ceil;
	using std::bit_floor;
	using std::rotl;
	using std::rotr;
	using std::countl_zero;
	using std::countl_one;
	using std::countr_one;
	using std::popcount;
}

#endif