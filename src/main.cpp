#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <vector>

//funcion prototypes
void randomizer(std::vector<int>& array, int n);
void print(std::vector<int>& array);
void BubbleSort(std::vector<int>& array);
void SelectionSort(std::vector<int>& array);
void swap(int *xp, int *yp);

int main()
{
   std::vector<int> array;

   randomizer(array, 9);
   print(array);
   SelectionSort(array);
   std::cout << "done" << std::endl;
   print(array);

   return 0;
}

//function that randomises and sets the size of the vector
void randomizer(std::vector<int>& array, int n)
{
   srand(time(0)); //seed depends on current time

   //randomiser
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
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
  }
}

//Selection Sort
void SelectionSort(std::vector<int>& array)
{
   int min_ind;

   for(int i = 0; i < array.size() - 1; i++)
   {
      //finding minimum value in unsorted vector
      min_ind = i;
      for(int j = i+1; j < array.size(); j++)
      {
         if(array[j] < array[min_ind])
         {
            min_ind = j;
         }
         //swap
         swap(&array[min_ind], &array[i]);
      }
   }
}

void swap(int *xp, int *yp)
{
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}