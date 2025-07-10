##########
# file: 		Makefile
# author:	Teslaram
# date:		10.7.25
# brief:		Makefile for 2TSort
##########
##########################
########## VALS ##########

CXX = g++
CXXFLAGS = -std=c++11

COMPILE = $(CXX) $(CXXFLAGS) $^ -o $@

SIZE ?= 1000

COMP_OUT=comp_out.txt

########## VALS ##########
##########################
######### 2TSORT #########

2TSort: 2TSort.cpp
	$(COMPILE)

run: 2TSort
	./2TSort $(SIZE)

sort: run

######### 2TSORT #########
##########################
########## COMP ##########

comp: compare.cpp
	$(COMPILE)

compare: comp
	./comp > $(COMP_OUT)

########## COMP ##########
##########################
########## MISC ##########

.PHONY: run compare clean

clean:
	find . -maxdepth 1 -type f -executable -delete
	rm -f ./$(COMP_OUT)
	clear
