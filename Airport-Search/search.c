


// FILE: search.c
// Purpose: Use linked list to store all airports and allows users to
//          search for airports by airport code
// Written By: Eunsoo Jang
// Date: April 18, 2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

// Functions for handling Airport database load and search
void readData(char *file, List *L);
Airport *queryAirport(List *L, char *code);
int more();


int main(int argc, char *argv[]) {

   List *airportList;
   airportList=newList();	// A list of all airports

   // Load database...
   if (argc != 2) {
      printf("Cannot proceed: Missing file name.\n");
      exit(EXIT_FAILURE);
   }
   readData(argv[1], airportList);

   // Begin user interaction
   char code[5];
   Airport * result;
   do {
       printf("Enter the three-letter code for an airport: ");
       scanf("%s", code);
       printf("Searching: %s\n", code);
       result=queryAirport(airportList, code);

       if (result!= NULL) {
          printf("Success: ");
          show(result);
       }
       else
          printf("Unsuccessful: %s is not a known airport.\n", code);

   } while (more());
   printf("Goodbye!\n");

   return(0);
} // main()

Airport *queryAirport(List *L, char *code){
  Airport* result;
  result=contains(L,code,compareAirport);
  if (result!= NULL) {
    return result;
  }
  else{
    return NULL;
  }
}

int more() {
   char resp[5];
   while (1) {
       printf("Would you like to search again (Y/N)? ");
       scanf("%s", resp);
       if ((strcmp(resp, "Y") == 0) || (strcmp(resp, "y") == 0))
	  return 1;
       else if ((strcmp(resp, "N") == 0) || (strcmp(resp, "n") == 0))
	  return 0;
       else
          printf("Please enter a Y or a N.\n");
   }
} // more()

void readData(char *file, List *L) {
   // Load airport database into list[] from file, set n

   FILE *fp;

   printf("Opening file: %s\n", file);
   fp = fopen(file, "r");
   if (fp == NULL) {
      printf("Unable to open file %s.\n", file);
      exit(EXIT_FAILURE);
   }
   printf("Opened file %s.\n", file);
   printf("Reading...");

   char line[80];
   fgets(line, sizeof(line), fp); // ignore first line
   while ( (fgets(line, sizeof(line), fp)) != NULL) {
      int l = strlen(line);
      line[l-1] = '\0';
      Airport *a=parseAirport(line);
      add(L,a);
   }
   fclose(fp);
   printf("...done. [%d]\n", size(L));
} // readData()
