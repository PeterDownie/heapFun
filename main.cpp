#include <iostream>
#include <string>
//#include "heap.hpp"
#include "heap.cpp"

int main(){
	inter<std::string> i1(10);
	i1.insert("Hello");
	i1.insert("World");
	i1.print();
}
