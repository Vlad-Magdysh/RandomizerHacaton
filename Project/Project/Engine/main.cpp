#define _CRT_SECURE_NO_WARNINGS

#include "Students.h"
#include "Teachers.h"
#include "Randomizer.h"
#include <algorithm>
#include <Windows.h>
using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");
	wstring DirStud = L"Students";
	CreateDirectoryW(DirStud.c_str(), NULL);
	wstring DirTeach = L"Teachers";
	CreateDirectoryW(DirTeach.c_str(), NULL);
	cout << "Прочтите README.txt и перенесите файлы в папки Students и Teachers" << endl;
	system("pause");
	Randomizer our_rand;
	wstring DirRes = L"Result";
	CreateDirectoryW(DirRes.c_str(), NULL);

	string a1 = "    _~_        _~_        _~_        _~_    ";
	string a2 = "   (o o)      (o o)      (o o)      (o o)   ";
	string a3 = "  /  V  \\    /  V  \\    /  V  \\    /  V  \\ ";
	string a4 = " /(  _  )\\  /(  _  )\\  /(  _  )\\  /(  _  )\\";
	string a5 = "   ^^ ^^      ^^ ^^      ^^ ^^      ^^ ^^   ";
	for (int i = 0; i < 40; i++)
	{
		cout << a1 << "\n";
		cout << a2 << "\n";
		cout << a3 << "\n";
		cout << a4 << "\n";
		cout << a5 << "\n";
	}
	our_rand.UnsortedResult();
	cout << "DONE! ;)" << endl;
	system("pause");
	return 0;
}