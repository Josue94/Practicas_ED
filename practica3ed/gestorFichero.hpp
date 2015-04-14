/*
 * gestorFichero.hpp
 *
 *  Created on: 13/04/2015
 *      Author: i22feloj
 */

#ifndef GESTORFICHERO_HPP_
#define GESTORFICHERO_HPP_

#include "ListaOrdenadaDoblementeEnlazada.hpp"
#include "persona.hpp"

using namespace edi;

void guardarLista(const ListaOrdenadaDoblementeEnlazada<Persona> &l, const char * nomFich)
{
	ofstream f;
	f.open(nomFich);
	Persona alumno;
	if(f.is_open())
	{

		for(int i=0; l.isValid(i); ++i)
		{
			if(l.isValid(i))
			{
				alumno=l.item(i);
				f<<alumno;
			}
		}
	}

	f.close();
}

void cargarLista(ListaOrdenadaDoblementeEnlazada<Persona> &l, const char * nomFich)
{
	ifstream f;
	f.open(nomFich);

	Persona alumno;

	while(f>>alumno)
	{
		l.insertar(alumno);
	}

}



#endif /* GESTORFICHERO_HPP_ */
