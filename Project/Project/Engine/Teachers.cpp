#include "Teachers.h"

using namespace std;


bool Teachers::Add_Teachers(const string& path_to_the_file)
{
	ifstream teachers_File;
	teachers_File.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		cout << "Попытка открыть файл!" << endl;
		teachers_File.open(path_to_the_file);
		cout << "Файл успешно открыт!" << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Ошибка открытия файла" << endl;
		return false;
	}
	string dummy_line, prepod, subj, group, data1, data2;
	getline(teachers_File, dummy_line, ',');
	getline(teachers_File, dummy_line, ',');
	getline(teachers_File, dummy_line, ',');
	getline(teachers_File, dummy_line, '\n');

	while (!teachers_File.eof()) {
		getline(teachers_File, prepod, ',');
		getline(teachers_File, subj, ',');
		getline(teachers_File, group, ',');
		getline(teachers_File, data1, ' ');
		teachers_File >> dummy_line;
		if (dummy_line == "зачет" || dummy_line == "зачёт") {
			teachers[prepod][subj].push_back({ atoi(data1.c_str()),-1,group });
			if (teachers_File.eof()) {
				break;
			}
			getline(teachers_File, dummy_line, '\n');

		}
		else {
			teachers_File >> dummy_line;
			teachers_File >> data2;
			getline(teachers_File, dummy_line, '\n');
			teachers[prepod][subj].push_back({ atoi(data1.c_str()),atoi(data2.c_str()),group });
		}
	}

	return true;
}


const std::map<std::string, Teacher>& Teachers::GetRoot()
{
	return teachers;
}

int Teachers::DecrimentRecord(const std::string & name, const std::string & subject, const std::string & group_nam)
{
	for (auto& record : teachers[name][subject])
	{
		if (record.group_name == group_nam)
		{
			--record.sets;
			return record.sets;
		}
	}
	return 0;
}
