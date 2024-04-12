#include <iostream>
#include <string>
//#include "heap.hpp"
#include "heap.cpp"

int main(){
	inter<std::string> i1(2);
	i1.insertLast("Peter");
	i1.insertFirst("Downie");
	i1.insertAt(0, "John");
	i1.insertLast("Nathan");
	i1.insertLast("Drew");
	i1.deleteIndexAt(0);
	i1.deleteIndexLast();
	i1.deleteIndexFirst();
	std::cout << i1.getIndex(0);
	i1.removeCurrentBuffer();
	i1.print();
}
