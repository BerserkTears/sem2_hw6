#include <gtest/gtest.h>
#include "polynomial.h"

TEST(tests, threeElements) {
    const int amount = 3;
    constexpr int vec[] = {1,1,1};
    constexpr int vec1[] = {1,3,5};
    constexpr int vec2[] = {100,300,500};
    EXPECT_EQ(polynomial(amount, vec).solve(1), 3);
    EXPECT_EQ(polynomial(amount, vec1).solve(6), 199);
    EXPECT_EQ(polynomial(amount, vec2).solve(6), 19900);
}

TEST(tests, fiveElements) {
    const int amount = 5;
    constexpr int vec[] = {1,1,1,1,1};
    constexpr int vec1[] = {1,3,5,7,9};
    constexpr int vec2[] = {100,300,500, 7, 9};
    EXPECT_EQ(polynomial(amount, vec).solve(1), 5);
    EXPECT_EQ(polynomial(amount, vec1).solve(6), 13375);
    EXPECT_EQ(polynomial(amount, vec2).solve(20), 1702100);
}