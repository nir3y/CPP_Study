#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---- Player 클래스 선언부 ----
class Player
{
	wstring name;

public:
	void setPlayer(wstring name);
	wstring getName();
};

// ---- Player 클래스 구현부 ----
void Player::setPlayer(wstring name)
{
	this->name = name;
}

wstring Player::getName()
{
	return name;
}


// ---- WordGame 클래스 선언부 ----
class WordGame
{
	wstring currWord;
	vector<Player>p;
	int size;
public:
	WordGame(wstring currWord);
	void createPlayer();
	void run();
};

// ---- WordGame 클래스 구현부 ----

WordGame::WordGame(wstring currWord)
{
	this->currWord = currWord;
}

void WordGame::createPlayer()
{
	wstring name;
	int n;
	while (1)
	{
		wcout << L"게임에 참가하는 인원은 몇명입니까? >> ";
		cin >> n;

		if (n < 2) //참가 인원이 2명 미만이라면, 다시 입력 받기
		{
			wcout << L"게임 참가 인원은 2명 이상이여야 합니다. 다시 입력하세요." << endl;
			continue;
		}
		else
		{
			break;
		}
	}

	size = n;
	p.reserve(size);

	for (int i = 0; i < size; i++)
	{
		Player player;
		wcout << L"참가자의 이름을 입력하세요. 빈칸 없이 >> ";
		wcin >> name;
		player.setPlayer(name);
		p.push_back(player);
	}
}

void WordGame::run()
{
	wstring nextWord;
	wcout << L"끝말 잇기 게임을 시작합니다." << endl;
	createPlayer();

	wcout << L"시작하는 단어는 " << currWord << L"입니다." << endl;


	while (1)
	{

		for (int i = 0; i < size; i++)
		{
			wcout << p.at(i).getName() << L">> ";
			wcin >> nextWord;

			//끝말 잇기 성공했을 때
			if (currWord.back() == nextWord.front())
			{
				currWord = nextWord;
			}

			//끝말 잇기 실패했을 때
			else
			{
				wcout << L"일치하지 않습니다. " << p.at(i).getName() << L"의 패배입니다." << endl;
				wcout << L"끝말 잇기 게임을 종료합니다." << endl;
				return;
			}

		}
	}

}



int main()
{
	locale::global(locale(""));

	wstring startWord = L"아버지";
	WordGame game(startWord);
	game.run();

	return 0;
}