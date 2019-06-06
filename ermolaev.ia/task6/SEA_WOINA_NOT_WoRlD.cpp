#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <time.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;



class kletka
{
private:
	int type; // 0 - море(промах); 1 - море; 2 - корабль(неподбитый); 3 - корабль(подбитый); 4 - корабль(убитый); 
	int type_color;
	COORD position; // Кординаты клетки
	HANDLE console;

protected:
public:
	kletka(int a, SHORT i, SHORT j, HANDLE hConsole) : type(a), console(hConsole) { position = { j , i }; }
	kletka() : type(0) {}
	void Show();
	void Shoot();
	void KILL();
	void Set_type_cord(SHORT i, SHORT j, int t, HANDLE hConsole) { type = t; position = { j, i }; console = hConsole; type_color = 15; }
	void Set_type_cord(COORD xy, int t, HANDLE hConsole) { type = t; position = xy; console = hConsole; type_color = 15; }
	void Set_type(int t) { type = t; }
	int Get_type() { return type; }
	COORD GetCoord() { return position; }
	bool Check() { if ((type >= 2) && (type <= 3)) return true; return false; }
};


void kletka::Show()
{
	SetConsoleCursorPosition(console, position);
	if (type == 1)
		type_color = 9;
	else if (type == 3)
		type_color = 14;
	else if (type == 4)
		type_color = 4;
	SetConsoleTextAttribute(console, type_color);
	cout << type;
}



void kletka::Shoot()
{
	type++;
	if (type == 1)
		type_color = 9;
	else if (type == 3)
		type_color = 14;
	Show();
}

void kletka::KILL()
{
	type = 4;
	type_color = 4;
	Show();
}



bool All_check(vector <vector <kletka>> pole)
{
	for (int i = 0; i < pole.size(); i++)
		for (int j = 0; j < pole[i].size(); j++)
			if (pole[i][j].Check())
				return true;
	return false;
}

