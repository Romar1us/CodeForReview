#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <fstream>

#define SIDE
#define TEST

class Account;

using namespace std;


class Account
{
private:

	string UserName;
	string Password;
	fstream Accounts;

	void OpenFile()
	{
		Accounts.open("AccountsAndPassword.dat", ios::out | ios::in);
	}

	void Login(string UserName, string Password)
	{
		string DataPassword;

		while (getline(Accounts, DataPassword))
		{
			if (PasswordEncryption(UserName, Password) == DataPassword)
			{
				cout << "Success. Welcome back" << endl;
				SetUserName(UserName);
				SetPassword(Password);
				return;
			}
		}
		cout << "Wrong User Name or Password\nTry Again" << endl;
	}

public:

	Account()
	{
		OpenFile();

		string Command;
		string Password;

		cout << "Hello, type in your Username -> " << endl;
		cout << "Or if u wanna to create new Account type in: New -> ";

		cin >> Command;

		if (Command == "New")
		{
			CreateNewAccount();
		}

		cout << "Type in your password -> ";
		cin >> Password;

		this->Login(Command, Password);
	}

	bool IsFileExists()
	{
		Accounts.open("AccountsAndPassword.dat");

		return Accounts.is_open();
	}

	void CreateSaveFile()
	{
		ofstream Accounts("AccountsAndPassword.dat");
	}

	string GetUserName()
	{
		return UserName;
	}

	void SetUserName(string UserName)
	{
		this->UserName = UserName;
	}

	string GetPassword()
	{
		return Password;
	}

	void SetPassword(string Password)
	{
		this->Password = Password;
	}
	
	string PasswordEncryption(string UserName, string Password)
	{
		return UserName + "&" + Password;
	}

	void CreateNewAccount()
	{
		string PassWordConfirmation;

		cout << "Type in your Username -> ";
		cin >> UserName;

		cout << "\nType in your Password -> ";
		cin >> Password;

		cout << "\nConfirm your Password -> ";
		cin >> PassWordConfirmation;

		if (PassWordConfirmation == Password)
		{
			Accounts << PasswordEncryption(UserName, Password) << endl;
		}
	}

	
};

void Settings(Account *User)
{
	srand(time(0));

	if (!User->IsFileExists())//Checks does file exists and in the same time opens this file
	{
		User->CreateSaveFile();//If file doesn't exists creates new 
	}
}

void main()
{	
	Account User;
	Settings(&User);

	cout << User.GetUserName() << endl;

}