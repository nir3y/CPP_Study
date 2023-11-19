class Mul
{
	int a, b;
public:
	void setValue(int x, int y);
	int calculate;

};

void Mul::setValue(int x,int  y)
{
	a = x;
	b = y;
}

int Mul::calculate()
{
	return a * b;
}