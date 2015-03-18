/*
 * Recta2D.hpp
 *
 *  Created on: 16/02/2015
 *      Author: i22feloj
 */

#ifndef RECTA2D_HPP_
#define RECTA2D_HPP_

#include "Punto2D.hpp"
#include <cmath>

class Recta2D : public Punto2D
{

	private:

	  float a_;
	  float b_;
	  float c_;


	public:

	Recta2D (float a, float b, float c)
	{
		a_=a;
		b_=b;
		c_=c;
	}

	Recta2D (Punto2D p, Punto2D q)
	{
        a_=q.getY() - p.getY();
		b_=p.getX() - q.getX();
		c_= q.getX()*p.getY() - p.getX()*q.getY();
	}


	float getA()
	{
		return a_;
	}

	float getB()
	{
		return b_;
	}

	float getC()
	{
		return c_;
	}

	float distancia (Punto2D p)
	{
		float d;
		d=abs( getA()*p.getX() + getB()*p.getY() + getC()) / sqrt( (pow(getA(),2) + pow(getB(),2)) );
		return d;
	}




	void setA (float a)
	{
		a_=a;
	}

	void setB (float b)
	{
		b_=b;
	}

	void setC (float c)
	{
		c_=c;
	}




};


#endif /* RECTA2D_HPP_ */
