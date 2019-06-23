#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

//funcion prototypes
void randomizer(int* array, int n);
void print(int* array, int n);
void BubbleSort(int *array, int n);

int main()
{
    int array[9];

   randomizer(array, 9);
   print(array, 9);
   BubbleSort(array, 9);
   print(array, 9);

   return 0;
}

void randomizer(int* array, int n)
{
   srand(time(0));

   //randomiser
   for(int i = 0; i < n; i++)
   {
      array[i] = rand() % 10 + 1;
   }
}

void print(int *array, int n)
{

   std::cout << "[";

   for(int i = 0; i < n; i++)
   {
      if(i < n - 1)
      {
         std::cout << array[i] << ",";
      }
      else
      {
         std::cout << array[i] << "]" << std::endl;
      }
   }
}