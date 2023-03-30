all : prog

prog : main.o graphedge.o graphnode.o graph.o
	g++ -o prog main.o  graphedge.o graphnode.o graph.o

main.o : main.cpp 
	g++ -c main.cpp
	
graphnode.o : graphnode.cpp 
	g++ -c graphnode.cpp

graphedge.o : graphedge.cpp 
	g++ -c graphedge.cpp

graph.o : graph.cpp
	g++ -c graph.cpp

clean : 
	rm -rf *.o