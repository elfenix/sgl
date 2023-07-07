#include <gtest/gtest.h>
#include <sgl/version.h>

namespace sgl_test
{
    TEST(library_setup, version_present)
    {
        EXPECT_TRUE(sgl::version_major != 0 || sgl::version_minor != 0 || sgl::version_micro != 0);
    }
}