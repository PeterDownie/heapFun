#include <iostream>
#include <string>
//#include "heap.hpp"
#include "heap.cpp"

int main(){
	inter<std::string> i1(2);
	i1.insertLast("Peter");
	i1.insertLast("Peter");
	i1.insertLast("Peter");
	i1.insertLast("Peter");
	i1.insertLast("Peter");
	i1.print();
	i1.setBufferSize(20);
	std::cout << i1.getCurrentPayloadSize() << std::endl;
}
