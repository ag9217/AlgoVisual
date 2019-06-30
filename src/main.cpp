//Have two different threads, one for rendering and one for algorithm, so we can use sleep commands
//libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <thread>
#include <SFML/Graphics.hpp>

//resolution of window
extern const float width = 1800;
extern const float height = 600;

//Project header files
#include "algo.hpp" // algorithms
#include "extra.hpp" //self-written functions used on vectors

//-------------MAIN-----------------
int main()
{
  //variables
  int a = 2;
  int n = 500; //length of array / number of rectangles drawn
  srand(time(0)); //seed depends on current time
  std::vector<int> array; //vector containing random values
  std::vector<sf::RectangleShape> rectangles(n); //vector containing rectangles
  randomizer(array, n);

  sf::RenderWindow window(sf::VideoMode(width, height), "AlgoVisual");
  for(int i = 0; i < n; i++) //setting up initial rectangles and their style
  {
    rectangles[i].setSize(sf::Vector2f(width/float(n), array[i]*10));
    rectangles[i].setFillColor(sf::Color(255, 255, 255));
    rectangles[i].setOutlineThickness(-1.f);
    rectangles[i].setOutlineColor(sf::Color(0, 0, 0));
    rectangles[i].setOrigin(0.f, array[i]*10);
    rectangles[i].setPosition(0+(width/float(n))*i,height);
  }

  print(array);

  std::thread th1;

  while (window.isOpen())
  {
    updateRectangles(rectangles, array, n);

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if(event.type == sf::Event::KeyPressed)
        {
          if(event.key.code == sf::Keyboard::B)
          {
            a = 1;
            th1 = std::thread (BubbleSort, std::ref(array), std::ref(rectangles));
          }

          if(event.key.code == sf::Keyboard::S)
          {
            a = 2;
            th1 = std::thread (SelectionSort, std::ref(array), std::ref(rectangles));
          }
          if(event.key.code == sf::Keyboard::R)
          {
            std::cout << "hello" << std::endl;
            randomizer(array, n);
            updateRectangles(rectangles, array, n);
          }
        }
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