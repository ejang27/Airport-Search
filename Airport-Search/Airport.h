


// FILE: Airport.h
// Written By: Eunsoo Jang
// Date: April 18, 2018

typedef struct {
   char *code;	// code
   char *name;	// name of airport
   char *city;	// city
   char *state;	// state
   char *country;	// duh
} Airport;


void show(Airport* a);	// prints out a given airport object
Airport * parseAirport(char * str);	// Parses str into an Airport object
int compareAirport(const void *b,const void *a);
