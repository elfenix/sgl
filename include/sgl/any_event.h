#ifndef SGL_ANY_EVENT_H__
#define SGL_ANY_EVENT_H__

#include <sgl/events/mouse_motion.h>
#include <sgl/events/noop.h>
#include <sgl/events/quit_request.h>

#include <sgl/cpp/variant.h>

namespace sgl {
	using any_event = variant<
		events::mouse_motion,
		events::noop,
		events::quit_request
	>;

	template<typename EV>
	bool is_type(const any_event& ev) {
		return holds_alternative<EV>(ev);
	}

	template<typename EV>
	EV& get_event(any_event& ev) {
		return get<EV>(ev);
	}

	template<typename EV>
	const EV& get_event(const any_event& ev) {
		return get<EV>(ev);
	}
}

#endif
