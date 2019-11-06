#include <stdlib.h>
#include "node.h"

struct node *newNode(int item){
  struct node *n = malloc(sizeof(struct node));
  n->data = item;
  n->next = NULL;
  return n;
}
