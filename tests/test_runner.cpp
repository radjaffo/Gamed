#include <iostream>
#include "gtest/gtest.h"

using namespace std;

// int Factorial (int n);  // Returns the factorial of n

int main(int argc, char **argv) {
  cout << "test\n";  

  testing::InitGoogleTest(&argc, argv);
  return(RUN_ALL_TESTS());
}