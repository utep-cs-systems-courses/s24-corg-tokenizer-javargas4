#include "history.h"
#include <stdio.h>
#include <stdlib.h>


/* Initialize the linked list to keep the history. */
List* init_history () {
  // allocating memory for list structure
  List *list = (List*)malloc(sizeof(List));
  
  // check if memory allocated
  if (list == NULL) {
    fprintf(stderr, "Failed to allocate memory for history list.\n");
    return NULL;
  }
  // set root to NULL
  list->root = NULL;
  return list;
  
}
