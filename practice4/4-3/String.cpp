#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "문자열을 입력하세요 >>";
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

	cout << "문자 a의 개수는 "<<count<<"개 입니다."<<endl;


	system("pause");
	return 0;
}