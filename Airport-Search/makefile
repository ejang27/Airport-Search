search: search.o Airport.o List.o node.o
	gcc -o search search.o Airport.o List.o node.o
search.o: Airport.h List.h node.h search.c
	gcc -c search.c
Airport.o: Airport.h Airport.c
	gcc -c Airport.c
List.o: List.h List.c node.h Airport.h
	gcc -c List.c
node.o: node.c node.h
	gcc -c node.c
