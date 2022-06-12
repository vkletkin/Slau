
#include <iostream>
#include "Slau_metod.h"



int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 4;
	

	vector<vector<double>> A(n, vector <double>(n, 0));
	vector<double> b(n, 0);
	vector<double> x(n, 0);

	vector<complex<double>> X(n, 0);
	/*
	cout << "МЕТОД КВАДРАТНЫХ КОРНЕЙ " << endl;
	vvod_Slau_metod_kvad_korney(n, A, b);
	Slau_metod_kvad_korney(A, b, X, n);
	*/
	
	/*
	cout << "МЕТОД ПРОСТЫХ ИТЕРРАЦИЙ " << endl;
	vvod_Slau_metod_just_iter(n, A, b);
	Slau_metod_just_iter(A, b, x, n);
	*/
	
	//vvod1(n, A, b);

	cout << "МЕТОД ЗЕЙДЕЛЯ " << endl;
	vvod_Slau_metod_zeydel(n, A, b);
	Slau_metod_zeydel(A, b, x, n);
	/*
	cout << "МЕТОД ЗЕЙДЕЛЯ 2 версия " << endl;

	Slau_metod_zeydel_2VER(A, b, x, n);
	
	cout << "МЕТОД ГАУСА по столбцам " << endl;
	
	Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy(A, b, x, n);

	cout << "МЕТОД ГРАДИЕНТНОГО СПУСКА " << endl;
	Slau_metod_GRAD(A, b, x, n);
	*/
	
	system("pause");
	return 0;
}
