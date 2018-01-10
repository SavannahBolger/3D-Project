#pragma once
/// <summary>
/// @author: Savannah Bolger
/// @student number: C00215747
/// @date: 8/1/2018
/// @approx no hours: 0 hrs
/// </summary>

#include <iostream>

class Vector3D
{
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	~Vector3D();

	double length()const;
	double lengthSquared()const;
	double angleBetween(const Vector3D other)const;
	Vector3D unit() const;
	void normalise();

private:
	double m_x;
	double m_y;
	double m_z;
};
