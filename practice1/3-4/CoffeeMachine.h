#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

class CoffeeMachine
{
	int water, coffee, sugar;
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void fill();
	void show();
};



#endif // !COFFEEMACHINE_H

