//libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <vector>
//Project header files
#include "../include/algo.hpp" //importing algorithms
#include "../include/extra.hpp" //self-written functions used on vectors

//-------------MAIN-----------------
int main()
{
   std::vector<int> array;

   randomizer(array, 9);
   print(array);
   BubbleSort(array);
   std::cout << "done" << std::endl;
   print(array);

   return 0;
}