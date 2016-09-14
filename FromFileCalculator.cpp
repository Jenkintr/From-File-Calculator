//Taylor Jenkins
//03-16-16

/*This program that opens the file "Random.txt", 
reads all the numbers from the file, and calculates the following: 
A)  The number of numbers in the file 
B)  The sum of all the numbers in the file
C)  The average of all the numbers in the file 
The program displays the number of numbers found in the file, the sum of the 
numbers, and the average of the numbers. The program then ouputs the information to 
a txt file named "RandomOutput.txt".*/

#include <fstream>
#include <iostream>
using namespace std;

int main()
{ // start of int main

	//Variables
	int aNumber = 0; // stores a number that is read
	int numbers = 0; // stores the number of numbers
	double sum = 0.0; // stores the total of the sum of numbers
	double average = 0.0; // stores the average of the numbers

	cout << "Getting file information." << endl;

	ifstream randomNumbersInput; // defines input file stream as randomNumbersInput
	randomNumbersInput.open("Random.txt"); // opens input file stream with file "Random.txt"

	if (randomNumbersInput.fail()) //"Random.txt cannot be opened, display "failed to read file.
		cout << "Failed to read file." << endl;
	else // If Random.txt can be opened, complete the following statements:
	{
		while (randomNumbersInput >> aNumber) // reads numbers into a number
		{
			numbers++; //increment the number of numbers
			sum += aNumber;// and add the number being read to the total of the sum of numbers
		}
		if (numbers > 0) //if the number of numbers is greater than 0:
			average = sum / numbers; //calculate the average and store value into the average of numbers variable.
		else // if the number of numbers is less than 0:
			average = 0.0; //average remains 0.0

		cout << "Number of numbers: " << numbers << "\n"; //displays the number of numbers
		cout << "Sum of numbers: " << sum << "\n"; // displays the sum of numbers
		cout << "Average of numbers: " << average << "\n"; // displays the average of numbers
	}

	randomNumbersInput.close(); // close the input file

	ofstream randomNumbersOutput; // defines output file stream as randomNumbersOutput
	randomNumbersOutput.open("RandomOutput.txt"); // opens output file stream with file "RandomOutput.txt"

	//Write data to output file
	randomNumbersOutput << "Number of numbers: " << numbers << endl; 
	randomNumbersOutput << "Sum of numbers: " << sum << endl;
	randomNumbersOutput << "Average of numbers: " << average << endl;
	
	randomNumbersOutput.close(); // close the output file
	return 0;
} //End of int main
