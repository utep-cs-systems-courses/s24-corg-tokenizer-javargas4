#include "history.h"
#include "tokenizer.h"
#include "test_functions.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {
  // string for user input
  char user_input[256];

  // print input indicator
  printf("$ ");
  
  // read a line of input from the user
  if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
    // remove newline character at the end if it exists
    for (int i = 0; user_input[i] != '\0'; i++) {
      if (user_input[i] == '\n') {
	user_input[i] = '\0';
	break;
      }
    }

    // tokenize the input
    char **tokens = tokenize(user_input);

    // check if tokenization was successful
    if (tokens != NULL) {
      // print the tokens
      print_tokens(tokens);

      // free the allocated tokens
      free_tokens(tokens);

    } else {
      printf("Failed to tokenize input or no tokens found.\n");
      
    }

  } else {
    printf("Failed to read input.\n");

  }

  // initialize the history list
  List *history = init_history();

  if (history == NULL) {
    fprintf(stderr, "Failed to initialize history.\n");
  }

  // add some items to the history
  add_history(history, "First entry");
  add_history(history, "Second entry");
  add_history(history, "Third entry");


  // print the history to verify
  print_history(history);
  
}
