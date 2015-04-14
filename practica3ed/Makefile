OBJECTS = main.o generarpersona.o persona.o gestorFichero.o

main: $(OBJECTS)
	g++ -g $(OBJECTS) -o main

main.o: main.cpp edi_LinkedList.hpp edi_LinkedNode.hpp edi_List.hpp asignatura.hpp
	g++ -g -c main.cpp

persona.o: persona.hpp persona.cpp 
	g++ -g -c persona.cpp

generarpersona.o: generarpersona.cpp generarpersona.hpp
	g++ -g -c generarpersona.cpp

gestorFichero.o: gestorFichero.cpp gestorFichero.hpp
	g++ -g -c gestorFichero.cpp

clean: $(OBJECTS)
	rm -f $(OBJECTS)