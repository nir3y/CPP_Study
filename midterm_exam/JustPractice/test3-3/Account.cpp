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
	string getOwner();//������ ���� 
	int withdraw(int money);//�ܾ�
	int inquiry();//���� �ܾ�

};

Account::Account(string n , int i , int bal)
{
	name = n; id = i; balance = bal;
}

void Account::deposit(int money)
{
	balance += money;

}

string Account::getOwner()
{
	return name;
}

int Account::withdraw(int money)
{
	if (money > balance)
	{
		money = balance; // ����� ���� �ݾ׸�ŭ�� �� �� ������.
		balance = 0;
	}

	balance -= money;

	return money;
}

int Account::inquiry()
{
	return balance;
}


int main() {
	Account a("kitae", 1, 5000); // id 1��, �ܾ� 5000��, �̸��� kitae�� ���� ����
	a.deposit(50000);// 50000�� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	int money = a.withdraw(20000);// 20000�� ���. withdraw()�� ����� ���� �ݾ� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	system("pause");
	return 0;
}
