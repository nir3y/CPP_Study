#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "아래에 한 줄을 입력하세요. (exit 입력 시 종료)" << endl;
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
			char tmp; //임시로 저장
			tmp = text[i];
			text[i] = text[len - 1 - i];
			text[len - 1 - i] = tmp;

		}
		cout << text << endl;
	}

	system("pause");
	return 0;
}