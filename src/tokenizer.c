#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>


/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */

int space_char (char c) {
  // check if ' ' or '\t'
  return c == ' ' || c == '\t';
  
}


/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */

int non_space_char (char c) {
  // check if ' ' or '\t' or '\0'
  return c != ' ' && c != '\t' && c != '\0';

}


/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */

char *token_start (char *str) {
  // check each character until end of line '\0'
  while (*str != '\0') {
    // check if non-whitespace char, returns first non-whitespace char
    if (non_space_char(*str)) {
      return str;
    }
    // increment str memory address to check the next char
    str++;
  }
  // return zero pointer if str has no tokens
  return NULL;
  
}


/* Returns a pointer terminator char following *token */

char *token_terminator (char *token) {
  // move to next character as long as null terminator not hit and
  // the current character is not a whitespace
  while (*token != '\0' && !space_char(*token)) {
    token++;
  }
  // return the pointer for the current character, either whitespace or '\0'
  return token;
  
}


/* Counts the number of tokens in the string argument. */

int count_tokens(char *str) {
  int count = 0;
  char *start = NULL;
  char *end = NULL;

  // iterate thru string till end of string
  while (*str != '\0') {
    // get start of token
    start = token_start(str);

    // break loop if start is NULL, end of string reached
    if (start == NULL) {
      break;
    }

    // get end of this token
    end = token_terminator(start);

    // increment counted tokens
    count++;

    /* move to end of current token for next iteration if end
       doesn't point to '\0'*/
    str = *end ? end + 1 : end;

  }

  // return token count
  return count;

}


/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len) {
  // memory allocation for length of characters and null terminator
  char *newStr = malloc(len + 1);

  // checks if memory allocation was successful
  if (newStr == NULL) {
    return NULL;
  }

  // copy len characters from inStr to newStr
  for (int i = 0; i < len; i++) {
    newStr[i] = inStr[i];
  }

  // null-terminate the new string
  newStr[len] = '\0';

  return newStr;
}
