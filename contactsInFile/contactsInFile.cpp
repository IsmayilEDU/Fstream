
#include <iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<string>
#include<conio.h>

#include"functionsForContact.h"
#include"classContact.h"
#include"classDatabase.h"
#include"functionsForFile.h"



int main()
{
	Menu menu;
	Database* database = new Database();
	try
	{
		system("cls");

		while (true)
		{
			system("cls");
			char choice;
			cout << "Choose from menu: \n" <<
				"1 - Show contacts\n" <<
				"2 - Add contact\n" <<
				"3 - Delete contact\n" <<
				"4 - Uptade contact\n" << endl;
			cin >> choice;

			//	Show contacts
			if (choice == '1')
			{
				system("cls");
				menu.showContacts();
			}

			//	Add contact
			else if (choice == '2')
			{
				system("cls");
				menu.addContact(*database);
			}
			
			//	Delete contact
			else if (choice == '3')
			{
				system("cls");
				menu.deleteContact(*database);
			}
			
			//	Add contact
			else if (choice == '4')
			{
				system("cls");
				menu.updateContact(*database);
			}

			//	Other symbols
			else
			{
				cout << "Please choose correct symbol!" << endl;
			}

		}
		
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
		
	delete database;
}
