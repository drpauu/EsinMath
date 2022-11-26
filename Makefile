OPCIONS = -g -O0 -ansi -Wall -Wextra -Werror -lesin -Wno-deprecated

programa_racional1.exe: main_cesco.o racional.o token.o
	g++ -o programa_racional1.exe main_cesco.o $(OPCIONS)
	rm *.o

programa_racional2.exe: main_pau.o racional.o token.o
	g++ -o programa_racional2.exe main_pau.o $(OPCIONS)
	rm *.o

main_pau.o: main_pau.cpp token.o racional.o
	g++ -c main_pau.cpp $(OPCIONS)

main_cesco.o: main_cesco.cpp racional.o
	g++ -c main_cesco.cpp $(OPCIONS)

racional.o: racional.cpp racional.hpp racional.rep
	g++ -c racional.cpp  $(OPCIONS)

token.o: token.cpp token.hpp token.rep racional.o
	g++ -c token.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch