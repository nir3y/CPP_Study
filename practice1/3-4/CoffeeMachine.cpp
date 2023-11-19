#include <iostream>
using namespace std;

#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(int c, int w, int s)
{
	coffee = c; water = w; sugar = s;
}

void CoffeeMachine::drinkEspresso()
{
	if (coffee < 1 || water < 1)
	{
		return;
	}
	coffee--;
	water--;
}

void CoffeeMachine::drinkAmericano()
{
	if (coffee < 1 || water < 1)
	{
		return;
	}
	coffee--;
	water-=2;
}

void CoffeeMachine::drinkSugarCoffee()
{
	if (coffee < 1 || water < 1)
	{
		return;
	}
	coffee--;
	water--;
	sugar--;
}

void CoffeeMachine::fill()
{
	water = 10; coffee = 10; sugar = 10;
}
void CoffeeMachine::show()
{
	cout << "커피머신 현재 상태" << endl;
	cout << "커피:" << coffee << '\t' << "물:" << water << '\t' << "설탕:" << sugar << endl << endl;
}