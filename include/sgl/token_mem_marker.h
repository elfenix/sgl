#ifndef SGL_TOKEN_MEM_MARKER_H__
#define SGL_TOKEN_MEM_MARKER_H__

#include <sgl/cpp/string_view.h>

namespace sgl {
	/// @brief Marker for unique tokens
	/// @details
	/// The mem_marker token utilizes program address space to provide a unique
	/// marker with a strong gaurantee of no collisions.
	class alignas(16) token_mem_marker {
	public:
		token_mem_marker(string_view name) : _name{ name } {}
		virtual ~token_mem_marker() {}

		string_view get_name() const { return _name; }

	private:
		string_view _name;
	};
}

#endif
