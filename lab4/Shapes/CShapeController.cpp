#include <string>
#include <sstream>

#include "CShapeController.h"
#include "CLineSegment.h"
#include "Errors.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"

const std::string COMMAND_ADD_CIRCLE = "circle";
const std::string COMMAND_ADD_RECTANGLE = "rectangle";
const std::string COMMAND_ADD_TRIANGLE = "triangle";
const std::string COMMAND_ADD_LINE = "line";
const std::string COMMAND_GET_MAX_AREA = "maxArea";
const std::string COMMAND_GET_MIN_PERIMETER = "minPerimeter";

CShapeController::CShapeController(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

void CShapeController::HandleCommand()
{
	std::string command;
	getline(m_input, command);

	std::istringstream strm(command);

	std::string action;
	strm >> action;

	if (action == COMMAND_ADD_LINE)
	{
		AddLineSegment(strm);
		return;
	}
	if (action == COMMAND_ADD_TRIANGLE)
	{
		AddTriangle(strm);
		return;
	}
	if (action == COMMAND_ADD_RECTANGLE)
	{
		AddRectangle(strm);
		return;
	}
	if (action == COMMAND_ADD_TRIANGLE)
	{
		AddCircle(strm);
		return;
	}
	if (action == COMMAND_GET_MAX_AREA)
	{
		GetShapeWithMaxArea();
		return;
	}
	if (action == COMMAND_GET_MIN_PERIMETER)
	{
		GetShapeWithMinPerimeter();
		return;
	}
}

void CShapeController::AddLineSegment(std::istream& command)
{
	std::string outlineColorStr;
	uint32_t outlineColor;
	CPoint startPoint;
	CPoint endPoint;

	command >> startPoint.x >> startPoint.y >> endPoint.x >> endPoint.y >> outlineColorStr;

	if ((!command.eof()) || (command.fail()))
	{
		m_output << ERROR_INCORRECT_INPUT;
		return;
	}

	try
	{
		outlineColor = std::stoi(outlineColorStr, nullptr, 16);
	}
	catch (...)
	{
		m_output << ERROR_INCORRECT_COLOR;
		return;
	}

	CLineSegment line(outlineColor, startPoint, endPoint);
	m_shapes.push_back(std::make_shared<CLineSegment>(line));
}

void CShapeController::AddRectangle(std::istream& command)
{
	std::string outlineColorStr;
	std::string fillColorStr;

	uint32_t outlineColor;
	uint32_t fillColor;
	CPoint leftTop;
	double width;
	double height;

	command >> leftTop.x >> leftTop.y >> width >> height >> outlineColorStr >> fillColorStr;

	if ((!command.eof()) || (command.fail()))
	{
		m_output << ERROR_INCORRECT_INPUT;
		return;
	}

	try
	{
		outlineColor = std::stoi(outlineColorStr, nullptr, 16);
		fillColor = std::stoi(fillColorStr, nullptr, 16);
	}
	catch (...)
	{
		m_output << ERROR_INCORRECT_COLOR;
		return;
	}

	CRectangle rect(outlineColor, fillColor, leftTop, width, height);
	m_shapes.push_back(std::make_shared<CRectangle>(rect));
}

void CShapeController::AddTriangle(std::istream& command)
{
	std::string outlineColorStr;
	std::string fillColorStr;

	uint32_t outlineColor;
	uint32_t fillColor;

	CPoint vertex1;
	CPoint vertex2;
	CPoint vertex3;

	command >> vertex1.x >> vertex1.y >> vertex2.x >> vertex2.y >> vertex3.x >> vertex3.y >> outlineColorStr >> fillColorStr;

	if ((!command.eof()) || (command.fail()))
	{
		m_output << ERROR_INCORRECT_INPUT;
		return;
	}

	try
	{
		outlineColor = std::stoi(outlineColorStr, nullptr, 16);
		fillColor = std::stoi(fillColorStr, nullptr, 16);
	}
	catch (...)
	{
		m_output << ERROR_INCORRECT_COLOR;
		return;
	}

	CTriangle triangle(outlineColor, fillColor, vertex1, vertex2, vertex3);
	m_shapes.push_back(std::make_shared<CTriangle>(triangle));
}

void CShapeController::AddCircle(std::istream& command)
{
	std::string outlineColorStr;
	std::string fillColorStr;

	uint32_t outlineColor;
	uint32_t fillColor;

	CPoint point;
	double radius;
		
	command >> point.x >> point.y >> radius >> outlineColorStr >> fillColorStr;

	if ((!command.eof()) || (command.fail()))
	{
		m_output << ERROR_INCORRECT_INPUT;
		return;
	}

	try
	{
		outlineColor = std::stoi(outlineColorStr, nullptr, 16);
		fillColor = std::stoi(fillColorStr, nullptr, 16);
	}
	catch (...)
	{
		m_output << ERROR_INCORRECT_COLOR;
		return;
	}

	CCircle circle(outlineColor, fillColor, point, radius);
	m_shapes.push_back(std::make_shared<CCircle>(circle));
}

void CShapeController::GetShapeWithMinPerimeter() const
{
	if (m_shapes.empty())
	{
		m_output << ERROR_EMPTY_SHAPES << std::endl;
		return;
	}

	double perimeter = m_shapes[0]->GetPerimeter();
	std::string info;

	for (auto shape : m_shapes)
	{
		if (shape->GetPerimeter() <= perimeter)
		{
			perimeter = shape->GetPerimeter();
			info = shape->ToString();
		}
	}
	m_output << info << std::endl 
		<< "Min perimeter = " << perimeter << std::endl << std::endl;
}

void CShapeController::GetShapeWithMaxArea() const
{
	if (m_shapes.empty())
	{
		m_output << ERROR_EMPTY_SHAPES << std::endl;
		return;
	}

	double area = 0;
	std::string info;
	for (auto shape : m_shapes)
	{
		if (shape->GetArea() > area)
		{
			area = shape->GetArea();
			info = shape->ToString();
		}
	}

	m_output << info << std::endl << "Max area: " << area << std::endl << std::endl;
}
