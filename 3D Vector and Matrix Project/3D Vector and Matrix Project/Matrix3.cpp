#include "Matrix3.h"

Matrix3::Matrix3() :
	m11{ 0.0f },
	m12{ 0.0f },
	m13{ 0.0f },
	m21{ 0.0f },
	m22{ 0.0f },
	m23{ 0.0f },
	m31{ 0.0f },
	m32{ 0.0f },
	m33{ 0.0f }
{
}

Matrix3::Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) :
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

Matrix3::Matrix3(Vector3D row1, Vector3D row2, Vector3D row3) :
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

Matrix3::~Matrix3()
{
}

Vector3D Matrix3::operator*(Matrix3 M, Vector3D V)
{
	return Vector3D(M.m11 * V.X() + M.m12 * V.Y() + M.m13 * V.Z(),
		            M.m21 * V.X() + M.m22 * V.Y() + M.m23 * V.Z(),
		            M.m31 * V.X() + M.m32 * V.Y() + M.m33 * V.Z());
}

Vector3D Matrix3::operator*(Vector3D V, Matrix3 M)
{
	return Vector3D(M.m11 * V.X() + M.m21 * V.Y + M.m31 * V.Z(),
					M.m12 * V.X() + M.m22 * V.Y() + M.m32 * V.Z(),
					M.m13 * V.X() + M.m23 * V.Y() + M.m33 * V.Z());
}

Matrix3 Matrix3::transpose(Matrix3 M)
{
	return Matrix3(M.m11, M.m12, M.m13, 
				   M.m21, M.m22, M.m23, 
				   M.m31, M.m32, M.m33);
}

Matrix3 Matrix3::operator+(Matrix3 M1, Matrix3 M2)
{
	return Matrix3(M1.m11 + M2.m11, M1.m12 + M2.m12, M1.m13 + M2.m13,
				   M1.m21 + M2.m21, M1.m22 + M2.m22, M1.m23 + M2.m23,
				   M1.m31 + M2.m31, M1.m32 + M2.m32, M1.m33 + M2.m33);
}

Matrix3 Matrix3::operator-(Matrix3 M1, Matrix3 M2)
{
	return Matrix3(M1.m11 - M2.m11, M1.m12 - M2.m12, M1.m13 - M2.m13,
				   M1.m21 - M2.m21, M1.m22 - M2.m22, M1.m23 - M2.m23,
				   M1.m31 - M2.m31, M1.m32 - M2.m32, M1.m33 - M2.m33);
}

Matrix3 Matrix3::operator*(double x, Matrix3 M)
{
	Matrix3 answer = Matrix3();

	answer.m11 = M.m11 * x;
	answer.m12 = M.m12 * x;
	answer.m13 = M.m13 * x;
	answer.m21 = M.m21 * x;
	answer.m22 = M.m22 * x;
	answer.m23 = M.m23 * x;
	answer.m31 = M.m31 * x;
	answer.m32 = M.m32 * x;
	answer.m33 = M.m33 * x;

	return answer;
}

Matrix3 Matrix3::operator*(Matrix3 M1, Matrix3 M2)
{
	Matrix3 answer = Matrix3();

	answer.m11 = M1.row(0) * M2.column(0);
	answer.m12 = M1.row(0) * M2.column(1);
	answer.m13 = M1.row(0) * M2.column(2);

	answer.m21 = M1.row(1) * M2.column(0);
	answer.m22 = M1.row(1) * M2.column(1);
	answer.m23 = M1.row(1) * M2.column(2);

	answer.m31 = M1.row(2) * M2.column(0);
	answer.m32 = M1.row(2) * M2.column(1);
	answer.m33 = M1.row(2) * M2.column(2);

	return answer;
}

double Matrix3::determinant(Matrix3 M)
{
	return (M.m11 * (M.m22 * M.m33 - M.m32 * M.m23) - M.m21 * (M.m33 * M.m12 - M.m32 * M.m13) + M.m31 * (M.m23 * M.m12 - M.m22 * M.m13));
}

Matrix3 Matrix3::inverse(Matrix3 M)
{
	double det = determinant(M);

	return Matrix3(M.m33 * M.m22 - M.m32 * M.m23, M.m32 * M.m13 - M.m33 * M.m12, M.m23 * M.m12 - M.m22 * M.m13,
				   M.m31 * M.m23 - M.m33 * M.m21, M.m33 * M.m11 - M.m31 * M.m13, M.m21 * M.m13 - M.m23 * M.m11,
				   M.m32 * M.m21 - M.m31 * M.m22, M.m31 * M.m12 - M.m32 * M.m11, M.m22 * M.m11 - M.m21 * M.m12);
}

Vector3D Matrix3::row(int row)
{
	switch (row)
	{
	case 1:
		return Vector3D(m11, m12, m13);
	case 2:
		return Vector3D(m21, m22, m23);
	case 3:
		return Vector3D(m31, m32, m33);
	}
	return Vector3D();
}

Vector3D Matrix3::column(int column)
{
	switch (column)
	{
	case 1:
		return Vector3D(m11, m21, m31);
	case 2:
		return Vector3D(m12, m22, m32);
	case 3:
		return Vector3D(m13, m23, m33);
	}
	return Vector3D();
}
