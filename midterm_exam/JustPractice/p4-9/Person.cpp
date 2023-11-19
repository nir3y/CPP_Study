#include <iostream>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};



int main()
{

	PersonManager manager(3);
	manager.show();
	manager.search();


	system("pause");
	return 0;

}