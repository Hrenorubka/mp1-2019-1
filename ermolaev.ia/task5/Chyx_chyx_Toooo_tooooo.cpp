#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct FIO
{
	string Name;
	string Surname;
	string Patronymic;
};

struct date
{
	int day;
	int mounth;
	int year;
	bool operator==(date obl)
	{
		if (day == obl.day)
			if (mounth = obl.mounth)
				if (year == obl.year)
					return 1;
		return 0;
	}
};

struct mesto
{
	int cost;
	int busy;
	int type;
	FIO client;
};

struct vagon
{
	int num;
	int type;
	vector <mesto> kol_m;
};

struct poezd_chyx_chyx
{
	int ID_st_to, ID_st_fr;
	vector <int> ID;
	int type;
	vector <vagon> vagon______vagon;
};

struct ID_poezd
{
	int ID_date;
	int num_poezd;
	vector <int> num_vag;
};

const date zero{ 0, 0, 0 };

struct date_poezd_chyx_chyx
{
	vector <poezd_chyx_chyx> poezds;
	date client_date;
};

class GJD
{
private:
	vector <date_poezd_chyx_chyx> vagon______vagon$vagon______vagon;
public:

	GJD(vector <date_poezd_chyx_chyx> poezd) : vagon______vagon$vagon______vagon(poezd) {}

	int Find_your_date(date x)
	{
		for (int i = 0; i < vagon______vagon$vagon______vagon.size(); i++)
		{
			if (x == vagon______vagon$vagon______vagon[i].client_date)
				return i;
		}
	}

	vector <int> Find_vagons(int ID_date, int num_poezd, int type_vag)
	{
		vector <int> obl;
		for (int i = 0; i < vagon______vagon$vagon______vagon[ID_date].poezds[num_poezd].vagon______vagon.size(); i++)
			if (type_vag == vagon______vagon$vagon______vagon[ID_date].poezds[num_poezd].vagon______vagon[i].type)
				obl.push_back(i);
		return obl;
	}

	int Find_your_poezd(int ID_date, vector <int> ID_poezd)
	{
		for (int i = 0; i < vagon______vagon$vagon______vagon[ID_date].poezds.size(); i++)
		{
			bool fl = true;
			for (int j = 0; j < 10; j++)
				if (ID_poezd[j] != vagon______vagon$vagon______vagon[ID_date].poezds[i].ID[j])
					fl = false;
			if (fl)
				return i;
		}
		return -1;
	}

	void New_poezd(date x, vector <poezd_chyx_chyx> Chyx)
	{
		int l = vagon______vagon$vagon______vagon.size();
		vagon______vagon$vagon______vagon.resize(l + 1);
		vagon______vagon$vagon______vagon[l].client_date = x;
		vagon______vagon$vagon______vagon[l].poezds = Chyx;
	}

	bool Check_vagon(ID_poezd your_poezd, int num_vag, mesto mestos)
	{

		for (int i = 0; i < vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m.size(); i++)
			if (vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[i].type == mestos.type)
				if (vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[i].busy == 0)
				{
					vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[i].busy = 3;
					return 1;
				}
		return 0;
	}

	void Uncheck_vagon(ID_poezd your_poezd, int num_vag, mesto mestos)
	{
		for (int i = 0; i < vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m.size(); i++)
			if (vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[i].type == mestos.type)
				if (vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[i].busy == 3)
					vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[i].busy = 0;
	}

	vagon Get_vagon(ID_poezd your_poezd, int num_vag)
	{
		return vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag];
	}

	vector <mesto> Get_mestos(ID_poezd your_poezd, int num_vag)
	{
		vector <mesto>  obl;

		for (int i = 0; i < vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m.size(); i++)
		{
			obl.push_back(vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[i]);
		}
		return obl;
	}

	void Zareservate(ID_poezd your_poezd, int num_vag, int num_mestos)
	{
		vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[num_mestos].busy = 2;
	}

	int Money_money_money(ID_poezd your_poezd, int num_vag, int num_mestos)
	{
		return vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[num_mestos].cost;
	}

	void Absorb(ID_poezd your_poezd, int num_vag, int num_mestos)
	{
		vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[num_mestos].busy = 0;
	}

	void Zanyatie_mesta(ID_poezd your_poezd, int num_vag, int num_mestos, FIO your_client)
	{
		vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[num_mestos].busy = 1;
		vagon______vagon$vagon______vagon[your_poezd.ID_date].poezds[your_poezd.num_poezd].vagon______vagon[num_vag].kol_m[num_mestos].client = your_client;
	}

};

