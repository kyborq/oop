#include <sstream>
#include <iomanip>
#include "CTriangle.h"

CTriangle::CTriangle(uint32_t outlineColor, uint32_t fillColor, const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3)
	: m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

double CTriangle::GetArea() const
{
	return abs((m_vertex1.x - m_vertex3.x) * (m_vertex2.y - m_vertex3.y) - (m_vertex2.x - m_vertex3.x) * (m_vertex1.y - m_vertex3.y)) / 2;
}

double CTriangle::GetPerimeter() const
{
	double a = sqrt(pow(m_vertex2.x - m_vertex1.x, 2) + pow(m_vertex2.y - m_vertex1.y, 2));
	double b = sqrt(pow(m_vertex3.x - m_vertex2.x, 2) + pow(m_vertex3.y - m_vertex2.y, 2));
	double c = sqrt(pow(m_vertex1.x - m_vertex3.x, 2) + pow(m_vertex1.y - m_vertex3.y, 2));
	return (a + b + c) / 2;
}

std::string CTriangle::ToString() const
{
	std::ostringstream strm;

	strm << "Perimeter: " << GetPerimeter() << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "OutlineColor: #" << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor << std::endl
		<< "FillColor: #" << std::setfill('0') << std::setw(6) << std::hex << m_fillColor << std::endl
		<< "Vertex1: [" << GetVertex1().x << "; " << GetVertex1().y << "]" << std::endl
		<< "Vertex2: [" << GetVertex2().x << "; " << GetVertex2().y << "]" << std::endl
		<< "Vertex3: [" << GetVertex3().x << "; " << GetVertex3().y << "]" << std::endl;

	return strm.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}
