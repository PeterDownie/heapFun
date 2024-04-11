heap: main.cpp heap.o
	g++ main.cpp -o heap heap.o
	rm -f testVersion

heap.o: heap.hpp heap.cpp
	g++ -c heap.cpp -o heap.o

gbd: main.cpp
	g++ -g main.cpp -o testVersion

clean:
	rm -f heap testVersion a.out heap.o
