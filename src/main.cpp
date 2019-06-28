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

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

   std::vector<int> array;

   randomizer(array, 9);
   print(array);
   BubbleSort(array);
   std::cout << "done" << std::endl;
   print(array);

   return 0;
}