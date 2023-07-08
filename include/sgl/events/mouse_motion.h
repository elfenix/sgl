#ifndef SGL_EVENTS_MOUSE_MOTION_H__
#define SGL_EVENTS_MOUSE_MOTION_H__

#include <sgl/point.h>
#include <sgl/token.h>
#include <sgl/input/mouse_buttons.h>

namespace sgl::events {
    struct mouse_motion
    {
        token device;  //< Device associated with movement
        point pos;     //< Position relative to Window
        point rel;     //< Global position
    };
}

#endif
