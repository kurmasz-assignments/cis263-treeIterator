CPPFLAGS = -g -Wall -std=c++17

all: studentTest profTest

testMain.o: testMain.cpp
	g++ -c $(CPPFLAGS) $< -o $@

treeMain.o: treeMain.cpp BinarySearchTree.h
	g++ -c $(CPPFLAGS) $< -o $@

treeIteratorTest.o: treeIteratorTest.cpp BinarySearchTree.h
	g++ -c $(CPPFLAGS) $< -o $@

treeMain: treeMain.o
	g++ $(CPPFLAGS) $^ -o $@

studentTest: treeIteratorTest.o testMain.o
	g++ $(CPPFLAGS) $^ -o $@

profTest: treeIteratorShadowProfTest.cpp testMain.o
	g++ $(CPPFLAGS) $^ -o $@

test:
	./studentTest
	./profTest

valgrind:
	valgrind --leak-check=full --error-exitcode=7 ./studentTest
	valgrind --leak-check=full --error-exitcode=9 ./profTest


