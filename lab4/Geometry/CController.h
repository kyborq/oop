#pragma once
#include <string>
#include <vector>

#include "IShape.h"
#include "CPoint.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CLineSegment.h"
#include "CRectangle.h"

class CController
{
public:
	void AddShape(std::string shapeString);
	std::string GetMaxArea() const;
	std::string GetMinPerimeter() const;
	std::vector<IShape> GetShapes() const;
private:
	std::vector<IShape> m_shapes;

	CLineSegment AddLineSegment(std::stringstream& ss) const;
	CTriangle AddTriangle(std::stringstream& ss) const;
	CRectangle AddRectangle(std::stringstream& ss) const;
	CCircle AddCircle(std::stringstream& ss) const;
};

