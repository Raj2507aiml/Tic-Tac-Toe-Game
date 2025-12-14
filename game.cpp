#include <iostream>
using namespace std;

char board[9] = { '1','2','3','4','5','6','7','8','9' };
char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
bool checkWin() {
    int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[winPatterns[i][0]] == currentPlayer &&
            board[winPatterns[i][1]] == currentPlayer &&
            board[winPatterns[i][2]] == currentPlayer)
            return true;
    }
    return false;
}

// Function to check draw
bool checkDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O')
            return false;
    }
    return true;
}

int main() {
    int choice;

    cout << "===== TIC TAC TOE GAME =====\n";

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter position (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9 ||
            board[choice - 1] == 'X' ||
            board[choice - 1] == 'O') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[choice - 1] = currentPlayer;

        if (checkWin()) {
            displayBoard();
            cout << "🎉 Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "🤝 Game Draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}

