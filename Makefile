##########
# file: 		Makefile
# author:	Teslaram
# date:		10.7.25
# brief:		Makefile for 2TSort
##########

.PHONY: all run clean

all: 2TSort

2TSort: 2TSort.cpp
	g++ 2TSort.cpp -o 2TSort

run: all
	./2TSort

clean:
	rm -f 2TSort