output: main.o algo.o extra.o
	g++ main.o algo.o extra.o -o algov -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -I ../include/

algo.o: ../include/algo.cpp ../include/algo.hpp
	g++ -c ../include/algo.cpp -o algo.o

extra.o: ../include/extra.cpp ../include/extra.hpp
	g++ -c ../include/extra.cpp -o extra.o

clean:
	rm -rf *.o output