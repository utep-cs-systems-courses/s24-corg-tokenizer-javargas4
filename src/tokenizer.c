#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>


/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char (char c) {
  return c == ' ' || c == '\t';
  
}


/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char (char c) {
  return c != ' ' && c != '\t' && c != '\0';

}
