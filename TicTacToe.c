#include <stdio.h>

void gametable();
int checkWin();
void system(); // Function declarations

char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void main() {
  int player = 1, input,
      status = -1; // Variables for player turn, user input, and game status
  gametable();

  while (status == -1) // Main game loop
  {
    player = (player % 2 == 0) ? 2 : 1;
    char mark = (player == 1) ? 'X' : 'O'; // Switch player turn
    printf("Please enter any Number from the table For Player %d\n", player);
    scanf("%d", &input);
    if (input < 1 || input > 9) { // Check for invalid input
      printf("invalid input");
    }

    table[input] = mark; // Update the game table with the player's mark
    gametable();         // Prints the updated game table

    int result = checkWin(); // Check for game result (win, draw, or continue)

    if (result == 1) {
      printf("Player %d is the Winner", player);
      return;
    } else if (result == 0) { // display draw and exit
      printf("It's a draw, play again");
      return;
    }

    player++; // switch to the next player
  }
}

void gametable() { // creating a function that prints the table
  system("cls");   // CLear the console screen
  printf("\n\n");
  printf("====== Welcome To The Game======\n\n     ====Tic-Tac-Toe====\n\n\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", table[1], table[2], table[3]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", table[4], table[5], table[6]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", table[7], table[8], table[9]);
  printf("     |     |     \n");
  printf("\n\n");
} // displaying a game table

int checkWin() {

  if (table[1] == table[2] && table[2] == table[3]) {
    return 1;
  }
  if (table[1] == table[4] && table[4] == table[7]) {
    return 1;
  }
  if (table[7] == table[8] && table[8] == table[9]) {
    return 1;
  }
  if (table[3] == table[6] && table[6] == table[9]) {
    return 1;
  }
  if (table[1] == table[5] && table[5] == table[9]) {
    return 1;
  }
  if (table[3] == table[5] && table[5] == table[7]) {
    return 1;
  }
  if (table[2] == table[5] && table[5] == table[8]) {
    return 1;
  }
  if (table[4] == table[5] && table[5] == table[6]) {
    return 1;
  } // conditions for winning

  int count = 0;
  for (int i = 1; i <= 9; i++) {
    if (table[i] == 'X' || table[i] == 'O') {
      count++; // Check for a draw
    }
  }
  if (count == 9) {
    return 0; // if it is Draw
  }
  return -1;
}