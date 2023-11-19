#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*
	string s, first, sub;

	cout << "문자열을 입력하세요. (단, 한글 안됨)" << endl;
	getline(cin, s, '\n');//엔터키 눌렀을 때 까지 
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		first = s.substr(0, 1); //substr는 s string의 몇번째 글짜 가져올지
		sub = s.substr(1, len - 1);
		s = sub + first;
		cout << s << endl;
	}
	*/

	//좀 더 개선한 코드

	locale::global(locale(""));

	wcout << L"문자열을 입력하세요. (한글 가능)" << endl;

	wstring s;
	getline(wcin, s, L'\n');
	int len = s.size();

	for (int i = 0; i < len; i++)
	{
		wchar_t firstChar = s[0];
		s.erase(0, 1); // 맨 앞 문자 삭제
		s += firstChar;
		wcout << s << endl;

	}
	system("pause");
	return 0;
}