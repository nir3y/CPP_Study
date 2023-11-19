#include <iostream>
#include <string>

using namespace std;


int main() {
	cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료)" << endl;
	string text;


	while (true) {
		cout << ">> ";
		getline(cin, text, '\n');
		if (text == "exit") break;

		int size = text.length();
		int n = size / 2;

		for (int i = 0; i < n; i++) {
			char tmp = text[i];
			text[i] = text[size - i - 1];
			text[size - i - 1] = tmp;
		}
		cout << text << endl;

	}
	system("pause");
	return 0;
}


