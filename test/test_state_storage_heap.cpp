#include <sgl/state_storage_heap.h>
#include <gtest/gtest.h>


namespace sgl_test
{
    using namespace sgl;

    TEST(state_storage_heap, create)
    {
        ASSERT_TRUE(!!state_storage_heap::create());
    }

    TEST(state_storage_heap, subtree_start)
    {
        auto ptr = state_storage_heap::create();
        ptr->start_subtree("Hello"sv);

        ASSERT_TRUE(!!ptr->find_subtree("Hello"sv));
    }

    TEST(state_storage_heap, clone_subtree_start)
    {
        auto ptr = state_storage_heap::create();
        ptr->start_subtree("Hello"sv);
        ASSERT_TRUE(!!ptr->find_subtree("Hello"sv));

        auto clone = ptr->clone();
        ASSERT_TRUE(!!clone->find_subtree("Hello"sv));
    }

    TEST(state_storage_heap, repeat_subtree_fail)
    {
        auto ptr = state_storage_heap::create();
        ptr->start_subtree("Hello"sv);

        ASSERT_ANY_THROW(ptr->start_subtree("Hello"sv));
    }
}
