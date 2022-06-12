#include "Slau_metod.h"

int progonka_3d(const vector<double>& c,const vector<double>& b,const vector<double>& a,const vector<double>& d,vector <double>& X,int n)
{
	//																			расчёт производится по принципуAX = D
	//========================================================================================================================================================================================================================   
	vector <double> Alpha(n, 0);
	vector <double> Betta(n, 0);
	//==========================================================================ПРЯМАЯ ПРОГОНКА
	Alpha[0] = -c[0] * 1. / b[0];
	Betta[0] = d[0] * 1. / b[0];
	for (int i = 1; i < n; i++)
	{
		double y = b[i] + a[i] * Alpha[i - 1];
		double t = d[i] - a[i] * Betta[i - 1];
		Alpha[i] = -c[i] * 1. / y;
		Betta[i] = t / y;
	}
	//==========================================================================ОБРАТНАЯ ПРОГОНКА				
	X[n - 1] = Betta[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		X[i] = Alpha[i] * X[i + 1] + Betta[i];
	}
	return 0;
}

int Slau_metod_kvad_korney(const vector<vector<double>>& A,const vector<double>& b,vector<complex<double>>& x,int n)
{
	if (proverka_na_simetriu(A, n) == 1)
	{
		cout << "Матрица не симетричная, иди уроки учи олух";
		return 1;
	}

	//==========================================================================ПРЯМАЯ ПРОГОНКА

	vector < vector < complex<double> >> T( n, vector < complex <double>>(n, 0));
	complex <double> D;

	T[0][0] = sqrt(A[0][0]);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j > i)
			{
				T[0][j] = A[0][j] / T[0][0];
			}

			if (i == j && i > 0)
			{
				D = 0;
				for (int k = 0; k < i; k++)
				{
					D += T[k][i] * T[k][i];
				}
				T[i][i] = sqrt(A[i][i] - D);
			}

			if (i < j && i != 0)
			{
				D = 0;
				for (int k = 0; k < i; k++)
				{
					D += T[k][i] * T[k][j];
				}
				T[i][j] = (A[i][j]- D) / T[i][i];
			}
			if (i > j)
			{
				T[i][j] = 0;
			}
		}
	}

	//==========================================================================ОБРАТНАЯ ПРОГОНКА		
	
	transponirovanie(T, n);

	vector<complex<double>> y(n,0);
	complex<double> R;

	y[0] = b[0] / T[0][0];

	for (int  i = 1; i < n; i++)
	{
		R = 0;
		for (int k = 0;k < i; k++)
		{
			R += T[i][k] * y[k];
		}
		y[i] = (b[i] - R) / T[i][i];
	}

	transponirovanie(T, n);

	x[n - 1] = y[n - 1] / T[n - 1][n - 1];
	for (int i = n-2; i >= 0; i--)
	{
		R = 0;
		for (int k = i + 1; k < n; k++)
		{
			R += T[i][k] * x[k];
		}
		x[i] = (y[i] - R) / T[i][i];
	}
	vivodX(x, n);
	return 0;
}


int Slau_metod_just_iter(const vector<vector<double>>& A, const vector<double>& b, vector<double>& x, int n) // не нормальное забивание данных
{
 // Расчет производится в ненормальном виде 

	double D;
	vector<double>x_old(n,0);
	do
	{
		x_old = x;
		for (int i = 0; i < n; i++)
		{
			D = 0;
			for (int j = 0; j < n; j++)
			{
				D += A[i][j] * x_old[j];
			}
			x[i] = D + b[i];
		}
	}
	while (timmer(x, x_old, n, 0.000001));
	vivodX(x,n);
	return 0;
}


