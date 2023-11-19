#include <iostream>
using namespace std;

#include "CoffeeMachine.h"

int main()
{
	CoffeeMachine java(5, 10, 3); //커피량, 물량, 설탕량 초기화
	java.drinkEspresso();//커피 1, 물 1 소비
	java.show();//현재 커피머신의 상태를 출력함
	java.drinkAmericano();//커피 1 , 물 2 소비
	java.drinkSugarCoffee();//커피 1, 물 1, 설탕 1 소비
	java.show();
	java.fill(); //커피 10 , 물 10, 설탕 10 채워지도록 함
	java.show();

	system("pause");
	return 0;
}