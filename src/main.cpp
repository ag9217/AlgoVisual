#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <vector>

//funcion prototypes
void randomizer(std::vector<int>& array, int n);
void print(std::vector<int>& array);
void BubbleSort(std::vector<int>& array);

int main()
{
   std::vector<int> array;

   randomizer(array, 9);
   print(array);
   BubbleSort(array);
   print(array);

   return 0;
}

void randomizer(std::vector<int>& array, int n)
{
   srand(time(0));

   //randomiser
   for(int i = 0; i < n; i++)
   {
      array.push_back(rand() % 10 + 1);
   }
}

void print(std::vector<int>& array)
{
   for(int i = 0; i < array.size(); i++)
   {
      std::cout << array[i] << std::endl;
   }
}

//-------------ALGORITHMS-----------------
void BubbleSort(std::vector<int>& array) {
  bool swapped = true;
  int j = 0;
  int temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < array.size() - j; ++i) {
      if (array[i] > array[i + 1]) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
  }
}