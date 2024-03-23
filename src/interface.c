#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

void test_space_char () {
  char test_letter = ' ';
  printf("int space_char return value with test c = ' '\nReturn: %d\n", space_char(test_letter));

  test_letter = '\t';
  printf("int space_char return value with test c = '\\t'\nReturn: %d\n", space_char(test_letter));

  test_letter = 'a';
  printf("int space_char return value with test c = 'a'\nReturn: %d\n", space_char(test_letter));

  test_letter = 'A';
  printf("int space_char return value with test c = 'A'\nReturn: %d\n", space_char(test_letter));

}

void test_non_space_char () {
  char test_letter = ' ';
  printf("int non_space_char return value with test c = ' '\nReturn: %d\n",
	 non_space_char(test_letter));

  test_letter = '\t';
  printf("int non_space_char return value with test c = '\\t'\nReturn: %d\n",
	 non_space_char(test_letter));

  test_letter = '\0';
  printf("int non_space_char return value with test c = '\\0'\nReturn: %d\n",
	 non_space_char(test_letter));

  test_letter = 'a';
  printf("int non_space_char return value with test c = 'a'\nReturn: %d\n",
	 non_space_char(test_letter));

  test_letter = 'A';
  printf("int non_space_char return value with test c = 'A'\nReturn: %d\n",
	 non_space_char(test_letter));

}


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
  test_space_char();
  printf("\n");
  test_non_space_char();
}
