#/******************************************************************************
#*******************************************************************************
#*                           EECS 1580 - 001                                   *
#*                        Project #3 Binary Tree                               *
#*                                                                             *
#*                      Written by: Logan Anteau                               *
#*                          March 24, 2013                                     *
#*******************************************************************************
#*******************************************************************************
#*/

Project3 : main.o
	g++ -ggdb -o Project3 main.o Tree.o bstnode.o BasketballTeam.o

main.o : main.cpp Tree.o bstnode.o BasketballTeam.o
	g++ -ggdb -c main.cpp

Tree.o : Tree.h Tree.cpp bstnode.h bstnode.cpp
	g++ -ggdb -c Tree.cpp
	
bstnode.o : bstnode.h bstnode.cpp BasketballTeam.h BasketballTeam.cpp
	g++ -ggdb -c bstnode.cpp

BasketballTeam.o : BasketballTeam.h BasketballTeam.cpp
	g++ -ggdb -c BasketballTeam.cpp

clean:
	rm -f *.o Project3