void main()
{
	ifstream file_1;
	string f;
	setlocale(LC_ALL, "rus");
	cout << "Введите путь к папке игры\n";
	cin >> f;
	srand(time(NULL));
	char buff[10];
	string d;
	d = itoa(rand() % 14, buff, 10);
	d = "\\Test" + d + ".txt";
	f = f + d;
	//f = f + "\Test0" + ".txt";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	vector <vector <kletka>> pole_you, pole_komp_show, pole_komp_hide;
	SHORT i1 = 3;
	SHORT j1 = 40;
	for (int i = 0; i < 10; i++)
	{
		vector <kletka> obl;
		obl.resize(10);
		int k = 0;
		for (SHORT j = 0; j < obl.size(); j++)
		{
			obl[j].Set_type_cord(i + 4, j + k + 40, 0, hConsole);
			k++;
		}
		pole_you.push_back(obl);
	}

	for (SHORT i = 0; i < 10; i++)
	{
		vector <kletka> obl;
		obl.resize(10);
		int k = 0;
		for (SHORT j = 0; j < obl.size(); j++)
		{
			obl[j].Set_type_cord(i + 19, j + k + 40, 0, hConsole);
			//obl[j].Show();
			k++;
		}
		pole_komp_hide.push_back(obl);
	}

	for (SHORT i = 0; i < 10; i++)
	{
		vector <kletka> obl;
		obl.resize(10);
		int k = 0;
		for (SHORT j = 0; j < obl.size(); j++)
		{
			obl[j].Set_type_cord(i + 4, j + k + 75, 0, hConsole);
			k++;
		}
		pole_komp_show.push_back(obl);
	}

	file_1.open(f);

	if (!file_1.is_open())
	{
		throw;
	}
	bool vvod = true;
	while (vvod)
	{
		system("cls");
		cout << "Введите координаты ваших коралей:\n";
		cout << "4-х палубный\n";
		int x_a, y_a;
		vector <vector <int>> xy;
		for (int i = 0; i < 4; i++)
		{
			cin >> x_a;
			cin >> y_a;
			xy.push_back({ y_a, x_a });
		}

		for (int i = 0; i < 4; i++)
		{
			pole_you[xy[i][0]][xy[i][1]].Set_type(2);
		}
		cout << "3-х палубный\n";
		xy.pop_back();
		for (int i = 0; i < 3; i++)
		{
			cin >> x_a;
			cin >> y_a;
			xy[i] = { y_a, x_a };
		}

		for (int i = 0; i < 3; i++)
		{
			pole_you[xy[i][0]][xy[i][1]].Set_type(2);
		}
		cout << "3-х палубный\n";
		for (int i = 0; i < 3; i++)
		{
			cin >> x_a;
			cin >> y_a;
			xy[i] = { y_a, x_a };
		}
		for (int i = 0; i < 3; i++)
		{
			pole_you[xy[i][0]][xy[i][1]].Set_type(2);
		}
		xy.pop_back();
		cout << "2-х палубный\n";
		for (int i = 0; i < 2; i++)
		{
			cin >> x_a;
			cin >> y_a;
			xy[i] = { y_a, x_a };
		}

		for (int i = 0; i < 2; i++)
		{
			pole_you[xy[i][0]][xy[i][1]].Set_type(2);
		}
		cout << "2-х палубный\n";
		for (int i = 0; i < 2; i++)
		{
			cin >> x_a;
			cin >> y_a;
			xy[i] = { y_a, x_a };
		}



		for (int i = 0; i < 2; i++)
		{
			pole_you[xy[i][0]][xy[i][1]].Set_type(2);
		}
		cout << "2-х палубный\n";
		for (int i = 0; i < 2; i++)
		{
			cin >> x_a;
			cin >> y_a;
			xy[i] = { y_a, x_a };
		}



		for (int i = 0; i < 2; i++)
		{
			pole_you[xy[i][0]][xy[i][1]].Set_type(2);
		}
		xy.pop_back();
		cout << "1-но палубный\n";
		cin >> x_a;
		cin >> y_a;
		xy[0] = { y_a, x_a };
		pole_you[xy[0][0]][xy[0][1]].Set_type(2);
		cout << "1-но палубный\n";
		cin >> x_a;
		cin >> y_a;
		xy[0] = { y_a, x_a };
		pole_you[xy[0][0]][xy[0][1]].Set_type(2);
		cout << "1-но палубный\n";
		cin >> x_a;
		cin >> y_a;
		xy[0] = { y_a, x_a };
		pole_you[xy[0][0]][xy[0][1]].Set_type(2);
		cout << "1-но палубный\n";
		cin >> x_a;
		cin >> y_a;
		xy[0] = { y_a, x_a };
		pole_you[xy[0][0]][xy[0][1]].Set_type(2);
		vvod = false;
	}
	system("cls");
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			pole_you[i][j].Show();
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			pole_komp_show[i][j].Show();
	for (SHORT i = 0; i < 9; i++)
	{

		SetConsoleCursorPosition(hConsole, { j1 - 2, i1 + i + 1 });
		cout << i + 1;
	}
	SetConsoleCursorPosition(hConsole, { j1 - 3, i1 + 10 });
	cout << 10;
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			pole_you[i][j].Show();
		}
	}
	SetConsoleCursorPosition(hConsole, { j1, i1 - 1 });
	cout << "Your pole:";
	char lett = 65;
	SHORT k = 0;
	SetConsoleTextAttribute(hConsole, 13);
	for (SHORT j = 0; j < 10; j++)
	{

		SetConsoleCursorPosition(hConsole, { j1 + j + k, i1 });
		k++;
		cout << lett;
		lett++;
	}
	lett = 65;
	for (SHORT i = 0; i < 9; i++)
	{

		SetConsoleCursorPosition(hConsole, { j1 - 2, i1 + i + 1 });
		cout << i + 1;
	}
	SetConsoleCursorPosition(hConsole, { j1 - 3, i1 + 10 });
	cout << 10;
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			pole_komp_show[i][j].Show();
		}
	}
	k = 0;
	j1 = 75;
	i1 = 3;
	SetConsoleCursorPosition(hConsole, { j1, i1 - 1 });
	cout << "Comp pole:";
	for (SHORT j = 0; j < 10; j++)
	{

		SetConsoleCursorPosition(hConsole, { j1 + j + k, i1 });
		k++;
		SetConsoleTextAttribute(hConsole, 13);
		cout << lett;
		lett++;
	}
	for (SHORT i = 0; i < 9; i++)
	{

		SetConsoleCursorPosition(hConsole, { j1 - 2, i1 + i + 1 });
		cout << i + 1;
	}
	SetConsoleCursorPosition(hConsole, { j1 - 3, i1 + 10 });
	cout << 10;
	SetConsoleTextAttribute(hConsole, 15);
	char buff_1[256];
	int matrix[10][10];
	int i = 0;
	while (file_1 >> buff_1)
	{


		for (int j = 0; j < 10; j++)
		{
			string s;
			s = buff_1[j];
			matrix[i][j] = stoi(s);
		}
		i++;
	}
	file_1.close();

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			pole_komp_hide[i][j].Set_type_cord(pole_komp_show[i][j].GetCoord(), matrix[i][j], hConsole);
			//pole_komp_hide[i][j].Show();
		}
	// программа
	vector <int> xx;
	vector <int> yy;
	vector <int> xx_k;
	vector <int> yy_k;
	bool ybil = false;
	bool ybil_k = false;
	bool fl1 = true, fl2 = true;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			matrix[i][j] = j;
	int l_i = 10, l_j = 10;

	while (fl1 && fl2)
	{
		SetConsoleTextAttribute(hConsole, 15);
		SetConsoleCursorPosition(hConsole, { 0, 0 });
		cout << "                                                     ";
		SetConsoleCursorPosition(hConsole, { 0, 1 });
		cout << "                                                     ";
		SetConsoleCursorPosition(hConsole, { 0, 2 });
		cout << "                                  ";
		SetConsoleCursorPosition(hConsole, { 0, 3 });
		cout << "                                  ";
		SetConsoleCursorPosition(hConsole, { 0, 4 });
		cout << "                                  ";
		SetConsoleCursorPosition(hConsole, { 0, 0 });
		cout << "Стреляйте:\n";
		int x, y;
		cin >> y;
		cin >> x;
		bool popal = false;
		if (pole_komp_hide[y][x].Get_type() == 2)
			popal = true;
		pole_komp_hide[y][x].Shoot();
		pole_komp_show[y][x].Set_type(pole_komp_hide[y][x].Get_type());
		pole_komp_show[y][x].Show();
		if (popal)
		{
			ybil = true;
			if ((y - 1 >= 0) && (pole_komp_hide[y - 1][x].Get_type() == 2))
			{
				ybil = false;
				xx.push_back(x);
				yy.push_back(y);
				continue;
			}
			else if ((y + 1 < 10) && (pole_komp_hide[y + 1][x].Get_type() == 2))
			{
				ybil = false;
				xx.push_back(x);
				yy.push_back(y);
				continue;
			}
			else if ((x + 1 < 10) && (pole_komp_hide[y][x + 1].Get_type() == 2))
			{
				ybil = false;
				xx.push_back(x);
				yy.push_back(y);
				continue;
			}
			else if ((x - 1 >= 0) && (pole_komp_hide[y][x - 1].Get_type() == 2))
			{
				ybil = false;
				xx.push_back(x);
				yy.push_back(y);
				continue;
			}
			for (int i = 0; i < xx.size(); i++)
			{
				pole_komp_hide[yy[i]][xx[i]].KILL();
				pole_komp_show[yy[i]][xx[i]].KILL();
			}
			pole_komp_show[y][x].KILL();
			pole_komp_hide[y][x].KILL();
			fl1 = All_check(pole_komp_hide);
			if (!fl1)
				break;
			ybil = false;
			continue;

		}
		else
		{
			bool turn = true;
			bool plyx = true;
			while (turn)
			{
				SetConsoleTextAttribute(hConsole, 15);
				turn = false;

				int r_i = rand() % 10;
				int r_j = rand() % 10;
				if ((pole_you[r_i][r_j].Get_type() == 1) || (pole_you[r_i][r_j].Get_type() == 4))
				{
					turn = true;
					continue;
				}
				bool popalk = false;
				if (pole_you[r_i][r_j].Get_type() == 2)
					popalk = true;
				pole_you[r_i][r_j].Shoot();
				if (popalk)
				{
					ybil_k = true;
					turn = true;
					if ((r_i - 1 >= 0) && (pole_you[r_i - 1][r_j].Get_type() == 2))
					{
						ybil_k = false;
						xx_k.push_back(r_j);
						yy_k.push_back(r_i);
						continue;
					}
					else if ((r_i + 1 <= 10) && (pole_you[r_i + 1][r_j].Get_type() == 2))
					{
						ybil_k = false;
						xx_k.push_back(r_j);
						yy_k.push_back(r_i);
						continue;
					}
					else if ((r_j + 1 <= 10) && (pole_you[r_i][r_j + 1].Get_type() == 2))
					{
						ybil_k = false;
						xx_k.push_back(r_j);
						yy_k.push_back(r_i);
						continue;
					}
					else if ((r_j - 1 >= 0) && (pole_you[r_i][r_j - 1].Get_type() == 2))
					{
						ybil_k = false;
						xx_k.push_back(r_j);
						yy_k.push_back(r_i);
						continue;
					}
					for (int i = 0; i < xx_k.size(); i++)
					{
						pole_you[yy_k[i]][xx_k[i]].KILL();
					}
					pole_you[r_i][r_j].KILL();
					fl2 = All_check(pole_you);
					if (!fl2)
						break;
					ybil_k = false;
					continue;

				}
			}
		}



	}
	system("cls");
	if (!fl1)
		cout << "Вы выиграли!\n";
	else cout << "Вы проиграли = (\n";
	//поле закончено
	while (true);
}