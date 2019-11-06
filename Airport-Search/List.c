


// FILE: List.c
// Written By: Eunsoo Jang
// Date: April 18, 2018

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "List.h"


List *newList() {			// Creates a new empty list
  List *L = malloc(sizeof(List));
  L->head = NULL;
  L->tail = NULL;
  L->size = 0;
  return L;
} // newList()

int size(const List *l) {		// Returns the size of list-l
   return l->size;
} // size()


void add(List *l, void *item) {	// Add item at end of list-l
   struct node *n= newNode(item);
   if (l->size == 0){
     l->head =n;
     l->tail = n;
   }
   else {
      l->tail->next = n;
      l->tail = n;
   }
   l->size++;
} // add()


void *contains(const List *l, char *item, int (*comp)(const void*, const void *)) {
   // Does list-l have item? Use compare() to check.
   struct node *n = l->head;
   while (n != NULL) {
      if (comp(n->data, item))
         return n->data;
      n = n->next;
   }
   return NULL;

} // contains()
