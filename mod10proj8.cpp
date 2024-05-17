/*Author: Francisco Bumanglag
Project: Rock Paper Scisscors
Assignment: Module 10 Project 8
Course: C++ Santa Ana College
Class: CMPR120 Dr. Tahir Aziz
Date: April 18, 2024*/


#include <iostream>  //for input and output operations
#include <cstdlib>  //for rand() and srand() functions 
#include <ctime>  //accessing system time to seed the random num generator
#include <string>  //for string operations

using namespace std;  //avoid prefixing standard lib types and functions

//enumeration for the threee possible choices 
enum Choice {
	Rock, Paper, Scissors
};

//generate random computer choice 
Choice getComputerChoice() {
	return static_cast<Choice> (rand() % 3);
}

//user input -- continously prompts user for a choice 
Choice getUserChoice() {
	string input; 
	while (true) {
		cout << "Enter 'Rock', 'Paper', or 'Scissors': ";
		cin >> input; 
		if (input == "Rock") return Rock; 
		if (input == "Paper") return Paper; 
		if (input == "Scissors") return Scissors; 
	}
}

//function maps Choice enum to padded string: rock, paper, scissors
string theChoice(Choice choice) {
	switch (choice) {
	case Rock: return "Rock.   "; 
	case Paper: return "Paper.  ";
	case Scissors: return "Scissors.  ";
	}
}

//function evaluates game outcome : tie, user win, or computer win
void theWinner(Choice userChoice, Choice computerChoice) {
	if (userChoice == computerChoice) {
		cout << "  Its a tie! \n";
	}else if ((userChoice == Rock && computerChoice == Scissors) ||
		(userChoice == Scissors && computerChoice == Paper) ||
			(userChoice == Paper && computerChoice == Rock)) {
		cout << "You win! \n";

	}
	else {
		cout << "Computer wins! \n";
	}
}

//main function initializes, loops game rounds, determines outcomes, repeats if tied
int main() {
	srand(static_cast<unsigned int> (time(nullptr))); //initailze random seed

	Choice userChoice, computerChoice; 
	bool validChoice; 

	do {
		validChoice = true; 

		userChoice = getUserChoice(); 
		computerChoice = getComputerChoice(); 
		cout << "Computer chose: " << theChoice(computerChoice) << "\n";

		if (userChoice != computerChoice)
		{
			theWinner(userChoice, computerChoice);

		}
		else {
			cout << "Its a tie!  Play again. \n";
			validChoice = false; 
		}
	} while (!validChoice); //repeat if its a tie 

	return 0; 
}

