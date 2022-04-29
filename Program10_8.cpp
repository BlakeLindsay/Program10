/*
Program Name: Sales Report
Programmer: Blake Lindsay
Course: CSC119144 Introduction to Programming  C++ Spring 2022
Submission Date: 4/28/2022
This program will read the records in the "brewster.txt" file and then display them in a particular format.
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
	//set the opened file of dataFile to "brewster.txt"
	dataFile.open("brewster.txt");
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

void read(ifstream &file)
{
	//display the header
	cout << "Brewster's Used Cars, Inc." << endl;
	cout << "Sales Report" << endl;
	cout << "Salesperson ID\tSale Amount" << endl;
	cout << "============================" << endl;
	//declare the variable to hold the value of the ID
	int iD;
	//declare the variable to hold the value of the previous ID
	int iDPrevious;
	//declare the variable to hold the value of the sale amount
	float amount;
	//declare the variable to hold the total sales amount of a salesperson
	float total;
	//declare the variable to hold the total sales amount of all salespersons
	float totalAll;
	//prepare the loop by storing the first value in the file to the iD variable
	file >> iD;
	//This while loop will run as long as the end of the file has not been reached.
	while (!file.eof())
	{
		//set the iDPrevious variable to the value of iD
		iDPrevious = iD;
		//This do while loop will run as long as the file inputs a valid value to iD, and iD is equal to iDPrevious
		do
		{
			//store the next value in the file in amount
			file >> amount;
			//display the value of iD and amount separated by a tab
			cout << iD << "\t$" << amount << endl;
			//add the value of amount to total
			total += amount;
		} while (file >> iD && iD == iDPrevious);
		//display the value of total as the total sales for this salesperson
		cout << "Total sales for this salesperson: $" << total << endl;
		//add the value of the total to totalAll
		totalAll += total;
		//reset total to 0
		total = 0;
	}
	//display the value of totalAll as the total of all sales
	cout << "Total of all sales: $" << totalAll << endl;
}
