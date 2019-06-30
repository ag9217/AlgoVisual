#include <vector>
#include <thread>
#include "algo.hpp"
//this file contains all the algorithms used in this program
using namespace std::literals::chrono_literals;
//-------------ALGORITHMS-----------------
//Bubble Sort
void BubbleSort(std::vector<int>& array)
{

  bool swapped = true;
  int j = 0;
  int temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < array.size() - j; ++i) {
      if (array[i] > array[i + 1]) {
        std::this_thread::sleep_for(0.01s);
        swap(array[i+1], array[i]);
        std::this_thread::sleep_for(0.01s);
        swapped = true;
      }
    }
  }
}

//Selection Sort
void SelectionSort(std::vector<int>& array)
{
   int imin;

   for(int i = 0; i<array.size()-1; i++) {
      imin = i;   //find index of smallest value in vector
      std::this_thread::sleep_for(0.01s);

      for(int j = i+1; j<array.size(); j++)

         if(array[j] < array[imin])

            imin = j;
            std::this_thread::sleep_for(0.01s);

         //placing in correct position by swapping

         swap(array[i], array[imin]);
         std::this_thread::sleep_for(0.01s);
   }
}

void swap(int &a, int &b) //used to swap two values in a vector/array
{
   int temp = a;
   a = b;
   b = temp;
}