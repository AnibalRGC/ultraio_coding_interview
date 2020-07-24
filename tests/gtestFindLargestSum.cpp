#include <gmock/gmock.h>
#include "gtest/gtest.h"
#include "findLargestSum.hpp"

TEST(FindLargestSumTest, init) {
    std::vector<uint32_t> I = {1, 2, 3, 4, 5, 6, 7};
    std::vector<uint32_t> M = {};
    uint32_t S = 0;

    // Exercice example
    find_largest_sum(11, I, M, S);
    EXPECT_THAT(M, ::testing::ElementsAreArray({ 5, 3, 2, 1 }));
    EXPECT_EQ(S, 11);


    // Impossible match
    M.clear();
    S=0;
    find_largest_sum(1111, I, M, S);
    EXPECT_THAT(M, ::testing::ElementsAreArray({ 7, 6, 5, 4, 3, 2, 1 }));
    EXPECT_EQ(S, 28);

    // Empty vector
    M.clear();
    S=0;
    find_largest_sum(1111, {}, M, S);
    EXPECT_TRUE(M == std::vector<uint32_t>({}));
    EXPECT_EQ(S, 0);

    // Bigger vector
    I.clear();
    I.resize(10000);
    std::fill(I.begin(),I.end(),1);
    M.clear();
    S=0;
    find_largest_sum(1234, I, M, S);
    EXPECT_TRUE(M == std::vector<uint32_t>(1234, 1));
    EXPECT_EQ(S, 1234);
}
