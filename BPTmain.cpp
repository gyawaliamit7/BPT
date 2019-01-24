#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


#include "BPTharddrive.h"
void displayMenu();
void openFile(ifstream & inputF, ofstream & outputF);
void outputFile(ofstream & outputF);
void output();
void insertFile(sequenceSet& s, sequenceSet* s1);
void deleteFile();
void printInformation();



int main()
{
	int choice;
	ifstream inFile;
	ofstream outFile;
	sequenceSet s;
	sequenceSet* s1;
	s1 = new(nothrow) sequenceSet;
	displayMenu();
	cin >> choice;

	do
	{
		if (choice == 1)
		{
			openFile(inFile, outFile);
		}

		else if (choice == 2)
		{
			insertFile(s, s1);

		}
		else if (choice == 3)
		{
			deleteFile();

		}
		else if (choice == 4)
		{
			printInformation();

		}
		else if (choice == 5)
		{

		}
		else if (choice >6)
		{
			cout << "The choice is invalid \n";
			break;
		}

		displayMenu();
		cin >> choice;


	} while (choice <= 5);

	return 0;

}

void displayMenu()
{
	cout << "Please Choose your options: \n";
	cout << "1.to open and readfile \n";
	cout << "2.to insert a record \n";
	cout << "3.to delete a record \n";
	cout << "4.to print information \n "
		<< "5.to sort input file into blocks and records \n";
	cout << "6.to exit \n ";
	cout << endl;
}

void openFile(ifstream & inputF, ofstream & outputF)
{
	string inFileName;
	cout << endl;
	cout << "Please enter a input file name (Zip for class text file.): ";
	cin >> inFileName;
	inFileName += ".txt";
	inputF.open(inFileName.c_str());
	if (!inputF)
	{
		cout << "Error file was not found." << endl;
	}
	else
	{
		cout << "File successfully opened and read." << endl;
		outputFile(outputF);
	}


}

void outputFile(ofstream & outputF)
{
	string outFileName;

	cout << endl << "Please enter an output file name (other than ZipOutput): ";
	cin >> outFileName;
	outFileName += ".txt";
	outputF.open(outFileName.c_str());
	if (!outputF)
	{
		cout << "Error file was not found." << endl;
	}
	else
	{
		cout << "File successfully opened." << endl;
	}
}

void insertFile(sequenceSet & s, sequenceSet * s1)
{
	record r;
	int zip;
	string city;
	cout << "Please enter a zip code \n";
	cin >> zip;
	cout << "Please enter a city name \n";
	cin >> city;
	r.zipCode = zip;
	r.data = city;
	s.insertion(r, s1);
	cout<<"Record successfully added \n";

	}

	void deleteFile()
	{

	}

	void printInformation()
	{

	}





	/*


	cin >> filename;
	infile1.open(filename);
	while (infile1.fail())
	{
	cout << "Entered file is invalid" << endl;
	cout << "Enter the input file name: ";
	cin >> filename;
	infile1.open(filename);
	}
	cout << "Enter the name of the index set file: ";
	cin >> outputfile;
	infile2.open(outputfile);
	if (infile2.fail())	// checking if our index set exist
	{
	infile2.close();
	outfile.open(outputfile);
	index_set_flag = true;	//we need to write index set to the output
	}
	int count_data;	//counter variable to count the number of data skipped while building sequence set
	if (index_set_flag)
	{
	//building new sequence set or index set
	getline(infile1, record);
	outfile << "int";
	while (!infile1.eof())
	{
	getline(infile1, record);
	//cout<<record<<endl;
	for (int i = 0; i<5; i++) { key[i] = record[i]; }
	cout << key;
	outfile << "|" << key << count;
	count_data = 1;
	for (int j = 0; j<4; j++)
	{
	getline(infile1, record);
	if (!infile1.eof())
	count_data++;
	else
	break;
	}
	if (!infile1.eof())
	count++;
	}
	outfile << "|" << endl;
	outfile.close();
	infile2.open(outputfile);
	}
	long i, n;
	bool j;
	long t;
	char ch;
	infile2.get(ch);     //to get int from the input file
	infile2.get(ch);		//gets '|' and ignores it.
	while (!infile2.eof())		//Reads until the end of file.
	{
	infile2.get(ch);
	while (ch != '|')		//Unless '|' is found
	{
	infile2.get(ch);
	}
	infile2 >> t;	//Gets any integer from the file.
	cout << t << endl;
	cout << "Inserting the value " << t << endl;
	s.Insertion(t);
	}
	while (option != 4)
	{
	cout << "Please choose your options" << endl;

	cout << "1 to open and readfile \n";
	cout << "2 to print information\n";
	cout << "3 to insert a record\n";
	cout << "4 to delete a record\n";
	cout << "5  to exit\n"; << endl;
	cin >> option;
	switch (option)
	{

	case'1';
	cout << "Enter a filename to open and read \n';
	infile1.open(filename)

	case'2'
	cout << "Enter a filename with new records \n";
	cin >> newrecord;
	//cin >> t;	// it takes long values

	newrecord_file.open(newrecord);//reading from the new record file actually opening the new record file to read from it
	//infile1.close();
	//infile1.open(filename); //was trying to open the previous record file to write on it
	while (!newrecord.eof())
	{
	getline(newrecord, record);

	infile1 << record;	//updating our record file

	for (int i = 0; i<5; i++) { key[i] = record[i]; }
	if (count_data == 5)
	{
	count++;
	t = atol(key);
	t = t * 1000 + count;
	b.Insert(t);
	}
	else
	count_data++;
	}
	break;
	case'3': delete
	printf("enter the value to be deleted");
	cin >> t;
	b.Delete(t);

	break;

	//case'4': Exitbreak;
	case'4': printf("Exit"); return 0; break;
	default: break;

	}

	}


	return 0;
	} */

	/**
	\fn void insertNewElement(record r, sequenceSet* s)
	\details Inserts a new element.
	\return No return value
	\pre record and sequenceSet pointer are passed.
	\post value is inserted.
	*/
	/*
	void insertNewElement(record r, sequenceSet* s)
	{
	s->insertion(r);
	}



	\fn int findIndex(vector<int> & keyList, int key)
	\details Finds the index of the search key.
	\return returns the index
	\pre vector is passed by reference, key is passed.
	\post index is returned

	int findIndex(vector<int> & keyList, int key)
	{
	int i = 0;
	while (keyList[i] < key && i <= keyList.size())
	{
	i++;
	}
	return i - 1;
	}


	\fn void readInSSet(sequenceSet* s)
	\details Takes care of the input of the sequenceSet.
	\return No return value.
	\pre sequenceSet is passed.
	\post sequenceSet is altered with values.

	void readInSSet(sequenceSet* s)
	{

	}*/