int Slau_metod_zeydel(const vector<vector<double>>& A,const vector<double>& b, vector<double>& x, int n)
{
//																			расчёт производится по принципуAX = B
//========================================================================================================================================================================================================================   
	vector<vector<double>>B(n + 1, vector<double >(n, 0));
	vector<double >m(n, 0);
	vector<vector<double>>B_old(n + 1, vector<double >(n, 0));
	vector<double >m_old(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
		}

	}
	for (int j = 0; j < n; j++)
	{
		B[n][j] = j;
	}

	m = b;

	perestanovka(B, m, n);

	B_old = B;
	m_old = m;

	privedeniye_k_diagonalnomu_vidu(B_old, B, m_old, m, n);
	vivod(B, n);
	//vivod(m, n);

	perevod_v_NEnorm(B, m, n);

	double D;
	vector<double>x_old(n, 0);
	vector<double>Xt(n, 0);
	do
	{
		for (int i = 0; i < n; i++)
		{
			D = 0;
			for (int j = 0; j < n; j++)
			{
				D += B[i][j] * x_old[j];
			}
			Xt[i] = x_old[i];
			x_old[i] = x[i] = D + m[i];
		}
	} while (timmer(x, Xt, n, 0.001));
	vivodX(x, n);
	return 0;
}

int Slau_metod_zeydel_2VER(const vector<vector<double>>& A, const vector<double>& b, vector<double>& x, int n)
{
	//																			расчёт производится по принципуAX = B
	//========================================================================================================================================================================================================================   
	vector<vector<double>>B(n + 1, vector<double >(n, 0));
	vector<double >m(n, 0);
	vector<vector<double>>B_old(n + 1, vector<double >(n, 0));
	vector<double >m_old(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		B[n][j] = j;
	}

	m = b;

	perestanovka(B, m, n);

	B_old = B;
	m_old = m;

	
	privedeniye_k_diagonalnomu_vidu(B_old, B, m_old, m, n);
	//vivod(B, n);
	//vivod(m, n);

	double D;
	vector<double>x_old(n, 0);
	vector<double>Xt(n, 0);
	do
	{
		for (int i = 0; i < n; i++)
		{
			D = 0;
			for (int j = 0; j < n; j++)
			{
				if (j != i)D += B[i][j] * x_old[j];
			}
			Xt[i] = x_old[i];
			x_old[i] = x[i] = (-D + m[i]) / B[i][i];
		}
	} while (timmer(x, Xt, n, 0.001));
	vivodX(x, n);
	return 0;
}

int Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy(const vector<vector<double>>& A, const vector<double>& b, vector<double>& X, int n)
{
	
	int i, j, m, k;
	double aa, bb;
	
	vector<vector<double>> a(n, vector <double>(n+1, 0)); //матрица коэффициентов, где последний столбец - правая часть системы

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i][n] = b[i];
	}
	

	vector<double> x(n + 1, 0);

	for (k = 0; k < n; k++)					 //Поиск максимального элемента в первом столбце
	{
		aa = abs(a[k][k]);
		i = k;
		for (m = k + 1; m < n; m++)
			if (abs(a[m][k]) > aa)
			{
				i = m;
				aa = abs(a[m][k]);
			}

		if (aa == 0)						 //проверка на нулевой элемент
		{
			cout << "Система не имеет решений" << endl;
			return 1;
		}

		if (i != k)							//  перестановка i-ой строки, содержащей главный элемент k-ой строки
		{
			for (j = k; j < n + 1; j++)
			{
				bb = a[k][j];
				a[k][j] = a[i][j];
				a[i][j] = bb;
			}
		}

		aa = a[k][k];						//преобразование k-ой строки (Вычисление масштабирующих множителей)
		a[k][k] = 1;
		for (j = k + 1; j < n + 1; j++)
			a[k][j] = a[k][j] / aa;
		for (i = k + 1; i < n; i++)			//преобразование строк с помощью k-ой строки
		{
			bb = a[i][k];
			a[i][k] = 0;
			if (bb != 0)
				for (j = k + 1; j < n + 1; j++)
					a[i][j] = a[i][j] - bb * a[k][j];
		}
	}

	for (i = n - 1; i >= 0; i--)			 //Нахождение решений СЛАУ
	{
		x[i] = 0;
		aa = a[i][n];
		for (j = n; j > i; j--)
			aa = aa - a[i][j] * x[j];
		x[i] = aa;
	}

	vivodX(x, n);
	return 0;
}


