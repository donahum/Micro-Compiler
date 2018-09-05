#!/bin/bash

team: 
	@echo "Team: 6d 69 6b 65 6e 72 65 73 68 61 76\n" 
	@echo "Reshav Abraham\nabe66\n" 
	@echo "Mike Donahue\ndonahum\n"
compiler:
	@flex -o scanner.cpp abeslex.ll
	@g++ scanner.cpp -o a.out
clean:
	@if [ -f lex.yy.cc ]; then \
		rm lex.yy.cc ;\
	fi

#	@if [ -f output.txt ]; then \
#		rm output.txt ;\
#	fi

	@if [ -f a.out ]; then\
		rm a.out ;\
	fi