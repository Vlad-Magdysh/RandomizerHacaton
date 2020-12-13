#include "Randomizer.h"
#include <random>
#include <ctime>
#include <set>
using namespace std;

using Teacher = std::map<std::string, std::vector<Record>>;

Randomizer::Randomizer()
{
	teacher_db.Add_Teachers("Teachers//Teachers.csv");
	fpm.Add_Students("Students//Students.csv");
	for (int i = 2; fpm.Add_Students({ "Students//Students" + to_string(i) + ".csv" }); i++);
}

int Randomizer::Random(size_t group_size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, group_size - 1);

	return dis(gen);
}

void Randomizer::UnsortedResult()
{
	vector<string> result_base;
	result_base.push_back("Группа, Предмет, Преподаватель, Имя студента, Количество баллов,");
	string temp = "";

	ofstream prepod_output("Result//Prepod.csv");

	const map<string, Teacher>& teachers = teacher_db.GetRoot();
	for (const auto& teacher_name : teachers)
	{
		for (const auto& subject : teacher_name.second)
		{
			set<int> duplicates;
			for (const auto& record : subject.second)
			{
				if (record.points != -1)
					duplicates.clear();
				do
				{
					const vector<string>& current_group = fpm.Get_Group(record.group_name);
					int lucky = Random(current_group.size());
					while (duplicates.count(lucky))
					{
						lucky = Random(current_group.size());
						if (current_group.size() - 1 == duplicates.size())
							break;
					}
					duplicates.insert(lucky);
					
					if (record.points == -1)
					{
						prepod_output << teacher_name.first + "," + subject.first + "," + record.group_name + "," + current_group[lucky] + "," + "зачет" << endl; // !!!
						temp += record.group_name + "," + subject.first + "," + teacher_name.first + "," + current_group[lucky] + "," + "зачет";
					}
					else
					{
						prepod_output << teacher_name.first + "," + subject.first + "," + record.group_name + "," + current_group[lucky] + "," + to_string(record.points) << endl; // !!!
						temp += record.group_name + "," + subject.first + "," + teacher_name.first + "," + current_group[lucky] + "," + to_string(record.points);
					}
					result_base.push_back(move(temp));
					temp.clear();
				}while (teacher_db.DecrimentRecord(teacher_name.first, subject.first, record.group_name) > 0);
			}
		}
	}
	ofstream group_output("Result//Groups.csv");

	sort(result_base.begin(), result_base.end(), [](const string& lhs, const string& rhs)
	{
		return  lhs.substr(0, 7) < rhs.substr(0, 7);
	});
	for (auto& r : result_base)
	{
		group_output << r << endl;
	}
}