int Slau_metod_GRAD(const vector<vector<double>>& A, const vector<double>& b, vector<double>& x, int n)
{
//																			расчёт производится по принципуAX = B
//========================================================================================================================================================================================================================   
	vector<vector<double>>B(n + 1, vector<double >(n, 0));
	vector<double >m(n, 0);
	vector<vector<double>>B_old(n + 1, vector<double >(n, 0));
	vector<double >m_old(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		B[n][j] = j;
	}
	m = b;

	perestanovka(B, m, n);

	B_old = B;
	m_old = m;

	privedeniye_k_diagonalnomu_vidu(B_old, B, m_old, m, n);
	//vivod(B, n);
	//vivod(m, n);

	 //приводим систему к виду f= AX-b

	vector<vector<double>>B_tr(n + 1, vector<double >(n, 0));
	B_tr = B;
	transponirovanie(B_tr,n);



	double MU, UP, DOWN;

	vector<double >B_tr_on_r(n, 0);
	vector<double >B_on_x(n, 0);
	vector<double >B_on_B_tr_on_r(n, 0);
	
	vector<double >r(n, 0);

	vector<double>Xt(n, 0);
	vector<double>x_old(n, 0);

	for (int i = 0; i < n; i++)
	{
		x_old[i] =- m[i]/ B[i][i];
	}

	do
	{
		B_on_x = multu_matrix_on_vector(B, x_old, n);
		for (int i = 0; i < n; i++)
		{
			r[i] = B_on_x[i] - m[i];
		}

		B_tr_on_r = multu_matrix_on_vector(B_tr, r, n);
		B_on_B_tr_on_r = multu_matrix_on_matrix_on_vector(B, B_tr, r, n);

		UP = DOWN = 0;
		for (int i = 0; i < n; i++)
		{
			UP += r[i] * B_on_B_tr_on_r[i];
			DOWN += B_on_B_tr_on_r[i] * B_on_B_tr_on_r[i];
		}
		MU = UP / DOWN;

		for (int i = 0; i < n; i++)
		{
			Xt[i] = x_old[i];
			x[i] = x_old[i] - MU * B_tr_on_r[i];
			x_old[i] = x[i];
		}

	} while (timmer(x, Xt, n, 0.0000000001));
	vivodX(x, n);
	return 0;
}

int timmer(const vector<double>& a, const vector<double>& b, int n, double e)
{
	double f = 0;
	for (int i = 0; i < n; i++)
	{
		f += pow(a[i] - b[i], 2);
	}
		if (sqrt(f) > e) return 1;
	
	return 0;
}

int transponirovanie(vector<vector<double>>& A, int n)
{
	double t = 0;
	for (int  i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j)
			{
				t = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = t;
			}
		}
	}
	return 0;
}
int transponirovanie(
	vector<vector<complex<double>>>& A,
	int n)
{
	complex<double> t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j)
			{
				t = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = t;
			}
		}
	}
	return 0;
}

int proverka_na_simetriu(const vector<vector<double>>& A, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j= 0; j < n; j++)
		{
			if (A[i][j]!= A[j][i])
			{
				cout << "matric ne semetrichn" << endl;
				return 1;
			}
		}
	}
	return 0;
}

int proverka_na_diagonaln_preoblodaniye(const vector<vector<double>>& A, int n, int i)
{
	double D = 0;
	for (int j = 0; j < n; j++)
	{
		if (j != i)D += abs(A[i][j]);
	}
	if (abs(A[i][i]) < D)return 1;
	return 0;
}


