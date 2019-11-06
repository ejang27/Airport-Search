


// FILE: Airport.c
// Written By: Eunsoo Jang
// Date: April 18, 2018


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Airport.h"

void show(Airport *a) {	// print Airport object
   printf("%s - %s, %s, %s (%s).\n",a->code,a->name,a->city,a->state,a->country);
} // show()

Airport *parseAirport(char * str) { // Parse srt into an Airport object

   Airport *result=malloc(sizeof(Airport));

   char *token;
   token = strtok(str, ",");	// code
   result->code=malloc(strlen(token)+1);
   strcpy(result->code, token);

   token = strtok(NULL, ",");	// name
   result->name=malloc(strlen(token)+1);
   strcpy(result->name, token);

   token = strtok(NULL, ",");	// city
   result->city=malloc(strlen(token)+1);
   strcpy(result->city, token);

   token = strtok(NULL, ",");	// state
   result->state=malloc(strlen(token)+1);
   strcpy(result->state, token);

   token = strtok(NULL, ",");	// country
   result->country=malloc(strlen(token)+1);
   strcpy(result->country, token);

   return result;
} // parseAirport()

int compareAirport(const void *b,const void *a){
  Airport *x=(Airport *)b;
  char *y = (char *)a;
  return strcmp(x->code,y)==0;
}
