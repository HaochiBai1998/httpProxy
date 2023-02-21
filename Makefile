all: main
main: main.cpp proxy.cpp proxy.h 
		g++ -g -o main main.cpp proxy.cpp proxy.h  -lpthread
.PHONY:
		cliean
clean:
		rm -rf *.o main

