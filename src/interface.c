#include "tokenizer.h"
#include <stdio.h>

// Basic UI
int main (void) {
  /*
  // string for user input
  char user_input[50];

  // print input indicator
  printf("$ ");
  
  // get user input
  fgets(user_input, sizeof(user_input), stdin);

  // print user input
  printf("%s", user_input);
  */
  char test_letter = ' ';
  printf("int space_char return value with test c = ' '\nReturn: %d\n", space_char(test_letter));

  test_letter = '\t';
  printf("int space_char return value with test c = '\t'\nReturn: %d\n", space_char(test_letter));

  test_letter = 'y';
  printf("int space_char return value with test c = 'y'\nReturn: %d\n", space_char(test_letter));

}
