#include <iostream>
#include <string>


using namespace std;

class Big_top_int
{
private:
	unsigned int ostat;
	int step;
	bool negative_flag = false;
	int *d2_a = new int[64];
	void converter(int *d2_a)
	{
		int i;
		for (i = 0; i < 64; i++)
			if (d2_a[i] == 1)
				d2_a[i] = 0;
			else
				d2_a[i] = 1;
		bool fl = true;
		i = 63;
		while ((fl) && (i != 0))
		{
			fl = false;
			d2_a[i]++;
			if (d2_a[i] % 2 == 0)
			{
				d2_a[i] = 0;
				i--;
				fl = true;
			}
		}
	}

	void d2_into_d10()
	{
		bool fl = true;
		if (d2_a[0] == 1)
		{
			fl = false;
			converter(d2_a);
		}
		for (int i = 32; i < 64; i++)
		{
			ostat = ostat * 2 + d2_a[i];
		}
		for (int i = 0; i < 32; i++)
		{
			step = step * 2 + d2_a[i];
		}
		if (!fl)
		{
			step = -step;
			converter(d2_a);
		}

	}

	bool test_zero(int *d2_a)
	{
		bool fl = true;
		for (int i = 1; i < 64; i++)
		{
			if (d2_a[i] == 1)
				fl = false;
		}
		return fl;
	}

	bool test_poln_poz(int *d2_a)
	{
		bool fl_poz = true;
		bool fl_neg = true;
		if (d2_a[0] == 1)
		{
			for (int i = 1; i < 64; i++)
			{
				if (d2_a[i] == 1)
					fl_neg = false;
			}
			fl_poz = false;
		}
		else
		{
			fl_neg = false;
			for (int i = 1; i < 64; i++)
			{
				if (d2_a[i] == 0)
					fl_poz = false;
			}
		}
		if (fl_neg)
			return fl_neg;
		else
		{
			return fl_poz;
		}
	}


public:
	Big_top_int()
	{
		ostat = 0;
		step = 0;
		for (int i = 0; i < 64; i++)
			d2_a[i] = 0;
	}

	Big_top_int(char *ch, int length)
	{
		int *d10_a = new int[length + 1];
		bool fl_neg = true;
		int i = 0;
		if (ch[0] == '-')
		{
			fl_neg = false;
			i = 1;
		}
		for (; i < length; i++)
		{
			d10_a[i] = ch[i] - 48;
		}
		bool fl = true;
		int length_int;
		if (fl_neg)
			length_int = 0;
		else
			length_int = 1;


		for (int i = 0; i < 64; i++)
			d2_a[i] = 0;
		int j = 0;
		while (fl)
		{
			for (int i = length_int; i < length - 1; i++)
			{
				d10_a[i + 1] = (d10_a[i] % 2) * 10 + d10_a[i + 1];
				d10_a[i] = d10_a[i] / 2;
			}
			d2_a[63 - j] = d10_a[length - 1] % 2;
			j++;
			d10_a[length - 1] = d10_a[length - 1] / 2;
			fl = false;
			while ((length_int < length) && (d10_a[length_int] == 0))
				length_int++;
			if (length_int != length)
				fl = true;
		}
		delete d10_a;
		if (d2_a[0] == 1)
		{
			d2_a[0] = 0;
			for (int i = 1; i < 64; i++)
				d2_a[i] = 1;
		}
		/*for (int i = 0; i < 64; i++)
		{
			cout << d2_a[i];
		}
		cout << "\n";*/
		if (!fl_neg)
		{
			converter(d2_a);
			negative_flag = true;
		}
		/*for (int i = 0; i < 64; i++)
		{
			cout << d2_a[i];
		}
		cout << "\n";*/
		ostat = 0;
		step = 0;
	}

	void out()
	{
		d2_into_d10();
		if (!negative_flag)
			cout << step << " * 2^32 + " << ostat << "\n";
		else
			cout << step << " * 2^32 - " << ostat << "\n";
	}

	Big_top_int operator=(const Big_top_int a)
	{
		step = a.step;
		ostat = a.ostat;
		for (int i = 0; i < 64; i++)
			d2_a[i] = a.d2_a[i];
		negative_flag = a.negative_flag;
		return *this;
	}

	Big_top_int operator=(int a)
	{
		if (a < 0)
		{
			negative_flag = true;
			a = -a;
		}
		int *d2 = new int[64];
		for (int i = 0; i < 63; i++)
			d2[i] = 0;
		int i = 0;
		while (a != 0)
		{
			d2[i] = a % 2;
			a = a / 2;
			i++;
		}

		int j;
		for (j = 0; j < i; j++)
		{
			d2_a[63 - j] = d2[j];
		}
		for (i = j; 63 - i >= 0; i++)
			d2_a[63 - i] = 0;
		if (negative_flag)
			converter(d2_a);
		delete d2;
		return *this;
	}

