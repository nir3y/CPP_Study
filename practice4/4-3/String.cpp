#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "���ڿ��� �Է��ϼ��� >>";
	getline(cin, text);
	
	int count = 0;
	int findex = 0;

	while (true)
	{
		findex = text.find('a', findex);

		if (findex == -1)
		{
			break;
		}
		count++;
		findex++;
	}

	cout << "���� a�� ������ "<<count<<"�� �Դϴ�."<<endl;


	system("pause");
	return 0;
}