/*
 * NodoDoblementeEnlazado.hpp
 *
 *  Created on: 16/03/2015
 *      Author: i22feloj
 */

#ifndef NODODOBLEMENTEENLAZADO_HPP_
#define NODODOBLEMENTEENLAZADO_HPP_

#include "ListaOrdenadaDoblementeEnlazada.hpp"

template<class L> class ListaOrdenadaDoblementeEnlazada;


template <class L>

class NodoDoblementeEnlazado
{

	private:
		L item_;
		NodoDoblementeEnlazado<L> *siguiente_;
		NodoDoblementeEnlazado<L> *anterior_;

		friend class ListaOrdenadaDoblementeEnlazada<L>;

	public:

	NodoDoblementeEnlazado (L item, NodoDoblementeEnlazado<L> *sig=NULL, NodoDoblementeEnlazado<L> *ant=NULL) : item_(item),siguiente_(sig),anterior_(ant){}

	L& getItem()
	{
		return item_;
	}

	void setItem(L itemaux)
	{
		item_=itemaux;
	}

	NodoDoblementeEnlazado<L> * getSiguiente()
	{
		return siguiente_;
	}

	void setSiguiente (NodoDoblementeEnlazado<L> *sig)
	{
		siguiente_=sig;
	}

	NodoDoblementeEnlazado<L> * getAnterior()
	{
		return anterior_;
	}


	void setAnterior (NodoDoblementeEnlazado<L> *ant)
	{
		anterior_=ant;
	}


};

#endif /* NODODOBLEMENTEENLAZADO_HPP_ */