class Kassa
{
private:
	ID_poezd obl_poezd;
	vector <mesto> obl_mest;
	int obl_num_vag;
	vector <int> obl_num_mesto;
	FIO obl_FIO;

public:

	void Get_info(date client_date, vector <int> num_poezd, int type_vag, int type_mests, int kol_mest, FIO client, GJD base)
	{
		obl_poezd.ID_date = base.Find_your_date(client_date);
		obl_poezd.num_poezd = base.Find_your_poezd(obl_poezd.ID_date, num_poezd);
		obl_poezd.num_vag = base.Find_vagons(obl_poezd.ID_date, obl_poezd.num_poezd, type_vag);
		int l = obl_mest.size();
		obl_mest.resize(kol_mest + l);
		for (int i = l; i < obl_mest.size(); i++)
			obl_mest[i].type = type_mests;
		obl_FIO = client;
	}

	bool Check_mesto(GJD base, vector <vagon> Izbytok)
	{
		bool flag = true;
		for (int i = 0; i < obl_poezd.num_vag.size(); i++)
		{
			bool flag_vag = true;
			for (int j = 0; j < obl_mest.size(); j++)
			{
				flag_vag = base.Check_vagon(obl_poezd, obl_poezd.num_vag[i], obl_mest[j]);
				if (!flag_vag)
				{
					flag = flag_vag;
					base.Uncheck_vagon(obl_poezd, obl_poezd.num_vag[i], obl_mest[j]);
					Izbytok.push_back(base.Get_vagon(obl_poezd, obl_poezd.num_vag[i]));
					break;
				}
			}
		}
		return flag;
	}

	void Rezervate(int num_vag, vector <int> num_mest, GJD base)
	{
		obl_num_vag = num_vag;
		obl_num_mesto = num_mest;
		for (int i = 0; i < num_mest.size(); i++)
			base.Zareservate(obl_poezd, num_vag, num_mest[i]);
	}

	int	Count(GJD base)
	{
		int cost = 0;
		for (int i = 0; i < obl_num_mesto.size(); i++)
			cost = cost + base.Money_money_money(obl_poezd, obl_num_vag, obl_num_mesto[i]);
		return cost;
	}

	void Go_home(GJD base)
	{
		for (int i = 0; i < obl_num_mesto.size(); i++)
			base.Absorb(obl_poezd, obl_num_vag, obl_num_mesto[i]);
		obl_mest.resize(0);
		obl_num_mesto.resize(0);
		obl_poezd.num_vag.resize(0);
		obl_poezd.ID_date = -1;
		obl_poezd.num_poezd = -1;
		obl_num_vag = -1;
	}

	void Purchase(GJD base)
	{
		for (int i = 0; i < obl_num_mesto.size(); i++)
		{
			base.Zanyatie_mesta(obl_poezd, obl_num_vag, obl_num_mesto[i], obl_FIO);
		}
	}

};

