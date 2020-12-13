#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include <map> 
#include<vector>
#include <string> 


struct Record {
	int sets;
	int points;
	std::string group_name;
};

using Teacher = std::map<std::string, std::vector<Record>>;

class Teachers
{
private:
	std::map<std::string, Teacher> teachers;// 1-ключ-имя, 2-ключ - предмет,  знач инфа про учителя
public:
	bool Add_Teachers(const std::string& path_to_the_file);
	const std::map<std::string, Teacher>& GetRoot();
	int DecrimentRecord(const std::string& name ,const std::string& subject, const std::string& group_nam);
};