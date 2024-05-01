#include <iostream>
#include <limits>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
bool tie = false;
char token = 'X';
string player1;
string player2;

 void Game1();
 void Game2();
 bool Game3();
 bool Game4();


int main(){
    cout << "Enter the Name of the First player : \n";
    getline(cin, player1);
    cout << "Enter the Name of the Second player : \n";
    getline(cin, player2);
    cout << player1 << " is going to Start the Game.\n";

    while (!Game3() && !Game4()) {
        Game1();
        Game2();
    }

    // Print result
    // Check for draw first
    if (Game4()) {
        cout << "It's a DRAW !\n";
    } else {
        // Check the token to determine the winner
        if (token == 'O') {
            cout << player1 << " wins!\n";
        } else if (token == 'X') {
            cout << player2 << " wins!\n";
        }
    }

    return 0;
}

void Game1() {
    cout << "        ________________________\n";
    cout << "       |        |       |       |\n";
    cout << "       |    " << space[0][0] << "   |" << "   " << space[0][1] << "   |   " << space[0][2] << "   |\n";
    cout << "       |________|_______|_______|\n";
    cout << "       |        |       |       |\n";
    cout << "       |    " << space[1][0] << "   |" << "   " << space[1][1] << "   |   " << space[1][2] << "   |\n";
    cout << "       |________|_______|_______|\n";
    cout << "       |        |       |       |\n";
    cout << "       |    " << space[2][0] << "   |" << "   " << space[2][1] << "   |   " << space[2][2] << "   |\n";
    cout << "       |________|_______|_______|\n";
}

void Game2() {
    int digit;

    while (true) {
        cout << "Please enter a number (1-9): ";
        cin >> digit;

        // Convert digit to row and column
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        // Check if the cell is within the valid range and empty
        if (digit >= 1 && digit <= 9 && space[row][column] != 'X' && space[row][column] != 'O') {
            space[row][column] = token;

            // Toggle token
            token = (token == 'X') ? 'O' : 'X';
            break; // Exit the loop as a valid move is made
        } else {
            cout << "Invalid move! Please enter a valid number.\n";
            // Clear the input stream to prevent infinite loop
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}



bool Game3() {
    // Check rows and columns for a win
    for (int i = 0; i < 3; ++i) {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true; // If a player wins, return true
        }
    }

    // Check diagonals for a win
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true; // If a player wins, return true
    }
    return false;
}
    
bool Game4(){
    // Check for a draw
    bool draw = true; // Initially assume it's a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                draw = false; // If there's an empty cell, it's not a draw
                break;
            }
        }
    }
    return draw;
}