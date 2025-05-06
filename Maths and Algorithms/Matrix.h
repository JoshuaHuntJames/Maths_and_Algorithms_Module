#pragma once
#include "Vector.h"


class Matrix
{
public:
	//this is a 3 x 3

	float Data[3][3] ;

	float Determinate();

	void SetRotateAroundX(float Angle);
	void SetRotateAroundY(float Angle);
	void SetRotateAroundZ(float Angle);

	Matrix operator* (Matrix& RHS)
	{
		Matrix& LHS = *this;

		//fill this in to multiply Matrix LHS by Matrix RHS

		return LHS;
	}
	Vector operator* (Vector& RHS)
	{
		Matrix& LHS = *this;

		//fill this in to multiply Matrix LHS by Vector RHS
		return Vector(0, 0, 0);
	}

	void Translate(Vector delta);
	void SetMatrix(int[3][3]);
};

