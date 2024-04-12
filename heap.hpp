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
 * This may have memory leaks
 */
#include <iostream>
//TODO: any T *old = payload()
template <typename T>
class inter{
	T *payload = new T[0]; //Other variables below.
	public: //Object Creation
	inter(); /* Default buffer of one */
	inter(int buffer); /* Set buffer, uses more space */
	~inter(); /* Cleans up payload */
	public:
	void insertAt(int index, T input); /* insert value to the array */ 
	void insertFirst(T input); /* Put item in front of array */
	void insertLast(T input); /* Most effiecent way to add items */
	void print(); /* Print all of the numbers in the array */ 
	int getBufferReassignments() const; /* See how many times the buffer has been reset */
	T getIndex(int index) const;
	void deleteIndexAt(int index); //Does not resize item in memory.
	void deleteIndexLast();  //Does not resize item in memory. Most efficent delete
	void deleteIndexFirst();  //Does not resize payload in memory.
	void removeCurrentBuffer(); //This will remove the current buffer, saves space but costs processing power.
	void resetNextItem(); //reset items	
	T getNextItem(); //return items, NULL when no items left.
	bool itemsLeft(); //check this to end loop of getNextItem();
	private:
	int nextItem = 0; //For iterating through the function. 
	int count = 0; //Items currently stored in payload, may have more items in memory.
	int buffer = 1; //How much buffer to create when reassising payload.
	int bufferReassignments = 0; //How many times this function was resized 
	int getBufferRemainder() const; /* If 0, new buffer needs to be created */
	void resizeArrayIfNeeded();  //This will remove logic froms inserts
};
