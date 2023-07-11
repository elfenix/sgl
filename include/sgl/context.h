#ifndef SGL_CONTEXT_H_
#define SGL_CONTEXT_H_

#include <sgl/any_event.h>
#include <sgl/state.h>
#include <sgl/state_storage.h>
#include <sgl/draw_list.h>

namespace sgl {
	class application;

	/// @brief Transformer Input/Output Context
	///
	/// @details
	/// SGL operates on the concept that a GUI application may be represented
	/// by a series of events (E_1, E_2, ... E_n) transforming application
	/// state. Specifically:
	///		S_n = X(S_n-1, E_n)
	/// 
	/// This concept is slightly at odds with the features of C++ object
	/// representation when not forcing either extreme template metaprograms,
	/// substantial heap allocations, or other limitations. Instead, the
	/// transform function accepts a context object which enables the
	/// platform to determine the appropriate interface and create S_n for
	/// the transformer to modify.
	///
	class context {
	public:
		context(const context&) = delete;
		context& operator=(const context&) = delete;
		context(context&&) = default;
		context& operator=(context&&) = default;

		context(application* parent, state_storage::ptr prev_state, any_event trigger,
				state_storage::ptr out_state, draw_list::ptr out_draw)
			: _parent{ parent }
			, _prev_state{std::move(prev_state)}
			, _trigger{ trigger }
			, _out_state{std::move(out_state)}
			, _draw_list{ std::move(out_draw) }
		{
		}

		application* get_parent() const { return _parent; }

		const any_event& get_trigger() const { return _trigger; }

		const state& prev_state() const { return _prev_state; }
		state& out_state() { return _out_state; }

		bool is_drawing() const { return !!_draw_list; }

		draw_list& draw_list() {
			if (!_draw_list) { throw out_of_range{"not drawing"}; }
			return *_draw_list;
		}

		draw_list::ptr release_draw_list() {
			return std::move(_draw_list);
		}

	private:
		application* _parent;
		const state _prev_state;
		any_event _trigger;
		state _out_state;
		draw_list::ptr _draw_list;
	};
}

#endif
