CC=g++
CFLAGS=-Wall -pedantic -std=c++11 -g
INCDIR=../../include
SOURCES=$(wildcard $(INCDIR)/*.cpp)
OBJS=$(SOURCES:.cpp=.o)

all: check_permutations 

#1.1
unique_strings: $(OBJS) unique_strings.cpp
	$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) unique_strings.cpp

#1.2
check_permutations: $(OBJS) check_permutations.cpp
	$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) check_permutations.cpp

$(INCDIR)/%.o: $(INCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $(INCDIR)/$@
