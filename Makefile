 #************************************************************************
 #
 #	Makfile for CS2401 Project 1
 #	Made by Patricia Lindner
 #	Last updated 8/30/2024
 #	For automatic grading to work, do not change this file.
 #	Students are encouraged to read through to understand
 #		project requirements, however.
 #
 # ***********************************************************************

CFLAGS = -Wall -std=c++11
CC = g++

a.out: date.o person.o song.o
	$(CC) $(CFLAGS) main.cc  _TEST/date.o _TEST/person.o _TEST/song.o -o a.out

date.o: date.cc date.h
	$(CC) $(CFLAGS) -c $< -o _TEST/$@

person.o: person.cc person.h
	$(CC) $(CFLAGS) -c $< -o _TEST/$@

song.o: song.cc song.h
	$(CC) $(CFLAGS) -c $< -o _TEST/$@

run_tests: date.o person.o song.o
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc _TEST/date.o _TEST/person.o _TEST/song.o -o _TEST/run_tests && ./_TEST/run_tests

clean:
	rm -f _TEST/*.o a.out _TEST/run_tests _TEST/full_profile_save.txt
