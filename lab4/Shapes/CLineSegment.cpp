#include <sstream>
#include <iomanip>
#include "CLineSegment.h"

CLineSegment::CLineSegment(uint32_t outlineColor, const CPoint& startPoint, const CPoint& endPoint) 
    : m_outlineColor(outlineColor)
    , m_startPoint(startPoint)
    , m_endPoint(endPoint)
{
}

double CLineSegment::GetArea() const
{
    return 0;
}

double CLineSegment::GetPerimeter() const
{
    return sqrt(pow(m_endPoint.x - m_startPoint.x, 2) + pow(m_endPoint.y - m_startPoint.y, 2));
}

std::string CLineSegment::ToString() const
{
    std::ostringstream strm;
    
    strm << "Line" << std::endl
        << "Perimeter: " << GetPerimeter() << std::endl
        << "StartPoint: [" << GetStartPoint().x << "; " << GetStartPoint().y << "]" << std::endl
        << "EndPoint: [" << GetEndPoint().x << "; " << GetEndPoint().y << "]" << std::endl
        << "OutlineColor: #" << std::setfill('0') << std::setw(6) << std::hex << GetOutlineColor() << std::endl;

    return strm.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}
