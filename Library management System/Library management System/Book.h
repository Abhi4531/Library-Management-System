#pragma once
#include "Student.h"

class Book
{
public:
	template <typename T>

	void const get_input(const string question, T &input);
	void createBook();
	void displayBook();
	void editBook();
	void searchBook();
	void deleteBook();
	void issuebook();
	void depositbook();
	void showallBooks();
	void showallissuedBooks();
	Book();
	~Book();

private:
	string authorname;
	string bookname;
	string booknumber;
	string status;
	string id;
	string aname;
	string bname;
	string issuedbooknumber;
	int issuedstudentnumber;
	string bnumber;
	int Sid;
	int studentid;
	string studentname;
};

