#include "MyMatrix3.h"

/// <summary>
/// @author: Savannah Bolger
/// @date: Dec 2016
/// @student number: C00215747
///
/// time taken: 9 hours
/// no known issues
/// </summary>

///<summary>
///constructor default
///</summary>
MyMatrix3::MyMatrix3():
	m11{ 0.0 },
	m12{ 0.0 },
	m13{ 0.0 },
	m21{ 0.0 },
	m22{ 0.0 },
	m23{ 0.0 },
	m31{ 0.0 },
	m32{ 0.0 },
	m33{ 0.0 }
{
}

///<summary>
///constructor for matrix
///</summary>
MyMatrix3::MyMatrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) :
	m11{ a11 },
	m12{ a12 },
	m13{ a13 },
	m21{ a21 },
	m22{ a22 },
	m23{ a23 },
	m31{ a31 },
	m32{ a32 },
	m33{ a33 }
{
}

///<summary>
///constructor for matrix rows
///</summary>
MyMatrix3::MyMatrix3(MyVector3D row1, MyVector3D row2, MyVector3D row3) :
	m11{ row1.X() },
	m12{ row1.Y() },
	m13{ row1.Z() },
	m21{ row2.X() },
	m22{ row2.Y() },
	m23{ row2.Z() },
	m31{ row3.X() },
	m32{ row3.Y() },
	m33{ row3.Z() }
{
}

///<summary>
///deconstructor default
///</summary>
MyMatrix3::~MyMatrix3()
{
}

///<summary>
///construct the matrix output using std::string
///</summary>
std::string MyMatrix3::toString()
{
	char tmpbuf[512];
	sprintf_s(tmpbuf, "{ [ %g, %g, %g ] [ %g, %g, %g ] [ %g, %g, %g ] }", m11, m12, m13, m21, m22, m23, m31, m32, m33);
	return tmpbuf;

	
}

///<summary>
///constructor for adding two matrices 
///</summary>
MyMatrix3 MyMatrix3::operator+(const MyMatrix3 other) const
{
	return MyMatrix3(m11 + other.m11, m12 + other.m12, m13 + other.m13,
					 m21 + other.m21, m22 + other.m22, m23 + other.m23,
					 m31 + other.m31, m32 + other.m32, m33 + other.m33);
}

///<summary>
///constructor for subtracting two matrices 
///</summary>
MyMatrix3 MyMatrix3::operator-(const MyMatrix3 other) const
{
	return MyMatrix3(m11 - other.m11, m12 - other.m12, m13 - other.m13,
					 m21 - other.m21, m22 - other.m22, m23 - other.m23,
					 m31 - other.m31, m32 - other.m32, m33 - other.m33);
}

///<summary>
///constructor for multiplying two matrices 
///</summary>
MyMatrix3 MyMatrix3::operator*(const MyMatrix3 other) const
{
	return MyMatrix3(m11 * other.m11 + m12 * other.m21 + m13 * other.m31, m11 * other.m12 + m12 * other.m22 + m13 * other.m32, m11 * other.m13 + m12 * other.m23 + m13 * other.m33,
					 m21 * other.m11 + m22 * other.m21 + m23 * other.m31, m21 * other.m12 + m22 * other.m22 + m23 * other.m32, m21 * other.m13 + m22 * other.m23 + m23 * other.m33,
					 m31 * other.m11 + m32 * other.m21 + m33 * other.m31, m31 * other.m12 + m32 * other.m22 + m33 * other.m32, m31 * other.m13 + m32 * other.m23 + m33 * other.m33 );
}

///<summary>
///constructor for multiplying a matrix and a vector
///</summary>
MyVector3D MyMatrix3::operator*(const MyVector3D vector) const
{
	return MyVector3D(m11 * vector.X() + m12 * vector.Y() + m13 * vector.Z(),
					  m21 * vector.X() + m22 * vector.Y() + m23 * vector.Z(),
					  m31 * vector.X() + m32 * vector.Y() + m33 * vector.Z());
}

///<summary>
///constructor for multiplying a matrix and a scale
///</summary>
MyMatrix3 MyMatrix3::operator*(const double scale) const
{
	return MyMatrix3(m11 * scale, m12 * scale, m13 * scale,
					 m21 * scale, m22 * scale, m23 * scale,
					 m31 * scale, m32 * scale, m33 * scale);
}

