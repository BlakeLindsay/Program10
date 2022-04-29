/*
Program Name: Golf Scores B
Programmer: Blake Lindsay
Course: CSC119144 Introduction to Programming  C++ Spring 2022
Submission Date: 4/28/2022
This program will read the records in the "golf.txt" file and then display them.
*/

// include directive - importing input/output library
#include <iostream>
#include <fstream> // for input from or output to a file

// use standard namespace
using namespace std;

//declare the used functions
bool testFile (ifstream &file);
void read(ifstream &file);

//main function - Entry point
int main()
{
	//declare the input file variable
	ifstream dataFile;
	//set the opened file of dataFile to "golf.txt"
	dataFile.open("golf.txt");
	//pass the dataFile to the testFile function to determine if the file opened successfully
	if (testFile(dataFile))
	{
		//pass the dataFile reference to the read function
		read(dataFile);
	} else
	{
		//display to the user that the file did not open correctly and then exit the program
		cout << "Error opening file." << endl;
		exit(1);
	}
	//close the file
	dataFile.close();
    return 0;
} // main ends

//This function takes the reference of a file and tests if it opened correctly. If it did open correctly, it will return true. Otherwise, it will return false.
bool testFile (ifstream &file)
{
	if (file.fail())
	{
		return false;
	} else
	{
		return true;
	}
}

//This function takes the reference for the used file, and then displays each line in the file to the user.
void read(ifstream &file)
{
	string record;
	while (!file.eof())
	{
		getline(file, record);
		cout << record << endl;
	}
}
