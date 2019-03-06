#include <iostream>



using namespace std;

class Vectors
{

	double *a;
	int length;
public:

	Vectors()
	{
		length = 0;
	}

	~Vectors()
	{

	}

	void innum(int num)
	{
		cin >> a[num];
	}

	void innum()
	{
		for (int i = 0; i < length; i++)
		{
			cin >> a[i];
		}
	}
	void  out()
	{
		cout << a[0] << " * x0";
		for (int i = 1; i < length; i++)
			cout << " + " << a[i] << " * x" << i;
		cout << "\n";
	}

	void  out_num(int num)
	{
		cout << a[num] << "\n";
	}

	void inlen(int len)
	{
		length = len;
		if (length <= 0)
			throw;
		a = new double[length];
	}
	void  lenout()
	{
		cout << length << "\n";
	}

	double len_v()
	{
		double v = 0;
		for (int i = 0; i < length; i++)
		{
			v = v + a[i] * a[i];
		}
		v = sqrt(v);
		return v;
	}

	double skal_proiz(const Vectors& v)
	{
		double proiz = 0;
		if (length != v.length)
			throw 1;
		for (int i = 0; i < length; i++)
			proiz = proiz + a[i] * v.a[i];
		return proiz;
	}

	Vectors& operator=(const Vectors& v)
	{
		Delete();
		inlen(v.length);
		for (int i = 0; i < length; i++)
			a[i] = v.a[i];
		return *this;
	}

	Vectors operator+(const Vectors& v)
	{
		Vectors sum;
		sum.inlen(length);
		for (int i = 0; i < length; i++)
			sum.a[i] = a[i] + v.a[i];

		return sum;
	}

	void Delete()
	{
		delete a;
	}
};



void main()
{

	Vectors trre, errt, sum;
	int num;
	bool fl = 1;
	while (fl)
	{
		cout << "input size first vector\n";
		cin >> num;
		trre.inlen(num);
		cout << "input coordinates first vector\n";
		trre.innum();
		cout << "input num of component\n";
		cin >> num;
		cout << "This component:\n";
		trre.out_num(num - 1);
		cout << "size of this vector\n";
		trre.lenout();
		cout << "length of this vector:\n" << trre.len_v() << "\n";
		cout << "input size second vector\n";
		cin >> num;
		errt.inlen(num);
		cout << "input coordinates second vector\n";
		errt.innum();
		cout << "their summ:\n";
		sum = trre + errt;
		sum.out();
		cout << "their scalar product:\n" << trre.skal_proiz(errt) << "\n";
		cout << "exit?";
		cin >> fl;
	}
}
