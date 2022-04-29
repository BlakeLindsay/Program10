/*
Program Name: Average of Numbers
Programmer: Blake Lindsay
Course: CSC119144 Introduction to Programming  C++ Spring 2022
Submission Date: 4/28/2022
This program will read all of the numbers stored in the "numbers.txt" file, and then calculate and display their average.
*/

// include directive - importing input/output library
#include <iostream>
#include <fstream> // for input from or output to a file

// use standard namespace
using namespace std;

//declare the used functions
bool testFile (ifstream &file);
float average(ifstream &file);
void display(float num);

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
		//pass the dataFile to the average function, and pass its returned value to the display function
		display(average(dataFile));
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

//This function takes the reference of a file and then reads the integers on each line while counting the total of the integers, counting the total number of the integers, and displaying each integer. Afterwards, it returns the average of the integers.
float average(ifstream &file)
{
	int total = 0;
	int num;
	int count = 0;
	while (file >> num)
	{
		total += num;
		count++;
		cout << num << endl;
	}
	float average = total / count;
	return average;
}

//This function takes a single float and displays to the user that it is the average.
void display(float num)
{
	cout << "\nThe average is: " << num << endl;
}
