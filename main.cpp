/** heapFun.cpp
 * Created By: Peter Downie (peterdownie@live.com)
 * Created: 2024-04-09 
 * This program stores integers in the heap. This allows for dynamic memory usage.
 * This will be more cpu intesive, because the heap uses more resources to assign.
 *
 * Upgrades
 * Putting in a buffer number to reduce the amount of reassignment.
 * Okay this is pretty neat.
 */
#include <iostream>

class inter{
	int *payload = new int[0];
	int count = 0;
	int buffer = 1; 
	int bufferReassignments = 0;
	public:
	inter(){
	
	}
	inter(int buffer) : buffer(buffer){
		if(buffer < 1){
			throw std::out_of_range("BUFFER_MUST_BE_AT_LEAST_ONE"); 
		}
	}
	void addNumber(int number){
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
	void printNumbers(){
		for(int i = 0; i < count; i++){
			std::cout << payload[i] << std::endl;	
		}
	}
	int getBufferRemainder() const{
		int cBufferMultiplier = 1;
		do{
			if(count <= (buffer * cBufferMultiplier)){
				return buffer * cBufferMultiplier - count;
			}
			cBufferMultiplier++;	
		}while(true);
	}
	int getBufferReassignments(){
		return bufferReassignments;
	}
};

int main(){
	inter i1(10);
	for(int i = 0; i < 100; i++){
		i1.addNumber(i);
	}
	std::cout << "BFR: " << i1.getBufferReassignments() << std::endl;
}
