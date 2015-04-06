/*
 * ListaOrdenadaDoblementeEnlazada.hpp
 *
 *  Created on: 09/03/2015
 *      Author: i22feloj
 */

#ifndef LISTAORDENADADOBLEMENTEENLAZADA_HPP_
#define LISTAORDENADADOBLEMENTEENLAZADA_HPP_


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
		/*
		NodoDoblementeEnlazado<L>* getAnterior()
		{
					return actual_->getAnterior();
		}


		void setAnterior (NodoDoblementeEnlazado<L> *act)
		{
			actual_=setAnterior(act);
		}
		*/


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
			NodoDoblementeEnlazado<L> *prev;//NULL;
			bool encontrado=false;


			//Si la lista está vacía
			if(getCabeza()==NULL)
			{

				setCabeza(new NodoDoblementeEnlazado<L>(item,NULL,NULL));

			}
			else
			{
				setActual(getCabeza());

				while(getActual() !=NULL and not encontrado)
				{
					if(getActual()->getItem() > item)
					{
						encontrado=true;
					}
					else
					{
						prev=getActual();
						setActual(getActual()->getSiguiente());

					}//fin else

				}//fin del while

				//cout<<"sigo"<<endl;
				if(not prev) //inserta antes de la cabeza
				{
					cout<<"he entrado"<<endl;

						setCabeza(new NodoDoblementeEnlazado<L>(item,getActual(),NULL));
						getActual()->setAnterior(getCabeza()); //Linko el actual con la nueva cabeza
				}
				else if (not getActual()) //inserta después del último
				{
						cout<<"he entrado2"<<endl;

						prev->setSiguiente(new NodoDoblementeEnlazado<L>(item,NULL,prev));//Linko el ultimo con el nuevo nodo
						//prev->getSiguiente()->setAnterior(prev);//Linko el último con el último viejo
				}
				else //Inserta entre dos elementos
				{
					cout<<"he entrado3"<<endl;


					nuevo=new NodoDoblementeEnlazado<L>(item,getActual(),getActual()->getAnterior());
					//Linkamos el anterior con el nuevo nodo
					getActual()->getAnterior()->setSiguiente(nuevo);


				}





			}



		}


		void borraPosicion (int pos);

};

#endif /* LISTAORDENADADOBLEMENTEENLAZADA_HPP_ */
