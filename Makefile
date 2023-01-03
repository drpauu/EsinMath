OPCIONS = -g -O0 -ansi -Wall -Wextra -Werror -lesin -Wno-deprecated

driver.exe: driver_esinmath.o token.o racional.o expressio.o variables.o math_sessio.o math_io.o
	g++ -o driver.exe driver_esinmath.o token.o racional.o expressio.o variables.o math_sessio.o math_io.o -lesin
	rm *.o

programa_racional1.exe: main_cesco.o token.o racional.o
	g++ -o programa_racional1.exe main_cesco.o token.o racional.o -lesin
	rm *.o

programa_racional2.exe: main_pau.o token.o racional.o
	g++ -o programa_racional2.exe main_pau.o token.o racional.o -lesin	
	rm *.o

main_pau.o: main_pau.cpp token.o racional.o
	g++ -c main_pau.cpp $(OPCIONS)

main_cesco.o: main_cesco.cpp token.o
	g++ -c main_cesco.cpp $(OPCIONS)

racional.o: racional.cpp racional.hpp racional.rep
	g++ -c racional.cpp  $(OPCIONS)

token.o: token.cpp token.hpp token.rep racional.o
	g++ -c token.cpp $(OPCIONS)

expressio.o: expressio.cpp expressio.hpp expressio.rep token.o
	g++ -c expressio.cpp $(OPCIONS)

variables.o: variables.cpp variables.hpp variables.rep expressio.o
	g++ -c variables.cpp $(OPCIONS)

math_sessio.o: math_sessio.cpp math_sessio.hpp math_sessio.rep variables.o math_io.o
	g++ -c math_sessio.cpp $(OPCIONS)

math_io.o: math_io.cpp math_io.hpp math_io.rep token.o
	g++ -c math_io.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch