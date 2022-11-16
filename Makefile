OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o racional.o token.o expressio.o variables.o math_sessio.o math_io.o
	g++ -o program.exe main.o racional.o token.o expressio.o variables.o math_sessio.o math_io.o
	rm *.o

main.o: main.cpp racional.o token.o expressio.o variables.o math_sessio.o math_io.o
	g++ -c main.cpp racional.o token.o expressio.o variables.o math_sessio.o math_io.o $(OPCIONS)

racional.o: racional.cpp racional.hpp racional.rep
	g++ -c racional.cpp $(OPCIONS)

token.o: token.cpp token.hpp token.rep racional.o
	g++ -c token.cpp racional.o $(OPCIONS)

expressio.o: expressio.cpp expressio.hpp expressio.rep racional.o token.o
	g++ -c expressio.cpp racional.o token.o $(OPCIONS)

variables.o: variables.cpp variables.hpp variables.rep expressio.o
	g++ -c variables.cpp expressio.o $(OPCIONS)

math_sessio.o: math_sessio.cpp math_sessio.hpp math_sessio.rep token.o expressio.o variables.o
	g++ -c math_sessio.cpp token.o expressio.o variables.o $(OPCIONS)

math_io.o: math_io.cpp math_io.hpp token.o
	g++ -c math_io.hpp token.o $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch