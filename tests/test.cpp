#include <gtest/gtest.h>

#include "template.hpp"

TEST(graph_test, addition) {
    auto expected = 4;
    EXPECT_EQ(expected, placeholder::add(1, 3));
}