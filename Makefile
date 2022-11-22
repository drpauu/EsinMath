OPCIONS = -g -O0 -ansi -Wall -Wextra -Werror -lesin -Wno-deprecated

programa_racional.exe: main.o racional.o
	g++ -o programa_racional.exe main.o  -lesin
	rm *.o

main.o: main.cpp racional.o
	g++ -c main.cpp $(OPCIONS)

racional.o: racional.cpp racional.hpp racional.rep
	g++ -c racional.cpp  $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch