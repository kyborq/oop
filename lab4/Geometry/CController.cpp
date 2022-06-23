#include "CController.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"

void CController::AddShape(std::string shapeString)
{
}

std::string CController::GetMaxArea() const
{
	return std::string();
}

std::string CController::GetMinPerimeter() const
{
	return std::string();
}

std::vector<IShape> CController::GetShapes() const
{
	return std::vector<IShape>();
}

CLineSegment CController::AddLineSegment(std::stringstream& ss) const
{
	double x1, y1, x2, y2;
	std::string strOutlineColor;
	uint32_t outlineColor;
	stream >> x1 >> y1 >> x2 >> y2 >> strOutlineColor;
	if ((!stream.eof()) || (stream.fail()))
	{
		throw std::invalid_argument("incorrect input");
	}
	try
	{
		outlineColor = stoi(strOutlineColor, nullptr, 16);
	}
	catch (...)
	{
		throw std::invalid_argument("incorrect input");
	}
	CLineSegment line(outlineColor, { x1, y1 }, { x2, y2 });
	return std::make_shared<CLineSegment>(line);
}

CTriangle CController::AddTriangle(std::stringstream& ss) const
{
	return CTriangle();
}

CRectangle CController::AddRectangle(std::stringstream& ss) const
{
	return CRectangle();
}

CCircle CController::AddCircle(std::stringstream& ss) const
{
	return CCircle();
}
