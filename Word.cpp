// Word.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Serena Allison
// 10-19/2018

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
//Welcome the player
{
    std::cout << "Hello World!\n";
	cout << "Welcome to the Code Breaking Simulator Program!\n\n";
	cout << "Unscramble the words that the CIA is training other code breakers to learn...\n\n";
	cout << "Here are the rules...\n\n";
	cout << "Enter 'hint' for a hint.\n\n";
	cout << "Enter 'quit' to quit the program.\n\n";

	//information needed for the words that the player will see and guess from
	enum fields { WORD, HINT, NUM_FIELDS };		//values that have their own value data type
	const int NUM_WORDS = 10;					// telling that the constant intager that the number of words is equal to 10
	const string WORDS[NUM_WORDS][NUM_FIELDS] =		//constant string of words that are in a array of words and number of fields
	{
		{"door", "You open and close, either entering or leaving"},		//all the words but the meaning is what will be shown, the words is the answer
		{"you will get burned", "fire"},
		{"fan", "To cool you off when it's hot out"},
		{"trash", "You throw your garbage in"},
		{"bookshelf", "Holds books and stuff"},
		{"cat", "Furry feline household family member"},
		{"lamp", "Turn this on to brighten your room"},
		{"chair", "Something you sit on"},
		{"water", "This keeps you hydrated, make sure you drink a lot!"},
		{"bed", "You sleep on this after a long day at work, or you just feel like being lazy"},
	};
	//Jumnle the word
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];	// tring to guess the word
	string theHint = WORDS[choice][HINT];	// hint of the word that your trying to guess
	string jumble = theWord;		//jumbled up version of the word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);			//this is telling us that the random 2 constants of a letter is being switched 
		int index2 = (rand() % length);			//and the outcome of the word for example if i wanted cat it would be "act"
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	//Loop for when the player is guessing and if they fail or guess right
		cout << "The Jumble is: " << jumble;
		string guess;
		cout << "\n\n Your guess: ";
		cin >> guess;
		
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that is not the correct word.";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "That's it!\n\n";
	}

	cout << "\nYour training is complete!\n";
	//end the function
	return 0;
}

