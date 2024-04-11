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

class inter{
	int *payload = new int[0];
	int count = 0;
	int buffer = 1; 
	int bufferReassignments = 0;
	public:
	inter();
	inter(int buffer);
	void addNumber(int number);
	void printNumbers();
	int getBufferRemainder() const;
	int getBufferReassignments();
};
