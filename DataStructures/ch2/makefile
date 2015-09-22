CC=g++
INCDIR=../../include
CFLAGS=-Wall -Wno-sign-compare -Wno-vla -pedantic -std=c++11 -g -I$(INCDIR)
SOURCES=$(wildcard *.cpp)
OUTPUTS=$(SOURCES:.cpp=.out)

all: $(OUTPUTS)

%.out: %.cpp
	$(CC) $(CFLAGS) $(INCDIR)/ctci_linked_list.o $< -o $@

clean: 
	rm *.out
