#include <stdio.h>

// Basic UI

int main (void) {
  // string for user input
  char userInput[50];

  // print input indicator
  printf("$ ");
  
  // get user input
  fgets(userInput, sizeof(userInput), stdin);

  // print user input
  printf("%s", userInput);
  
}
