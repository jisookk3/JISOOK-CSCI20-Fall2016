# this target will compile all files

# lab21.o:  // Target
# lab21.cpp  // Defendency
# g++ -Wall -g -c lab21.cpp  // Command

# all:  // default 
# In the terminal, if you type: make   
# goes to lab21exe target   
# you can type Instead:  make all  
# OR:  make lab21exe

# an executable named lab21exe
# In order to to test that your program works, in the terminal type: ./lab21exe

# to remove .o files, type: make clean

all: lab21exe
	
lab21exe: lab21.o MyClass.o
	g++ -Wall -g lab21.o MyClass.o -o lab21exe

lab21.o: lab21.cpp
	g++ -Wall -g -c lab21.cpp

MyClass.o: MyClass.cpp
	g++ -Wall -g -c MyClass.cpp

clean:
	rm -rf *o lab21