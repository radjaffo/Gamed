#include <iostream>
#include <string>
#include "core/world.h"
 
using namespace std;

int main()
{
  srand(0);

  World *a = new World;

  
  a->displayMap();
  // a->looper();


  return 0;
}