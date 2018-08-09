#pragma once
#include "Utilities.cpp"

class Student
{
public:
	Student();
	~Student();

	template <typename T>
	void const get_input(const string question, T &input);
	void insertStudent();
	void searchStudent();
	void updateStudent();
	void deleteStudent();
	void showallStudents();


private:
	int studentid;
	string studentname;
	string booknumber;
	string status;
	int id;
	string name;
	string deleteline;
	string line;
};

