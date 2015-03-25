/*
 * principal.cpp
 *
 *  Created on: 19/03/2015
 *      Author: i22feloj
 */
#include "ListaOrdenadaDoblementeEnlazada.hpp"
#include "NodoDoblementeEnlazado.hpp"

#include <iostream>
using namespace std;

//template<class L> class ListaOrdenadaDoblementeEnlazada;
//template<class L> class NodoDoblementeEnlazado;

int main()
{
	ListaOrdenadaDoblementeEnlazada<int> l;

	l.insertar(5);


	cout <<l.getCabeza()->getItem()<<endl;

	return 0;
}





