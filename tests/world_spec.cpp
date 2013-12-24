#include <iostream>
#include "gtest/gtest.h"

using namespace std;

// int Factorial (int n);  // Returns the factorial of n

int main(int argc, char **argv) {
  cout << "test\n";  

  testing::InitGoogleTest(&argc, argv);
  return(RUN_ALL_TESTS());
}

/*int Factorial(int n) {
  return(n-1);
} */
// Tests factorial of 0

TEST(FactorialTest, abs) {
  EXPECT_EQ(1, abs(-1));
  EXPECT_EQ(1, abs(1));
}
