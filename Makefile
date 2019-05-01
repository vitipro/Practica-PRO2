OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjto_idiomas.o Idioma.o Nodo.o Treecode.o
	g++ -o program.exe program.o Idioma.o Cjto_idiomas.o Nodo.o Treecode.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cjto_idiomas.o: Cjto_idiomas.cc Cjto_idiomas.hh
	g++ -c Cjto_idiomas.cc $(OPCIONS)

Idioma.o: Idioma.cc Idioma.hh
	g++ -c Idioma.cc $(OPCIONS)

Nodo.o: Nodo.cc Nodo.hh
	g++ -c Nodo.cc $(OPCIONS) 

Treecode.o: Treecode.cc Treecode.hh
	g++ -c Treecode.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
