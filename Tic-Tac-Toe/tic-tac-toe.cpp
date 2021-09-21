#include <iostream>

void player1Turn();
void player2Turn();

void tableBuild();
void newTable();

void gameEnd();
void gameRepeat();
void clearcin();

/*Used to get the information for where player's 'X' or '0' should be placed in the table*/
char placement;

/*When 'player1 = true', it lets player 1 place it's 'X'. When 'player2 = true', it lets
player 2 place it's '0'*/
bool player1 = true;
bool player2 = true;

/*Used in checking if placement is valid or not. If 'check = true', it will continue the game
as normal and let the next player choose a spot to place it's 'X' or '0'.
If 'check = false', it will tell the user it is an invalid input and let's them try again.*/
bool check = false;

const int row = 3;
const int col = 3;
char table[row][col] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

int main() {
	std::cout << "******** Welcome to Tic-Tac-Toe! ********" << std::endl;
	tableBuild();

	while (true) {
		while (true) {
			player1Turn();
			//Breaks out of the loop if player 1 won
			if (player2 == false) {
				//Makes sure player 1 starts first after a restarted match
				player1 = true;
				break;
			}

			player2Turn();
			//Breaks out of the loop if player 2 won
			if (player1 == false) {
				//Makes sure player 1 starts first after a restarted match
				player1 = true;
				break;
			}
		}

		//Resets the layout after a win or a draw
		std::cout << "******** Welcome to Tic-Tac-Toe! ********" << std::endl;
		newTable();
	}

	return 0;
}

void player1Turn() {
	while (player1 == true) {
		//Resets the 'check' bool to it's default value
		check = false;

		//Asks where player 1 would like to place it's 'X'
		std::cout << "Player 1's turn: ";
		std::cin >> placement;
		clearcin();

		/*Takes player 1's "placement" value and changes it's corresponding "table" value
		to an 'X'*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (placement == table[i][j]) {
					table[i][j] = 'X';
					check = true;
				}
			}
		}

		//Does not allow you to place on 'X' or '0'
		if (placement == 'X' || placement == '0') {
			check = false;
		}

		//If it's a valid placement, it becomes player 2's turn
		if (check == true) {
			system("cls");
			tableBuild();
			player2 = true;
			player1 = false;
		}
		/*If it's an invalid placement, it gets player 2 to try again by changing 'player1'
		to 'true' and 'player2' to 'false'*/
		else if (check == false) {
			system("cls");
			tableBuild();
			player2 = false;
			player1 = true;
			std::cout << "Invalid input. Try again." << std::endl << std::endl;
		}

		gameEnd();
	}

	return;
}

void player2Turn() {
	while (player2 == true) {
		//Resets the "check" bool to it's default value
		check = false;

		//Asks where player 2 would like to place it's '0'
		std::cout << "Player 2's turn: ";
		std::cin >> placement;
		clearcin();

		/*Takes player 2's "placement" value and changes it's corresponding "table" value
		to an '0'*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (placement == table[i][j]) {
					table[i][j] = '0';
					check = true;
				}
			}
		}

		//Does not allow you to place on 'X' or '0'
		if (placement == 'X' || placement == '0') {
			check = false;
		}

		//If it's a valid placement, it becomes player 1's turn
		if (check == true) {
			system("cls");
			tableBuild();
			player2 = false;
			player1 = true;
		}
		/*If it's an invalid placement, it gets player 2 to try again by changing "player2"
		to "true" and "player1" to "false"*/
		else if (check == false) {
			system("cls");
			tableBuild();
			player2 = true;
			player1 = false;
			std::cout << "Invalid input. Try again." << std::endl << std::endl;
		}

		gameEnd();
	}

	return;
}

//Builds the Tic-Tac-Toe table using a for-loop and a nested-for-loop
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

/*When the game has ended, it will manually change all the values of the table to '1', '2',
'3', and so on. Then print the new table*/
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

