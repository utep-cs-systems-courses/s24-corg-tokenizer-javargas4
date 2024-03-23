#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

//Test

// function to test test_space_char
void test_space_char () {
  // test cases for space_char
  char test_char1 = ' ';
  char test_char2 = '\t';
  char test_char3 = 'a';
  char test_char4 = 'A';

  // printing results for each test case
  printf("space_char return value with test c = '%c'\nReturn: %d\n",
	 test_char1, space_char(test_char1));

  printf("space_char return value with test c = '\\t'\nReturn: %d\n",
	 space_char(test_char2));

  printf("space_char return value with test c = '%c'\nReturn: %d\n",
	 test_char3, space_char(test_char3));

  printf("space_char return value with test c = '%c'\nReturn: %d\n",
	 test_char4, space_char(test_char4));

  printf("\n");
  
}

// function to test non_space_char
void test_non_space_char () {
  // test cases for non_space_char
  char test_char1 = ' ';
  char test_char2 = '\t';
  char test_char3 = '\0';
  char test_char4 = 'a';
  char test_char5 = 'A';
  
  // printing results for each test case
  printf("non_space_char return value with test c = '%c'\nReturn: %d\n",
	 test_char1, non_space_char(test_char1));

  printf("non_space_char return value with test c = '\\t'\nReturn: %d\n",
	 non_space_char(test_char2));

  printf("non_space_char return value with test c = '\\0'\nReturn: %d\n",
	 non_space_char(test_char3));

  printf("non_space_char return value with test c = '%c'\nReturn: %d\n",
	 test_char4, non_space_char(test_char4));

  printf("non_space_char return value with test c = '%c'\nReturn: %d\n",
	 test_char5, non_space_char(test_char5));

  printf("\n");
  
}
// function to test *token_start
void test_token_start() {
  // test cases for *token_start
  char *test_str1 = "   Leading spaces";
  char *test_str2 = "NoLeadingSpaces";
  char *test_str3 = "\t\t\tTabbed\tstring";
  char *test_str4 = "     ";
  char *test_str5 = ""; 

  // dereferencing result to access the character directly
  char *result;

  /* running test strings, returning '0' if non-whitespace char doesn't
     exist to match type of *result */
  result = token_start(test_str1);
  printf("token_start with test string: \"%s\"\nResult: %c\n",
	 test_str1, result ? *result : '0');

  result = token_start(test_str2);
  printf("token_start with test string: \"%s\"\nResult: %c\n",
	 test_str2, result ? *result : '0');

  result = token_start(test_str3);
  printf("token_start with test string: \"%s\"\nResult: %c\n",
	 test_str3, result ? *result : '0');

  result = token_start(test_str4);
  printf("token_start with test string: \"%s\"\nResult: %s\n",
	 test_str4, result ? "Found non-whitespace character" :
	 "No non-whitespace character found");

  result = token_start(test_str5);
  printf("token_start with test string: \"%s\"\nResult: %s\n",
	 test_str5, result ? "Found non-whitespace character" :
	 "No non-whitespace character found");

  printf("\n");
  
}

// function to test *token_terminator
void test_token_terminator() {
  // test cases for *token_terminator
  char *test_str1 = "Token1 Token2";
  char *test_str2 = "AToken";
  char *test_str3 = "token with space";
  char *test_str4 = "";

  // pointer to store function results
  char *result;

  // should print ' ', from space after 'Token1'
  result = token_terminator(test_str1);
  printf("token_terminator with test string: \"%s\"\nResult: '%c'\n",
	 test_str1, result && *result ? *result: '0');

  // should print 'Null terminator or empty string'
  result = token_terminator(test_str2);
  printf("token_terminator with test string: \"%s\"\nResult: '%s'\n",
	 test_str2, result && *result ? "Char found" : "Null terminator or empty string");

  // should print ' ', from space after 'token'
  result = token_terminator(test_str3);
  printf("token_terminator with test string: \"%s\"\nResult: '%c'\n",
	 test_str3, result && *result ? *result: '0');

  // should print 'Null terminator or empty string'
  result = token_terminator(test_str4);
  printf("token_terminator with test string: \"%s\"\nResult: '%s'\n",
	 test_str4, result && *result ? "Char found" : "Null terminator or empty string");

  printf("\n");
  
}

// function to test count_tokens
void test_count_tokens() {
  // test cases for count_tokens
  char *test_str1 = "I am testing this string";
  char *test_str2 = "OnlyOneToken";
  char *test_str3 = "    leading spaces";
  char *test_str4 = "traling spaces    ";
  char *test_str5 = "          "; 
  char *test_str6 = "";

  printf("count_tokens with test string: \"%s\"\nTokens: %d\n",
	 test_str1, count_tokens(test_str1));

  printf("count_tokens with test string: \"%s\"\nTokens: %d\n",
	 test_str2, count_tokens(test_str2));

  printf("count_tokens with test string: \"%s\"\nTokens: %d\n",
	 test_str3, count_tokens(test_str3));

  printf("count_tokens with test string: \"%s\"\nTokens: %d\n",
	 test_str4, count_tokens(test_str4));

  printf("count_tokens with test string: \"%s\"\nTokens: %d\n",
	 test_str5, count_tokens(test_str5));

  printf("count_tokens with test string: \"%s\"\nTokens: %d\n",
	 test_str6, count_tokens(test_str6));

  printf("\n");

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
  test_non_space_char();
  test_token_start();
  test_token_terminator();
  test_count_tokens();
}
