#include <iostream>
using namespace std;
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
};
void displayboard() {
  cout << "\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j];
      if (j < 2)
        cout << "|";
    }
    cout << "\n";
    if (i < 2)
      cout << "--+---+--   \n";
  }
  cout << "\n";
}
bool checkwin() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
      return true;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
      return true;
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return true;
  if (board[0][2] == board[1][1] == board[1][1] == board[2][0])
    return true;
  return false;
}
int main() {
  int choice;
  char player = 'x';
  int moves = 0;
  while (true) {
    displayboard();
    cout << "player" << player << "enter position:";
    cin >> choice;
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    if (board[row][col] != 'x' && board[row][col] != 'o') {
      board[row][col] = player;
      moves++;
      if (checkwin()) {
        displayboard();
        cout << "player" << player << "wins!" << endl;
        break;
      }
      if (moves == 9) {
        displayboard();
        cout << "it's a draw!";
        break;
      }
      player = (player == 'x') ? 'o' : 'x';
    } else {
      cout << "invalid move! try again.\n";
    }
  }
  return 0;
}