/*Checks if any of the players has gotten the same values 3 in a row (either 
horizontally, vertically or diagonally). If it has it will say that that player has won the
game, and then ends the game. (See last 'else if' statement for how I calculate if the game
has come to a draw)*/
void gameEnd() {
	if (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == 'X') {
		std::cout << "Gongrats Player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}
	else if (table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == 'X') {
		std::cout << "Gongrats Player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}
	else if (table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == 'X') {
		std::cout << "Gongrats Player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}
	else if (table[0][0] == 'X' && table[1][0] == 'X' && table[2][0] == 'X') {
		std::cout << "Gongrats Player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}
	else if (table[0][1] == 'X' && table[1][1] == 'X' && table[2][1] == 'X') {
		std::cout << "Gongrats Player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}
	else if (table[0][2] == 'X' && table[1][2] == 'X' && table[2][2] == 'X') {
		std::cout << "Gongrats Player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}
	else if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X') {
		std::cout << "Gongrats Player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}
	else if (table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == 'X') {
		std::cout << "Gongrats Player 1 won the game!" << std::endl;
		player2 = false;
		gameRepeat();
	}

	else if (table[0][0] == '0' && table[0][1] == '0' && table[0][2] == '0') {
		std::cout << "Gongrats Player 2 won the game!" << std::endl;
		player1 = false;
		gameRepeat();
	}
	else if (table[1][0] == '0' && table[1][1] == '0' && table[1][2] == '0') {
		std::cout << "Gongrats Player 2 won the game!" << std::endl;
		player1 = false;
		gameRepeat();
	}
	else if (table[2][0] == '0' && table[2][1] == '0' && table[2][2] == '0') {
		std::cout << "Gongrats Player 2 won the game!" << std::endl;
		player1 = false;
		gameRepeat();
	}
	else if (table[0][0] == '0' && table[1][0] == '0' && table[2][0] == '0') {
		std::cout << "Gongrats Player 2 won the game!" << std::endl;
		player1 = false;
		gameRepeat();
	}
	else if (table[0][1] == '0' && table[1][1] == '0' && table[2][1] == '0') {
		std::cout << "Gongrats Player 2 won the game!" << std::endl;
		player1 = false;
		gameRepeat();
	}
	else if (table[0][2] == '0' && table[1][2] == '0' && table[2][2] == '0') {
		std::cout << "Gongrats Player 2 won the game!" << std::endl;
		player1 = false;
		gameRepeat();
	}
	else if (table[0][0] == '0' && table[1][1] == '0' && table[2][2] == '0') {
		std::cout << "Gongrats Player 2 won the game!" << std::endl;
		player1 = false;
		gameRepeat();
	}
	else if (table[0][2] == '0' && table[1][1] == '0' && table[2][0] == '0') {
		std::cout << "Gongrats Player 2 won the game!" << std::endl;
		player1 = false;
		gameRepeat();
	}
	/*Checks if all the values on the table has changed, and if it has it says that the game
	has come to a draw*/
	else if (table[0][0] != '1' && table[0][1] != '2' && table[0][2] != '3' &&
		table[1][0] != '4' && table[1][1] != '5' && table[1][2] != '6' &&
		table[2][0] != '7' && table[2][1] != '8' && table[2][2] != '9') {
		std::cout << "Game has come to a draw." << std::endl;
		/*Since player 1 will always be the last one to finish if the game will be a draw,
		am I using the same method to restart the game as if player 1 won (see description
		for 'if (player2 == false)' in 'main')*/
		player2 = false;
		gameRepeat();
	}

	return;
}

/*Asks if players want to start a new game. This is in an infinite-while-loop in case user
presses an invalid input*/
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
			system("cls");
			std::cout << "Please enter a valid input (y/n). Try again.";
			std::cout << std::endl;
			continue;
		}
	}

	return;
}

//Clears the cin-buffer
void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}