#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "extra.hpp"
//this file contains functions that are used on the randoimised vectors
//function that randomises and sets the size of the vector
void randomizer(std::vector<int>& array, int n)
{
   srand(time(0)); //seed depends on current time

   //puts random value into vector
   for(int i = 0; i < n; i++)
   {
      array.push_back(rand() % 10 + 1);
   }
}

void print(std::vector<int>& array) //print array
{
   std::cout << "[";
   for(int i = 0; i < array.size() - 2; i++)
   {
      std::cout << array[i] << ",";
   }
   std::cout << array[array.size()-1] << "]" << std::endl;
}