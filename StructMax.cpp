#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <cstdio>
#include <list>


using namespace std;

struct DateBorn
{
	int day;
	int month;
	int year;
	bool IsCorect();
public: void ShowDate();
	

};
void DateBorn::ShowDate()
{
	cout << day << "." << month<<"." << year << endl;
}
bool DateBorn::IsCorect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
	
}
struct Emploee
{
	string Name;
	string Surname;
	string Patronymic;
	string Position;
	DateBorn date_born;
	struct Manager
	{
		static const int salary = 100000;//"$"

	};
	struct Rower//Гребец
	{
		static const  int salary = 3000;

	};
};

void ShowInfoForMayEmploee(const int num_may_emp,Emploee* mas_emploee,int count_may_emp)
{
cout << "FullName\tPosition\tDate_Born\tManager_Salary\tRower_Salary\n";
for (int i = 0; i < count_may_emp; i++)
{
	if (num_may_emp == mas_emploee[i].date_born.month)
	{
		cout << mas_emploee[i].Name<<" "<< mas_emploee[i].Surname<<" "<< mas_emploee[i].Patronymic << "\t\t";
		cout << mas_emploee[i].Position << "\t\t";
		cout<<mas_emploee[i].date_born.day<<"."<<mas_emploee[i].date_born.month<<"."<<mas_emploee[i].date_born.year<< "\t\t";
		cout << Emploee::Manager::salary << "\t\t";
		cout << Emploee::Rower::salary << endl;
	}
}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//srand(time(NULL));
	Emploee* mas_emploee = new Emploee[2];
	
	//list<Emploee> List_Emploee[2];

	int min = 20000;
	int may_month =5;
	int num_may_emp;
	int count_may_emp=0;
	for (size_t i = 0; i < 2; i++)
	{
		       cout << "Введите ФИО "<<i+1 << "-ого сотрудника галеры: ";
			   cin.ignore(cin.rdbuf()->in_avail());
		       cin>>mas_emploee[i].Name>> mas_emploee[i].Surname>> mas_emploee[i].Patronymic;
			   cout << "Введите должность " << i + 1 << "-ого  сотрудника галеры(Manager or Гребец): ";
			   cin >> mas_emploee[i].Position;//Manager or Worker
			   cout << "Введите дату рождения " << i + 1 << "-ого сотрудника галеры через пробел(напрример 12 12 12):";
			   cin >> mas_emploee[i].date_born.day >> mas_emploee[i].date_born.month >> mas_emploee[i].date_born.year;
			   if (mas_emploee[i].date_born.month == may_month){
				   num_may_emp = mas_emploee[i].date_born.month;
				   count_may_emp++;
			   }
	}
	ShowInfoForMayEmploee(num_may_emp,mas_emploee, count_may_emp);
	




}

