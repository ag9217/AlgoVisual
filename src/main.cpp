#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <vector>

//-------------PROTOTYPES-----------------
//functions
void randomizer(std::vector<int>& array, int n);
void print(std::vector<int>& array);
void swap(int &a, int &b);
//algorithms
void BubbleSort(std::vector<int>& array);
void SelectionSort(std::vector<int>& array);

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

//-------------ALGORITHMS-----------------
//Bubble Sort
void BubbleSort(std::vector<int>& array) {
  bool swapped = true;
  int j = 0;
  int temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < array.size() - j; ++i) {
      if (array[i] > array[i + 1]) {
        swap(array[i+1], array[i]);
        swapped = true;
      }
    }
  }
}

//Selection Sort
void SelectionSort(std::vector<int>& array) {
   int imin;

   for(int i = 0; i<array.size()-1; i++) {

      imin = i;   //find index of smallest value in vector

      for(int j = i+1; j<array.size(); j++)

         if(array[j] < array[imin])

            imin = j;

         //placing in correct position by swapping
         swap(array[i], array[imin]);
   }
}

void swap(int &a, int &b) //used to swap two values in a vector/array
{
   int temp = a;
   a = b;
   b = temp;
}