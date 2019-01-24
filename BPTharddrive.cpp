#include "BPTharddrive.h"
#include <string>
#include <iostream>
#include <iomanip>

/**
\fn void recordCopy(record & copied, record & original)
\details A function which takes in two records and copies one
to the other.
\return No return value
\pre Two valid record structs are passed by reference.
\post The original is copied over and the copied value is changed.
*/
void recordCopy(record & copied, record & original)
{
	cout << "Entering recordCopy function";
	copied.zipCode = original.zipCode;
	copied.data = original.data;
	cout << "-Exiting recordCop function" << endl;
}

/**
\fn ostream & operator<<(ostream & out, record & r)
\details Overloaded insertion operator for output.
\return A referenced ostream value passed as out.
\pre A valid ostream object and record struct both passed by reference.
\post ostream object out is returned to proceed to output.
*/
ostream & operator<<(ostream & out, record & r)
{
	cout << "Entering record output";
	out << setw(6) << left << r.zipCode << '|' 
		<< setw(100) << right << r.data << endl;
	cout << "-Exiting record output" << endl;
	return out;
}

sequenceSet::~sequenceSet()
{
	cout << "deleting sequence set";
	
	cout << "-sequence set deleted";
}

void sequenceSet::split(sequenceSet* nextNode)
{
	cout << "entering split function";
	record temp;
	for (int i = 2; i < 4; i++)
	{
		recordCopy(temp, this->address[i]);
		recordCopy(nextNode->address[i - 2], temp);
		this->address[i].data.clear();
		this->address[i].zipCode = 0;
	}
	nextNode->mainKey = nextNode->address[0].zipCode;
	nextNode->next = this->next;
	nextNode->prev = this->mainKey;
	this->next = nextNode->mainKey;
	this->nextPtr = nextNode;
	cout << "-exiting split function" << (*this) << endl;
}

void sequenceSet::addElement(record r)
{
	cout << "Entering addElement function, r is " << r;
	int i = getIndex(r.zipCode);
	cout << "The index value that was found " << i;
	record temp1;
	for (int j = i; j < 4 - i && r.zipCode != 0; j++)
	{
		recordCopy(temp1, address[j]);
		recordCopy(address[j], r);
		recordCopy(r, temp1);
	}
	if (i = 0)
	{
		mainKey = address[0].zipCode;
	}
	cout << "Exiting addElement function" << address[0] << endl;
}

bool sequenceSet::deleteRecord(record r)
{
	cout << "Entering deleteRecord function";
	bool temp = false;
	int i = getIndex(r.zipCode);
	this->address[i].zipCode = 0;
	this->address[i].data.clear();
	if (i < 3)
	{
		int j = i + 1;
		for (; j < 4
			&& this->address[j].zipCode != 0; j++)
		{
			recordCopy(this->address[j - 1],
				this->address[j]);
		}
		this->address[j].zipCode = 0;
		this->address[j].data.clear();
	}
	this->mainKey = this->address[0].zipCode;

	cout << "-exiting deleteRecord" << (*this) << endl;
	return temp;
}

ostream & operator<<(ostream & out, sequenceSet & s)
{
	cout << "Entering sequenceSet output function";
	string temp = "|";
	temp += s.getMainKey();
	temp += '|';
	temp += s.getPrev();
	temp += '|';
	temp += s.getNext();
	temp += '\n';
	out << temp;
	for (int i = 0; i < 4; i++)
	{
		out << s.getAddress(i);
	}
	cout << "Exiting sequenceSet output function";
	return out;
}

void sequenceSet::insertion(record r, sequenceSet* newNode)
{
	cout << "Entering insertion function";
	if (isFull())
	{
		this->split(newNode);
		if (nextPtr->getMainKey() < r.zipCode)
		{
			nextPtr->addElement(r);
		}
	}
	else
	{
		addElement(r);
	}
	cout << "-Exiting insertion function" << (*this) << endl;
}

void sequenceSet::setAddress(record & r, int index)
{
	cout << "Entering setAddress function";
	recordCopy(address[index], r);
	cout << "Exiting setAddress function";
};
