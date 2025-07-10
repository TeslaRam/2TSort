##########
# file: 		Makefile
# author:	TeslaRam
# brief:		Makefile for 2TSort
# date:		10.7.25
# see:		https://github.com/TeslaRam/2TSort
##########
##################
########## VALS ##########

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
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

comp_compare.o: ./comps/comp_compare.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
comp_generation.o: ./comps/comp_generation.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
comp_setup_cleanup.o: ./comps/comp_setup_cleanup.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
comp_sorts.o: ./comps/comp_sorts.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

comp: comp_compare.o comp_generation.o comp_setup_cleanup.o comp_sorts.o
	$(CXX) $(CXXFLAGS) $^ -o $@

compare: comp
	./comp $(SIZE) # > $(COMP_OUT)

########## COMP ##########
##########################
########## MISC ##########

.PHONY: run sort compare clean

clean:
	find . -type f -executable -delete
	find . -type f -name "*.o" -delete
	rm -f ./$(COMP_OUT)
	clear
