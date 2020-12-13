#include "Students.h"
using namespace std;
bool Students::Add_Students(const string& path_to_the_file)
{
	ifstream student_File;
	student_File.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		cout << "Попытка открыть файл!" << endl;
		student_File.open(path_to_the_file);
		cout << "Файл успешно открыт!" << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "Загрузка закончена!" << endl;
		return false;
	}
	string dummy_line, group, FIO, order;
	getline(student_File, dummy_line, ',');
	getline(student_File, dummy_line, ',');
	getline(student_File, dummy_line, '\n');

	getline(student_File, group, ',');

	students[group].resize(30);
	int group_size = 0;
	while (!student_File.eof()) {
		getline(student_File, FIO, ',');
		getline(student_File, order, '\n');
		students[group][atoi(order.c_str())] = FIO;
		group_size++;
		try {
			getline(student_File, dummy_line, ',');
		}
		catch (const std::exception& ex) {
			cout << "Конец чтения" << endl;
		}
	}
	int size = students[group].size() - group_size - 1;
	for (int i = 0; i < size; i++) {
		students[group].pop_back();
	}
	students[group].shrink_to_fit();
	student_File.close();
	return true;
}

const vector<string>& Students::Get_Group(const string& group) const
{
	return students.at(group);
}

int Students::Get_Count_Of_Groups()
{
	return students.size();
}