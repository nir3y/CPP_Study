#include <iostream>
#include <string>
using namespace std;

class Account
{
	string name;
	int id;
	int balance;
public:
	Account(string n, int i, int bal);
	void deposit(int money);
	int withdraw(int money);
	int inquiry();
	string getOwner() { return name; }

};

Account::Account(string n, int i, int bal)
{
	name = n;
	id = i;
	balance = bal;
}

void Account::deposit(int money)
{
	balance += money;
}

int Account::withdraw(int money)
{
	if (money > balance)
	{
		money = balance;
		balance = 0;

	}
	else
	{
		balance -= money;
	}
	return money;
}

int Account::inquiry()
{
	return balance;
}


int main()
{
	Account a("정예린", 123, 5000);
	a.deposit(10000);
	cout << a.getOwner() << "의 잔액은" << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout<<a.getOwner()<<"의 잔액은"<< a.inquiry() << endl;

	return 0;
}