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



int main()
{
	ListaOrdenadaDoblementeEnlazada<int> l;

	l.insertar(6);



	cout <<l.getCabeza()->getItem()<<endl;
	l.insertar(9);
	cout <<l.getCabeza()->getItem()<<endl;


	cout<<l.getCabeza()->getSiguiente()->getItem()<<endl;
	//cout<<l.getCabeza()->getSiguiente()->getAnterior()->getItem()<<endl;


	l.insertar(12);
	cout <<l.getCabeza()->getItem()<<endl;
	cout<<l.getCabeza()->getSiguiente()->getItem()<<endl;
	cout<<l.getCabeza()->getSiguiente()->getSiguiente()->getItem()<<endl;

	l.insertar(10);
	cout <<l.getCabeza()->getItem()<<endl;
	cout<<l.getCabeza()->getSiguiente()->getItem()<<endl;
	cout<<l.getCabeza()->getSiguiente()->getSiguiente()->getAnterior()->getItem()<<endl;//tiene que dar 9
	cout<<l.getCabeza()->getSiguiente()->getSiguiente()->getSiguiente()->getItem()<<endl;
/*
	l.insertar(20);
	cout <<l.getCabeza()->getItem()<<endl;
		cout<<l.getCabeza()->getSiguiente()->getItem()<<endl;
		cout<<l.getCabeza()->getSiguiente()->getSiguiente()->getItem()<<endl;
		cout<<l.getCabeza()->getSiguiente()->getSiguiente()->getSiguiente()->getItem()<<endl;
		cout<<l.getCabeza()->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente()<<endl;

*/
	return 0;
}





