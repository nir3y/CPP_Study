#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int price;
    int pages;
public:
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title; this->price = price; this->pages = pages;
    }
    void show() {
        cout << title << ' ' << price << "�� " << pages << " ������" << endl;
    }
    string getTitle() { return title; }
    friend bool  operator ==(Book book, int price);
    friend bool operator ==(Book book, string title);
    friend bool operator ==(Book book, int pages);
   
};

bool operator ==(Book book, int price)
{
    if (book.price == price)
        return true;
    else
        return false;
}

bool operator ==(Book book, string title)
{
    if (book.title == title)
        return true;
    else
        return false;
}

bool operator ==(Book book, Book book1)
{
    if (book == book1)
        return true;
    else
        return false;
}



int main() {
    Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
    if (a == 30000) cout << "���� 30000��" << endl; // price ��
    if (a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl; // å title ��
    if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl; // title, price, pages ��� �� 
}


