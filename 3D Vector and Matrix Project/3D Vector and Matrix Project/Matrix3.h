#pragma once
/// <summary>
/// @author: Savannah Bolger
/// @student number: C00215747
/// @date: 8/1/2018
/// @approx no hours: 0 hrs
/// </summary>

#include <iostream>
#include "Vector3D.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(double a11, double a12, double a13,
		double a21, double a22, double a23,
		double a31, double a32, double a33);
	Matrix3(Vector3D row1, Vector3D row2, Vector3D row3);
	~Matrix3();

	static Vector3D operator *(Matrix3 M, Vector3D V);
	static Vector3D operator *(Vector3D V, Matrix3 M);
	static Matrix3 transpose(Matrix3 M);
	static Matrix3 operator +(Matrix3 M1, Matrix3 M2);
	static Matrix3 operator -(Matrix3 M1, Matrix3 M2);
	static Matrix3 operator *(double x, Matrix3 M);
	static Matrix3 operator *(Matrix3 M1, Matrix3 M2);

	static double determinant(Matrix3 M);
	static Matrix3 inverse(Matrix3 M);
	Vector3D row(int row);
	Vector3D column(int column);

private:
	double m11;
	double m12;
	double m13;
	double m21;
	double m22;
	double m23;
	double m31;
	double m32;
	double m33;
};
