#include<random>
#include <iostream>

int choice, attempts = 0;
enum Difficulty
{
	EASY = 1,
	MEDIUM = 2,
	HARD = 3
};

int genRandomNum() {
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> distr(1, 100); 
	int rand = distr(gen); 
	return rand;
}


void gameStart() {
	int randNum = genRandomNum();
	std::cout << "Can you guess the number?!!? 0 - 100\n";

	int numGuessed;

	while (std::cin >> numGuessed) {

		if (numGuessed == randNum) {
			std::cout << "YOU WIN!!! YOU GUESSED IT IN " << attempts << " ATTEMPTS!!!\n";
			break;
		}
		else {
			attempts -= 1;
			std::cout << "That's not it...\n";

			if (numGuessed > randNum) {
				std::cout << "The number is smaller than that...\n";
			}
			else {
				std::cout << "The number is bigger than that...\n";
			}
			std::cout << "You have " << attempts << " left...\n";

			if (attempts == 0) {
				std::cout << "Game over...\n";
				break;
			}
		}
	}
}


void intro() {
	std::cout << "Welcome to the Number Guessing Game!\n";
	std::cout << "Please select game difficulty: \n1.Easy\n2.Medium\n3.Hard" << std::endl;

	std::cin >> choice;

	switch (choice) {
	case 1:
		attempts = 10;
		std::cout << "You have " << attempts << " attempts\n";
		gameStart();
		break;
	case 2:
		attempts = 5;
		std::cout << "You have " << attempts << " attempts\n";
		gameStart();
		break;
	case 3:
		attempts = 3;
		std::cout << "You have " << attempts << " attempts\n";
		gameStart();
		break;
	}
}

int main() {
	intro();
	return 0;
}

//trying to figure out GitHub;