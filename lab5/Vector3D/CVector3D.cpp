#include <cmath>
#include <float.h>

#include "CVector3D.h"

CVector3D::CVector3D(double x0, double y0, double z0)
	: x(x0)
	, y(y0)
	, z(z0)
{
}

double CVector3D::GetLength() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void CVector3D::Normalize()
{
	double length = GetLength();
	if (length > 0)
	{
		double invertedLength = 1 / length;
		x *= invertedLength;
		y *= invertedLength;
		z *= invertedLength;
	}
}

CVector3D const CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D const CVector3D::operator+() const
{
	return *this;
}

CVector3D const CVector3D::operator+(CVector3D const& vector2) const
{
	return CVector3D(x + vector2.x, y + vector2.y, z + vector2.z);
}

CVector3D const CVector3D::operator*(double scalar) const
{
	return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D const CVector3D::operator/(double scalar) const
{
	return CVector3D(x / scalar, y / scalar, z / scalar);
}

const CVector3D& CVector3D::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;

	return *this;
}

const CVector3D& CVector3D::operator/=(double scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;

	return *this;
}

bool CVector3D::operator==(CVector3D const& other) const
{
	double x0 = x - other.x;
	double y0 = y - other.y;
	double z0 = z - other.z;

	return ((abs(x0) <= DBL_EPSILON) || (abs(y0) <= DBL_EPSILON) || (abs(z0) <= DBL_EPSILON));
}

bool CVector3D::operator!=(CVector3D const& other) const
{
	double x0 = x - other.x;
	double y0 = y - other.y;
	double z0 = z - other.z;

	return ((abs(x0) > DBL_EPSILON) || (abs(y0) > DBL_EPSILON) || (abs(z0) > DBL_EPSILON));
}

CVector3D const CVector3D::operator-(CVector3D const& vector2) const
{
	double x0 = x - vector2.x;
	double y0 = y - vector2.y;
	double z0 = z - vector2.z;

	return CVector3D(x0, y0, z0);
}

const CVector3D& CVector3D::operator+=(CVector3D const& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;

	return *this;
}

const CVector3D& CVector3D::operator-=(CVector3D const& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;

	return *this;
}

CVector3D const operator*(double scalar, const CVector3D& vector)
{
	return CVector3D((scalar * vector.x), (scalar * vector.y), (scalar * vector.z));
}

std::istream& operator>>(std::istream& input, CVector3D& vector)
{
	std::string str;

	input >> vector.x >> str;
	input >> vector.y >> str;
	input >> vector.z;

	return input;
}

std::ostream& operator<<(std::ostream& output, CVector3D& vector)
{
	output << "[" << vector.x << "; " << vector.y << "; " << vector.z << "]";
	return output;
}

double DotProduct(CVector3D const& v1, CVector3D const& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2)
{
	double x = v1.y * v2.z - v1.z * v2.y;
	double y = v1.z * v2.x - v1.x * v2.z;
	double z = v1.x * v2.y - v1.y * v2.x;

	return CVector3D(x, y, z);
}

CVector3D Normalize(CVector3D const& v)
{
	double length = v.GetLength();
	CVector3D normalizedVector = v;

	if (length > 0)
	{
		double invertedLength = 1 / length;
		normalizedVector.x *= invertedLength;
		normalizedVector.y *= invertedLength;
		normalizedVector.z *= invertedLength;
	}

	return normalizedVector;
}
