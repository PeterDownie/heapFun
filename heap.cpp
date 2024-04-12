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
void inter<T>::setBufferSize(unsigned int size){
	currentPayloadSize = count + size;
	T *old = payload;
	payload = new T[currentPayloadSize];;	
	for(int i = 0; i < count; i++){
		payload[i] = old[i];
	}
}

template <typename T>
int inter<T>::getCurrentPayloadSize(){
	return currentPayloadSize;
}

template <typename T>
bool inter<T>::itemsLeft(){
	if(nextItem < count){
		return true;
	}
	return false;
}

template <typename T>
T inter<T>::getNextItem(){
	if(nextItem < count){
		return payload[nextItem++];
	}
	throw std::out_of_range("nextItem_gt_count_check_itemsLeft"); 
}

template <typename T>
void inter<T>::resetNextItem(){
	nextItem = 0;	
}

template <typename T>
void inter<T>::resizeArrayIfNeeded(){
	if(count == 1){
		currentPayloadSize = buffer;
		payload = new T[currentPayloadSize];
	}else if(getBufferRemainder() == 0){
		bufferReassignments++;
		T *old = new T[count];
		for(int i = 0; i < count; i++){
			old[i] = payload[i];
		}	
		currentPayloadSize = count + buffer;
		payload = new T[currentPayloadSize];
		for(int i = 0; i < count; i++){
			payload[i] = old[i];
		}
	}
	//delete old; //TODO: memory leak?
}

template <typename T>
void inter<T>::insertLast(T input){
	count++;
	resizeArrayIfNeeded();
	payload[count-1] = input;
}

template <typename T>
inter<T>::~inter(){
	//delete payload;
}

template <typename T>
void inter<T>::insertFirst(T input){
	T *old = new T[count];
	for(int i = 0; i < count; i++){
		old[i] = payload[i];
	}
	count++;
	resizeArrayIfNeeded();
	payload[0] = input;
	for(int i = 1; i < (count); i++){
		payload[i] = old[i-1];	
	}
	//delete old; //TODO: memory leak?
}

template <typename T>
void inter<T>::deleteIndexFirst(){
	T *old = payload;
	for(int i = 0; i < (count -1); i++){
		payload[i] = old[i + 1];
	}
	count--;
}

template <typename T>
void inter<T>::deleteIndexLast(){
	count--;
}

template <typename T>
void inter<T>::removeCurrentBuffer(){
	T *old = payload;
	currentPayloadSize = count;
	payload = new T[currentPayloadSize];	
	for(int i = 0; i < count; i++){
		payload[i] = old[i];	
	}
	//delete old; //TODO: memory leak?
}

template <typename T>
void inter<T>::deleteIndexAt(int index){
	if(index > (count - 1)){
		throw std::out_of_range("INDEX_OUT_OF_RANGE");	
	}
	//If the item is the last index, it will not need changing.
	if(index != (count - 1)){
		T *old = payload; 
		for(int i = index; i < (count - 1); i++){
			payload[i] = old[i + 1];
		}
	}
	count--;	
}
	
template <typename T>
T inter<T>::getIndex(int index) const{
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
void inter<T>::insertAt(int index, T input){
	if(index > count){
		throw std::out_of_range("insertAt_INDEX_IS_TOO_BIG");
	}
	T *old = new T[count];
	for(int i = index; i < count; i++){
		old[i] = payload[i];
	}
	count++;
	resizeArrayIfNeeded();
	payload[index] = input;
	for(int i = (index+1); i < count; i++){
		payload[i] = old[i-1];	
	}
	//delete old; //TODO: memory leak?
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