int WrireLine(const vector<vector<double>>& A, vector<vector<double>>& B,const  vector<double>& b, vector<double>& m, int n, int i)
{
	for (int alpha = 1, l = 0; abs(alpha) < 100; l % 2 == 0 ? alpha = -alpha : alpha = abs(alpha) + 1, l++)
	{
		for (int Betta = 1, r = 0; abs(Betta) < 100; r % 2 == 0 ? Betta = -Betta : Betta = abs(Betta) + 1, r++)
		{
			for (int k = 0; k < n; k++)
			{
				if (k != i)
				{
					for (int j = 0; j < n; j++)
					{
						B[i][j] = A[i][j] * alpha + A[k][j] * Betta;
						m[i] = b[i] * alpha + b[k] * Betta;
					}
					if (proverka_na_diagonaln_preoblodaniye(B, n, i) == 0)
					{
						cout << " исправили строку " << i << "строчкой " << k << " на " << B[i][0] << "  " << B[i][1] << "  " << B[i][2] << "  " << m[i] << "    " << alpha << " " << Betta << endl;
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int max_v_stolbce(const vector<vector<double>>& A, int n, int i)
{
	double f = abs(A[i][i]);
	int k = i;
	for (int j = i + 1; j < n; j++)
	{
		if (f < abs(A[j][i]))
		{
			f = abs(A[j][i]);
			k = j;
		}
	}
	return k;
}

int max_v_stroke(const vector<vector<double>>& A, int n, int i)
{
	double f = abs(A[i][i]);
	int k = i;
	for (int j = i + 1; j < n; j++)
	{
		if (f < abs(A[i][j]))
		{
			f = abs(A[i][j]);
			k = j;
		}
	}
	return k;
}


int perevod_v_norm(vector<vector<double>>& B,vector<double>& m, int n)
{

	for (int j = 0; j < n; j++)
	{
		m[j] = -m[j];
	}

	for (int i = 0; i < n; i++)
	{
		B[i][i] = -1;
	}
	return 0;
}

int perevod_v_NEnorm(vector<vector<double>>& B, vector<double>& m, int n)
{
	for (int j = 0; j < n; j++)
	{
		m[j] = m[j] / B[j][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				B[i][j] = -B[i][j] / B[i][i];
			}
		}
		B[i][i] = 0;
	}
	return 0;
}

int perestanovka(vector<vector<double>>& B, vector<double>& m, int n)
{

	int k, r;
	double R;

	for (int i = 0; i < n; i++)
	{
		k = max_v_stolbce(B, n, i);
		r = max_v_stroke(B, n, i);

		if (abs(B[k][i]) >= abs(B[i][r]))
		{

			// идет смена i на к строчку
			for (int j = 0; j < n; j++)
			{
				R = B[i][j];
				B[i][j] = B[k][j];
				B[k][j] = R;
			}
			R = m[i];
			m[i] = m[k];
			m[k] = R;

			if (proverka_na_diagonaln_preoblodaniye(B, n, i)==1)
			{
				// идет обратная смена i на к строчку
				for (int j = 0; j < n; j++)
				{
					R = B[i][j];
					B[i][j] = B[k][j];
					B[k][j] = R;
				}
				R = m[i];
				m[i] = m[k];
				m[k] = R;

			}
		}
		else
		{
			// идет смена i на r столбец
			for (int j = 0; j < n; j++)
			{
				R = B[j][i];
				B[j][i] = B[j][r];
				B[j][r] = R;
			}
			R = B[n][i];
			B[n][i] = B[n][r];
			B[n][r] = R;
			if (proverka_na_diagonaln_preoblodaniye(B, n, i) == 1)
			{
				// идет обратная смена i на r столбец
				for (int j = 0; j < n; j++)
				{
					R = B[j][i];
					B[j][i] = B[j][r];
					B[j][r] = R;
				}
				R = B[n][i];
				B[n][i] = B[n][r];
				B[n][r] = R;
			}
		}

		vivod(B, n);
		vivod(m, n);
		
	}
	return 0;
}
int multu_matrix_on_matrix(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C, int n)
{
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			C[i][l] = 0;
			for (int j = 0; j < n; j++) {
				C[i][l] += A[i][j] * B[j][l];
			}
		}
	}
	return 0;
}


vector<double> multu_matrix_on_matrix_on_vector(const vector<vector<double>>& A, const vector<vector<double>>& B, const vector<double>& C, int n)
{
	vector<vector<double>> E(n, vector<double>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int l = 0; l < n; l++)
		{
			for (int j = 0; j < n; j++)
			{
				E[i][l] += A[i][j] * B[j][l];
			}
		}
	}

	return multu_matrix_on_vector(E, C, n);
}

vector<double> multu_matrix_on_vector(const vector<vector<double>>& A, const vector<double>& C, int n)
{
	vector<double> f(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f[i] += A[i][j] * C[j];
		}
	}
	return f;
}

int privedeniye_k_diagonalnomu_vidu(const vector<vector<double>>& B_old, vector<vector<double>>& B, const  vector<double>& m_old, vector<double>& m, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (proverka_na_diagonaln_preoblodaniye(B, n, i) == 1)				// i строка на которой проверка  
		{
			if (WrireLine(B_old, B, m_old, m, n, i) == 1)
			{
				//cout << " невозможно привести к диагональному виду строку " << i << endl;
				B[i] = B_old[i];
				m[i] = m_old[i];
			}

		}
	}
	return 0;
}