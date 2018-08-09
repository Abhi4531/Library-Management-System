#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;

class Utilities
{
public:

	static void get_input(const string &question, int &input)
	{
		cout << question << endl;
		cin >> input;
	}



	static void draw_message(const string message)
	{
		cout << "\n" << endl;
		cout << setfill('*') << setw(40) << "\n";
		cout << message << "\n";
		cout << setfill('*') << setw(40) << "\n";
		cout << "\n" << endl;
	}



	static int draw_menu(const vector<string> &options)
	{
		int count = 1;
		for (string option : options)
		{
			cout << count << ") " << option << endl;
			count++;
		}

		cout << "\n" << endl;
		cout << setfill('=') << setw(30) << "\n";
		cout << endl;

		int choice;

		get_input("Please choose an option:", choice);

		return choice;
	}

};