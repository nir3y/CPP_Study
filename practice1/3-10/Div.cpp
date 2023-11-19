class Div
{
	int a, b;
public:
	void setValue(int x, int y);
	int calculate;

};

void Div::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Div::calculate()
{
	return a / b;
}