#pragma once
#include <iostream>
#include <vector>

#include "IShape.h"

class CShapeController
{
public:
	CShapeController(std::istream& input, std::ostream& output);
	void HandleCommand();
private:
	std::istream& m_input;
	std::ostream& m_output;
	std::vector<std::shared_ptr<IShape>> m_shapes;

	void AddLineSegment(std::istream& command);
	void AddRectangle(std::istream& command);
	void AddTriangle(std::istream& command);
	void AddCircle(std::istream& command);

	void GetShapeWithMinPerimeter() const;
	void GetShapeWithMaxArea() const;
};
