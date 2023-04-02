#pragma once

class Contact
{

private:

    static int _staticID;
    int* _ID;
    string* _name;
    string* _surname;
    string* _gMail;
    string* _telephone;

public:

    //  Get method of ID
    const int* get_ID() const noexcept
    {
        return this->_ID;
    }

    //  Get method of name
    const string* get_name() const noexcept
    {
        return this->_name;
    }

    //  Set method of name
    void set_name(const string& name)
    {
        //  Check length of name
        if (name.length() >= 2)
        {
            //  Check other symbols in name
            if (checkOtherSymbolInString(name) == false)
            {
                this->_name = new string(name);
            }

            //  If there is other symbol in name
            else
            {
                throw exception("There is other symbol in name!");
            }
        }

        //  If length of name less than 2
        else
        {
            throw exception("Length of name should be min 2!");
        }
    }

    //  Get method of surname
    const string* get_surname() const noexcept
    {
        return this->_surname;
    }

    //  Set method of surname
    void set_surname(const string& surname)
    {
        //  Check length of surname
        if (surname.length() >= 2)
        {
            //  Check other symbols in surname
            if (checkOtherSymbolInString(surname) == false)
            {
                this->_surname = new string(surname);
            }

            //  If there is other symbol in surname
            else
            {
                throw exception("There is other symbol in surname!");
            }
        }

        //  If length of surname less than 2
        else
        {
            throw exception("Length of surname should be min 2!");
        }
    }

    //  Get method of gMail
    const string* get_gMail() const noexcept
    {
        return this->_gMail;
    }

    //  Set method of gMail
    void set_gMail(const string& gMail)
    {
        bool check = true;
        string endOfGmail = "@gmail.com";

        //  Check 10 characters from the end
        for (int i = gMail.length() - 10, index = 0; i < gMail.length(); i++)
        {
            if (endOfGmail[index++] != gMail[i])
            {
                check = false;
                break;
            }
        }

        //  If gMail ends with "@gmail.com"
        if (check)
        {
            this->_gMail = new string(gMail);
        }

        //If gMail doesn't end with "@gmail.com"
        else
        {
            throw exception("Gmail shoul be ends with '@gmail.com'");
        }
    }

    //  Get method of telephone
    const string* get_telephone() const noexcept
    {
        return this->_telephone;
    }

    //  Set method of telephone
    void set_telephone(const string& telephone)
    {
        //  Check length, operator, other symbol in telephone
        if ((telephone.length() == 10) &&
            (checkOperatorInTelephone(telephone)) &&
            (checkOtherSymbolInTelephone(telephone) == false))
        {
            string newTelephone = "";
            for (int i = 0; i < telephone.length(); i++)
            {
                newTelephone += telephone[i];

                //  Add symbol (-)
                if (i == 2 || i == 5 || i == 7)
                {
                    newTelephone += '-';
                }
            }

            this->_telephone = new string(newTelephone);
        }

        //  if the operator or length is not entered correctly or
        //  if there is another character in telephone
        else
        {
            throw exception("Telephone is not entered correctly!");
        }
    }

    //  Constructor with parameters
    Contact(const string& name, const string& surname, const string& gMail, const string& telephone)
    {
        this->_ID = new int(++_staticID);
        set_name(name);
        set_surname(surname);
        set_gMail(gMail);
        set_telephone(telephone);
    }

    //  Copy constructor
    Contact(const Contact& other)
    {
        this->_ID = new int(*(other._ID));
        this->set_name(*other._name);
        this->set_surname(*other._surname);
        this->set_gMail(*other._gMail);
        this->set_telephone(*other._telephone);
    }

    //  Operator = 
    Contact& operator = (const Contact& other)
    {
        this->_ID = new int(*(other._ID));
        this->set_name(*other._name);
        this->set_surname(*other._surname);
        this->set_gMail(*other._gMail);
        this->set_telephone(*other._telephone);

        return *this;
    }

    //  Move constructor
    Contact(Contact&& other)
    {
        //  Move ID
        this->_ID = other._ID;
        other._ID = nullptr;

        //  Move name
        this->_name = other._name;
        other._name = nullptr;

        //  Move surname
        this->_surname = other._surname;
        other._surname = nullptr;

        //  Move Gmail
        this->_gMail = other._gMail;
        other._gMail = nullptr;

        //  Move telephone
        this->_telephone = other._telephone;
        other._telephone = nullptr;
    }

    //  Show contact's specifications
    void showSpecifications() const noexcept
    {
        cout << " Contact's specifications\n" <<
            "ID: " << *(this->_ID) << endl <<
            "Name: " << *(this->_name) << endl <<
            "Surname: " << *(this->_surname) << endl <<
            "Gmail: " << *(this->_gMail) << endl <<
            "Telephone: " << *(this->_telephone) << endl << endl;
    }

    //  Destructor
    ~Contact()
    {
        delete this->_ID;
        delete this->_name;
        delete this->_surname;
        delete this->_gMail;
        delete this->_telephone;
    }

};

int Contact::_staticID = 0;