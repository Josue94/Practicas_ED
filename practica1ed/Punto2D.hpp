/*
 * Punto2D.hpp
 *
 *  Created on: 16/02/2015
 *      Author: i22feloj
 */

#ifndef PUNTO2D_HPP_
#define PUNTO2D_HPP_

#include <iostream>

using namespace std;

class Punto2D {

private:
	float x_;
	float y_;

public:

	Punto2D (float x, float y)
	{
		x_=x;
		y_=y;
	}
	Punto2D(){}
	float getX() const
	{
		return x_;
	}

	float getY() const
	{
		return y_;
	}

	void setX(float x)
	{
		x_=x;
	}

	void setY(float y)
	{
		y_=y;
	}


	bool sonIguales (Punto2D p)
	{
		if (getX()==p.getX() && getY()==p.getY())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};


#endif /* PUNTO2D_HPP_ */
