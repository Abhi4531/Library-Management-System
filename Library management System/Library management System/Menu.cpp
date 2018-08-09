#include "Menu.h"
#include "Book.h"


Menu::Menu()
{
	init();
}


Menu::~Menu()
{

}

void menu() {
	vector<string> options = {
		"ISSUE A BOOK",
		"DEPOSIT A  BOOK",
		"CREATE STUDENT RECORD",
		"DISPLAY ALL STUDENTS RECORD",
		"DISPLAY SPECIFIC STUDENT RECORD",
		"MODIFY STUDENT RECORD",
		"DELETE STUDENT RECORD",
		"ADD NEW BOOK",
		"DISPLAY ALL BOOKS",
		"DISPLAY SPECIFIC BOOK ",
		"DISPLAY ALL ISSUED BOOK",
		"UPDATE BOOK DATA",
		"DELETE A BOOK",
		"EXIT"
	};

	int value = Utilities::draw_menu(options);
	Book book; Student student;
	if (value == 1) {
		book.issuebook(); 

	}
	else if (value == 2) {
		book.depositbook();
	}
	else if (value == 3) {
		student.insertStudent();
	}
	else if (value == 4) {
		student.showallStudents();
	}
	else if (value == 5) {
		student.searchStudent();
	}
	else if (value == 6) {
		student.updateStudent();
	}
	else if (value == 7) {
		student.deleteStudent();
	}
	else if (value == 8) {
		book.createBook();
	}
	else if (value == 9) {
		book.showallBooks();
	}
	else if (value == 10) {
		book.showallissuedBooks();
	}
	else if (value == 11) {
		book.searchBook();
	}
	else if (value == 12) {
		book.editBook();
	}
	else if (value == 13) {
		book.deleteBook();
	}
	else if (value == 14) {
		exit(0);
	}
	else {
		Utilities::draw_message(" PLEASE CHOOSE THE ONLY FROM 1 - 12 ");
		menu();
	}
}
void Menu::init()
{
	system("cls");

	Utilities::draw_message("WELCOME TO THE LiBRARY MANAGEMENT SYSTEM");
	Utilities::draw_message("MADE BY ABHINAV AND GURJEET");

	Utilities::draw_message(" Please Select Your Option:-");
	menu();
}

