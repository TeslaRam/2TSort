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

COMP_SOURCES := $(wildcard $(COMPS_DIR)/comp_*.cpp)
COMP_BINS := $(patsubst %.cpp, %, $(COMP_SOURCES))

COMPS_DIR = ./comps
SRCS = $(COMPS_DIR)/comp_*.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

comp: $(OBJS)
	$(COMPILE)

compare: comp
	./comp > $(COMP_OUT)

########## COMP ##########
##########################
########## MISC ##########

.PHONY: run sort compare clean

clean:
	find . -type f -executable -delete
	find . -type f -name "*.o" -delete
	rm -f ./$(COMP_OUT)
	clear
