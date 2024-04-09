/** heapFun.cpp
 * Created By: Peter Downie (peterdownie@live.com)
 * Created: 2024-04-09 
 * This program stores integers in the heap. This allows for dynamic memory usage.
 * This will be more cpu intesive, because the heap uses more resources to assign.
 */
#include <iostream>

class inter{
	int *payload = new int[0];
	int count = 0;
	public:
	void addNumber(int number){
		count++;
		if(count != 1){
			int *old = payload;	
			payload = new int[count];
			for(int i = 0; i < (count-1); i++){
				payload[i] = old[i];
			}
			payload[count - 1] = number;
		}else{
			payload = new int[count];
			payload[0] = number;
		}
	}
	void printNumbers(){
		for(int i = 0; i < count; i++){
			std::cout << payload[i] << std::endl;	
		}
	}
};

int main(){
	inter i1;
	for(int i = 0; i < 10; i++){
		i1.addNumber(i);
	}
	i1.printNumbers();
}
