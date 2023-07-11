#include <sgl/application.h>

namespace sgl {
	application::~application() {
	}

	void application::run(transformer xform, uintptr_t user) {
		for (;;) {
			context ctx = next_transform();
			if (xform(&ctx, user) == exit_run) { break; }
			complete_transform(ctx);
		}
	}
}
