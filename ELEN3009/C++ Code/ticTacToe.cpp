#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void playGame() {
        bool gameover = false;
        while (!gameover) {
            printBoard();
            gameover = takeTurn();
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void printBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "-----\n";
        }
    }

    bool takeTurn() {
        int row = 0;
        int col = 0;
        while (true) {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == ' ') {
                board[row-1][col-1] = currentPlayer;
                break;
            }
            std::cout << "Invalid move. Try again.\n";
        }
        return checkWin();
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
        }
        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;

        return false;
    }
};

int main() {
    TicTacToe game;
    game.playGame();
}
