#pragma once

void writeContactsInOUT(Database& database)
{
	//	Again other contacts add to contact in out mode
	ofstream file("file.txt");

	if (file.is_open())
	{
		for (int i = 0; i < database._contacts.size(); i++)
		{
			file << *database._contacts[i]->get_ID() << ' '
				<< *database._contacts[i]->get_name() << ' '
				<< *database._contacts[i]->get_surname() << ' '
				<< *database._contacts[i]->get_gMail() << ' '
				<< *database._contacts[i]->get_telephone() << endl;
		}

		file.close();
	}
}

void changeParameter(Database& database, int ID)
{
	char menu;
	cout << "Change parameter\n" <<
		"1 - Name\n" <<
		"2 - Surname\n" <<
		"3 - Gmail\n" <<
		"4 - Telephone\n";
	cin >> menu;

	string data;

	//	Set name
	if (menu == '1')
	{
		cout << "Please enter new name: ";
		cin >> data;
		database._contacts[ID]->set_name(data);
	}

	//	Set surname
	if (menu == '2')
	{
		cout << "Please enter new surname: ";
		cin >> data;
		database._contacts[ID]->set_surname(data);
	}

	//	Set gmail
	if (menu == '3')
	{
		cout << "Please enter new gmail: ";
		cin >> data;
		database._contacts[ID]->set_gMail(data);
	}

	//	Set telephone
	if (menu == '4')
	{
		cout << "Please enter new telephone: ";
		cin >> data;
		database._contacts[ID]->set_telephone(data);
	}
}

class Menu
{

public:

	//	Show all contacts
	void showContacts()
	{
		system("cls");

		ifstream file("file.txt");

		//	If file is open
		if (file.is_open())
		{
			string contact;
			
			while (!file.eof())
			{
				getline(file, contact);
				cout << contact<<endl;
			}

			file.close();
		}

		//	Back to menu
		cout << "Enter - back to menu...";
		int back = _getch();
		while (true)
		{
			if (back == 13)
			{
				break;
			}
		}
	}

	//	Add contact
	void addContact(Database& database)
	{
		string name, surname, gmail, telephone;

		//	Input contact's specifications
		cout << "Please enter contact's name, surname, gmail, telephone: " << endl;
		cin >> name;
		cin >> surname;
		cin >> gmail;
		cin >> telephone;

		//	Create new contact and add to database
		Contact* newContact = new Contact(name, surname, gmail, telephone);
		database._contacts.push_back(&(*newContact));

		//	New contact add to file
		ofstream file("file.txt", ios::app);

		if (file.is_open())
		{

			file << *database._contacts.back()->get_ID() << ' '
				<< *database._contacts.back()->get_name() << ' '
				<< *database._contacts.back()->get_surname() << ' '
				<< *database._contacts.back()->get_gMail() << ' '
				<< *database._contacts.back()->get_telephone() << endl;

			file.close();
		}
			

	}

	//	Delete contact
	void deleteContact(Database& database)
	{
		//	Input ID
		int ID;
		cout << "Please enter ID which you want to delete: " << endl;
		cin >> ID;

		//	Delete contact from contacts by ID
		bool checkID = false;
		for (int i = 0; i < database._contacts.size(); i++)
		{
			if (*database._contacts[i]->get_ID() == ID)
			{
				checkID = true;
				break;
			}
		}

		//	If ID find
		if (checkID)
		{
			database._contacts.erase(database._contacts.begin() + (ID - 1));

			writeContactsInOUT(database);
		}

		//	Not find
		else
		{
			throw exception("Please enter correct ID!");
		}
	}

	//	Update contact
	void updateContact(Database& database)
	{
		//	Input ID
		int ID;
		cout << "Please enter ID which you want to update: " << endl;
		cin >> ID;

		//	Search ID
		bool checkID = false;
		for (int i = 0; i < database._contacts.size(); i++)
		{
			if (*database._contacts[i]->get_ID() == ID)
			{
				checkID = true;
				break;
			}
		}

		//	If ID find
		if (checkID)
		{
			//	Change parameter
			changeParameter(database, ID);

			writeContactsInOUT(database);
		}

		//	Not find
		else
		{
			throw exception("Please enter correct ID!");
		}
	}
};