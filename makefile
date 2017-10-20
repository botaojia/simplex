CC=g++
CFLAGS=-c -Wall -O3

all: spectrum_nlsq_fit demo

spectrum_nlsq_fit: main.o data.o spectrum_RSS.o
	$(CC) main.o data.o spectrum_RSS.o -o spectrum_nlsq_fit
demo: demo.o
	$(CC) demo.o -o demo
demo.o:
	$(CC) $(CFLAGS) demo.cpp
main.o:
	$(CC) $(CFLAGS) main.cpp
data.o:
	$(CC) $(CFLAGS) data.cpp
spectrum_RSS.o:
	$(CC) $(CFLAGS) spectrum_RSS.cpp

.PHONY: clean
clean:
	rm -rf *.o demo spectrum_nlsq_fit;
