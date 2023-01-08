OPCIONS = -c -Wall -ansi -Wno-deprecated -O0 -std=c++11 -lesin

#DRIVER
programa_driver.e: driver_esinmath.o math_sessio.o math_io.o variables.o expressio.o token.o racional.o
	g++ -o programa_driver.e driver_esinmath.o math_sessio.o math_io.o variables.o expressio.o token.o racional.o -lesin

driver_esinmath.o: driver_esinmath.cpp math_sessio.hpp math_io.hpp variables.hpp expressio.hpp token.hpp racional.hpp
	g++ -c driver_esinmath.cpp  $(OPCIONS)


#classe MATH_SESSIO
math_sessio.o: math_sessio.cpp math_sessio.hpp math_sessio.rep math_io.hpp variables.hpp expressio.hpp token.hpp racional.hpp
	g++ -c math_sessio.cpp  $(OPCIONS)

#classe MATH_IO
math_io.o: math_io.cpp math_io.hpp token.hpp racional.hpp
	g++ -c math_io.cpp  $(OPCIONS)

#classe VARIABLES
variables.o: variables.cpp variables.hpp variables.rep expressio.hpp token.hpp racional.hpp
	g++ -c variables.cpp  $(OPCIONS)


#classe EXPRESSIO
programa_exp.exe: main_exp.o expressio.o token.o racional.o 
	g++ -o programa_exp.exe  main_exp.o expressio.o token.o racional.o -lesin

main_exp.o: main_exp.cpp expressio.hpp token.hpp racional.hpp
	g++ -c main_exp.cpp -lesin  $(OPCIONS)

expressio.o: expressio.cpp expressio.hpp expressio.rep token.hpp racional.hpp
	g++ -c expressio.cpp  $(OPCIONS)

#classe TOKEN
programa_token.exe: main_token.o token.o racional.o 
	g++ -o programa_token.exe  main_token.o token.o racional.o -lesin

main_token.o: main_token.cpp token.hpp racional.hpp
	g++ -c main_token.cpp -lesin  $(OPCIONS)

token.o: token.cpp token.hpp token.rep racional.hpp
	g++ -c token.cpp  $(OPCIONS)

#classe RACIONAL
programa_racional.exe: main_racional.o racional.o 
	g++ -o programa_racional.exe main_racional.o racional.o -lesin

main_racional.o: main_racional.cpp racional.hpp 
	g++ -c main_racional.cpp -lesin $(OPCIONS)

racional.o: racional.cpp racional.hpp racional.rep
	g++ -c racional.cpp  $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch

#OPCIONS = -g -O0 -ansi -Wall -Wextra -Werror -lesin -Wno-deprecated

#programa_racional1.exe: main_cesco.o token.o racional.o
#	g++ -o programa_racional1.exe main_cesco.o token.o racional.o -lesin
#	rm *.o

#programa_racional2.exe: main_pau.o racional.o token.o
#	g++ -o programa_racional2.exe main_pau.o -lesin	
#	rm *.o

#main_pau.o: main_pau.cpp token.o racional.o
#	g++ -c main_pau.cpp $(OPCIONS)

#main_cesco.o: main_cesco.cpp token.o
#	g++ -c main_cesco.cpp $(OPCIONS)

#racional.o: racional.cpp racional.hpp racional.rep
#	g++ -c racional.cpp  $(OPCIONS)

#token.o: token.cpp token.hpp token.rep racional.o
#	g++ -c token.cpp $(OPCIONS)

#clean:
#	rm *.o
#	rm *.exe
#	rm *.gch