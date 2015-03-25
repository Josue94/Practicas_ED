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

	setActual(getCabeza());

	int nEle=0;

	while(getActual()!=NULL)
	{
		setActual(getActual()->getSiguiente());
		nEle++;
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
//fin funcion esUltimo

//Funcion esValida
template <class L>

bool ListaOrdenadaDoblementeEnlazada<L>::esValida(int pos)
{
	setActual(getCabeza());

		int nEle=0;

		while(getActual()!=NULL)
		{
			setActual(getActual()->getSiguiente());
			nEle++;
		}

		if(pos==nEle || pos<nEle)
		{
			return true;
		}
		else
		{
			return false;
		}


}
template <class L>

const L& ListaOrdenadaDoblementeEnlazada<L>:: devuelveItem(const int pos)
{
		getActual()=getCabeza();

			int nEle=0;

			while(getActual()!=NULL)
			{
				setActual(getActual()->getSiguiente());

				if(pos==nEle)
				{
					return getActual()->getItem();
				}

				nEle++;
			}

}

template <class L>
void ListaOrdenadaDoblementeEnlazada<L>::insertar(L item)
{
	NodoDoblementeEnlazado<L> *nuevo;
	ListaOrdenadaDoblementeEnlazada<L> l;

	//Si la lista está vacía
	if(l.getCabeza()==NULL)
	{
		nuevo=new NodoDoblementeEnlazado<L>(item,NULL,NULL);
		l.setCabeza(nuevo);
	}
	else
	{
		setActual(getCabeza());
		bool insertado=false;

		while(insertado!=true)
		{

			//Insertar delante de la cabeza
			if(item < getActual()->getItem())
			{
				nuevo=new NodoDoblementeEnlazado<L>(item,getActual(),NULL);
				setCabeza(nuevo);
				insertado=true;
			}

			//Insertar entre medias
			if(item > getActual()->getItem() && getActual()->getSiguiente()!=0)
			{
				while(getActual()->getSiguiente()->getItem() <= item)
				{
					setActual(getActual()->getSiguiente());
				}

				nuevo=new NodoDoblementeEnlazado<L>(item,getActual()->getSiguiente(),getActual());
				getActual()->getSiguiente()=nuevo;
			}


		}
	}
}
