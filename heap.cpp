/** heapFun.cpp
 * Created By: Peter Downie (peterdownie@live.com)
 * Created: 2024-04-09 
 * This program stores integers in the heap. This allows for dynamic memory usage.
 * This will be more cpu intesive, because the heap uses more resources to assign.
 *
 * Upgrades
 * Putting in a buffer number to reduce the amount of reassignment.
 * Okay this is pretty neat.
 *
 * This is going to be split!
 */
#include <iostream>
#include "heap.hpp"

inter::inter(int buffer) : buffer(buffer){
	if(buffer < 1){
		throw std::out_of_range("BUFFER_MUST_BE_AT_LEAST_ONE"); 
	}
}
void inter::addNumber(int number){
	count++;
	if(count != 1){
		int remainingBuffer = getBufferRemainder();
		if(remainingBuffer == 0){
			bufferReassignments++;
			int *old = payload;	
			payload = new int[count + buffer];
			for(int i = 0; i < (count-1); i++){
				payload[i] = old[i];
			}
			payload[count - 1] = number;
		}else{
			payload[count - 1] = number;
		}
	}else{
		payload = new int[buffer];
		payload[0] = number;
	}
}
void inter::printNumbers(){
	for(int i = 0; i < count; i++){
		std::cout << payload[i] << std::endl;	
	}
}
int inter::getBufferRemainder() const{
	int cBufferMultiplier = 1;
	do{
		if(count <= (buffer * cBufferMultiplier)){
			return buffer * cBufferMultiplier - count;
		}
		cBufferMultiplier++;	
	}while(true);
}
int inter::getBufferReassignments(){
	return bufferReassignments;
}
