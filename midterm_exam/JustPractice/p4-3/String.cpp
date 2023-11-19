#include <iostream>
#include <string>
using namespace std;

int main()
{
	int start = 0;
	int count = 0;
	string text;
	cout << "문자열을 입력하세요 >> ";
	getline(cin, text);
	

	while (true)
	{
		//그래서 start에 a가 나타난 위치의 인덱스를 넣어서 이후의 a를 계속 찾는 것.
		start = text.find('a',start); // a를 찾았을때 a의 인덱스 값을 반환함.
		
		if (start == std::string::npos)
		{
			break;
		}
		count++;
		start++;

	}

	cout << "a의 개수는 " << count << "개 입니다." << endl;


	system("pause");
	return 0;
}