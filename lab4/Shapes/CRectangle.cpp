#include <sstream>
#include <iomanip>
#include "CRectangle.h"

CRectangle::CRectangle(uint32_t outlineColor, uint32_t fillColor, CPoint leftTop, double width, double height)
	: m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) / 2;
}

std::string CRectangle::ToString() const
{
	std::ostringstream strm;

	strm << "Perimeter: " << GetPerimeter() << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "OutlineColor: #" << std::setfill('0') << std::setw(6) << std::hex << m_outlineColor << std::endl
		<< "FillColor: #" << std::setfill('0') << std::setw(6) << std::hex << m_fillColor << std::endl
		<< "TopLeftPont: [" << GetLeftTop().x << "; " << GetLeftTop().y << "]" << std::endl
		<< "Width: " << GetWidth() << std::endl
		<< "Height: " << GetHeight() << std::endl;

	return strm.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
