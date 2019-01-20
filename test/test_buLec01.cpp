#include <gtest/gtest.h>
#include "test_api.h"
#include <buLec01.h>
TEST(BuLec, gcd)
{
    ASSERT_EQ(1, gcd(10, 9));
    ASSERT_EQ(3, gcd(6, 9));
    ASSERT_EQ(gcd(1191, 110), 1);
    ASSERT_EQ(gcd(8, 16), 8);
}
