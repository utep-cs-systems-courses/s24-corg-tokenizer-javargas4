#include "history.h"
#include "tokenizer.h"
#include "test_functions.h"
#include <stdio.h>
#include <stdlib.h>

// compare two strings, returns 0 if equal 
int string_compare(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return (unsigned char)(*str1) - (unsigned char)(*str2);

}

// checks if the character is a digit 
int is_digit(char c) {
  return c >= '0' && c <= '9';
}


// converts a string to an integer assumes the string is a valid number
int string_to_int(char *str) {
  int result = 0;
  
  for (; *str; str++) {
    result = result * 10 + (*str - '0');
  }

  return result;

}

int main(void) {
  char user_input[256];

  // initialize history list
  List* history_list = init_history();

  while (1) {
    // print UI symbol for user input
    printf("$ ");

    // get user input
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
      
      // remove newline character at the end if it exists
      for (int i = 0; user_input[i] != '\0'; i++) {
	if (user_input[i] == '\n') {
	  user_input[i] = '\0';
	  break;
	}

      }

      // handle 'quit' command
      if (string_compare(user_input, "quit") == 0) {
	break;
      }

      // handle 'history' command
      else if (string_compare(user_input, "history") == 0) {
	printf("\n");
	print_history(history_list);
	printf("\n");
      }

      // handle recall command '!x'
      else if (user_input[0] == '!' && is_digit(user_input[1])) {
	
	int id = string_to_int(&user_input[1]);
	char *recalled_input = get_history(history_list, id);

	// get data in 'id', if it exists
	if (recalled_input) {
	  printf("\n");
	  printf("Recalling: %s\n", recalled_input);
	  
	  // tokenize the recalled data
	  char **tokens = tokenize(recalled_input);

	  // print tokens
	  if (tokens) {
	    printf("\n");
	    print_tokens(tokens);
	    printf("\n");
	    free_tokens(tokens);
	  }

	} else {
	  // handle the case 'id' doesn't exist
	  printf("\n");
	  printf("No history item with id %d.\n\n", id);

	}
      }

      // handle regular string input
      else {
	// add user input to history and tokenize
	add_history(history_list, user_input);
	char **tokens = tokenize(user_input);

	// print tokens and free memory allocation
	if (tokens) {
	  printf("\n");
	  print_tokens(tokens);
	  printf("\n");
	  free_tokens(tokens);

	} else {
	  printf("Failed to tokenize input or no tokens found.\n");

	}

      }

    } else {
      printf("Failed to read input.\n");
      
    }

  }

  // clean up before quitting
  free_history(history_list);
  
  return 0;

}
