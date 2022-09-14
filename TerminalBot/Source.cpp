#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

string PasswordEncryption(string UserName, string Password);
string Login();
void Settings();
string FlipCoin();
void Settings();
void CreateNewAccount();

void Settings()
{
	srand(time(0));
}

void CreateNewAccount()
{
	fstream Accounts;
	Accounts.open("AccountsAndPassword.dat", ios::out | ios::in | ios::app);

	string UserName;
	string PassWord;
	string PassWordConfirmation;

	cout << "Type in your Username -> ";
	cin >> UserName;
	
	cout << "\nType in your Password -> ";
	cin >> PassWord;

	cout << "\nConfirm your Password -> ";
	cin >> PassWordConfirmation;

	if (PassWordConfirmation == PassWord)
	{
		Accounts << PasswordEncryption(UserName, PassWord) << endl;
	}

	Login();
}

string Login()
{
	fstream Accounts;
	Accounts.open("AccountsAndPassword.dat", ios::out | ios::in | ios::app);
	
	string UserName;
	string PassWord;
	string Command;
	string EncryptedPassword;
	string DataPassword;

	cout << "Hello, type in your Username -> " << endl;
	cout << "Or if u wanna to create new Account type in: New -> ";
	cin >> Command;

	if (!Accounts.is_open())
	{
		cout << "Fatal Error" << endl;
		return ;
	}


	if (Command == "New")
	{
		CreateNewAccount();
	}
	UserName = Command;
	cout << "Type in your password -> ";
	cin >> PassWord;
	EncryptedPassword = PasswordEncryption(UserName, PassWord);

	cout << Accounts.gcount() << endl;


	while (getline(Accounts, DataPassword))
	{
		cout << DataPassword << endl;
		if (EncryptedPassword == DataPassword)
		{
			cout << "Success. Welcome back" << endl;
			cout << DataPassword << endl;
			return UserName;
		}
	}
	cout << "Wrong User Name or Password\nTry Again" << endl;
	Login();	
}

void MainMenu()
{
	cout << "Choose option" << endl;

}

string FlipCoin()
{
	string CoinSide;
	int RandomNumber = rand() % 2;

	(RandomNumber == 0 ? CoinSide = "Orel" : CoinSide = "Reshka");
	return CoinSide;
}

string PasswordEncryption(string UserName, string Password)
{
	string EncryptedPassword;

	EncryptedPassword = UserName + "&" + Password;

	return EncryptedPassword;
}

void main()
{	
	string UserName = Login();

	FlipCoin();
}