#include <iostream>

void game();
void tableBuild();
void gameEnd();
void gameRepeat();
void clearcin();

char placement;

const int row = 3;
const int col = 3;
char table[row][col] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

int main() {
	std::cout << "******** Welcome to Tic-Tac-Toe! ********" << std::endl;

	while (true) {
		tableBuild();
		game();
	}

	return 0;
}

//Asks each player where they want to place their 'X' and '0'
void game() {
	while (true) {
		//Asks where player 1 would like to place it's 'X'
		std::cout << "Player one's turn: ";
		std::cin >> placement;
		clearcin();

		//Takes player 1's "placement" value and changes it's corresponding "table" value to an 'X'
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (placement == table[i][j]) {
					table[i][j] = 'X';
					tableBuild();
				}
			}
		}

		gameEnd();

		//Asks where player 2 would like to place it's '0'
		std::cout << "Player two's turn: ";
		std::cin >> placement;
		clearcin();

		//Takes player 2's "placement" value and changes it's corresponding "table" value to an '0'
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (placement == table[i][j]) {
					table[i][j] = '0';
					tableBuild();
				}
			}
		}
	}

	return;
}

//Builds the array table
void tableBuild() {
	//Prints the overhead line above the rest of the table
	std::cout << std::endl << "---------------" << std::endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << "| " << table[i][j] << " |";
		}
		std::cout << std::endl << "---------------" << std::endl;
	}

	return;
}

void gameEnd() {
	if (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == 'X') {
		std::cout << "Gongrats player 1 won the game!" << std::endl;
		gameRepeat();
	}
	else if (table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == 'X') {
		std::cout << "Gongrats player 1 won the game!" << std::endl;
		gameRepeat();
	}
}

void gameRepeat() {
	while (true) {
		std::cout << "Would like to start a new game? (y/n): ";
		char answer;
		std::cin >> answer;
		clearcin();
		answer = tolower(answer);

		if (answer == 'y') {
			break;
		}
		else if (answer == 'n') {
			exit(0);
		}
		else {
			std::cout << "Please enter a valid input (y/n). Try again.";
			continue;
		}
	}
}

//Clears the cin-buffer
void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}