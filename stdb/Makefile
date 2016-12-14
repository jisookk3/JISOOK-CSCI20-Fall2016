all: stdbexe
	
stdbexe: stdb.o Database.o
	g++ -Wall -g stdb.o Database.o -o stdbexe

stdb.o: stdb.cpp
	g++ -Wall -g -c stdb.cpp

Database.o: Database.cpp
	g++ -Wall -g -c Database.cpp

clean:
	rm -rf *o stdb