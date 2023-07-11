#ifndef SGL_PLATFORM_NATIVE_COLOR_H__
#define SGL_PLATFORM_NATIVE_COLOR_H__

#include <sgl/cpp/stdint.h>

namespace sgl {
	using native_color = uint32_t;

	constexpr native_color native_color_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
		return static_cast<uint32_t>(r) << 24 |
			static_cast<uint32_t>(b) << 16 |
			static_cast<uint32_t>(g) << 8 |
			static_cast<uint32_t>(a);
	}

	namespace detail {
		constexpr uint8_t native_color_component(float f) {
			return static_cast<uint8_t>(static_cast<int>(f * 255.0) & 0xff);
		}
	}

	constexpr native_color native_color_rgba_fp(float r, float g, float b, float a = 1.0f) {
		return native_color_rgba(detail::native_color_component(r),
			detail::native_color_component(g),
			detail::native_color_component(b),
			detail::native_color_component(a));
	}

	constexpr uint8_t native_color_r8(native_color c) {
		return static_cast<uint8_t>((c >> 24) & 0xff);
	}

	constexpr uint8_t native_color_g8(native_color c) {
		return static_cast<uint8_t>((c >> 16) & 0xff);
	}

	constexpr uint8_t native_color_b8(native_color c) {
		return static_cast<uint8_t>((c >> 8) & 0xff);
	}

	constexpr uint8_t native_color_a8(native_color c) {
		return static_cast<uint8_t>(c & 0xff);
	}

}

#endif
