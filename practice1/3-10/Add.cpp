class Add
{
	int a, b;
public:
	void setValue(int x, int y);
	int calculate;

};

void Add::setValue(int x, int y)
{
	a = x;
	b = y;
}

int Add::calculate()
{
	return a + b;
}

