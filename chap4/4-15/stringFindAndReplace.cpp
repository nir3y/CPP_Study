#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cout << "�������� ���ڿ��� �Է��ϼ���. �Է��� ���� &�����Դϴ�." << endl;
	getline(cin, s, '&');
	cin.ignore();

	string f, r;
	cout << endl << "find:";
	
	getline(cin, f, '\n'); // �˻��� ���ڿ� �Է�
	cout << "replace:";
	getline(cin, r, '\n'); // ��ġ�� ���ڿ� �Է�

	int startIndex = 0;
	while (true) {
		int fIndex = s.find(f, startIndex); // startIndex���� ���ڿ� f �˻�
		if (fIndex == -1)
			break; // ���ڿ� s�� ������ �����Ͽ���
		s.replace(fIndex, f.length(), r); // fIndex���� ���ڿ� f�� ���̸�ŭ ���ڿ� r�� ����
		startIndex = fIndex + r.length();

	}
	cout << s << endl << endl;
	system("pause");
	return 0;

}