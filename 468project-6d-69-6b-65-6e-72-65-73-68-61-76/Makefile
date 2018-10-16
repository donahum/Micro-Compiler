#!/bin/bash
export PATH := /opt/gcc/7.1.0/bin:$(PATH)
team: 
	@echo "Team: 6d 69 6b 65 6e 72 65 73 68 61 76\n" 
	@echo "Reshav Abraham\nabe66\n" 
	@echo "Mike Donahue\ndonahum\n"

compiler:
	mkdir -p generated
	mkdir -p build
	flex -o generated/scanner.cpp src/scanner.ll
	bison -d -o generated/parser.cpp src/parser.yy
	g++ -std=c++0x -g -c -o build/parser.o generated/parser.cpp
	g++ -std=c++0x -g -c -o build/scanner.o generated/scanner.cpp
	g++ -std=c++0x -g -c -o build/main.o src/main.cpp
	g++ -std=c++0x -g -c -o build/SymbolTable.o src/SymbolTable.cpp
	g++ -std=c++0x -g -c -o build/Node.o src/Node.cpp
	g++ -std=c++0x -g -o Micro build/scanner.o build/parser.o build/main.o build/SymbolTable.o build/Node.o


scanner:
	mkdir -p generated
	mkdir -p build
	flex -o generated/scanner.cpp src/scanner.ll
	bison -d -o generated/parser.cpp src/parser.yy
	g++ -std=c++0x -c -o build/scanner.o generated/scanner.cpp
	g++ -std=c++0x -c -o build/main.o src/scan_main.cpp
	g++ -std=c++0x -o Scanner build/scanner.o build/main.o 

clean:
	@rm -rf generated
	@rm -rf build
	@rm -f Micro
	@rm -f Scanner
	@rm -f Tester

testSTE:
	g++ -std=c++0x src/SymbolTableEntry.cpp -o Tester

testST:
	mkdir -p build
	g++ -std=c++0x -g -o Tester src/SymbolTable.cpp src/SymbolTableEntry.cpp
