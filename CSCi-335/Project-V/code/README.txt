##############################################
##############################################
## Makefile
## LINUX compilation 
##############################################
##############################################

Name: Robi Gurung
Date: 10 December 2021
Graph Algorithms-Assignment 5

Comments:
Assignment is completed. Runs as it should.

One of the materials needed for study was a textbook. When I first started the project,
I tried to create an adjacency list using the vectors in the vector. After reading the 
textbook and using internet resources, I noticed that it can be thought of as an adjacency 
matrix rather than an adjacency list. I learned how to implement and then moved on to using a map where the key is the node to which the vertices are connected and the key is the weight. 

I also checked out the YouTube video to get a better understanding of Dijkstra's algorithm. One of the areas I struggled with was finding a way to track paths and nodes that I had already accessed. Watching the YouTube video gave me a better idea of ​​the data structure used to track the node I'm accessing. It also helped me understand the underlying concepts of Dijkstra's algorithm.

Submitting files: CreateGraphAndTest.cc, graph.h, FindPaths.cc and README.txt

Input files: Graph1.txt, Graph2.txt, AdjacencyQueries1.txt and AdjacencyQueries2.txt


#FLAGS
C++FLAG = -g -std=c++11 -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.



#Rule for .cc files
# .SUFFIXES : .cc.o 

.cc.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@


#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=CreateGraphAndTest.o
PROGRAM_0=CreateGraphAndTest
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ1=FindPaths.o
PROGRAM_1=FindPaths
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)


#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1))


Thank you

(:
