//libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>

//Project header files
#include "algo.hpp" //importing algorithms
#include "extra.hpp" //self-written functions used on vectors

//-------------MAIN-----------------
int main()
{
  //variables
  int n = 100; //length of array / number of rectangles drawn
  std::vector<int> array; //vector containing random values
  std::vector<sf::RectangleShape> rectangles(n); //vector containing rectangles
  randomizer(array, n);

  sf::RenderWindow window(sf::VideoMode(800, 600), "AlgoVisual");
  for(int i = 0; i < n; i++) //setting up initial rectangles and their style
  {
    rectangles[i].setSize(sf::Vector2f(800.f/float(n), array[i]*10));
    rectangles[i].setFillColor(sf::Color(255, 255, 255));
    rectangles[i].setOutlineThickness(-1.f);
    rectangles[i].setOutlineColor(sf::Color(0, 0, 0));
    rectangles[i].setOrigin(0.f, array[i]*10);
    rectangles[i].setPosition(0+(800.f/float(n))*i,600);
  }

  print(array);

  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
      }
      window.clear();

      for(int i = 0; i < n; i++)
      {
        window.draw(rectangles[i]);
      }

      window.display();

  }

  return 0;
}