#include <iostream>
#include <string>

using namespace std;

class Player {
	string name; // ���� �������� �̸�
	string word; // �����ڰ� ���� �ܾ�
public:
	void setName(string name) {
		this->name = name;
	}
	string getName() { return name; }
	string sayWord();
	bool succeed(string lastWord);
};




string Player::sayWord() {
	cout << name + ">>";
	cin >> word;
	return word;
}

bool Player::succeed(string lastWord) {
	int lastIndex = lastWord.length() - 2;

	if (lastWord.at(lastIndex) == word.at(0) &&
		lastWord.at(lastIndex + 1) == word.at(1))
		return true;
	else
		return false;
}

class Player;

class WordGame {
private:
	string title;
	string startWord;
	int nPlayers;
	Player* players;
	bool createPlayers();
public:
	WordGame(string title, string startWord);
	void run();
	~WordGame();
};

WordGame::WordGame(string title, string startWord) {
	this->title = title;
	this->startWord = startWord;
	this->players = NULL;
}

WordGame::~WordGame() {
	if (this->players != NULL)
		delete[] this->players;
}

bool WordGame::createPlayers() {
	int n;
	cout << title << " ������ �����մϴ�" << endl;
	cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�?";
	cin >> n;
	if (n < 2) {
		cout << "�ο����� 2 �̻��Դϴ� " << endl;
		return false;
	}
	nPlayers = n;
	players = new Player[n];
	if (!players)
		return false;

	string playerName;
	for (int i = 0; i < nPlayers; i++) {
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ ����>>";
		cin >> playerName;
		players[i].setName(playerName);
	}

	return true;
}
void WordGame::run() {
	if (!createPlayers()) // ������ ���� 2���� ��4���� ������ ���� ���
		return;

	string lastWord = startWord;
	cout << "�����ϴ� �ܾ�� " + lastWord + "�Դϴ�" << endl;
	int next = 0; // �����ڵ��� ������� ����

	// ������ ���� ������ ����
	while (true) {
		// next �����ڰ� �ܾ ���ϵ��� �Ѵ�.
		string newWord = players[next].sayWord();

		// next �����ڰ� �����Ͽ����� �˻�.
		if (!players[next].succeed(lastWord)) {
			cout << players[next].getName() + "�� �����ϴ�.";
			break; // ������ �����Ѵ�.
		}
		next++; // ���� ������
		//next�� �������� �������� ���� �����ϴ� ���� ���´�.
			next %= nPlayers; // lastWord = newWord;
	}
}
int main() {
	WordGame* game;
	game = new WordGame("�����ձ�", "�ƹ���");
	game->run();
	delete game;
}

