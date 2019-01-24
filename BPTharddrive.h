/**
	\file BPTharddrive.h
	\class sequenceSet
	\brief sequenceSet - an ordered lowest-level node which contains the previous node key and the next node key along with an array of records.

	\invariant 
	1. Items in the sets are in ascending order.
	2. When there is no previous key it equals -1.
	3. When there is no next key it equals -1.

	This class is an ordered linked list of arrays of addresses obtained from
	a file. There will only at any point be one to two sequenceSet objects
	in memory. In all other cases they will be on the disk in a txt file.
*/

#ifndef B_P_TREE
#define B_P_TREE

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/**
	\struct record 
	\brief record - Holds zipcodes and the string data for the rest of the program.
*/
struct record
{
	int zipCode;
	string data;
};

/**
\fn void recordCopy(record & copied, record & original)
\details A function which takes in two records and copies one
to the other.
\return No return value
\pre Two valid record structs are passed by reference.
\post The original is copied over and the copied value is changed.
*/
void recordCopy(record & copied, record & original);

/**
\fn ostream & operator<<(ostream & out, record & r)
\details Overloaded insertion operator for output.
\return A referenced ostream value passed as out.
\pre A valid ostream object and record struct both passed by reference.
\post ostream object out is returned to proceed to output.
*/
ostream & operator<<(ostream & out, record & r);

class sequenceSet
{
public:

	/**
	\fn sequenceSet()
	\details Constructor for the sequenceSet class. Defaults to prev = -1, 
	next = -1, mainKey = 0, nextPtr = NULL.
	\return No return value.
	\pre None
	\post A sequenceSet object is created.
	*/
	sequenceSet() :prev(-1), next(-1), mainKey(0), nextPtr(NULL) 
	{
		address[0].zipCode = 0; address[0].data.clear();
	};

	/**
	\fn ~sequenceSet()
	\details Destructor for the sequenceSet class. Deletes itself.
	\return No return value.
	\pre A valid sequenceSet object exists.
	\post Object and memory is unallocated.
	*/
	~sequenceSet();

	/**
	\fn void split(sequenceSet* nextNode)
	\details Splits a full sequenceSet node and sets the now half full node's
	nextPtr to the new next node while updating all other necessary variables.
	\return No return value.
	\pre A node is full and/or user wants to split node, also a new nextNode
	is created.
	\post The node is split, it's nextPtr value equals nextNode and all 
	necessary variables are altered.
	*/
	void split(sequenceSet* nextNode);

	/**
	\fn void addElement(record r)
	\details Adds an element to a non-full sequenceSet.
	\return sequenceSet with element inserted.
	\pre A sequenceSet exists and a record is passed.
	\post The record is added to the address array of records.
	*/
	void addElement(record r);

	/**
	\fn bool deleteRecord(record r)
	\details Removes a record from the sequenceSet.
	\return A boolean stating if the set is empty.
	\pre A record exists within the sequenceSet.
	\post The recorsd is removed and the boolean is returned.
	*/
	bool deleteRecord(record r);

	/**
	\fn void insertion(record r)
	\details Manages the insertion of elements into a sequence set. Determines
	whether splitting is necessary or if just the element can be inserted.
	\return No return value
	\pre A sequenceSet exists and a record r is passed to it.
	\post The value r is inserted into the sequenceSet.
	*/
	void insertion(record r, sequenceSet* newNode);

	/**
	\fn int sizeOf()
	\details Returns the size of the sequenceSet.
	\return The size of the sequenceSet.
	\pre Existing sequenceSet
	\post An int value representing the size is returned.
	*/
	int sizeOf() { return sizeof(this);  };

	/**
	\fn bool isEmpty()
	\details Checks if the sequenceSet is empty.
	\return A boolean representing emptiness.
	\pre An existing sequenceSet.
	\post Boolean is returned.
	*/
	bool isEmpty() { return (this->address[0].zipCode == 0); };

	/**
	\fn int getPrev()
	\details Gets the previous key.
	\return Integer representing the previous key value
	\pre An existing sequenceSet.
	\post the previous value is returned.
	*/
	int getPrev() { return prev; };

	/**
	\fn int getNext()
	\details Gets the next key.
	\return The next key.
	\pre An existing sequenceSet.
	\post The next key is returned.
	*/
	int getNext() { return next; };

	/**
	\fn int getMainKey()
	\details Gets the mainKey.
	\return The mainKey variable.
	\pre An existing sequenceSet.
	\post The mainKey variable is returned.
	*/
	int getMainKey() { return mainKey; };

	/**
	\fn void  setMainKey(int k)
	\details Sets the main key to passed value.
	\return No return value
	\pre An existing sequenceSet and an integer for the set value.
	\post mainKey is set the the int variable k.
	*/
	void  setMainKey(int k) { mainKey = k; };

	/**
	\fn void setNext(int k)
	\details Sets the next key to the passed value.
	\return No return value.
	\pre An existing sequenceSet and an integer for the set value.
	\post The next key is set to the integer k.
	*/
	void setNext(int k) { next = k; };

	/**
	\fn void setPrev(int k)
	\details Sets the prev key value to the passed value.
	\return No return value.
	\pre An existing sequenceSet and an integer for the set value.
	\post prev is set to the integer k.
	*/
	void setPrev(int k) { prev = k; };

	/**
	\fn bool isFull()
	\details Checks if the sequenceSet is full.
	\return True if full, false if not.
	\pre An existing sequenceSet.
	\post The boolean stating fullness is returned.
	*/
	bool isFull() { return (address[3].zipCode != 0); };

	/**
	\fn void setNextPtr(sequenceSet * newNext)
	\details Sets the nextPtr to the the passed sequenceSet pointer.
	\return No return value.
	\pre A valid sequenceSet and a passed sequenceSet pointer.
	\post The nextPtr is set to the newNext pointer.
	*/
	void setNextPtr(sequenceSet * newNext) { nextPtr = newNext; };

	/**
	\fn sequenceSet * getNextPtr()
	\details Gets the nextPtr from the sequenceSet object.
	\return Returns a sequenceSet pointer that was contained in nextPtr. 
	\pre A valid sequenceSet.
	\post The nextPtr is returned.
	*/
	sequenceSet * getNextPtr() { return nextPtr; };

	/**
	\fn record & getAddress(int index) 
	\details Gets the address of a specific place within the record struct.
	\return The record correlating to the index we are searching for is returned.
	\pre An index integer is passed.
	\post The record containing the searched value is returned.
	*/
	record & getAddress(int index) 
	{ return address[index]; };

	int getIndex(int zip)
	{
		int i = 0;
		for (; i < 4 && address[i].zipCode < zip && address[i].zipCode != 0; i++)
		{}
		return i;
	}

	/**
	\fn void setAddress(record & r, int index)
	\details Sets the address at a position when given the index and the 
	record to replace it with.
	\return No return value.
	\pre A record and index position are passed.
	\post The record at the index position is replaced with the r.
	*/
	void setAddress(record & r, int index);

private:
	int prev, next, mainKey;
	record address[4];
	sequenceSet* nextPtr;
};

/**
\fn ostream * operator<<(ostream * out, sequenceSet & s)
\details The overloaded output operator for the sequenceSet class.
\return An ostream pointer.
\pre A valid sequenceSet and ostream.
\post The output is sent to the ostream.
*/
ostream & operator<<(ostream & out, sequenceSet & s);

#endif