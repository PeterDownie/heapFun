#include <iostream>
#include "heap.hpp"

int main(){
	inter i1(10);
	for(int i = 0; i < 100; i++){
		i1.addNumber(i);
	}
	std::cout << i1.getIndex(200) << std::endl;
}
