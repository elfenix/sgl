#ifndef SGL_STATE_H__
#define SGL_STATE_H__

#include <sgl/state_storage.h>
#include <sgl/token.h>

namespace sgl
{
	/// @brief Persistent GUI State Storage
	///
	/// This object allows for persistent GUI state storage for (ideally) a
	/// minimal information set saved from frame to frame. This provides a
	/// significantly more formal definition than the global state used in
	/// other toolkits written with more 'immediate mode' style.
	///
	/// These state objects are intended to allow various platforms to
	/// determine a memory management scheme, potentially eschewing heap
	/// allocation altogether. State objects are intended to be a function
	/// of prior state object and the current event. States are intended
	/// to be 'mostly' const - as the goal is to enforce a more functional
	/// paradigm for interaction.
	class state {
	public:
		state(const state&) = delete;
		state& operator=(const state&) = delete;

		explicit state(state_storage::ptr s) : _storage{ std::move(s) } {}

		const state find_subtree(token tok) const {
			return state{ _storage->find_subtree(tok) };
		}

		state start_subtree(token tok) { 
			return state{ _storage->start_subtree(tok) };
		}

	private:
		state_storage::ptr _storage;
	};
}

#endif
