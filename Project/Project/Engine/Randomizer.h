#pragma once

#include <set>
#include "Students.h"
#include "Teachers.h"

class Randomizer
{
public:
	Randomizer();
	void UnsortedResult();
private:
	int Random(size_t group_size);
	const std::vector<Students>* stud_db;
	Teachers teacher_db;
	Students fpm;
};
