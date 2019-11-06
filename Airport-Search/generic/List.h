#include "node.h"

typedef struct{
  int size;
  struct node *head;
  struct node *tail;
}List;

List newList();
int size(const List *l);
int empty(const List *l);
void clear(List *l);
void add(List *l, int item);
int get(const List *l, int index);
int contains(const List *l, int item);
void print(const List *l);
