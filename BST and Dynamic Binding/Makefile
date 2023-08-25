CC = g++ -Wall -g


all: program

program: main.o tree.o armor.o weapons.o potions.o 
	$(CC) -o program tree.o main.o armor.o weapons.o potions.o 

main.o: main.cpp 
	$(CC) -c main.cpp

tree.o: tree.cpp tree.h product.h
	$(CC) -c tree.cpp

armor.o: armor.cpp product.h
	$(CC) -c armor.cpp

weapons.o: weapons.cpp product.h
	$(CC) -c weapons.cpp

potions.o: potions.cpp product.h
	$(CC) -c potions.cpp

clean:
	rm -f *.o program *~ \#*