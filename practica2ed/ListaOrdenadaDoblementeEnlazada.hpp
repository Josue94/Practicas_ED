/*
 * ListaOrdenadaDoblementeEnlazada.hpp
 *
 *  Created on: 09/03/2015
 *      Author: i22feloj
 */

#ifndef LISTAORDENADADOBLEMENTEENLAZADA_HPP_
#define LISTAORDENADADOBLEMENTEENLAZADA_HPP_


#include <iostream>

template<class L> class NodoDoblementeEnlazado;

template <class L>

class ListaOrdenadaDoblementeEnlazada
{
	private:

		NodoDoblementeEnlazado<L> *cabeza_;
		NodoDoblementeEnlazado<L> *actual_;

	public:

		ListaOrdenadaDoblementeEnlazada() : cabeza_(NULL),actual_(NULL) {};


		~ListaOrdenadaDoblementeEnlazada () {} ; //Destructor

		NodoDoblementeEnlazado<L> getCabeza()
		{
			return cabeza_;
		}

		void setCabeza (NodoDoblementeEnlazado<L> *cab)
		{
			cabeza_=cab;
		}


		NodoDoblementeEnlazado<L> getActual()
		{
			return actual_;
		}

		void setActual (NodoDoblementeEnlazado<L> *act)
		{
			actual_=act;
		}

		bool esUltimo(int pos);

		bool esValida(int pos);

		const L& item(const int pos);

		int buscaItem(L item, int from);

		void inserta(L item);

		void borraPosicion (int pos);

};

#endif /* LISTAORDENADADOBLEMENTEENLAZADA_HPP_ */
