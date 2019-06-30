#include <vector>
#include <thread>
#include <SFML/Graphics.hpp>
#include "algo.hpp"
#include "main.hpp"
//this file contains all the algorithms used in this program
using namespace std::literals::chrono_literals;
//-------------ALGORITHMS-----------------
//Bubble Sort
void BubbleSort(std::vector<int>& array, std::vector<sf::RectangleShape> &rectangles)
{

  bool swapped = true;
  int j = 0;
  int temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < array.size() - j; ++i) {

      for(int k = 0; k < array.size(); k++) //Setting every rectangle to white
      {
        rectangles[k].setFillColor(sf::Color(255, 255, 255));
      }

      if (array[i] > array[i + 1]) { 
        rectangles[i].setFillColor(sf::Color(0, 255, 0)); //change the two rectangles being swapped to green
        rectangles[i+1].setFillColor(sf::Color(0, 255, 0)); 
        std::this_thread::sleep_for(0.0001s);
        swap(array[i+1], array[i]); //swap the position of the values
        std::this_thread::sleep_for(0.0001s);
        swapped = true;
        continue;
      }

      rectangles[i].setFillColor(sf::Color(255, 0, 0)); //if there is no swap, make rectangle red
      std::this_thread::sleep_for(0.0001s);
    }
  }

  for(int k = 0; k < array.size(); k++)
  {
    rectangles[k].setFillColor(sf::Color(255, 255, 255)); //when sorting is finished, make rectangles white
  }
}

//Selection Sort
void SelectionSort(std::vector<int>& array, std::vector<sf::RectangleShape> &rectangles)
{
   int imin;

   for(int i = 0; i<array.size()-1; i++)
   {

      imin = i;   //find index of smallest value in vector
      //std::this_thread::sleep_for(0.001s);

      for(int j = i+1; j<array.size(); j++){
          for(int k = 0; k < array.size(); k++) //Setting every rectangle to white
          {
            rectangles[k].setFillColor(sf::Color(255, 255, 255));
          }

         if(array[j] < array[imin])
         {
            imin = j;
            std::this_thread::sleep_for(0.001s);
         }

         else
         {
          rectangles[j].setFillColor(sf::Color(255, 0, 0)); //change the two rectangles being swapped to green
          rectangles[imin].setFillColor(sf::Color(255, 0, 0));
          std::this_thread::sleep_for(0.0001s); 
         }
       }

         //placing in correct position by swapping
         rectangles[i].setFillColor(sf::Color(0, 255, 0)); //change the two rectangles being swapped to green
         rectangles[imin].setFillColor(sf::Color(0, 255, 0)); 
         std::this_thread::sleep_for(0.0001s);
         swap(array[i], array[imin]);
   }

    for(int k = 0; k < array.size(); k++) //Setting every rectangle to white
    {
      rectangles[k].setFillColor(sf::Color(255, 255, 255));
    }
}

void swap(int &a, int &b) //used to swap two values in a vector/array
{
   int temp = a;
   a = b;
   b = temp;
}