all: compile link run
compile:
	g++ -I "./include" -c ./src/node.cpp -o ./lib/node.o
	g++ -I "./include" -c ./src/linkedlist.cpp -o ./lib/linkedlist.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
link:
	g++  -o ./bin/program  ./lib/linkedlist.o  ./lib/node.o   ./lib/main.o 
run:
	./bin/program