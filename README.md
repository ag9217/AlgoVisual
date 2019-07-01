# AlgoVisual
Algorithm visualisation in C++ with SFML. This project is a great way to see how algorithms work in practice, as they are usually taught in very abstract ways. This project also allowed me to experiment more with the [SFML](https://www.sfml-dev.org/) library and multi-threaded applications.

### Side Note
This program is mutli-threaded where one thread is rendering the graphics and the other sorting the random values. Implementing multiple threads was easy, but difficult to work with. So some features I wanted to implement might come at a later date.

### Installation
This project requires SFML to function. To install SFML:

```
sudo apt-get install libsfml-dev
```

In order to compile the program, simply run the makefile in the `src` directory by typing `make`. To then run the program, type `./algov`.

### Usage
You can randomise the values by pressing `r` and pick between Bubble Sort `b` or Selection Sort `s`. While the program is sorting the array, the up and down keys can be used to increase and decrease the delay between steps respectively.

Green indicates that two values were swapped in the array and red indicates no swap.

### Images
![alt text](https://i.imgur.com/LmtkkiJ.gif)
