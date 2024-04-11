#include <iostream>
#include "heap.hpp"

int main(){
	inter i1(10);
	for(int i = 0; i < 100; i++){
		i1.addNumber(i);
	}
	std::cout << "BFR: " << i1.getBufferReassignments() << std::endl;
}