///<summary>
///constructor for getting the transpose of a matrix
///</summary>
MyMatrix3 MyMatrix3::transpose() const
{
	return MyMatrix3(m11, m21, m31,
					 m12, m22, m32,
					 m13, m23, m33);
}

///<summary>
///constructor for getting the determinant of a matrix
///</summary>
double MyMatrix3::determinant() const
{
	return (m11 * (m22 * m33 - m32 * m23) - m21 * (m33 * m12 - m32 * m13) + m31 * (m23 * m12 - m22 * m13));
}

///<summary>
///constructor for getting the inverse of a matrix
///</summary>
MyMatrix3 MyMatrix3::inverse() const
{ 
	return MyMatrix3(m33 * m22 - m32 * m23, m32 * m13 - m33 * m12, m23 * m12 - m22 * m13,
					 m31 * m23 - m33 * m21, m33 * m11 - m31 * m13, m21 * m13 - m23 * m11,
					 m32 * m21 - m31 * m22, m31 * m12 - m32 * m11, m22 * m11 - m21 * m12);
}

///<summary>
///constructor for getting a row of a matrix
///</summary>
MyVector3D MyMatrix3::row(int row) const
{
	switch (row)
	{
	case 1:
		return MyVector3D(m11,m12,m13);
	case 2:
		return MyVector3D(m21, m22, m23);
	case 3:
		return MyVector3D(m31, m32, m33);
	}
	return MyVector3D();
}

///<summary>
///constructor for getting a column of a matrix
///</summary>
MyVector3D MyMatrix3::column(int column) const
{
	switch (column)
	{
	case 1:
		return MyVector3D(m11, m21, m31);
	case 2:
		return MyVector3D(m12, m22, m32);
	case 3:
		return MyVector3D(m13, m23, m33);
	}
	return MyVector3D();
}

///<summary>
///constructor for if two matrices are equal
///</summary>
bool MyMatrix3::operator==(const MyMatrix3 other) const
{
	return (m11 == other.m11 && m12 == other.m12 && m13 == other.m13 &&
			m21 == other.m21 && m22 == other.m22 && m23 == other.m23 &&
			m31 == other.m31 && m32 == other.m32 && m33 == other.m33);
}

///<summary>
///constructor for if two matrices are not equal
///</summary>
bool MyMatrix3::operator!=(const MyMatrix3 other) const
{
	return (m11 != other.m11 || m12 != other.m12 || m13 != other.m13 ||
			m21 != other.m21 || m22 != other.m22 || m23 != other.m23 ||
			m31 != other.m31 || m32 != other.m32 || m33 != other.m33);
}

///<summary>
///constructor for rotation of the z axis in a matrix
///</summary>
MyMatrix3 MyMatrix3::rotationZ(double angleRadians)
{
	return MyMatrix3(cos(angleRadians), -sin(angleRadians), 0,
					 sin(angleRadians), cos(angleRadians), 0,
					 0 , 0 , 1);
}

///<summary>
///constructor for rotation of the y axis in a matrix
///</summary>
MyMatrix3 MyMatrix3::rotationY(double angleRadians)
{
	return MyMatrix3(cos(angleRadians), 0, sin(angleRadians), 
					 0, 1, 0,
					-sin(angleRadians), 0, cos(angleRadians) );
}

///<summary>
///constructor for rotation of the x axis in a matrix
///</summary>
MyMatrix3 MyMatrix3::rotationX(double angleRadians)
{
	return MyMatrix3(1, 0, 0,
					 0, cos(angleRadians), -sin(angleRadians),
					 0, sin(angleRadians), cos(angleRadians) );
}

///<summary>
///constructor for the translation of a matrix
///</summary>
MyMatrix3 MyMatrix3::translation(MyVector3D displacement)
{
	return MyMatrix3(1, 0, displacement.X(),
					 0, 1, displacement.Y(),
					 0, 0, 1);
}

///<summary>
///constructor for the scaling of a matrix
///</summary>
MyMatrix3 MyMatrix3::scale(double scalingfactor)
{
	return MyMatrix3(scalingfactor, 0, 0,
					 0, scalingfactor, 0,
					 0, 0, scalingfactor);
}
