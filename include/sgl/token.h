#ifndef SGL_TOKEN_H_
#define SGL_TOKEN_H_

#include <sgl/cpp/stdint.h>
#include <sgl/cpp/string_view.h>
#include <sgl/cpp/functional.h>

#include <sgl/xxh32.h>

namespace sgl {
	class alignas(16) token_mem_marker;

	/// @brief Token reference for an object
	/// @details
	/// A token is a small object intended to tag information within a state
	/// tree. A token value is intended to be 'relatively' unique - ie have a
	/// very strong probability that duplicates do not occur.
	///
	/// A token may be formed from a hash or user defined 32 bit integer. An
	/// optional 16-bit user variable is also permitted.
	/// 
	/// Memory tokens return false for both hash and user test functions on
	/// most architectures, but are not gauranteed to do so by the C++ standard.
	class token {
	public:
		static_assert(sizeof(uintptr_t) <= sizeof(uint64_t), "64bits ought to be enough for anyone");

		token(const token_mem_marker* value) : _value{ static_cast<uint64_t>(reinterpret_cast<uintptr_t>(value)) } {}

		constexpr token(uint32_t value, uint16_t uflags = 0) : token(value, uflags, type_user_32) {}
		constexpr token(xxh32 value, uint16_t uflags = 0) : token(value.value(), uflags, type_xxh32) {}

		constexpr token(string_view sv) : token(xxh32{ sv.data(), sv.size() }, static_cast<uint16_t>(sv.size()))
		{
			if (sv.size() > 65536) { throw std::runtime_error{"token string > 16 bit length"}; }
		}

		constexpr uint64_t get_raw() const { return _value; }
		
		constexpr uint32_t get_h32() const { return static_cast<uint32_t>((_value >> 32) & 0xffffffff); }
		constexpr uint16_t get_l16() const { return static_cast<uint16_t>((_value >> 16) & 0xffff); }

		bool is_object(const token_mem_marker* marker) const { return static_cast<uintptr_t>(get_raw()) == reinterpret_cast<uintptr_t>(marker); }
		bool is_object(const token_mem_marker& marker) const { return is_object(&marker); }

		constexpr bool is_hash() const { return (_value & type_mask) == type_xxh32; }
		constexpr bool is_user() const { return (_value & type_mask) == type_user_32; }

		constexpr auto operator<=>(const token&) const = default;

	private:
		constexpr token(uint32_t value, uint16_t low_val, uint64_t type_mask) 
			: _value{ (static_cast<uint64_t>(value) << 32) | 
			          (static_cast<uint64_t>(low_val) << 16) |
			          type_mask }
		{
		}

		constexpr uint64_t _get_type() const {
			return _value & type_mask;
		}

		static constexpr uint64_t type_mem_marker = 0;
		static constexpr uint64_t type_user_32 = 1;
		static constexpr uint64_t type_xxh32 = 2;
		static constexpr uint64_t type_mask = 0x0f;

		uint64_t _value;
	};
}

template<>
struct sgl::hash<sgl::token> {
	constexpr sgl::size_t operator()(const sgl::token& r) const {
		return static_cast<sgl::size_t>(r.get_raw());
	}
};

#endif
