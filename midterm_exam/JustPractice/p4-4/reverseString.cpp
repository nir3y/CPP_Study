#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "�Ʒ��� �� ���� �Է��ϼ���. (exit �Է� �� ����)" << endl;
	while (true)
	{
		cout << ">>";
		getline(cin, text, '\n');
		if (text == "exit")
		{
			break;
		}

		int len = text.length();
		int mid = len / 2;

		for (int i = 0; i < mid; i++)
		{
			char tmp; //�ӽ÷� ����
			tmp = text[i];
			text[i] = text[len - 1 - i];
			text[len - 1 - i] = tmp;

		}
		cout << text << endl;
	}

	system("pause");
	return 0;
}