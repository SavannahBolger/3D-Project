#include "Vector3D.h"

Vector3D::Vector3D() :
	m_x{ 0.0f },
	m_y{ 0.0f },
	m_z{ 0.0f }
{
}

Vector3D::Vector3D(double x, double y, double z) :
	m_x{ x },
	m_y{ y },
	m_z{ z }
{
}

Vector3D::~Vector3D()
{
}

double Vector3D::X()
{
	return m_x;
}

double Vector3D::Y()
{
	return m_y;
}

double Vector3D::Z()
{
	return m_z;
}

double Vector3D::length() 
{
	return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double Vector3D::lengthSquared() 
{
	return (m_x * m_x + m_y * m_y + m_z * m_z);
}

void Vector3D::normalise()
{
	if (length() > 0.0f)
	{
		double originalLength = length();
		m_x /= originalLength;
		m_y /= originalLength;
		m_z /= originalLength;
	}
}

Vector3D Vector3D::operator+(Vector3D v1, Vector3D v2)
{
	return Vector3D(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z);
}

Vector3D Vector3D::operator-(Vector3D v1, Vector3D v2)
{
	return Vector3D(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z);
}

Vector3D Vector3D::operator-(Vector3D v)
{
	Vector3D V1 = Vector3D();
	V1.m_x = -v.m_x;
	V1.m_y = -v.m_y;
	V1.m_z = -v.m_z;
	return V1;
}

double Vector3D::operator*(Vector3D v1, Vector3D v2)
{
	return (v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z);
}

Vector3D Vector3D::operator*(double k, Vector3D v)
{
	return Vector3D(v.m_x * k, v.m_y * k, v.m_z * k);
}

Vector3D Vector3D::operator*(float k, Vector3D v)
{
	return Vector3D(v.m_x * k, v.m_y * k, v.m_z * k);
}

Vector3D Vector3D::operator*(int k, Vector3D v)
{
	return Vector3D(v.m_x * k, v.m_y * k, v.m_z * k);
}

Vector3D Vector3D::operator^(Vector3D v1, Vector3D v2)
{
	return Vector3D(v1.m_y * v2.m_z - v1.m_z * v2.m_y, v1.m_z * v2.m_x - v1.m_x * v2.m_z, v1.m_x * v2.m_y - v1.m_y * v2.m_x);
}

std::string Vector3D::ToString()
{
	return std::string();
}

