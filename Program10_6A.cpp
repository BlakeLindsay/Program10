/*
Program Name: Golf Scores A
Programmer: Blake Lindsay
Course: CSC119144 Introduction to Programming  C++ Spring 2022
Submission Date: 4/28/2022
This program will continuously prompt the user to enter the names and scores of players, and then append that data to the "golf.txt" file.
*/

// include directive - importing input/output library
#include <iostream>
#include <fstream> // for input from or output to a file

// use standard namespace
using namespace std;

//declare the used functions
bool testFile (ofstream &file);
string enterName();
int enterScore();
void displayAndAppend(int score, string name, ofstream &file);

//main function - Entry point
int main()
{
	//declare the variable used to determine if the program will end
	string cont;
	//declare the output file variable
	ofstream dataFile;
	//set the opened file of dataFile to "golf.txt" in append mode
	dataFile.open("golf.txt", ios::app);
	//pass the dataFile to the testFile function to determine if the file opened successfully
	if (!testFile(dataFile))
	{
		//display to the user that the file did not open correctly and then exit the program
		cout << "Error opening file." << endl;
		exit(1);
	}
	//This do while loop will continuously repeat as long as the user inputs y at the end of the loop.
	do
	{
		//call the enterScore and enterName functions and pass their returned values along with the reference to the dataFile to the displayAndAppend function
		displayAndAppend(enterScore(), enterName(), dataFile);
		//prompt the user to enter y to continue appending player's scores
		cout << "Enter y to append more player's scores: ";
		cin >> cont;
	} while (cont == "y");
	//close the file
	dataFile.close();
    return 0;
} // main ends

//This function takes the reference of a file and tests if it opened correctly. If it did open correctly, it will return true. Otherwise, it will return false.
bool testFile (ofstream &file)
{
	if (file.fail())
	{
		return false;
	} else
	{
		return true;
	}
}

//This function prompts the user to enter a player's name and then returns the user's input as a string value.
string enterName()
{
	string name;
	cout << "Enter player's name: ";
	cin >> name;
	return name;
}

//This function prompts the user to enter a player's score and then returns the user's input as a int value.
int enterScore()
{
	int score;
	cout << "Enter player's score: ";
	cin >> score;
	return score;
}

//This function takes the value of the player's score as an int, the value of the player's name as a string, and the reference to the used file. It then appends the player's name and score to the used file, and then displays that to the user.
void displayAndAppend(int score, string name, ofstream &file)
{
	file << endl << name << "      " << score;
	cout << "The player " << name << "'s score of " << score << " was appended to the file." << endl;
}
