#include <iostream>

void game();

void player1Turn();
void player2Turn();
void tableBuild();
void gameEnd();
void gameRepeat();
void newTable();
void clearcin();

char placement;

bool player1 = true;
bool player2 = true;
bool repeat = false;

const int row = 3;
const int col = 3;
char table[row][col] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

int main() {
	std::cout << "******** Welcome to Tic-Tac-Toe! ********" << std::endl;
	tableBuild();
	repeat = true;

	while (repeat == true) {
		player1Turn();

		if (player2 == false) {
			repeat = false;
		}
		player2Turn();

		if (repeat == false) {
			std::cout << "******** Welcome to Tic-Tac-Toe! ********" << std::endl;
			newTable();
			repeat = true;
		}
	}

	return 0;
}

/*void game() {
	while (true) {
		while (player1 == true) {
			//Asks where player 1 would like to place it's 'X'
			std::cout << "Player 1's turn: ";
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

			player2 = true;
			player1 = false;
			gameEnd();
		}

		while (player2 == true) {
			//Asks where player 2 would like to place it's '0'
			std::cout << "Player 2's turn: ";
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

			player2 = false;
			player1 = true;
		}
	}

	return;
}*/

void player1Turn() {
	while (player1 == true) {
		//Asks where player 1 would like to place it's 'X'
		std::cout << "Player 1's turn: ";
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

		player2 = true;
		player1 = false;
		gameEnd();
	}

	return;
}

void player2Turn() {
	while (player2 == true) {
		//Asks where player 2 would like to place it's '0'
		std::cout << "Player 2's turn: ";
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

		player2 = false;
		player1 = true;
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

//Checks if any of the players got 3 in a row
void gameEnd() {
	if (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == 'X') {
		std::cout << "Gongrats player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}
	else if (table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == 'X') {
		std::cout << "Gongrats player 1 won the game!" << std::endl;
		gameRepeat();
	}

	return;
}

//Asks if player want to start a new game
void gameRepeat() {
	while (true) {
		std::cout << "Would you like to start a new game? (y/n): ";
		char answer;
		std::cin >> answer;
		clearcin();
		answer = tolower(answer);

		if (answer == 'y') {
			system("cls");
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

	return;
}

//Resets the table after a win or draw
void newTable() {
	table[0][0] = '1';
	table[0][1] = '2';
	table[0][2] = '3';

	table[1][0] = '4';
	table[1][1] = '5';
	table[1][2] = '6';

	table[2][0] = '7';
	table[2][1] = '8';
	table[2][2] = '9';

	std::cout << std::endl << "---------------" << std::endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << "| " << table[i][j] << " |";
		}
		std::cout << std::endl << "---------------" << std::endl;
	}

	return;
}

//Clears the cin-buffer
void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}