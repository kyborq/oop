#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

int compare_files(string source_file_name, string compare_file_name);

int main(int argc, char* argv[])
{
	setlocale(0, "");

	if (argc <= 2)
	{
		cerr << "Ожидалось аргументов 2, передано " << argc - 1 << endl << "Использование compare.exe file1.txt file2.txt" << endl;
		return 2;
	}

	string source_file_name = argv[1];
	string compare_file_name = argv[2];
	int compare_result = compare_files(source_file_name, compare_file_name);

	if (compare_result == -1)
	{
		cerr << "Не удалось открыть файлы. Проверьте существование " << source_file_name << " и " << compare_file_name << endl;
		return 3;
	}

	if (compare_result == 0)
	{
		cout << "Файлы идентичны." << endl;
		return 0;
	}

	cout << "Обнаружены расхождения в файлах на " << compare_result << " строке!" << endl;
	return 1;
}

/**
	@param string Имя файла источника
	@param string Имя файла для сравнения с источником
	@return int Номер строки если файлы отличаются. Нуль, если файлы равны. -1 если нельзя открыть файлы
*/
int compare_files(string source_file_name, string compare_file_name)
{
	ifstream source_file(source_file_name);
	ifstream compare_file(compare_file_name);

	if (!source_file.is_open() || !compare_file.is_open())
		return -1;

	string source_line;
	string compare_line;
	int line_index = -1;

	while (getline(source_file, source_line) && getline(compare_file, compare_line))
	{
		line_index++;

		if (compare_line != source_line)
			return line_index;
	}
}