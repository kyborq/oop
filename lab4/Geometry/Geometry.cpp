#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input("Shapes.txt");
	string shapeString;

	while (getline(input, shapeString))
	{
		try
		{

		}
		catch (const invalid_argument& e)
		{
			cerr << e.what() << endl;
		}
	}
}
