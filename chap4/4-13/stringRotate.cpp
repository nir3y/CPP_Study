#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*
	string s, first, sub;

	cout << "���ڿ��� �Է��ϼ���. (��, �ѱ� �ȵ�)" << endl;
	getline(cin, s, '\n');//����Ű ������ �� ���� 
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		first = s.substr(0, 1); //substr�� s string�� ���° ��¥ ��������
		sub = s.substr(1, len - 1);
		s = sub + first;
		cout << s << endl;
	}
	*/

	//�� �� ������ �ڵ�

	locale::global(locale(""));

	wcout << L"���ڿ��� �Է��ϼ���. (�ѱ� ����)" << endl;

	wstring s;
	getline(wcin, s, L'\n');
	int len = s.size();

	for (int i = 0; i < len; i++)
	{
		wchar_t firstChar = s[0];
		s.erase(0, 1); // �� �� ���� ����
		s += firstChar;
		wcout << s << endl;

	}
	system("pause");
	return 0;
}