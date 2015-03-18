/*
 * ListaOrdenadaDoblementeEnlazada.cpp
 *
 *  Created on: 16/03/2015
 *      Author: i22feloj
 */


#include "ListaOrdenadaDoblementeEnlazada.hpp"

template <class L>

bool ListaOrdenadaDoblementeEnlazada<L>::esUltimo(int pos)
{
	ListaOrdenadaDoblementeEnlazada<L> l;

	l.getActual()=l.getCabeza();

	int nEle=0;

	while(l.getActual()!=NULL)
	{
		nEle++;
		l.setActual(getActual()->getSiguiente());
	}

	if(pos==nEle)
	{
		return true;
	}
	else
	{
		return false;
	}

	return true;
}


