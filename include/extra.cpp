#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "extra.hpp"
#include "main.hpp"

//this file contains functions that are used on the randoimised vectors
//function that randomises and sets the size of the vector
void randomizer(std::vector<int> &array, int n)
{
   if(array.size()) //if we just want to randomise the values in the vector, not add new ones
   {
      for(int i = 0; i < n; i++)
      {
         array[i] = rand() % 55 + 1;
      }
   }
   if(!array.size())
   {
      //puts random value into vector
      for(int i = 0; i < n; i++)
      {
         array.push_back(rand() % 55 + 1);
      }
   }
}

//function that prints the array of numbers
void print(std::vector<int> &array)
{
   std::cout << "[";
   for(int i = 0; i < array.size() - 2; i++)
   {
      std::cout << array[i] << ",";
   }
   std::cout << array[array.size()-1] << "]" << std::endl;
}

//update rectangle styles
void updateRectangles(std::vector<sf::RectangleShape> &r, std::vector<int> &array, int n)
{
   for(int i = 0; i < n; i++)
   {
      r[i].setSize(sf::Vector2f(width/float(n), array[i]*10));
      r[i].setOrigin(0.f, array[i]*10);
      r[i].setPosition(0+(width/float(n))*i,600);
   }
}