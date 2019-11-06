


// FILE: node.c
// Written By: Eunsoo Jang
// Date: April 18, 2018

#include <stdlib.h>
#include "node.h"

struct node *newNode(void *item) {  // Creates a new node with item
   struct node *n = malloc(sizeof(struct node));
   n->data = item;
   n->next = NULL;
   return n;
} // newNode()
