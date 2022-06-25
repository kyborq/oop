#define CATCH_CONFIG_MAIN
#include "../../catch/catch.hpp"

#include <iostream>
#include "../Shapes/CShapeController.h"
#include "../Shapes/CLineSegment.h"
#include "../Shapes/CTriangle.h"
#include "../Shapes/CRectangle.h"
#include "../Shapes/CCircle.h"

using namespace std;

SCENARIO("Create line segment")
{
	CLineSegment line(0x000000, { 0, -1 }, { -2, 2.3 });

	CHECK(line.GetArea() == 0);
	CHECK(line.GetPerimeter() - 3.8587562763 < 0.00001);
	CHECK(line.ToString() == "Line\nPerimeter: 3.85876\nStartPoint: [0; -1]\nEndPoint: [-2; 2.3]\nOutlineColor: #000000\n");
	CHECK(line.GetOutlineColor() == 0x000000);
	CHECK(line.GetStartPoint().x == 0);
	CHECK(line.GetStartPoint().y == -1);
	CHECK(line.GetEndPoint().x == -2);
	CHECK(line.GetEndPoint().y == 2.3);
}

SCENARIO("Create triangle")
{
	CTriangle triangle(0xcc9900, 0x000000, { 3, 4 }, { 0, 7 }, { -3, -2 });

	CHECK(triangle.GetArea() == 18);
	CHECK((triangle.GetPerimeter() - 22.215) < 0.00001);
	CHECK(triangle.ToString() == "Perimeter: 11.1074\nArea: 18\nOutlineColor: #cc9900\nFillColor: #000000\nVertex1: [3; 4]\nVertex2: [0; 7]\nVertex3: [-3; -2]\n");
	CHECK(triangle.GetOutlineColor() == 0xcc9900);
	CHECK(triangle.GetFillColor() == 0x000000);
	CHECK(triangle.GetVertex1().x == 3);
	CHECK(triangle.GetVertex1().y == 4);
	CHECK(triangle.GetVertex2().x == 0);
	CHECK(triangle.GetVertex2().y == 7);
	CHECK(triangle.GetVertex3().x == -3);
	CHECK(triangle.GetVertex3().y == -2);
}

SCENARIO("Create rectangle")
{
	CRectangle rectangle(0xcc0066, 0xffffff, { -3, 4 }, 4.5, 7);
	
	CHECK(rectangle.GetArea() == 31.5);
	CHECK((rectangle.GetPerimeter() - 5.75) < 0.00001);
	CHECK(rectangle.ToString() == "Perimeter: 5.75\nArea: 31.5\nOutlineColor: #cc0066\nFillColor: #ffffff\nTopLeftPont: [-3; 4]\nWidth: 4.5\nHeight: 7\n");
	CHECK(rectangle.GetOutlineColor() == 0xcc0066);
	CHECK(rectangle.GetFillColor() == 0xffffff);
	CHECK(rectangle.GetLeftTop().x == -3);
	CHECK(rectangle.GetLeftTop().y == 4);
	CHECK(rectangle.GetWidth() == 4.5);
	CHECK(rectangle.GetHeight() == 7);
}

SCENARIO("Create circle")
{
	CCircle circle(0xffffff, 0x993366, { 5, -3 }, 2);

	CHECK((circle.GetArea() - 12.566371) < 0.00001);
	CHECK((circle.GetPerimeter() - 12.566371) < 0.00001);
	CHECK(circle.ToString() == "Perimeter: 12.5664\nArea: 12.5664\nOutlineColor: #ffffff\nFillColor: #993366\nCenter: [5; -3]\nRadius: 2\n");
	CHECK(circle.GetOutlineColor() == 0xffffff);
	CHECK(circle.GetFillColor() == 0x993366);
	CHECK(circle.GetCenter().x == 5);
	CHECK(circle.GetCenter().y == -3);
	CHECK(circle.GetRadius() == 2);
}

SCENARIO("Adding shapes")
{
	std::string shapeString = "line 0 300 300 300 ffffff";
	std::istringstream stream(shapeString);
	CShapeController shapeController(stream, std::cout);

	shapeController.HandleCommand();
	std::vector<std::shared_ptr<IShape>> shapes = shapeController.GetShapes();
	CHECK(shapes[0]->ToString() == "Line\nPerimeter: 300\nStartPoint: [0; 300]\nEndPoint: [300; 300]\nOutlineColor: #ffffff\n");

	shapeString = "rectangle 100 150 150 150 22222b ff1493";
	shapeController.HandleCommand();

}
