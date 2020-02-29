// StructMax.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <ctime>


using namespace std;

struct AMD
{
	int price;
	int volume_mem;
	int date_year;//12.12.12
	
};


int main()
{
	//srand(time(NULL));

	AMD* mas_pc = new AMD[10]{};
	int min = 20000;
	cout << "Price\t\tVolume\t\tData_Year\n";
	int temp;
	

	for (size_t i = 0; i < 10; i++)
	{
			
			cout<<  (mas_pc[i].price = pow(10, 3) + rand() )<<"\t\t";
			cout<< (mas_pc[i].volume_mem = 4 + rand() % 20 )<<"\t\t"; 
			cout << (mas_pc[i].date_year = 2000 + rand() % 21);
			cout << endl;
			if (mas_pc[i].price < min)
			{

				min = mas_pc[i].price;
				temp = i;

			}
			//mas_pc[i].date = while(rand())

		
	}
	

	cout << endl << mas_pc[temp].price << "\t" << mas_pc[temp].volume_mem<<"\t"<< mas_pc[temp].date_year;


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
