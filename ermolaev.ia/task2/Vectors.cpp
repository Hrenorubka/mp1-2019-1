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

	Vectors(int len, double *mas)
	{
		length = len;
		a = new double[length];
		for (int i = 0; i < length; i++)
			a[i] = mas[i];
	}

	Vectors(const Vectors &v)
	{
		length = v.length;
		a = new double[length];
		for (int i = 0; i < length; i++)
			a[i] = v.a[i];
		cout << "xyi\n";
	}

	~Vectors()
	{
		delete[] a;
	}

	void innum(int num, double znach)
	{
		if (num < length)
			a[num] = znach;
		else
		{
			cout << "num > length of vector";
		}
	}

	void innum(double *mas)
	{
		for (int i = 0; i < length; i++)
		{
			a[i] = mas[i];
		}
	}

	const void  out()
	{
		cout << a[0] << " * x0";
		for (int i = 1; i < length; i++)
			cout << " + " << a[i] << " * x" << i;
		cout << "\n";
	}

	const int out_num(int num)
	{
		return a[num];
	}

	void inlen(int len)
	{
		if (length != 0)
			delete a;
		length = len;
		if (length <= 0)
			throw;
		a = new double[length];
	}
	const int  lenout()
	{
		return length;
	}

	const double len_v()
	{
		double v = 0;
		for (int i = 0; i < length; i++)
		{
			v = v + a[i] * a[i];
		}
		v = sqrt(v);
		return v;
	}

	const double skal_proiz(const Vectors& v)
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


};



void main()
{

	Vectors trre, errt, sum;
	int num, obl_i;
	double obl_d;
	double *pop;
	bool fl = 1;
	while (fl)
	{
		cout << "input size first vector\n";
		cin >> num;
		trre.inlen(num);
		cout << "input coordinates first vector\n";
		pop = new double[num];
		for (int i = 0; i < num; i++)
		{
			cin >> pop[i];
		}
		trre.innum(pop);
		delete pop;
		cout << "input num of component\n";
		cin >> num;
		cout << "This component:\n";
		obl_d = trre.out_num(num - 1);
		cout << obl_d << "\n";
		cout << "size of this vector\n";
		obl_i = trre.lenout();
		cout << obl_i << "\n";
		cout << "length of this vector:\n" << trre.len_v() << "\n";
		cout << "input size second vector\n";
		cin >> num;
		errt.inlen(num);
		cout << "input coordinates second vector\n";
		pop = new double[num];
		for (int i = 0; i < num; i++)
		{
			cin >> pop[i];
		}
		errt.innum(pop);
		delete pop;
		cout << "their summ:\n";
		sum = trre + errt;
		sum.out();
		cout << "their scalar product:\n" << trre.skal_proiz(errt) << "\n";
		cout << "exit?";
		cin >> fl;
	}
}