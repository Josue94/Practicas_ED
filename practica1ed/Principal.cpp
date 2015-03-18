/*
 * Principal.cpp
 *
 *  Created on: 23/02/2015
 *      Author: i22feloj
 */


#include "Punto2D.hpp"
#include "Recta2D.hpp"
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void cargarContorno(vector<Punto2D> &contorno, char *ficheroContorno);
void cargarAproximacionPoligonal (vector<int> &aproximacionPoligonal, char *ficheroAproximacionPoligonal);
double calcularError(const vector<Punto2D> &contorno, const vector<int> &aproximacionPoligonal);

int main()
{
	vector<Punto2D> v;
	vector<int> v2(21);
	vector<Punto2D>::iterator ip;
	//int i;
	//int tam;
	double error=0;
	cargarContorno(v,(char*)"abrelatas.txt");
	cargarAproximacionPoligonal(v2,(char*)"aproximacion.txt");
	error=calcularError(v,v2);

	cout <<"Error: "<<error;


	/*
	tam=v2.size();

	for(i=0;i<tam;i++)
	{
		cout <<"X: " <<v2[i]<<endl;

	}
*/

	return 0;
}

void cargarContorno(vector<Punto2D> &contorno, char *ficheroContorno)
{
	Punto2D p(0.0,0.0);
	char x[5],y[5];

	ifstream fichero(ficheroContorno);

	while(fichero.getline(x,256,' '))
	{
		fichero.getline(y,256,'\n');
		p.setX(atof(x));
		p.setY(atof(y));

		contorno.push_back(p);

	}

	fichero.close();
}

void cargarAproximacionPoligonal (vector<int> &aproximacionPoligonal, char *ficheroAproximacionPoligonal)
{
	Punto2D p(0.0,0.0);
		char punto[5];
		int i=0;
		ifstream fichero(ficheroAproximacionPoligonal);

		while(fichero.getline(punto,256,'\n'))
		{
			aproximacionPoligonal[i]=atoi(punto);
			i++;

		}

}

double calcularError(const vector<Punto2D> &contorno, const vector<int> &aproximacionPoligonal)
{
	double error=0;

	vector<Punto2D>::const_iterator Punto2D_it,Punto2D_it_begin,Punto2D_it_end;
	vector<int>::const_iterator aproximacion_it;

	//Recorremos los puntos que se encuentran en el intervalo de la recta aproximada
	for(aproximacion_it=aproximacionPoligonal.begin(); aproximacion_it != aproximacionPoligonal.end()-1;aproximacion_it++)
	{
		//Establecemos los extremos de la recta aproximada
		Punto2D_it_begin= contorno.begin() + *aproximacion_it;
		Punto2D_it_end=contorno.begin() + *(aproximacion_it +1);

		for(Punto2D_it=Punto2D_it_begin; Punto2D_it != Punto2D_it_end; Punto2D_it++)
		{
			if(Punto2D_it == contorno.end())
				break;
			Recta2D r(*Punto2D_it_begin, *Punto2D_it_end);
			error += pow(r.distancia(*Punto2D_it),2);
		}
	}

	for(Punto2D_it=contorno.begin(); Punto2D_it != contorno.begin()+ *(aproximacion_it); Punto2D_it++)
	{
		if(Punto2D_it == contorno.end())
			break;
		Recta2D r(*Punto2D_it_begin, *Punto2D_it_end);
		error += pow(r.distancia(*Punto2D_it),2);
	}

	return error;

}


