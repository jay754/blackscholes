CC=g++ #main compiler

all: blackscholes

blackscholes: blackscholes.o 
	g++ blackscholes.o -o blackscholes

clean:
	rm -rf *o blackscholes