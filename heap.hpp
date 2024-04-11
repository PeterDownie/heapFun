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
 * This is going to be split! - done
 *
 * This now takes a typename and can add different types of objects!
 */
#include <iostream>

template <typename T>
class inter{
	T *payload = new T[0];
	int count = 0;
	int buffer = 1; 
	int bufferReassignments = 0;
	public:
	inter(); /* Default buffer of one */
	inter(int buffer); /* Set buffer, uses more space */
	void insert(T input); /* insert value to the array */ 
	void print(); /* Print all of the numbers in the array */ 
	int getBufferReassignments() const; /* See how many times the buffer has been reset */
	int getIndex(int index) const;
	private: 
	int getBufferRemainder() const; /* If 0, new buffer needs to be created */
};

