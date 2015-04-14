/*
 * ListaOrdenadaDoblementeEnlazada.hpp
 *
 *  Created on: 09/03/2015
 *      Author: i22feloj
 */

#ifndef LISTAORDENADADOBLEMENTEENLAZADA_HPP_
#define LISTAORDENADADOBLEMENTEENLAZADA_HPP_

#include <cassert>
#include <iostream>
using namespace std;

template<class L> class NodoDoblementeEnlazado;

template <class L>

class ListaOrdenadaDoblementeEnlazada
{
	private:

		NodoDoblementeEnlazado<L> *cabeza_;
		NodoDoblementeEnlazado<L> *actual_;

	public:

		ListaOrdenadaDoblementeEnlazada() : cabeza_(NULL),actual_(NULL) {}



		virtual ~ListaOrdenadaDoblementeEnlazada  ()
		{
			flush();
		}

		NodoDoblementeEnlazado<L>* getCabeza() const
		{
			return cabeza_;
		}

		void setCabeza (NodoDoblementeEnlazado<L> *cab)
		{
			cabeza_=cab;
		}

		NodoDoblementeEnlazado<L>* getActual() const
		{
			return actual_;
		}

		void setActual (NodoDoblementeEnlazado<L> *act)
		{
			actual_=act;
		}

		NodoDoblementeEnlazado<L> * getAnterior()
		{
			return actual_->getAnterior();
		}


		void setAnterior (NodoDoblementeEnlazado<L> *ant)
		{
			actual_->setAnterior(ant);
		}

		/** @brief Ir a la posición de una lista dada.
		* Si no existe, en actual_ habrá un puntero nulo.
		*/
		void goTo(const unsigned idx)
		{
			setActual(getCabeza());
			getActual()->setAnterior(0);
			for (unsigned i=0; i<idx and actual_!=0; ++i)
			{
				getActual()->setAnterior(getActual());
							setActual(getActual()->getSiguiente());
			}
		}

		/** @brief Is pos the last list's position?
		* Time analysis: O(n)
		* @arg[in] pos is the position to be tested.
		* @return true if the position is the last.
		* @pre pos is a valid list's position.
		*/
		virtual bool isLast(const int pos) const
		{
			assert(isValid(pos));
			ListaOrdenadaDoblementeEnlazada<L> * _this = const_cast<ListaOrdenadaDoblementeEnlazada<L>*>(this);
			ListaOrdenadaDoblementeEnlazada<L> * savedCurr=_this->getActual();
			ListaOrdenadaDoblementeEnlazada<L> * savedPrev=_this->getAnterior();
			_this->goTo(pos);
			bool retVal=(getActual()->getSiguiente()==NULL);
			_this->setActual(savedCurr);
			_this->setAnterior(savedPrev);
			return retVal;
		}


		/** @brief Is pos a valid List's position?
		* Time analysis: O(N)
		* @return true if pos is a valid list's position.
		*/
		virtual bool isValid (const int pos) const
		{
			ListaOrdenadaDoblementeEnlazada<L> * _this = const_cast<ListaOrdenadaDoblementeEnlazada<L>*>(this);
			ListaOrdenadaDoblementeEnlazada<L> * savedCurr=_this->getActual();
			ListaOrdenadaDoblementeEnlazada<L> * savedPrev=_this->getAnterior();
			_this->goTo(pos);
			bool retVal=(getActual()!=NULL);
			_this->setActual(savedCurr);
			_this->setAnterior(savedPrev);
			return retVal;
		}


		/** @brief Get the item at a given position.
		* Time analysis: O(N)
		* @arg[in] pos is the list's position.
		* @return a const reference to the stored.
		* @pre isValid(pos)
		*/
		virtual const L& item(const int pos) const
		{
			assert(isValid(pos));
			ListaOrdenadaDoblementeEnlazada<L> * _this = const_cast<ListaOrdenadaDoblementeEnlazada<L>*>(this);
			ListaOrdenadaDoblementeEnlazada<L> * savedCurr=_this->getActual();
			ListaOrdenadaDoblementeEnlazada<L> * savedPrev=_this->getAnterior();
			_this->goTo(pos);
			const L& retVal= getActual()->getItem();
			_this->setActual(savedCurr);
			_this->setAnterior(savedPrev);
			return retVal;
		}


