#ifndef SGL_COLOR_H__
#define SGL_COLOR_H__

#include <sgl/platform/native_color.h>

namespace sgl {
	class color {
	public:
		color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
			: _value{ native_color_rgba(r, g, b, a) }
		{
		}

		color()
			: _value{ native_color_rgba(0, 0, 0, 0) }
		{
		}

		constexpr native_color native() const { return _value; }
		constexpr uint8_t r8() const { return native_color_r8(_value); }
		constexpr uint8_t g8() const { return native_color_g8(_value); }
		constexpr uint8_t b8() const { return native_color_b8(_value); }
		constexpr uint8_t a8() const { return native_color_a8(_value); }

		native_color _value;
	};
}

#endif
