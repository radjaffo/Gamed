#include <iostream>
#include <string>
#include "core/world.h"
 
using namespace std;

int main()
{
  World *a = new World;
  cout << a->getHero();
  // a->looper();


  return 0;
}