void main()
{
	vector <mesto> Last(100);
	for (int i = 0; i < 100; i++)
	{
		Last[i].type = 0;
		Last[i].busy = 0;
		Last[i].cost = 650;
	}
	vector <mesto> Platscart(54);
	for (int i = 0; i < 27; i++) // верхние
	{
		Platscart[i].type = 2;
		Platscart[i].busy = 0;
		Platscart[i].cost = 300;
	}
	for (int i = 27; i < 54; i++) // нижние
	{
		Platscart[i].type = 1;
		Platscart[i].busy = 0;
		Platscart[i].cost = 350;
	}
	vector <mesto> Cuppe(36);
	for (int i = 0; i < 18; i++) // верхние
	{
		Cuppe[i].type = 2;
		Cuppe[i].busy = 0;
		Cuppe[i].cost = 450;
	}
	for (size_t i = 18; i < 36; i++) // нижние
	{
		Cuppe[i].type = 1;
		Cuppe[i].busy = 0;
		Cuppe[i].cost = 500;
	}
	vector <mesto> SV(18);
	for (int i = 0; i < 18; i++) // нижние
	{
		SV[i].type = 0;
		SV[i].busy = 0;
		SV[i].cost = 550;
	}
	vector <vagon> Lastochka(8);
	for (int i = 0; i < 8; i++)
	{
		Lastochka[i].kol_m = Last;
		Lastochka[i].type = 0;
		Lastochka[i].num = i;
	}
	vector <vagon> Fyrm_poezd(12);
	for (int i = 0; i < 2; i++)
	{
		Fyrm_poezd[i].kol_m = SV;
		Fyrm_poezd[i].type = 1;
		Fyrm_poezd[i].num = i;
	}
	for (int i = 2; i < 8; i++)
	{
		Fyrm_poezd[i].kol_m = Cuppe;
		Fyrm_poezd[i].type = 2;
		Fyrm_poezd[i].num = i;
	}
	for (int i = 8; i < 12; i++)
	{
		Fyrm_poezd[i].kol_m = Platscart;
		Fyrm_poezd[i].type = 3;
		Fyrm_poezd[i].num = i;
	}
	vector <vagon> Fast_poezd(12);
	for (int i = 0; i < 8; i++)
	{
		Fast_poezd[i].kol_m = Platscart;
		Fast_poezd[i].type = 3;
		Fast_poezd[i].num = i;
	}
	for (int i = 8; i < 12; i++)
	{
		Fast_poezd[i].kol_m = Cuppe;
		Fast_poezd[i].type = 2;
		Fast_poezd[i].num = i;
	}
	vector <poezd_chyx_chyx> All_chyx_chyx(10);
	for (int i = 0; i < 6; i++)
	{
		All_chyx_chyx[i].ID.resize(10);
		All_chyx_chyx[i].ID = { 10, 11, 12, 13, 14, 15, 16, 17, 18, i + 2 * i + 10 };
		All_chyx_chyx[i].ID_st_fr = i % 2; // 1 - Нижний 0 - Москва
		All_chyx_chyx[i].ID_st_to = (i + 1) % 2;
		All_chyx_chyx[i].vagon______vagon = Lastochka;
		All_chyx_chyx[i].type = 0;
	}
	for (int i = 6; i < 8; i++)
	{
		All_chyx_chyx[i].ID.resize(10);
		All_chyx_chyx[i].ID = { 10, 11, 12, 13, 14, 15, 16, 17, i + 2 * i + 10, 19 };
		All_chyx_chyx[i].ID_st_fr = i % 2; // 1 - Нижний 0 - Москва
		All_chyx_chyx[i].ID_st_to = (i + 1) % 2;
		All_chyx_chyx[i].vagon______vagon = Fyrm_poezd;
		All_chyx_chyx[i].type = 1;
	}
	for (int i = 8; i < 10; i++)
	{
		All_chyx_chyx[i].ID.resize(10);
		All_chyx_chyx[i].ID = { 10, 11, 12, 13, 14, 15, 16, i + 2 * i + 10, 18, 19 };
		All_chyx_chyx[i].ID_st_fr = i % 2; // 1 - Нижний 0 - Москва
		All_chyx_chyx[i].ID_st_to = (i + 1) % 2;
		All_chyx_chyx[i].vagon______vagon = Fast_poezd;
		All_chyx_chyx[i].type = 2;
	}
	vector <date_poezd_chyx_chyx> chyx(30);
	for (int i = 0; i < 30; i++)
	{
		chyx[i].client_date = { i + 1, 5, 2018 };
		chyx[i].poezds = All_chyx_chyx;
	}

	GJD base(chyx);

	Kassa Pararam;
	Pararam.Get_info({ 1, 5, 2018 }, { 10, 11, 12, 13, 14, 15, 16, 17, 18, 10 }, 0, 0, 5, { "Petr", "Pupckin", "Alexandrovich" }, base);
	vector <vagon> Izb;
	bool fl = Pararam.Check_mesto(base, Izb);
	int a = 0;
	if (fl)
		a = 1;
	cout << a << "\n";
	Pararam.Rezervate(5, { 1, 2, 3, 4, 5 }, base);
	int cost = Pararam.Count(base);
	cout << cost << "\n";
	Pararam.Purchase(base);
	Pararam.Get_info({ 1, 5, 2018 }, { 10, 11, 12, 13, 14, 15, 16, 17, 18, 10 }, 0, 0, 4, { "Petr", "Pupckin", "Alexandrovich" }, base);
	vector <vagon> Plyx;
	fl = Pararam.Check_mesto(base, Plyx);
	a = 0;
	if (fl)
		a = 1;
	cout << a << "\n";
	Pararam.Rezervate(5, { 10, 20, 30, 40 }, base);
	cost = Pararam.Count(base);
	cout << cost << "\n";
	Pararam.Go_home(base);
	while (true)
	{
	}
}