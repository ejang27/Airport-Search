


// FILE: List.h
// Written By: Eunsoo Jang
// Date: April 18, 2018

#include "node.h"
#include "Airport.h"

typedef struct {
   int size;
   struct node *head;
   struct node *tail;
} List;

List *newList();			// Creates a new empty list
int size(const List *l);		// Returns the size of list-l
void add(List *l, void *item);	// Add item at end of list-l
void *contains(const List *l, char *item, int (*comp)(const void*, const void *));
// Does list-l have item? Use compare() to check
