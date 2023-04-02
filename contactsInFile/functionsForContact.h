#pragma once

bool checkOtherSymbolInString(const string& text)
{
	bool check = false;

	//	If there is other symbol in string, then return true
	int symbol;
	for (int i = 0; i < text.length(); i++)
	{
		symbol = int(text[i]);
		if ((symbol >= 0 && symbol <= 64) ||
			(symbol >= 91 && symbol <= 96) ||
			(symbol >= 123 && symbol <= 255))
		{
			check = true;
			break;
		}
	}
	return check;
}

bool checkOperatorInTelephone(const string& telephone)
{
	bool check = false;

	//	Create operator from sent telephone
	string oper = "";
	for (int i = 0; i < 3; i++)
	{
		oper += telephone[i];
	}

	//	Check operator 
	if (oper == "070" || oper == "077" || oper == "050" ||
		oper == "051" || oper == "055" || oper == "099")
	{
		check = true;
	}

	return check;
}

bool checkOtherSymbolInTelephone(const string& telephone)
{
	bool check = false;

	//	Check other symbol in telephone
	for (int i = 0, symbol; i < telephone.length(); i++)
	{
		symbol = int(telephone[i]);
		if (symbol < 48 && symbol > 58)
		{
			check = true;
			break;
		}
	}

	return check;
}