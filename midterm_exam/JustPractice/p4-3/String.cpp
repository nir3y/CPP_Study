#include <iostream>
#include <string>
using namespace std;

int main()
{
	int start = 0;
	int count = 0;
	string text;
	cout << "���ڿ��� �Է��ϼ��� >> ";
	getline(cin, text);
	

	while (true)
	{
		//�׷��� start�� a�� ��Ÿ�� ��ġ�� �ε����� �־ ������ a�� ��� ã�� ��.
		start = text.find('a',start); // a�� ã������ a�� �ε��� ���� ��ȯ��.
		
		if (start == std::string::npos)
		{
			break;
		}
		count++;
		start++;

	}

	cout << "a�� ������ " << count << "�� �Դϴ�." << endl;


	system("pause");
	return 0;
}