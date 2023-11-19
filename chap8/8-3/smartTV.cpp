#include <iostream>
#include <string>
using namespace std;

class TV
{
	int size;
public:
	TV();
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};

class WideTV :public TV
{
	bool videoIn;
public:
	WideTV(int size, bool videoIn) :TV(size)
	{
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};

class SmartTV :public WideTV
{
	string IpAddr;
public:
	SmartTV(string IpAddr, int size) :WideTV(size, true)
	{
		this->IpAddr = IpAddr;
	}
	string getIpAddr() { return IpAddr; }
};

int main() {
	// 32 ��ġ ũ�⿡ "192.0.0.1"�� ���ͳ� �ּҸ� ������ ����Ʈ TV ��ü ����
	SmartTV  htv("192.0.0.1", 32);
	cout << "size= " << htv.getSize() << endl;
	cout << "videoIn= " << boolalpha << htv.getVideoIn() << endl;
	cout << "IP = " << htv.getIpAddr() << endl;

	system("pause");
	return 0;
}
