/*
Program Name: Sum of Numbers
Programmer: Blake Lindsay
Course: CSC119144 Introduction to Programming  C++ Spring 2022
Submission Date: 4/28/2022
This program will read all of the numbers stored in the "numbers.txt" file, and then calculate and display their total.
*/

// include directive - importing input/output library
#include <iostream>
#include <fstream> // for input from or output to a file

// use standard namespace
using namespace std;

//declare the used functions
bool testFile (ifstream &file);
int total(ifstream &file);
void display(int num);

//main function - Entry point
int main()
{
	//declare the input file variable
	ifstream dataFile;
	//set the opened file of dataFile to "numbers.txt"
	dataFile.open("numbers.txt");
	//pass the dataFile to the testFile function to determine if the file opened successfully
	if (testFile(dataFile))
	{
		//pass the dataFile to the total function, and pass its returned value to the display function
		display(total(dataFile));
	} else
	{
		//display to the user that the file did not open correctly and exit the program
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

//This function takes the reference of a file and then reads the integers on each line while counting the total of the integers and displaying each integer. Afterwards, it returns the total of the integers.
int total(ifstream &file)
{
	int total = 0;
	int num;
	while (file >> num)
	{
		total += num;
		cout << num << endl;
	}
	return total;
}

//This function takes a single integer and displays to the user that it is the total.
void display(int num)
{
	cout << "\nThe total is: " << num << endl;
}
