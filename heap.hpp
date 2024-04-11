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
	inter(); /* Default buffer of one */
	inter(int buffer); /* Set buffer, uses more space */
	void addNumber(int number); /* Add a number to the array */
	void printNumbers(); /* Print all of the numbers in the array */
	int getBufferReassignments(); /* See how many times the buffer has been reset */
	int getIndex(int index) const;
	private: 
	int getBufferRemainder() const; /* If 0, new buffer needs to be created */
};
