//Serena Allison
//C# Programming
//Assignment:Skynet
//10/14/2018

//Guess My Location
//Guessing Location of the Enemy with the use of the Skynet

#include "pch.h"
#include <iostream>
#include <cstdlib>		//helps generate numbers
#include <ctime>		//helps generate the random number generator with current time
#include <string>
bool searchGridHighNumber;
bool searchGridLowNumber;
using namespace std;

int sub_main()
{
	srand(static_cast<unsigned int>(time(0)));	//seed random number generator
	int targetLocationPrediction = (( searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
	int secretNumber = rand() % 64 + 1;		//random number between 1-64
	int tries = 0;
	int guess;

	cout << "\Generate Random enemy location on 8x8 grid...\n\n";
	cout << "\Skynet HK-Aerial Initializing software......\n\n";
	do
	{
		cout << "Enter low Grid Number\n\n";
		cin >> guess;
		++tries;		//player gets tries to guess

		if (guess > searchGridHighNumber)
		{
			cout << "\The Target locatin prediction of" << guess << "was higher than the actual enemy location of 56.\n\n";
		}
		else if (guess < searchGridLowNumber)
		{
			cout << "\The Target location prediction of" << guess << "was lower than the actual enemy location of" << targetLocationPrediction << ".\n\n";
		}
		else
		{
			cout << "\You hit the enemy! In " << tries << " guesses!\n\n";
		}
	} while (guess != secretNumber);
	return 0;
}