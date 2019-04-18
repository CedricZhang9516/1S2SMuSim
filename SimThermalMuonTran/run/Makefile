# Makefile for vmedrv libraries
# Created by Enomoto Sanshiro on 8 December 1999.  n
# Last updated by Enomoto Sanshiro on 20 December 1999.
CC = gcc
CFLAGS = -g -Wall -I/usr/include
CXX = g++
CXXFLAGS = -g -Wall -Wcomment -fno-inline-functions -O2
ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)

TARGETS = count  

.SUFFIXES: .cc .o

all: $(TARGETS)


count : count.cc
	$(CXX) -o $@ $< $(CXXFLAGS) $(ROOTFLAGS) $(ROOTLIBS)



% : %.c
	$(CXX) $(CXXFLAGS) -o $@ $<

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGETS)