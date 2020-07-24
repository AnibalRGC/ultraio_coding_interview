#include "gtest/gtest.h"
#include "bitOperator.hpp"

TEST(BitOperatorTest, init) {
    EXPECT_EQ(add(2, 5), 7);
    EXPECT_EQ(add(22,99), 121);
    EXPECT_EQ(add(98765,83592), 182357);
    EXPECT_EQ(add(std::numeric_limits<int>::max(),std::numeric_limits<int>::max()), -2);
    EXPECT_EQ(add(std::numeric_limits<int>::min(),std::numeric_limits<int>::min()), 0);
    EXPECT_EQ(add(std::numeric_limits<int>::max(),std::numeric_limits<int>::min()), -1);
    EXPECT_EQ(add(std::numeric_limits<int>::min(),std::numeric_limits<int>::max()), -1);
}
