#include "Student.h"



Student::Student()
{
}


Student::~Student()
{
}

template <typename T>
void const Student::get_input(const string question, T & input)
{
	bool pass = false;
	while (!pass) {
		cout << question << endl;
		cin >> input;

		if (cin.good()) {
			pass = true;
			continue;
		}

		cout << "Please enter a correct value." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void Student::insertStudent()
{
	get_input("What is the student's id?", id);
	ifstream file_("studentlist.txt");

	int i = 0;
	while (file_ >> studentid >> studentname)
	{
		if (id == studentid) {
			cout << "\n student record already exist";
			cout << studentid << " " << studentname << "\n";
			i++;
		}
		else {

		}
	}
	file_.close();

	ifstream file("studentlist.txt");
	ofstream new_file;
	new_file.open("newfile.txt");
	if (i == 0) {

		get_input("What is the student's name?", name);

		while (file >> studentid >> studentname)
		{


			new_file << studentid << " " << studentname << endl;

		}
		new_file << id << " " << name;
		cin.get();
		new_file.close();
	}
	else {


	}



	file.close();


	remove("studentlist.txt");
	rename("newfile.txt", "studentlist.txt");
}

void Student::searchStudent()
{
	get_input("What is the student's id that u want to delete?", id);
	ifstream file_("studentlist.txt");

	while (file_ >> studentid >> studentname)
	{
		if (id != studentid) {
		}
		else {
			cout << "\n\n\n" << endl;
			cout << studentid << " " << studentname << endl;
		}
	}

	file_.close();
}

void Student::updateStudent()
{
	get_input("What is the student's id?", id);
	ifstream file_("studentlist.txt");
	ofstream new_file;
	new_file.open("newfile.txt");
	while (file_ >> studentid >> studentname)
	{
		if (id != studentid) {
			new_file << studentid << " " << studentname << endl;
		}
		else {

		}
	}

	get_input("What is the new student's number?", studentid);
	get_input("What is the new student's name?", studentname);
	new_file << studentid << " " << studentname << endl;

	cin.get();
	new_file.close();



	file_.close();


	remove("studentlist.txt");
	rename("newfile.txt", "studentlist.txt");
}

void Student::deleteStudent()
{
	get_input("What is the student's id that u want to delete?", id);
	ifstream file_("studentlist.txt");
	ofstream new_file;
	new_file.open("newfile.txt");
	while (file_ >> studentid >> studentname)
	{
		if (id != studentid) {
			new_file << studentid << " " << studentname << endl;
		}
		else {
			cout << studentid << " " << studentname << endl;
		}
	}


	cin.get();
	new_file.close();



	file_.close();


	remove("studentlist.txt");
	rename("newfile.txt", "studentlist.txt");
}

void Student::showallStudents()
{
	int i = 0;
	string line;
	ifstream file_("studentlist.txt");
	while (file_ >> studentid >> studentname)
	{
		cout << studentid << " " << studentname;
	}

	file_.close();
}
