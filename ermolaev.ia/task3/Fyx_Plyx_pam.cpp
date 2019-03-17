#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

typedef void(*func)(void);




class menu
{
	int Number_commands;
	string *Name_comand;
	int Plyx_pyx_pyx_pyx_pyx_plyX;
	void Set_cursor(int x, int y) const;
	void StrCopy(string str, int num);
	func * m;
public:
	menu() { Number_commands = 0; Plyx_pyx_pyx_pyx_pyx_plyX = 0; };
	menu(int a);
	menu(const menu &v);
	~menu() { delete Name_comand; cout << "I has been deleted \n"; }
	void Set_Num_of_com(int a);
	int G_N_O_C() const; // Get_numbers_of_commands
	void Set_Name_of_Command(int a, string name);
	void Get_menu(int x, int y) const;
	void Choose_number(int num);
	int Last_choice() { if (Plyx_pyx_pyx_pyx_pyx_plyX == 0) throw(4);  return Plyx_pyx_pyx_pyx_pyx_plyX; }
};

menu::menu(int a)
{
	Number_commands = a;
	Name_comand = new string[a];
	Plyx_pyx_pyx_pyx_pyx_plyX = 0;
}

menu::menu(const menu &v)
{
	Number_commands = v.Number_commands;
	*Name_comand = *v.Name_comand;
	Plyx_pyx_pyx_pyx_pyx_plyX = v.Plyx_pyx_pyx_pyx_pyx_plyX;
}

void menu::Set_Num_of_com(int a)
{
	if (a <= 0)
		throw(1);
	Number_commands = a;
	delete Name_comand;
	Name_comand = new string[a];
	m = new func[Number_commands];

}

int menu::G_N_O_C() const
{
	if (Number_commands == 0)
		throw(2);
	return Number_commands;
}

void menu::StrCopy(string a, int num)
{
	Name_comand[num - 1] = a;
}

void menu::Set_Name_of_Command(int a, string name)
{
	if (Number_commands == 0)
		throw 2;
	else if (a > Number_commands)
		throw 3;
	else if (a <= 0)
		throw 1;
	StrCopy(name, a);
	cout << "String has been seted\n";
}

void menu::Get_menu(int x, int y) const
{
	if ((x < 0) || (y < 0))
		throw 1;
	for (int i = 0; i < Number_commands; i++)
	{
		Set_cursor(x, y);
		y++;
		cout << i + 1 << ". " << Name_comand[i] << "\n";
	}
}

void menu::Set_cursor(int x, int y) const
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void menu::Choose_number(int num)
{
	if (num > Number_commands)
		throw(3);
	else if (num <= 0)
		throw(1);
	Plyx_pyx_pyx_pyx_pyx_plyX = num;
	//m[num - 1]();
	cout << "Your choise " << num << ". " << Name_comand[num - 1] << "\n";
}



void main()
{
	menu Wrath;
	int Big_flag;
	cout << "Hello!Here you can create your menu\n";
	const string done[5] = { "1. Set the number of menu commands\n", "2. Find out the number of menu commands\n","3. Set the name of the menu item with the specified number\n","4. Display the menu on the screen in the selected position of the console window\n", "5. Exit from programm\n" };
	do
	{
		cout << done[0] << done[1] << done[2] << done[3] << done[4];
		cin >> Big_flag;
		try
		{
			switch (Big_flag)
			{
			case 1:
			{
				int col_vo_comand;
				cout << "Input quantity of commands\n";
				cin >> col_vo_comand;
				Wrath.Set_Num_of_com(col_vo_comand);
				break;

			}
			case 2:
			{
				cout << "Quantity of commands in menu:" << Wrath.G_N_O_C() << "\n";
				break;
			}
			case 3:
			{
				int num;
				string name_command;
				cout << "Input number command and its name \n";
				cin >> num;
				cin >> name_command;
				Wrath.Set_Name_of_Command(num, name_command);
				break;
			}
			case 4:
			{
				int x, y;
				cout << "Enter coordinates for menu(console will clear thereafter)\n";
				cin >> x >> y;
				system("cls");
				Wrath.Get_menu(x, y);
				const string done_menu[3] = { "1. Choose one of the point\n", "2. Give the number of the last menu item you selected\n", "3. Exit to main\n" };
				int Small_flag;
				do
				{
					cout << "This is your menu. Input what are you want?\n" << done_menu[0] << done_menu[1] << done_menu[2];
					cin >> Small_flag;
					switch (Small_flag)
					{
					case 1:
					{
						int choose;
						cout << "Choose one of the point\n";
						cin >> choose;
						Wrath.Choose_number(choose);
						break;
					}
					case 2:
					{
						cout << "This is your last choise: " << Wrath.Last_choice() << "\n";
						break;
					}
					case 3: break;
					default:
					{
						throw(5);
						break;
					}
					}

				} while (Small_flag != 3);
				break;
			}
			case 5: break;
			default:
			{
				throw(5);
				break;
			}
			}
		}
		catch (int a)
		{
			switch (a)
			{
			case 1: {cout << "ERROR: You enter nonpositive number\n"; break; }
			case 2: {cout << "ERROR: You didnt enter quantity of commands\n"; break; }
			case 3: {cout << "ERROR: You enter so big number\n"; break; }
			case 4: {cout << "ERROR: You didnt choose any command\n"; break; }
			case 5: {cout << "ERROR: You choose wrong command\n"; break; }
			}

		}
	} while (Big_flag != 5);
}