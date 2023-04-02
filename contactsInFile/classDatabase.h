#pragma once

class Database
{

private:


public:
    vector<Contact*> _contacts;

    //  Get method contacts
    vector<Contact*> get_contacts() const noexcept
    {
        return this->_contacts;
    }

    //  Add contact
    void addContact(Contact* contact)
    {
        _contacts.push_back(&(*contact));
    }

    //  Delete contact By ID
    void deleteContactByID(const int ID)
    {
        //  Search contact
        for (int i = 0; i < _contacts.size(); i++)
        {
            if (*(_contacts[i]->get_ID()) == ID)
            {
                //  Delete contact that we search
                delete _contacts[i];
                break;
            }
        }
    }

    //  Search contact By ID
    void searchContact(const int ID)
    {
        //  Search contact
        for (int i = 0; i < _contacts.size(); i++)
        {
            if (*(_contacts[i]->get_ID()) == ID)
            {
                //  Show contact's specifications
                _contacts[i]->showSpecifications();
                break;
            }
        }
    }

    ~Database()
    {
        for (int i = 0; i < this->_contacts.size(); i++)
        {
            delete this->_contacts[i];
        }

    }
};