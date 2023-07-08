#include <sgl/cpp/stdint.h>

namespace sgl::input {
    enum class mouse_buttons : uint32_t
    {
        None = 0x00000000u,
        Left = 0x00000001u,
        Right = 0x00000002u,
        Middle = 0x00000004u,
        Back = 0x00000008u,
        Forward = 0x00000010u,
        Task = 0x00000020u,
    };

    constexpr bool operator&(mouse_buttons a, mouse_buttons b)
    {
        return (static_cast<uint32_t>(a) & static_cast<uint32_t>(b)) != 0;
    }
}
