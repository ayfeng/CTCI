CC=g++
INCDIR=../../include
CFLAGS=-Wall -Wno-sign-compare -Wno-vla -pedantic -std=c++11 -g -I$(INCDIR)
SOURCES=$(wildcard *.cpp)
OUTPUTS=$(SOURCES:.cpp=.out)

all: $(OUTPUTS)

%.out: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm *.out
