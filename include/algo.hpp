#ifndef ALGO_H_
#define ALGO_H_

//function prototypes
void swap(int &a, int &b);
void BubbleSort(std::vector<int>& array, std::vector<sf::RectangleShape> &rectangles, std::chrono::microseconds &delay);
void SelectionSort(std::vector<int>& array, std::vector<sf::RectangleShape> &rectangles, std::chrono::microseconds &delay);
void CocktailSort(std::vector<int>& array, std::vector<sf::RectangleShape> &rectangles, std::chrono::microseconds &delay);
#endif