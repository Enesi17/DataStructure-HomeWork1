program: compile run

compile:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Node.o ./lib/LinkedList.o ./src/main.cpp
run:
	./bin/Test