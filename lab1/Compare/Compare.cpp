#include <iostream>
#include <string>
#include <locale>
#include <fstream>

using namespace std;

int compare_files(string file_name1, string file_name2)
{
    int line_number = 0;
    string line1;
    string line2;
    ifstream file1;
    ifstream file2;

    file1.open(file_name1);
    file2.open(file_name2);

    if (!file1.is_open() || !file2.is_open())
        line_number = -1;

    while (getline(file1, line1))
    {
        getline(file2, line2);

        if (line1.compare(line1) == 0)
        {
            return line_number;
        }

        line_number++;
    }

    return line_number;
}

int main(int *argc, char *argv[])
{
    setlocale(0, "");

    string file1 = argv[0];
    string file2 = argv[1];

    int result = compare_files(file1, file2);
    if (result == 0)
    {
        cout << "Files are equal";
        return 0;
    }
    else
    {
        cout << "Files are different. Line number is " << result;
        return 1;
    }
}