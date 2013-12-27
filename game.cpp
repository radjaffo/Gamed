#include <iostream>
#include <string>
#include <ctime>
#include "core/world.h"
 
using namespace std;

int main()
{
  srand(time(NULL));

  World *a = new World;
  

  
  a->displayMap();
  for(int i=0; i < 10; i++) 
  {
    a->randomMoveBoth();
    a->displayMap();
  }
  // a->looper();


  return 0;
}