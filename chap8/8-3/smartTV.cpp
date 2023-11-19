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
	// 32 인치 크기에 "192.0.0.1"의 인터넷 주소를 가지는 스마트 TV 객체 생성
	SmartTV  htv("192.0.0.1", 32);
	cout << "size= " << htv.getSize() << endl;
	cout << "videoIn= " << boolalpha << htv.getVideoIn() << endl;
	cout << "IP = " << htv.getIpAddr() << endl;

	system("pause");
	return 0;
}
