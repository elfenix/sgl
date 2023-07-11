#include <sgl/point.h>
#include <sgl/rect.h>
#include <sgl/size.h>
#include <gtest/gtest.h>


namespace sgl_test
{
    using namespace sgl;

    TEST(point, create)
    {
        point notnot{ 0, 0 };
        ASSERT_TRUE(notnot.x() == 0);
        ASSERT_TRUE(notnot.y() == 0);
    }

    TEST(point, compare)
    {
        point tl{ 0, 0 };
        point tr{ 10, 0 };
        point br{ 10, 10 };
        point bl{ 0, 10 };

        ASSERT_TRUE(tl < tr);
        ASSERT_TRUE(tl < bl);
        ASSERT_TRUE(tl < br);
        ASSERT_TRUE(tl == tl);
        ASSERT_TRUE(tr > tl);
    }
}
