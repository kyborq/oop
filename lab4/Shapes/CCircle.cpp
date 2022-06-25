#include <sstream>
#include <iomanip>
#include "CCircle.h"

#define M_PI 3.141592653589793

CCircle::CCircle(uint32_t outlineColor, uint32_t fillColor, CPoint center, double radius)
	: m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_center(center)
	, m_radius(radius)
{
}

double CCircle::GetArea() const
{
    return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
    return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
	std::ostringstream strm;

	strm << "Perimeter: " << GetPerimeter() << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "OutlineColor: #" << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor << std::endl
		<< "FillColor: #" << std::setfill('0') << std::setw(6) << std::hex << m_fillColor << std::endl
		<< "Center: [" << GetCenter().x << "; " << GetCenter().y << "]" << std::endl
		<< "Radius: " << GetRadius() << std::endl;

	return strm.str();
}

uint32_t CCircle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}
