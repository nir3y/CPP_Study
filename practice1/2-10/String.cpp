#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	//char str[50];
	string str; //string 헤더를 가져와서 작성한 코드

	cout << "문자열 입력 ==>";

	//cin.getline(str, 50);
	getline(cin, str);

	//int len = strlen(str);
	int len = str.length();


	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			cout << str[j];
		}
		cout << endl;
	}


	system("pause");
}