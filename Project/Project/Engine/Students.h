#pragma once
#include<iostream>
#include<fstream>
#include <map> 
#include<vector>
#include <string> 


class Students
{
private:
	std::map<std::string, std::vector<std::string>> students;
public:
	bool Add_Students(const std::string& path_to_the_file);

	const std::vector<std::string>& Get_Group(const std::string& group) const;

	int Get_Count_Of_Groups();
};

