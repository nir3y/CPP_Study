class Sub
{
	int a, b;
public:
	void setValue(int x, int y);
	int calculate;

};

void Sub::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Sub::calculate()
{
	return a - b;
}