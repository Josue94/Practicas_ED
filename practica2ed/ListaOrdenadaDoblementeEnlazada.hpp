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


		~ListaOrdenadaDoblementeEnlazada () {}//Destructor

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

		/** @brief Es pos la posición última de la lista?
		* @arg[in] pos es la posición para ser probado.
		* @return True si la posición es la última.
		* @pre la pos es una posición válida de la lista.
		*/
		bool esUltimo(const int pos)
		{
			assert(esValida(pos));

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


		/** @brief Es pos una posición valida de la lista?
		* @return true si pos es una posición valida de la lista
		*/
		bool esValida(int pos)
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


		/** @brief Devolver el item de una determinada posición.
		* @arg[in] pos es una posición de la lista
		* @return una referencia constante al item
		* @pre esValida(pos)
		*/
		const L& devuelveItem(const int pos)
		{
			assert(esValida(pos));
			setActual(getCabeza());

					int nEle=1;

					while(getActual()!=NULL)
					{

						if(pos==nEle)
						{
							return getActual()->getItem();
						}
						else
						{
							setActual(getActual()->getSiguiente());
							nEle++;
						}

					}
					return getActual()->getItem();

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
			assert(esValida(from));
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
				assert(not (retVal==-1) or esValida(retVal));
				assert(not (retVal==-1) or devuelveItem(retVal)==item);
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
			assert(esValida(pos));
			#ifndef NDEBUG
			bool oldIsLast = esUltimo(pos);
			L oldItemNext = L();
			if (not oldIsLast)
			oldItemNext = devuelveItem(pos+1);
			#endif
			goTo(pos);
			NodoDoblementeEnlazado<L> * old = getActual();
			if (getAnterior()==0)
			setCabeza(getActual()->next());
			else
			getAnterior()->setSiguiente(getActual()->getSiguiente());
			delete old;
			#ifndef NDEBUG
			assert(oldIsLast or devuelveItem(pos)==oldItemNext);
			#endif //NDEBUG
		}


};

#endif /* LISTAORDENADADOBLEMENTEENLAZADA_HPP_ */
