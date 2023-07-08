
#include <sgl/version.h>
#include <sgl/xxh32.h>
#include <sgl/token.h>
#include <sgl/token_mem_marker.h>

#include <gtest/gtest.h>
#include <sgl/cpp/array.h>

namespace sgl_test
{
    using namespace sgl;

    template<uint64_t value, uint64_t expected>
    struct constexpr_test { static_assert(value == expected, "Compile-time hash mismatch."); };

    bool checkhash_32(const void* ptr, size_t len, uint32_t seed, uint32_t expected)
    {
        const uint32_t hash = xxh32::hash(reinterpret_cast<const char*> (ptr), len, seed);
        if (hash != expected) {
            std::cerr << "[xxh32] Test failed: 0x" << std::hex << hash << " != 0x" << std::hex << expected << std::endl;
            return false;
        }
        return true;
    }

    constexpr_test<xxh32::hash("", 0, 0), 0x2CC5D05U> constexprTest_1;
    constexpr_test<xxh32::hash("", 0, 2654435761U), 0x36B78AE7U> constexprTest_2;
    constexpr_test<xxh32::hash("test", 4, 0), 0x3E2023CFU> constexprTest32_5;
    constexpr_test<xxh32::hash("test", 4, 2654435761U), 0xA9C14438U> constexprTest32_6;

    TEST(xxh32, general_tests)
    {
        static array<uint8_t, 10100> data;
        static constexpr uint32_t prime = 2654435761U;

        uint32_t byteGen = prime;
        for (auto i = 0; i < data.size(); i++) {
            data[i] = byteGen >> 24;
            byteGen *= byteGen;
        }

        EXPECT_TRUE(checkhash_32(nullptr, 0, 0, 0x2CC5D05U));
        EXPECT_TRUE(checkhash_32(nullptr, 0, prime, 0x36B78AE7U));
        EXPECT_TRUE(checkhash_32(data.data(), 1, 0, 0xB85CBEE5U));
        EXPECT_TRUE(checkhash_32(data.data(), 1, prime, 0xD5845D64U));
        EXPECT_TRUE(checkhash_32(data.data(), 14, 0, 0xE5AA0AB4U));
        EXPECT_TRUE(checkhash_32(data.data(), 14, prime, 0x4481951DU));
        EXPECT_TRUE(checkhash_32(data.data(), 101, 0, 0x1F1AA412U));
        EXPECT_TRUE(checkhash_32(data.data(), 101, prime, 0x498EC8E2U));
        EXPECT_TRUE(checkhash_32(data.data(), data.size(), 0, 0x3931B56F));
        EXPECT_TRUE(checkhash_32(data.data(), data.size(), prime, 0x44857AA1));
    }

    TEST(library_setup, version_present)
    {
        EXPECT_TRUE(sgl::version_major != 0 || sgl::version_minor != 0 || sgl::version_micro != 0);
    }

    token_mem_marker tmem_marker_1{ "Hello Memory" };
    token_mem_marker tmem_marker_2{ "Hello Memory2" };

    TEST(token, string_tokens)
    {
        token t{"Hello World"};

        std::unordered_map<token, int> v;
        v[t] = -1;

        EXPECT_TRUE(t == token{"Hello World"});
        EXPECT_TRUE(v.find("a"sv) == v.end());
        EXPECT_TRUE(t.is_hash());
        EXPECT_TRUE(token(t.get_h32(), t.get_l16()) != t);
        EXPECT_TRUE(!t.is_user());
    }

    TEST(token, user_tokens)
    {
        token t16_1{ 16, 1 };
        token t16_2{ 16, 2 };

        EXPECT_TRUE(t16_1 != t16_2);
        EXPECT_TRUE(t16_1.get_l16() == 1);
        EXPECT_TRUE(t16_2.get_h32() == 16);
        EXPECT_TRUE(t16_1.is_user());
    }

    TEST(token, mem_tokens)
    {
        token t1{ &tmem_marker_1 };
        token t2{ &tmem_marker_2 };

        EXPECT_TRUE(t1 != t2);
        EXPECT_TRUE(t1.get_raw() == reinterpret_cast<uint64_t>(&tmem_marker_1));
        EXPECT_TRUE(t1.is_object(&tmem_marker_1));
        EXPECT_FALSE(t1.is_object(&tmem_marker_2));
    }
}