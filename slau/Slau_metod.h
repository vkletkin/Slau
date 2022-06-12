#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include <complex>
#include <iomanip>
using namespace std;

int progonka_3d(
	const vector<double>& c,											// выше диагонали
	const vector<double>& b,											// cама диагональ
	const vector<double>& a,											// ниже диагонали
	const vector<double>& d,											// свободные значение
	vector<double>& X,													// искомый вектор
	int n);

int Slau_metod_kvad_korney(												// AX = B, Матрица должна быть симетричной 
	const vector<vector<double>>& A,
	const vector<double>& b,											
	vector<complex<double>>& x,											
	int n);

int Slau_metod_just_iter(												// x=ax-b
	const vector<vector<double>>& A,
	const vector<double>& b,											
	vector<double>& x,													
	int n);

int Slau_metod_zeydel(													//AX = B
	const vector<vector<double>>& A,
	const vector<double>& b,											
	vector<double>& x,													
	int n);

int Slau_metod_zeydel_2VER(												//AX = B
	const vector<vector<double>>& A,
	const vector<double>& b,											
	vector<double>& x,													
	int n);

int Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy(								//AX = B
	const vector<vector<double>>& A,
	const vector<double>& b,											
	vector<double>& X,													
	int n);

int Slau_metod_GRAD(													//AX = B
	const vector<vector<double>>& A,
	const vector<double>& b, 
	vector<double>& x, 
	int n);

int timmer(
	const vector<double>& a,
	const vector<double>& b, 
	int n,
	double e);
int transponirovanie(
	vector <vector<double>>& A,
	int n);

int transponirovanie(
	vector<vector<complex<double>>>& A,
	int n);

int vvod(
	int &n,
	vector <vector<double>>& A,
	vector<double>& b);									

int vvod1(
	int &n,
	vector <vector<double>>& A,
	vector<double>& b);

int vvod2(
	int &n,
	vector<vector<double>>& A, 
	vector<double>& b);

int vvod3(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);

int vvod4(
	int& n, 
	vector<vector<double>>& A, 
	vector<double>& b);

int vvod5(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);

int vivod(
	const vector <vector<double>>& A,
	int n);

int vivod(
	const vector<double>& A,
	int n);

int vivodX(
	 vector<complex<double>>& A,
	int n);

int vivodX(
	const vector<double>& A,
	int n);

int proverka_na_simetriu(
	const vector <vector<double>>& A,
	int n);

int proverka_na_diagonaln_preoblodaniye(
	const vector <vector<double>>& A,
	int n,
	int i);

int WrireLine(
	const vector<vector<double>>& A,
	vector<vector<double>>& B, 
	const vector<double>& b, 
	vector<double>& m, 
	int n, 
	int i);

int max_v_stolbce(
	const vector<vector<double>>& A,
	int n,
	int i);

int max_v_stroke(
	const vector<vector<double>>& A,
	int n, 
	int i);

int perevod_v_norm(
	vector<vector<double>>& B,
	vector<double>& m,
	int n);

int perevod_v_NEnorm(
	vector<vector<double>>& B,
	vector<double>& m, 
	int n);

int perestanovka(
	vector<vector<double>>& B,
	vector<double>& m,
	int n);

int multu_matrix_on_matrix(
	const vector<vector<double>>& A,
	const vector<vector<double>>& B, 
	vector<vector<double>>& C, 
	int n);

vector<double> multu_matrix_on_matrix_on_vector(
	const vector<vector<double>>& A,
	const vector<vector<double>>& B,
	const vector<double>& C,
	int n);

vector<double> multu_matrix_on_vector(
	const vector<vector<double>>& A, 
	const vector<double>& C, 
	int n);

int privedeniye_k_diagonalnomu_vidu(
	const vector<vector<double>>& B_old,
	vector<vector<double>>& B,
	const vector<double>& m_old,
	vector<double>& m,
	int n);




int vvod_Slau_metod_kvad_korney(
	int &n,
	vector <vector<double>>& A,
	vector<double>& b);
int vvod_Slau_metod_kvad_korney1(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);
int vvod_Slau_metod_kvad_korney2(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);
int vvod_Slau_metod_kvad_korney3(
	int& n,
	vector<vector<double>>& A, 
	vector<double>& b);


int vvod_Slau_metod_just_iter(
	int &n,
	vector <vector<double>>& A,
	vector<double>& b);
int vvod_Slau_metod_just_iter1(
	int& n,
	vector<vector<double>>& A, 
	vector<double>& b);


int vvod_Slau_metod_zeydel(
	int& n,
	vector<vector<double>>& A, 
	vector<double>& b);
int vvod_Slau_metod_zeydel1(
	int& n,
	vector<vector<double>>& A, 
	vector<double>& b);
int vvod_Slau_metod_zeydel2(
	int& n,
	vector<vector<double>>& A, 
	vector<double>& b);

int vvod_Slau_metod_zeydel3(
	int& n, 
	vector<vector<double>>& A,
	vector<double>& b);


int vvod_Slau_metod_zeydel_2VER(
	int& n,
	vector<vector<double>>& A, 
	vector<double>& b);
int vvod_Slau_metod_zeydel_2VER1(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_zeydel_2VER2(
	int& n, 
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_zeydel_2VER3(
	int& n,
	vector<vector<double>>& A, 
	vector<double>& b);


int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);
int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy1(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy2(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy3(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_GRAD(
	int& n, 
	vector<vector<double>>& A,
	vector<double>& b);
int vvod_Slau_metod_GRAD1(
	int& n, 
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_GRAD2(
	int& n, 
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_GRAD3(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_GRAD4(
	int& n,
	vector<vector<double>>& A,
	vector<double>& b);

int vvod_Slau_metod_GRAD5(
	int& n,
	vector<vector<double>>& A, 
	vector<double>& b);


