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

		ListaOrdenadaDoblementeEnlazada() : cabeza_(NULL),actual_(NULL) {}


		~ListaOrdenadaDoblementeEnlazada () {}//Destructor

		NodoDoblementeEnlazado<L>* getCabeza()
		{
			return cabeza_;
		}

		void setCabeza (NodoDoblementeEnlazado<L> *cab)
		{
			cabeza_=cab;
		}


		NodoDoblementeEnlazado<L>* getActual()
		{
			return actual_;
		}


		void setActual (NodoDoblementeEnlazado<L> *act)
		{
			actual_=act;
		}

		NodoDoblementeEnlazado<L>* getAnterior()
		{
					return actual_->getAnterior();
		}


		void setAnterior (NodoDoblementeEnlazado<L> *act)
		{
			actual_=setAnterior(act);
		}



		bool esUltimo(int pos)
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

		const L& devuelveItem(const int pos)
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
					return NULL;

		}




		int buscaItem(L item, int from);

		void insertar(L item)
		{
			NodoDoblementeEnlazado<L> *nuevo;
			bool encontrado=false;
			int contador=0;

			//Si la lista está vacía
			if(getCabeza()==NULL)
			{
				nuevo=new NodoDoblementeEnlazado<L>(item,NULL,NULL);
				setCabeza(nuevo);
			}
			else
			{
				setActual(getCabeza());

				while(getActual() !=0 and not encontrado)
				{
					if(getActual()->getItem()>item)
					{
						encontrado=true;
					}
					else
					{
						setActual(getActual()->getSiguiente());
						contador++;
					}//fin else
				}//fin del while


				if(encontrado)
				{

					if(contador==0)
					{
						nuevo=new NodoDoblementeEnlazado<L>(item,getActual(),NULL);
						setCabeza(nuevo);
						getActual()->setAnterior(getCabeza());
					}
					else
					{
						nuevo=new NodoDoblementeEnlazado<L>(item,getActual(),getActual()->getAnterior());

						getAnterior()->setSiguiente(nuevo);
						getActual()->setAnterior(nuevo);
					}
				}
				else
				{
					nuevo=new NodoDoblementeEnlazado<L>(item,NULL,getActual());
					getActual()->setSiguiente(nuevo);
				}





			}



		}


		void borraPosicion (int pos);

};

#endif /* LISTAORDENADADOBLEMENTEENLAZADA_HPP_ */
