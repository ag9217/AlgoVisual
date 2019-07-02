//Have two different threads, one for rendering and one for algorithm, so we can use sleep commands
//libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <thread>
#include <SFML/Graphics.hpp>

//namespace
using namespace std::literals::chrono_literals;

//Project header files
#include "algo.hpp" // algorithms
#include "extra.hpp" //self-written functions used on vectors

//-------------MAIN-----------------
int main()
{
  //resolution of window
  const float width = 1800;
  const float height = 900;

  //variables
  int n = 200; //length of array / number of rectangles drawn
  const int scale = 3; //scaling height of rectangles
  int comparisons = 0; //counting the number of comparisons during sorting
  std::chrono::microseconds delay = 750us;
  std::vector<int> array; //vector containing random values
  std::vector<sf::RectangleShape> rectangles(n); //vector containing rectangles

  srand(time(0)); //seed depends on current time
  randomizer(array, n); //randomise vector and set size equals to n

  sf::RenderWindow window(sf::VideoMode(width, height), "AlgoVisual");
  for(int i = 0; i < n; i++) //setting up initial rectangles and their style
  {
    rectangles[i].setSize(sf::Vector2f(width/float(n), array[i]*scale));
    rectangles[i].setFillColor(sf::Color(255, 255, 255));
    rectangles[i].setOutlineThickness(-1.f);
    rectangles[i].setOutlineColor(sf::Color(0, 0, 0));
    rectangles[i].setOrigin(0.f, array[i]*scale);
    rectangles[i].setPosition(0+(width/float(n))*i,height);
  }

  sf::Font font;
  font.loadFromFile("../resources/Roboto-Regular.ttf");

  sf::Text compareText;
  compareText.setFont(font);
  compareText.setCharacterSize(34);
  compareText.setFillColor(sf::Color::Blue);

  sf::Text compareInfo;
  compareInfo.setFont(font);
  compareInfo.setCharacterSize(34);
  compareInfo.setFillColor(sf::Color::Blue);
  compareInfo.setPosition(200.f, 0.f);

  print(array);

  std::thread th1; //creating thread for sorting

  while (window.isOpen())
  {
    updateRectangles(rectangles, array, n, width, height, scale);
    compareInfo.setString(std::to_string(comparisons));
    compareText.setString("Comparisons: ");

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            print(array);
            window.close();
        }

        if(event.type == sf::Event::KeyPressed) //if statement checking if certain buttons are pressed
        {
          if(event.key.code == sf::Keyboard::B) //B was pressed
          {
            th1 = std::thread (BubbleSort, std::ref(array), std::ref(rectangles), std::ref(delay), std::ref(comparisons));
          }
          if(event.key.code == sf::Keyboard::S) //S was pressed
          {
            th1 = std::thread (SelectionSort, std::ref(array), std::ref(rectangles), std::ref(delay), std::ref(comparisons));
          }
          if(event.key.code == sf::Keyboard::C) //C was pressed
          {
            th1 = std::thread (CocktailSort, std::ref(array), std::ref(rectangles), std::ref(delay), std::ref(comparisons));
          }
          if(event.key.code == sf::Keyboard::R) //R was pressed
          {
            randomizer(array, n);
            updateRectangles(rectangles, array, n, width, height, scale);
          }
          if(event.key.code == sf::Keyboard::Up) //Up arrow key was pressed
          {
            std::cout << "delay increased" << std::endl;
            delay += 500us;
          }
          if(event.key.code == sf::Keyboard::Down) //Down arrow key was pressed
          {
            std::cout << "delay decreased" << std::endl;
            delay -= 500us;
          }
          if(event.key.code == sf::Keyboard::Left) //Left arrow key was pressed
          {
            n--;
            array.clear(); //Removes all entries in vector
            rectangles.resize(n); //resize rectangles to new n value
            randomizer(array, n);
            updateRectangles(rectangles, array, n, width, height, scale);

            for(int i = 0; i < n; i++) //setting style for new rectangles
              {
                rectangles[i].setSize(sf::Vector2f(width/float(n), array[i]*scale));
                rectangles[i].setFillColor(sf::Color(255, 255, 255));
                rectangles[i].setOutlineThickness(-1.f);
                rectangles[i].setOutlineColor(sf::Color(0, 0, 0));
                rectangles[i].setOrigin(0.f, array[i]*scale);
                rectangles[i].setPosition(0+(width/float(n))*i,height);
              }
          }
          if(event.key.code == sf::Keyboard::Right) //Right arrow key was pressed
          {
            n++;
            array.clear();
            rectangles.resize(n);
            randomizer(array, n);
            updateRectangles(rectangles, array, n, width, height, scale);

            for(int i = 0; i < n; i++) //setting style for new rectangles
            {
              rectangles[i].setSize(sf::Vector2f(width/float(n), array[i]*scale));
              rectangles[i].setFillColor(sf::Color(255, 255, 255));
              rectangles[i].setOutlineThickness(-1.f);
              rectangles[i].setOutlineColor(sf::Color(0, 0, 0));
              rectangles[i].setOrigin(0.f, array[i]*scale);
              rectangles[i].setPosition(0+(width/float(n))*i,height);
            }
          }
        }
    }
    window.clear();

    for(int i = 0; i < n; i++)
    {
      window.draw(rectangles[i]);
    }
    window.draw(compareText);
    window.draw(compareInfo);
    window.display();

  }

  return 0;
}