	Big_top_int operator+(const Big_top_int a)
	{
		Big_top_int sum;
		if (((d2_a[0] == 0) && (a.d2_a[0] == 0)) || ((d2_a[0] == 1) && (a.d2_a[0] == 1)))
		{
			sum.negative_flag = negative_flag;
			if (sum.negative_flag)
			{
				converter(a.d2_a);
				converter(d2_a);
			}
			for (int i = 63; i > 1; i--)
			{
				sum.d2_a[i] = d2_a[i] + a.d2_a[i] + sum.d2_a[i];
				if (sum.d2_a[i] > 1)
				{
					sum.d2_a[i - 1] = sum.d2_a[i - 1] + sum.d2_a[i] / 2;
					sum.d2_a[i] = sum.d2_a[i] % 2;
				}
			}
			sum.d2_a[1] = d2_a[1] + a.d2_a[1] + sum.d2_a[1];
			if (sum.d2_a[1] > 1)
				for (int i = 1; i < 64; i++)
					sum.d2_a[i] = 1;

			if (sum.negative_flag)
			{
				converter(a.d2_a);
				converter(d2_a);
				converter(sum.d2_a);
			}

		}
		else
		{
			for (int i = 63; i > 0; i--)
			{
				sum.d2_a[i] = d2_a[i] + a.d2_a[i] + sum.d2_a[i];
				if (sum.d2_a[i] > 1)
				{
					sum.d2_a[i - 1] = sum.d2_a[i - 1] + sum.d2_a[i] / 2;
					sum.d2_a[i] = sum.d2_a[i] % 2;
				}
			}
			sum.d2_a[0] = (d2_a[0] + a.d2_a[0] + sum.d2_a[0]) % 2;
			if (sum.d2_a[0] == 1)
				sum.negative_flag = true;
		}
		return sum;
	}

	Big_top_int operator-(const Big_top_int a)
	{
		Big_top_int Difference;
		converter(a.d2_a);
		Difference = *this + a;
		converter(a.d2_a);
		return Difference;
	}

	Big_top_int operator*(const Big_top_int a)
	{
		Big_top_int mult, obl_a, ed;
		obl_a = a;
		Big_top_int obl_this = *this;
		ed = 1;
		if (a.negative_flag)
		{
			converter(obl_this.d2_a);
			ed = -1;
		}
		while ((test_poln_poz(mult.d2_a) == false) && (test_zero(obl_a.d2_a) == false))
		{
			mult = mult + obl_this;
			obl_a = obl_a - ed;
		}
		delete obl_a.d2_a;
		delete ed.d2_a;
		return mult;
	}

	Big_top_int operator%(const Big_top_int a)
	{
		Big_top_int raz;
		bool neg_raz, neg_this;
		if (negative_flag)
		{
			converter(d2_a);
			raz = *this;
			neg_this = !negative_flag;
			neg_raz = neg_this;
		}
		else
		{
			raz = *this;
			neg_this = negative_flag;
			neg_raz = neg_this;
		}
		if (a.negative_flag)
			converter(a.d2_a);
		bool check_cycle = false;
		while (neg_raz == neg_this)
		{
			raz = raz - a;
			neg_raz = raz.negative_flag;
			check_cycle = true;
		}
		if (check_cycle)
			raz = raz + a;
		if (negative_flag)
		{
			converter(d2_a);
			raz.negative_flag = negative_flag;
		}
		if (a.negative_flag)
			converter(a.d2_a);
		return raz;
	}

	Big_top_int operator/(const Big_top_int a)
	{
		Big_top_int raz, num, ed;
		ed = 1;
		bool neg_raz, neg_this;
		bool neg_num = false;
		if (negative_flag)
		{
			converter(d2_a);
			raz = *this;
			neg_this = !negative_flag;
			neg_raz = neg_this;
			neg_num = !neg_num;
		}
		else
		{
			raz = *this;
			neg_this = negative_flag;
			neg_raz = neg_this;
		}
		if (a.negative_flag)
		{
			converter(a.d2_a);
			neg_num = !neg_num;
		}
		bool check_cycle = false;
		while (neg_raz == neg_this)
		{
			raz = raz - a;
			neg_raz = raz.negative_flag;
			num = num + ed;
			check_cycle = true;
		}
		if (check_cycle)
			num = num - ed;
		if (negative_flag)
			converter(d2_a);
		if (a.negative_flag)
			converter(a.d2_a);
		num.negative_flag = neg_num;
		return num;
	}

};


void main()
{
	setlocale(LC_ALL, "Russian");
	char ch[100];
	cout << "Введите 2 числа:\n";
	gets_s(ch);
	int length = strlen(ch);
	Big_top_int a = Big_top_int(ch, length);
	gets_s(ch);
	length = strlen(ch);
	Big_top_int b = Big_top_int(ch, length);
	cout << "Выберете действие:\n";
	char done;
	cin >> done;
	Big_top_int c;
	switch (done)
	{
	case '+':
	{
		c = a + b;
		c.out();
		break;
	}
	case '-':
	{
		c = a - b;
		c.out();
		break;
	}
	case '*':
	{
		c = a * b;
		c.out();
		break;
	}
	case '/':
	{
		c = a / b;
		c.out();
		break;
	}
	case '%':
	{
		c = a % b;
		c.out();
		break;
	}
	default:
	{
		cout << "Такой операции пока нет =(\n";
		break;
	}
	}
	while (true);

}

















/*
..........................／＞　　フ
....................... | 　_　 _ |
......................／` ミ ＿xノ
..................../　　　　 |
................../　 ヽ　　 ﾉ
................│　　|　|　|
..........／￣|　　 |　|　|
..........| (￣ヽ＿_ヽ___ )
...........＼二つ
*/