//
// Created by yunji on 2023/5/30.
//
#include <gtest/gtest.h>

TEST(ExampleTest, TestAddition) {
  int a = 2;
  int b = 3;
  EXPECT_EQ(a + b, 5);
}

TEST(ExampleTest, TestAddition2) {
  int a = 2;
  int b = 3;
  EXPECT_EQ(a + b, 4);
}