		/** @brief devuelve la posición del  ítem  or -1, a partir de from
		* @arg[in] item del que queremos saber la posición.
		* @arg[in] posición a partir de la cual se va a iniciar la búsqueda.
		* @return -1 si no encuentra la posición del item.
		* @pre esValida(from)
		* @post retVal>=0 implica esValida(retVal)
		* @post retVal>=0 implies devuelveItem(retVal)=item
		*/
		int buscaItem(const L item, const int from=0)
		{
			assert(isValid(from));
			int retVal=-1;
			NodoDoblementeEnlazado<L> * _this = const_cast<ListaOrdenadaDoblementeEnlazada<L>*>(this);
			NodoDoblementeEnlazado<L> * savedCurr=_this->current();

			_this->goTo(from);
			for (int i=from; retVal==-1 and getActual()!=0; ++i)
			if (getActual()->getItem() == item)
				retVal = i;
			else
				_this->setActual(_this->getActual()->getSiguiente());
				_this->setActual(savedCurr);
				assert(not (retVal==-1) or isValid(retVal));
				assert(not (retVal==-1) or item(retVal)==item);
				return retVal;
		}

		/* @brief Función que inserta un item en una lista ordenada doblemente enlazada.
		 * @arg[in] Item que va a ser insertado en la lista.
		 */
		void insertar(const L& item)
		{
			NodoDoblementeEnlazado<L> *nuevo;
			NodoDoblementeEnlazado<L> *prev;
			int contador=0;

			//Si la lista está vacía
			if(getCabeza()==NULL)
			{
				setCabeza(new NodoDoblementeEnlazado<L>(item,0,0));
			}
			else
			{
				bool encontrado=false;

				setActual(getCabeza());

				while(getActual() !=NULL and not encontrado)
				{
					if(getActual()->getItem() > item)
					{
						encontrado=true;
					}
					else
					{
						prev=getActual(); //Guardo el anterior
						setActual(getActual()->getSiguiente());
						contador++;
					}
				}

				if(encontrado) //inserta antes de la cabeza
				{
					if (contador==0)
					{
					nuevo=new NodoDoblementeEnlazado<L>(item,getCabeza(),0);
					setCabeza(nuevo);
					getActual()->setAnterior(getCabeza()); //Linko el actual con la nueva cabeza
					}
					else //inserta entre dos elementos
					{

						nuevo=new NodoDoblementeEnlazado<L>(item,getActual(),getActual()->getAnterior());
						//Linkamos el anterior con el nuevo nodo
						getAnterior()->setSiguiente(nuevo);
						getActual()->setAnterior(nuevo);
					}

				}
				else //inserta después del último
				{
					nuevo=new NodoDoblementeEnlazado<L>(item,0,prev);
					prev->setSiguiente(nuevo);//Linko el ultimo con el nuevo nodo

				}

			}
		}//Fin de la funcion insertar

		void deletePosition(const int pos)
		{
			assert(isValid(pos));
			#ifndef NDEBUG
			bool oldIsLast = isLast(pos);
			L oldItemNext = L();
			if (not oldIsLast)
			oldItemNext = item(pos+1);
			#endif
			goTo(pos);
			NodoDoblementeEnlazado<L> * old = getActual();
			if (getAnterior()==0)
			setCabeza(getActual()->next());
			else
			getAnterior()->setSiguiente(getActual()->getSiguiente());
			delete old;
			#ifndef NDEBUG
			assert(oldIsLast or item(pos)==oldItemNext);
			#endif //NDEBUG
		}


		/** @brief Deallocate the list.*/
		void flush ()
		{
			setActual(getCabeza());
			while(getActual()!=NULL)
			{
			setAnterior(getActual());
			setActual(getActual()->getSiguiente());
			delete getAnterior();
			}
			setCabeza(0);
		}

};

#endif /* LISTAORDENADADOBLEMENTEENLAZADA_HPP_ */
