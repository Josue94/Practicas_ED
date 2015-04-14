/**
@file main.cpp
@author Ruben
@date 07/04/2015
@brief Main which executes functions about a subject as list.
*/

#include "edi_LinkedNode.hpp"
#include "edi_List.hpp"
#include "edi_LinkedList.hpp"
#include "edi_exports.hpp"
#include "gestorFichero.hpp"
#include "generarpersona.hpp"
#include "asignatura.hpp"
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>




using namespace edi;
using namespace std;

int main(){

	int nAlumnos;
	string fichero="personas.txt";
	string ficheroCopia;
	int menu=1;
	Persona p1, p2;
	string nombre, apellido;
	int dni;
	int opcion;

	LinkedList<Persona> auxlist;

	cout<<"Creando lista de alumnos..."<<endl;
	cout<<"Introduce el numero de alumnos: ";
	cin>>nAlumnos;
	getchar();
	cout<<"Introduce el nombre del fichero: ";
	getline(cin, fichero);

	Asignatura edi(nAlumnos);
	edi.cargarLista( generarPersonas(fichero.c_str(), nAlumnos));

	while(menu!=0){
		cout<<"Lista de alumnos:"<<endl;
		cout<<"\t1) Mostrar lista orden ascendente."<<endl;
		cout<<"\t2) Mostrar lista orden descendente."<<endl;
		cout<<"\t3) Listar alumnos entre dos alumnos."<<endl;
		cout<<"\t4) Modificar alumno."<<endl;
		cout<<"\t5) Guardar lista"<<endl;
		cout<<"\t6) Cargar lista"<<endl;
		cout<<"\t0) SALIR"<<endl;
		cout<<"Opción: ";
		cin>>menu;

		switch(menu){

			case 1:		cout<<"Lista ascendente de alumnos:"<<endl;
						cout<<"============================"<<endl;
						edi.imprimirAscendente();
						break;

			case 2:		cout<<"Lista descendente de alumnos:"<<endl;
						cout<<"============================"<<endl;
						edi.imprimirDescendente();
						break;

			case 3:			cout<<"¿Que desea? Ascendente o descendente (1/2): ";
							cin>>opcion;
							
							cout<<"Primer alumno"<<endl;
							getchar();
							cin>>p1;
							cout<<"Segundo alumno"<<endl;
							getchar();
							cin>>p2;

							if(opcion==2){
								edi.listarEntreDosDescendente(p1,p2);
							}else{
								edi.listarEntreDosAscendente(p1,p2);
							}



						break;

			case 4:		cout<<"Alumno para modificar"<<endl;
						getchar();
						cin>>p1;
						cout<<"Alumno con datos nuevos"<<endl;
						getchar();
						cin>>p2;

						edi.modificarAlumno(p1,p2);
						break;

			case 5:	getchar();
					cout<<"Introduce nombre fichero para guardar: ";   
					getline(cin, ficheroCopia);
					guardarLista(edi.getLista(), ficheroCopia.c_str());
					break;

			case 6:	getchar();
					cout<<"Introduce nombre fichero para cargar: ";   
					getline(cin, ficheroCopia);
					auxlist=edi.getLista();
					edi.setNumeroAlumnos( cargarLista(auxlist, ficheroCopia.c_str()) );
					edi.setLista(auxlist);
					break;

			case 0:     getchar();
				cout<<"Pulse cualquier tecla para cerrar..."<<endl;
						getchar();
						break;

			default:	cout<<"Opcion incorrecta"<<endl;
						break;
		}
	}


	



	return 0;
}
