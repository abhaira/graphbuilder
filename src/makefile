all: fileparser.o graph.o graphbuilder.o
	ar cr ../lib/libgraphbuilder.a ../build/fileparser.o ../build/graph.o ../build/graphbuilder.o

fileparser.o:	
	g++ -std=c++11 -c -I ../include -o ../build/fileparser.o FileParser.cpp

graph.o:
	g++ -std=c++11 -c -I ../include -o ../build/graph.o Graph.cpp

graphbuilder.o:	fileparser.o graph.o
	g++ -std=c++11 -c -I ../include -o ../build/graphbuilder.o GraphBuilder.cpp

clean:
	rm -f ../build/fileparser.o ../build/graph.o ../build/graphbuilder.o ../lib/libgraphbuilder.a
