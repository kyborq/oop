#include <iostream>
#include <fstream>

#include "CShapeController.h"

using namespace std;

const string ERROR_OPEN_FILE = "Failed to open file for reading";

int main()
{
	ifstream input("Shapes.txt");
	if (!input.is_open())
	{
		cout << ERROR_OPEN_FILE << endl;
		return 1;
	}

	CShapeController shapeController(input, cout);
	while (!input.eof() && !input.fail())
	{
		shapeController.HandleCommand();
	}
}
