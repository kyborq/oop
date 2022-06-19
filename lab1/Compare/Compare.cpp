#include <iostream>
#include <fstream>
#include <string>
#include <optional>

using namespace std;

struct Args
{
	string sourceFileName;
	string compareFileName;
};

int CompareFiles(string, string);
optional<Args> ParseArgs(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		cerr << "Invalid arguments count" << endl
			<< "Using: compare.exe <source file> <comparing file>" << endl;
		return 1;
	}

	int compareResult = CompareFiles(args->sourceFileName, args->compareFileName);

	if (compareResult == 0)
	{
		cout << "Files are equal" << endl;
		return 0;
	}

	if (compareResult > 0)
	{
		cout << "Files are different. Line number is " << compareResult << endl;
		return 1;
	}

	return compareResult;
}

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		return nullopt;
	}
	Args args;
	args.sourceFileName = argv[1];
	args.compareFileName = argv[2];

	return args;
}

int CompareFiles(string sourceFileName, string compareFileName)
{
	ifstream sourceFile;
	sourceFile.open(sourceFileName);
	if (!sourceFile.is_open())
	{
		cerr << "Failed to open '" << sourceFileName << "' for reading" << endl;
		return -1;
	}

	ifstream compareFile;
	compareFile.open(compareFileName);
	if (!compareFile.is_open())
	{
		cerr << "Failed to open '" << compareFileName << "' for reading" << endl;
		return -1;
	}

	string sourceLine;
	string compareLine;
	int lineIndex = 0;

	while (getline(sourceFile, sourceLine))
	{
		getline(compareFile, compareLine);

		lineIndex++;

		if (compareLine != sourceLine)
			return lineIndex;
	}

	return lineIndex;
}

