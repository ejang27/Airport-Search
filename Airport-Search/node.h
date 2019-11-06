


// FILE: node.h
// Written By: Eunsoo Jang
// Date: April 18, 2018

struct node {
   void *data;
   struct node *next;
};

struct node *newNode(void *item);
