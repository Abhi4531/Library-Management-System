#include "Book.h"



Book::Book()
{
}


Book::~Book()
{
}

template <typename T>

void const Book::get_input(const string question, T & input)
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

	
void Book::createBook()
{
	get_input("What is the student's id?", id);
	ifstream file_("booklist.txt");

	int i = 0;
	while (file_ >> booknumber >> bookname >> authorname >> status)
	{
		if (id._Equal(booknumber)) {
			cout << "\n Book Already Exist ";
			cout << booknumber << " " << bookname << " " << authorname << " " << status;
			i++;
		}
		else {

		}
	}
	file_.close();

	ifstream file("booklist.txt");
	ofstream new_file;
	new_file.open("newfile.txt");
	if (i == 0) {

		get_input("What is the book's name?", bname);
		get_input("What is the aurthur's name?", aname);

		while (file >> booknumber >> bookname >> authorname >> status)
		{

			new_file << booknumber << " " << bookname << " " << authorname << " " << status;


		}
		new_file << id << " " << bname << " " << aname << " " << "true";
		cin.get();
		new_file.close();
		file.close();


		remove("booklist.txt");
		rename("newfile.txt", "booklist.txt");
	}
	else {
		new_file.close();
		file.close();

	}

}

void Book::displayBook()
{
	ifstream file_("booklist.txt");
	while (file_ >> booknumber >> bookname >> authorname >> status)
	{

		cout << booknumber << " " << bookname << " " << authorname << " " << status << endl;

	}


	file_.close();
}

void Book::editBook()
{


	get_input("What is the student's id?", id);
	ifstream file_("booklist.txt");

	ofstream new_file;
	new_file.open("newfile.txt");
	int i = 0;
	while (file_ >> booknumber >> bookname >> authorname >> status)
	{
		if (id != (booknumber)) {
			new_file << booknumber << " " << bookname << " " << authorname << " " << status;

		}
		else {

		}
	}

	get_input("What is the new  book's id?", id);
	get_input("What is the new book's name?", bname);
	get_input("What is the new aurthur's name?", aname);
	new_file << id << " " << bname << " " << aname << " " << "true";


	cin.get();
	new_file.close();
	file_.close();


	remove("booklist.txt");
	rename("newfile.txt", "booklist.txt");
}

void Book::searchBook()
{
	get_input("What is the book's id that u want to delete?", id);
	ifstream file_("booklist.txt");

	while (file_ >> booknumber >> bookname >> authorname >> status)
	{
		if (id == (booknumber)) {
			cout << booknumber << " " << bookname << " " << authorname << " " << status;

		}


	}


	file_.close();
}

void Book::deleteBook()
{
	get_input("What is the book's id that u want to delete?", id);
	ifstream file_("booklist.txt");

	ofstream new_file;
	new_file.open("newfile.txt");
	int i = 0;
	while (file_ >> booknumber >> bookname >> authorname >> status)
	{
		if (id != (booknumber)) {
			new_file << booknumber << " " << bookname << " " << authorname << " " << status;

		}
		else {

		}
	}


	cin.get();
	new_file.close();
	file_.close();


	remove("booklist.txt");
	rename("newfile.txt", "booklist.txt");

}

void Book::issuebook()
{

	int i = 0;

	get_input("What is the student's id?", Sid);
	get_input("What is the Book's number?", bnumber);
	ifstream file_("issuelist.txt");

	while (file_ >> issuedbooknumber >> issuedstudentnumber)
	{
		if (Sid == (issuedstudentnumber)) {

			cout << "One book is already issued with this name";
			ifstream booklist("booklist.txt");
			while (booklist >> booknumber >> bookname >> authorname >> status)
			{
				if (bnumber == booknumber) {
					cout << booknumber << " " << bookname;
				}
			}
			booklist.close();
			ifstream studentlist("studentlist.txt");
			while (studentlist >> studentid >> studentname)
			{
				if (issuedstudentnumber == studentid) {
					cout << "By " << studentname;
				}
			}
			studentlist.close();
			i++;
		}
		else if (bnumber == issuedbooknumber) {
			i++;
			cout << " book is already issued";
			ifstream booklist("booklist.txt");
			while (booklist >> booknumber >> bookname >> authorname >> status)
			{
				if (bnumber == booknumber) {
					cout << booknumber << " " << bookname;
				}
			}
			booklist.close();
			ifstream studentlist("studentlist.txt");
			while (studentlist >> studentid >> studentname)
			{
				if (issuedstudentnumber == studentid) {
					cout << "By " << studentname;
				}
			}
			studentlist.close();
		}
		else {

		}
	}
	if (i == 0) {
		ifstream file_("issuelist.txt");
		ofstream new_file;
		new_file.open("newfile.txt");

		while (file_ >> issuedbooknumber >> issuedstudentnumber)
		{
			new_file << issuedbooknumber << " " << issuedstudentnumber;


		}

		new_file << bnumber << " " << Sid;

		cin.get();
		new_file.close();
		file_.close();

		remove("issuelist.txt");
		rename("newfile.txt", "issuelist.txt");


	}
}

void Book::depositbook()
{

	get_input("What is the Book's number?", bnumber);

	ifstream file_("issuelist.txt");
	ofstream new_file;
	new_file.open("newfile.txt");

	while (file_ >> issuedbooknumber >> issuedstudentnumber)
	{
		if (bnumber != issuedbooknumber) {
			new_file << issuedbooknumber << " " << issuedstudentnumber;
		}

	}


	cin.get();
	new_file.close();
	file_.close();

	remove("issuelist.txt");
	rename("newfile.txt", "issuelist.txt");

}

void Book::showallBooks()
{
	ifstream file_("booklist.txt");
	while (file_ >> booknumber >> bookname >> authorname >> status)
	{

		cout << booknumber << " " << bookname << " " << authorname << " " << status << endl;

	}


	file_.close();
}

void Book::showallissuedBooks()
{
	ifstream file_("issuelist.txt");
	while (file_ >> issuedbooknumber >> issuedstudentnumber)
	{

		cout << booknumber << " " << bookname;

	}


	file_.close();
}

