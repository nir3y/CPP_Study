#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---- Player Ŭ���� ����� ----
class Player
{
	wstring name;

public:
	void setPlayer(wstring name);
	wstring getName();
};

// ---- Player Ŭ���� ������ ----
void Player::setPlayer(wstring name)
{
	this->name = name;
}

wstring Player::getName()
{
	return name;
}


// ---- WordGame Ŭ���� ����� ----
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

// ---- WordGame Ŭ���� ������ ----

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
		wcout << L"���ӿ� �����ϴ� �ο��� ����Դϱ�? >> ";
		cin >> n;

		if (n < 2) //���� �ο��� 2�� �̸��̶��, �ٽ� �Է� �ޱ�
		{
			wcout << L"���� ���� �ο��� 2�� �̻��̿��� �մϴ�. �ٽ� �Է��ϼ���." << endl;
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
		wcout << L"�������� �̸��� �Է��ϼ���. ��ĭ ���� >> ";
		wcin >> name;
		player.setPlayer(name);
		p.push_back(player);
	}
}

void WordGame::run()
{
	wstring nextWord;
	wcout << L"���� �ձ� ������ �����մϴ�." << endl;
	createPlayer();

	wcout << L"�����ϴ� �ܾ�� " << currWord << L"�Դϴ�." << endl;


	while (1)
	{

		for (int i = 0; i < size; i++)
		{
			wcout << p.at(i).getName() << L">> ";
			wcin >> nextWord;

			//���� �ձ� �������� ��
			if (currWord.back() == nextWord.front())
			{
				currWord = nextWord;
			}

			//���� �ձ� �������� ��
			else
			{
				wcout << L"��ġ���� �ʽ��ϴ�. " << p.at(i).getName() << L"�� �й��Դϴ�." << endl;
				wcout << L"���� �ձ� ������ �����մϴ�." << endl;
				return;
			}

		}
	}

}



int main()
{
	locale::global(locale(""));

	wstring startWord = L"�ƹ���";
	WordGame game(startWord);
	game.run();

	return 0;
}