/*
 * principal.cpp
 *
 *  Created on: 19/03/2015
 *      Author: i22feloj
 */
#include "ListaOrdenadaDoblementeEnlazada.hpp"
#include "NodoDoblementeEnlazado.hpp"
#include "generarpersona.hpp"
#include "persona.hpp"
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
using namespace edi;

ListaOrdenadaDoblementeEnlazada<Persona> crearAsignatura(int numAlumnos);
void mostrarAscendente(ListaOrdenadaDoblementeEnlazada<Persona> asignatura);
void mostrarDescendente(ListaOrdenadaDoblementeEnlazada<Persona> asignatura);

int main()
{
	int N;
	ListaOrdenadaDoblementeEnlazada<Persona> a;
	ListaOrdenadaDoblementeEnlazada<int> b;
	string menu;

	do{
		cout<<endl;
		cout<<"1.Crear asignatura."<<endl;
		cout<<"2.Mostrar listado ascendente."<<endl;
		cout<<"Pulsa 0 para salir."<<endl;
		getline(cin,menu);


		switch(atoi(menu.c_str()))
		{
		case 1:
			cout<<"¿Cuantos usuarios tiene la asignatura?"<<endl;
			cin>>N;
			a=crearAsignatura(N);
			break;

		case 2:
			mostrarAscendente(a);
			break;

		case 3:
			mostrarDescendente(a);
			break;



		}
	}while(menu!="0");

return 0;
}

ListaOrdenadaDoblementeEnlazada<Persona> crearAsignatura(int numAlumnos)
{
	char nomFich[]="personas.txt";
	vector<Persona> aux;
	ListaOrdenadaDoblementeEnlazada<Persona> l;

	aux=generarPersonas(nomFich,numAlumnos);

	for(int i=0; i<numAlumnos;i++)
	{
		l.insertar(aux[i]);

	}

	return l;
}

void mostrarAscendente(ListaOrdenadaDoblementeEnlazada<Persona> asignatura)
{
	asignatura.setActual(asignatura.getCabeza());


		while(asignatura.getActual()!=NULL)
		{
			cout << asignatura.getActual()->getItem().nombre()<<" ";
			cout << asignatura.getActual()->getItem().apellido()<<" ";
			cout << asignatura.getActual()->getItem().dni()<<endl;
			asignatura.setActual(asignatura.getActual()->getSiguiente());
			}
}

void mostrarDescendente(ListaOrdenadaDoblementeEnlazada<Persona> asignatura)
{

	int contador=0;

		while(asignatura.getActual()!=NULL)
		{
			asignatura.setActual(asignatura.getActual()->getSiguiente());
			contador++;
		}
		asignatura.goTo(contador);
		while(asignatura.getActual()!=NULL)
				{
					cout << asignatura.getActual()->getItem().nombre()<<" ";
					cout << asignatura.getActual()->getItem().apellido()<<" ";
					cout << asignatura.getActual()->getItem().dni()<<endl;
					asignatura.setActual(asignatura.getActual()->getAnterior());
					}

}

