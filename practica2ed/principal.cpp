/*
 * principal.cpp
 *
 *  Created on: 19/03/2015
 *      Author: i22feloj
 */
#include "ListaOrdenadaDoblementeEnlazada.hpp"
#include "NodoDoblementeEnlazado.hpp"
#include "Asignatura.hpp"
#include "generarpersona.hpp"
#include "persona.hpp"
#include <vector>


#include <iostream>
using namespace std;
using namespace edi;

ListaOrdenadaDoblementeEnlazada<Persona> crearAsignatura(int numAlumnos);
void Mostrar(ListaOrdenadaDoblementeEnlazada<Persona> asignatura);

int main()
{
	int N;
	ListaOrdenadaDoblementeEnlazada<Persona> a;


	cout<<"¿Cuantos usuarios tiene la asignatura?"<<endl;
	cin>>N;


	a=crearAsignatura(N);

	Mostrar(a);
}

ListaOrdenadaDoblementeEnlazada<Persona> crearAsignatura(int numAlumnos)
{
	char nomFich[]="personas.txt";
	vector<Persona> aux;
	ListaOrdenadaDoblementeEnlazada<Persona> l;

	aux=generarPersonas(nomFich,numAlumnos);
	cout<<"sigue"<<endl;
	for(int i=0; i<numAlumnos;i++)
	{
		l.insertar(aux[i]);
		cout<<"entra "<<i <<endl;
	}

	return l;
}

void Mostrar(ListaOrdenadaDoblementeEnlazada<Persona> asignatura)
{
	asignatura.setActual(asignatura.getCabeza());
	for(int i=0;asignatura.esValida(i);i++)
	{
		cout << asignatura.getActual()<<endl;
		asignatura.setActual(asignatura.getActual()->getSiguiente());

	}
}


