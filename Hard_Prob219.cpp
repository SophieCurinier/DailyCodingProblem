/* Connect 4 is a game where opponents take turns dropping red or black discs into a 7 x 6 vertically suspended grid.
The game ends either when one player creates a line of four consecutive discs of their color (horizontally, vertically, or diagonally), or when there are no more spots left in the grid.

Design and implement Connect 4*/

#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;

class ConnectFour {
    public:
        ConnectFour() {
            board.resize(ROWS, vector<char>(COLUMNS, ' '));
            currentPlayer = 'X';
            gameOver = false;
        }

        void play() {
            while (!gameOver) {
                displayBoard();
                int column;
                cout << "Player " << currentPlayer << ", enter your move (1-7): ";
                cin >> column;

                if (isValidMove(column)) {
                    column--;
                    move(column);
                    if (isWin()) {
                        displayBoard();
                        cout << "Player " << currentPlayer << " wins!" << endl;
                        gameOver = true;
                    } else if (isBoardFull()) {
                        displayBoard();
                        cout << "It's a draw!" << endl;
                        gameOver = true;
                    } else {
                        togglePlayer();
                    }
                } else {
                    cout << "Invalid move. Try again." << endl;
                }
            }
        }
    
    private:
        vector<vector<char>> board;
        char currentPlayer ;
        bool gameOver ;

        void displayBoard() {
            for (int row=ROWS-1; row>=0; row--) {
                cout << "| ";
                for (int col=0; col<COLUMNS; col++) {
                    cout << board[row][col] << " ";
                }
                cout << "|" << endl;
            }
        }

        bool isValidMove(int col) {
            return (col <= COLUMNS && col >= 1 && board[ROWS-1][col-1] == ' ');
        }

        void move(int column) {
            for (int row=0; row<ROWS; row++) {
                if (board[row][column] == ' ') {
                    board[row][column] = currentPlayer;
                    break;
                }
            }
        }

        bool isBoardFull() {
            bool isFull = true;
            for (int row=0; row<ROWS; row++) {
                for (int column=0; column<COLUMNS; column++) {
                    if (board[row][column] == ' '){
                        isFull = false;
                        break;
                    }
                }
            }

            return isFull;
        }

        void togglePlayer() {
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        }

        bool isWin() {
            // Check horizontal
            for (int row = 0; row < ROWS; row++) {
                for (int column = 0; column < COLUMNS - 3; column++) {
                    if (board[row][column] == currentPlayer && board[row][column + 1] == currentPlayer &&
                        board[row][column + 2] == currentPlayer && board[row][column + 3] == currentPlayer) {
                        return true;
                    }
                }
            }

            // Check vertical
            for (int row = 0; row < ROWS - 3; row++) {
                for (int column = 0; column < COLUMNS; column++) {
                    if (board[row][column] == currentPlayer && board[row+1][column] == currentPlayer &&
                        board[row+2][column] == currentPlayer && board[row+3][column] == currentPlayer) {
                        return true;
                    }
                }
            }

            // Check diagonal (bottom-right to top-left)
            for (int row = 0; row < ROWS - 3; row++) {
                for (int col = 0; col < COLUMNS - 3; col++) {
                    if (board[row][col] == currentPlayer && board[row + 1][col + 1] == currentPlayer &&
                        board[row + 2][col + 2] == currentPlayer && board[row + 3][col + 3] == currentPlayer) {
                        return true;
                    }
                }
            }

            // Check diagonal (bottom-left to top-right)
            for (int row = 3; row < ROWS; row++) {
                for (int col = 0; col < COLUMNS - 3; col++) {
                    if (board[row][col] == currentPlayer && board[row - 1][col + 1] == currentPlayer &&
                        board[row - 2][col + 2] == currentPlayer && board[row - 3][col + 3] == currentPlayer) {
                        return true;
                    }
                }
            }

            return false;
        }

};

int main(int argc, char *argv[])
{
    ConnectFour game;
    game.play();
    return 0;
}