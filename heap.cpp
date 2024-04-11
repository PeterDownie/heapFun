/** heapFun.cpp
 * Created By: Peter Downie (peterdownie@live.com)
 * Created: 2024-04-09 
 * This program stores integers in the heap. This allows for dynamic memory usage.
 number;* This will be more cpu intesive, because the heap uses more resources to assign.
 *
 * Upgrades
 * Putting in a buffer number to reduce the amount of reassignment.
 * Okay this is pretty neat.
 *
 * This is going to be split!
 */
#include <iostream>
#include "heap.hpp"
	
template <typename T>
int inter<T>::getIndex(int index) const{
	if(index >= count){
		throw std::out_of_range("INDEX_NOT_DEFINED");
	}
	return payload[index];
}

template <typename T>
inter<T>::inter(): buffer(1){
}

template <typename T>
inter<T>::inter(int buffer) : buffer(buffer){
	if(buffer < 1){
		throw std::out_of_range("BUFFER_MUST_BE_AT_LEAST_ONE"); 
	}
}

template <typename T>
void inter<T>::insert(T input){
	count++;
	if(count != 1){
		int remainingBuffer = getBufferRemainder();
		if(remainingBuffer == 0){
			bufferReassignments++;
			T *old = payload;	
			payload = new T[count + buffer];
			for(int i = 0; i < (count-1); i++){
				payload[i] = old[i];
			}
			payload[count - 1] = input;
		}else{
			payload[count - 1] = input;
		}
	}else{
		payload = new T[buffer];
		payload[0] = input;
	}
}

template <typename T>
void inter<T>::print(){
	for(int i = 0; i < count; i++){
		std::cout << payload[i] << std::endl;	
	}
}

template <typename T>
int inter<T>::getBufferRemainder() const{
	int cBufferMultiplier = 1;
	do{
		if(count <= (buffer * cBufferMultiplier)){
			return buffer * cBufferMultiplier - count;
		}
		cBufferMultiplier++;	
	}while(true);
}

template <typename T>
int inter<T>::getBufferReassignments() const{
	return bufferReassignments;
}
