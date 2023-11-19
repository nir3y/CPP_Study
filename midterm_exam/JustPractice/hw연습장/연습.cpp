#include <iostream>
#include <string>

using namespace std;

class Player {
	string name; // 게임 참가자의 이름
	string word; // 참가자가 말한 단어
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
	cout << title << " 게임을 시작합니다" << endl;
	cout << "게임에 참가하는 인원은 몇명입니까?";
	cin >> n;
	if (n < 2) {
		cout << "인원수는 2 이상입니다 " << endl;
		return false;
	}
	nPlayers = n;
	players = new Player[n];
	if (!players)
		return false;

	string playerName;
	for (int i = 0; i < nPlayers; i++) {
		cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
		cin >> playerName;
		players[i].setName(playerName);
	}

	return true;
}
void WordGame::run() {
	if (!createPlayers()) // 참가자 수가 2보다 적4던지 문제가 생긴 경우
		return;

	string lastWord = startWord;
	cout << "시작하는 단어는 " + lastWord + "입니다" << endl;
	int next = 0; // 참가자들의 순서대로 증가

	// 게임이 끝날 때까지 루프
	while (true) {
		// next 참가자가 단어를 말하도록 한다.
		string newWord = players[next].sayWord();

		// next 참가자가 성공하였는지 검사.
		if (!players[next].succeed(lastWord)) {
			cout << players[next].getName() + "이 졌습니다.";
			break; // 게임을 종료한다.
		}
		next++; // 다음 참가자
		//next가 참가자의 개수보다 많게 증가하는 것을 막는다.
			next %= nPlayers; // lastWord = newWord;
	}
}
int main() {
	WordGame* game;
	game = new WordGame("끝말잇기", "아버지");
	game->run();
	delete game;
}

