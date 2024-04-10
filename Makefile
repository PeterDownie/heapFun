heap: main.cpp
	g++ main.cpp -o heap
	rm -f testVersion

gbd: main.cpp
	g++ -g main.cpp -o testVersion

clean:
	rm -f heap testVersion a.out
