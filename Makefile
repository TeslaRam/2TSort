##########
# file: 		Makefile
# author:	TeslaRam
# brief:		Makefile for 2TSort
# date:		11.7.25
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

sort: run

2TSort: 2TSort.cpp
	$(COMPILE)

run: 2TSort
	./2TSort $(SIZE)

######### 2TSORT #########
##########################
########## COMP ##########

comps/%.o: comps/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

COMP_SRCS := $(wildcard comps/*.cpp)
COMP_OBJS := $(patsubst %.cpp,%.o,$(COMP_SRCS))

comp: $(COMP_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

compare: comp
	./comp $(SIZE)
	cat $(COMP_OUT)

########## COMP ##########
##########################
########## MISC ##########

.PHONY: run sort compare clean

clean:
	find . -type f -executable -delete
	find . -type f -name "*.o" -delete
	rm -f ./$(COMP_OUT)
	clear
