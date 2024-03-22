#include "tokenizer.h"
#include <stdio.h>

/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char (char c) {
  return c == ' ' || c == '\t';
  
}
