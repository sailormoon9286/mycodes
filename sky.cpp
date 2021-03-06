// sky.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


int main()
{
	std::cout << "Hello World!\n";
	//seed random number generator
	srand(static_cast<unsigned int>(time(0)));
	int searchGridHighNumber = 59;
	int searchGridLowNumber = 1; 
	//binary search algorithm 
	int targetLocationPrediction = 0;
	int enemyLocation = rand() % 59 + 1;
	int attempt = 0;
	//state if enemy is found
	//Will change this to true when found
	bool isEnemyFound = false;
	bool playagain = true;

	//intro for user
	cout << "Time to get the enemy while we still can!!\n\n";
	cout << "Now lets get started! The cordinates give us that they are in grid location 59...\n\n";
	//start each turn unil enemy is found
	do
	{
		//tell the user but not the AI the enemy location for information only!
		cout << "\nThe enemy is hiding at location #" << enemyLocation << endl;
		//AI binary guess
		targetLocationPrediction = (searchGridHighNumber - searchGridLowNumber) / 2 + searchGridLowNumber;
		cout << "Binary AI Drone predicts enemy is at location #" << targetLocationPrediction << endl;
		//here we count the attempt to find enemy location and also display
		//++attempt is the same as saying
		//attempt = attempt + 1
		cout << "Skynet HK-Aerial attempt number" << ++attempt << "attempts." << endl;
		// AI Linear
		targetLocationPrediction = (searchGridHighNumber - searchGridLowNumber) / 2 + searchGridLowNumber;
		cout << "Linear AI Drone predicts enemy is at location #" << targetLocationPrediction << endl;
		//here we count the attempt to find enemy location and also display
		//++attempt is the same as saying
		//attempt = attempt + 1
		//random AI
		targetLocationPrediction = (searchGridHighNumber - searchGridLowNumber) / 2 + searchGridLowNumber;
		cout << "Random AI Drone predicts enemy is at location #" << targetLocationPrediction << endl;
		//here we count the attempt to find enemy location and also display
		//++attempt is the same as saying
		//attempt = attempt + 1
		//here we check for results for AI guess
		//if the guess aka targetlocationprediction too high do this
		if (targetLocationPrediction > enemyLocation)
		{
			cout << "Attempt is too high! The search range high number of" << targetLocationPrediction << "will now be changed to";
			//lets change the high number
			//we will be lower the high number
			searchGridHighNumber = targetLocationPrediction - 1;
			//here we show the user the new value and it displays the previous line
			cout << searchGridHighNumber << endl;
		}
		//if the guess is too low do this
		else if (targetLocationPrediction < enemyLocation)
		{
			cout << "Attempt is too low! The search range low number of" << targetLocationPrediction << "will now be changed to!";
			//lets change the low number
			//we will be increasing the low number
			searchGridLowNumber = targetLocationPrediction + 1;
			cout << searchGridLowNumber << endl;
		}
		else if(targetLocationPrediction == enemyLocation)
		{
			//found!change the flage to true
			isEnemyFound = true;
		}
	} while (attempt != enemyLocation);

	//dislplay stats to user when game over!
	cout << "Enemy Found by Drone! Boom! Boom! Boom!" << endl;
	cout << "Binary AI search took " << attempt << "tries to find enemy location";
	cout << "Linear AI search took " << attempt << "tries to find enemy location";
	//want to play again?
	char again;
	cout << "Would you like to play again? Enter y or n" << endl;
	cin >> again;

	if (again != 'y')
	{
		playagain = false;
		}
	system("pause"); //sure to close the window
		
	return 0;
}

