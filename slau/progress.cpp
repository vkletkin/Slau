#include "Slau_metod.h"


int vvod(int n,vector <vector<double>>& A,vector<double>& b)
{
	cout << "Vvedite elementi matr A postolbcam" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << " stolbec " << i + 1 << endl;
		for (int  j = 0; j < n; j++)
		{
			cin >> A[j][i];
		}
	}
	cout << "Vvedite elementi b " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];	
	}
	return 0;
}


int vvod1(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 2;	A[0][1] = 2;	A[0][2] = 10;	b[0] = 14;
	A[1][0] = 10;	A[1][1] = 1;	A[1][2] = 1;	b[1] = 12;
	A[2][0] = 2;	A[2][1] = 10;	A[2][2] = 1;	b[2] = 13;

	vivod(A, n);
	vivod(b, n);
	return 0;
}
int vvod2(int &n, vector <vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 7.6;	A[0][1] = 5.8;	A[0][2] = 4.7;	b[0] = 10.1;
	A[1][0] = 3.8;	A[1][1] = 4.1;	A[1][2] = 2.7;	b[1] = 9.7;
	A[2][0] = 2.9;	A[2][1] = 2.1;	A[2][2] = 3.8;	b[2] = 7.8;

	vivod(A, n);
	vivod(b, n);
	return 0;
}

int vvod3(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 4;	A[0][1] = -1;	A[0][2] = 1;	b[0] = 4;
	A[1][0] = 1;	A[1][1] = 6;	A[1][2] = 2;	b[1] = 9;
	A[2][0] = -1;	A[2][1] = -2;	A[2][2] = 5;	b[2] = 2;

	vivod(A, n);
	vivod(b, n);
	return 0;
}
int vvod4(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 4;

	A[0][0] = 3;	 A[0][1] = 4;	 A[0][2] = -9;	 A[0][3] = 5;	 b[0] = -14;
	A[1][0] = -15;	 A[1][1] = -12;	 A[1][2] = 50;   A[1][3] = -16;	 b[1] = 44;
	A[2][0] = -27;	 A[2][1] = -36;	 A[2][2] = 73;   A[2][3] = 8;    b[2] = 142;
	A[3][0] = 9;	 A[3][1] = 12;   A[3][2] = -10;  A[3][3] = -16;  b[3] = -76;

	vivod(A, n);
	vivod(b, n);
	return 0;
}

int vvod5(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 4;

	A[0][0] = 8;	 A[0][1] = -1;	 A[0][2] = -2;	A[0][3] = 0;	b[0] = -2.3;
	A[1][0] = 0;	 A[1][1] = 10;	 A[1][2] = -2;  A[1][3] = 2;	b[1] = 0.5;
	A[2][0] = -1;	 A[2][1] = 0;	 A[2][2] = 6;   A[2][3] = 2;    b[2] = 1.2;
	A[3][0] = 3;	 A[3][1] = -1;   A[3][2] = 2;	A[3][3] = 12;	b[3] = -3.7;

	vivod(A, n);
	vivod(b, n);
	return 0;
};

int vivod(const vector<vector<double>>& A, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4)<< A[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

int vivod(const vector<double>& A,int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << setw(4) << A[j] << endl;
	}
	cout << endl;
	return 0;
}

int vivodX(vector<complex<double>>& A,int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << setw(4) << "X[" << j << "] = " << A[j] << endl;
	}
	cout << endl;
	return 0;
}

int vivodX(const vector<double>& A, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << setw(4) <<"X["<<j<<"] = " <<A[j] << endl;
	}
	cout << endl;
	return 0;
}


int vvod_Slau_metod_kvad_korney(int &n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 1.42;		A[0][1] = -2.15;	A[0][2] = 1.07;		b[0] = 2.48;
	A[1][0] = -2.15;	A[1][1] = 0.76;		A[1][2] = -2.18;	b[1] = 1.15;
	A[2][0] = 1.07;		A[2][1] = -2.18;	A[2][2] = 1.23;		b[2] = 0.88;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}

int vvod_Slau_metod_kvad_korney1(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 2;		A[0][1] = 1;	A[0][2] = 4;		b[0] = 16;
	A[1][0] = 1;		A[1][1] = 1;	A[1][2] = 3;		b[1] = 12;
	A[2][0] = 4;		A[2][1] = 3;	A[2][2] = 14;		b[2] = 52;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}
int vvod_Slau_metod_kvad_korney2(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 3.2;		A[0][1] = 1;	A[0][2] = 1;		b[0] = 4;
	A[1][0] = 1;		A[1][1] = 3.7;	A[1][2] = 1;		b[1] = 4.5;
	A[2][0] = 1;		A[2][1] = 1;	A[2][2] = 4.2;		b[2] = 4;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}
int vvod_Slau_metod_kvad_korney3(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 1.65;		A[0][1] = -2.27;	A[0][2] = 0.18;		b[0] = 2.25;
	A[1][0] = -2.27;	A[1][1] = 1.73;		A[1][2] = -0.46;	b[1] = 0.93;
	A[2][0] = 0.18;		A[2][1] = -0.46;	A[2][2] = 2.16;		b[2] = 1.33;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}



int vvod_Slau_metod_just_iter(int &n, vector<vector<double>>& A, vector<double>& b)// забита не в норме
{
	n = 4;
	A[0][0] = 0.13;	 A[0][1] = 0.23;	A[0][2] = -0.44;	A[0][3] = -0.05;	b[0] = 2.13;
	A[1][0] = 0.24;	 A[1][1] = 0;		A[1][2] = -0.31;	A[1][3] = 0.15;		b[1] = -0.18;
	A[2][0] = 0.06;	 A[2][1] = 0.15;	A[2][2] = 0;		A[2][3] = -0.23;    b[2] = 1.44;
	A[3][0] = 0.72;	 A[3][1] = -0.08;	A[3][2] = -0.05;	A[3][3] = 0;		b[3] = 2.42;

	vivod(A, n);
	vivod(b, n); 
	return 0;
}

int vvod_Slau_metod_just_iter1(int& n, vector<vector<double>>& A, vector<double>& b)// забита не в норме
{
	n = 3;
	A[0][0] = 0;	A[0][1] = -0.1; A[0][2] = -0.1; b[0] = 1.2;
	A[1][0] = -0.2; A[1][1] = 0;	A[1][2] = -0.1; b[1] = 1.3;
	A[2][0] = -0.2; A[2][1] = -0.2; A[2][2] = 0;	b[2] = 1.4;

	vivod(A, n);
	vivod(b, n);
	return 0;
}


int vvod_Slau_metod_zeydel(int& n, vector<vector<double>>& A, vector<double>& b) 
{
	n = 3;
	A[0][0] = 7.6;	A[0][1] = 5.8;	A[0][2] = 4.7;	b[0] = 10.1;
	A[1][0] = 3.8;	A[1][1] = 4.1;	A[1][2] = 2.7;	b[1] = 9.7;
	A[2][0] = 2.9;	A[2][1] = 2.1;	A[2][2] = 3.8;	b[2] = 7.8;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}


int vvod_Slau_metod_zeydel1(int& n, vector<vector<double>>& A, vector<double>& b) 
{
	n = 3;
	A[0][0] = 2;	A[0][1] = 2;	A[0][2] = 10;	b[0] = 14;
	A[1][0] = 10;	A[1][1] = 1;	A[1][2] = 1;	b[1] = 12;
	A[2][0] = 2;	A[2][1] = 10;	A[2][2] = 1;	b[2] = 13;

	vivod(A, n);
	vivod(b, n); 
	return 0;
}

int vvod_Slau_metod_zeydel2(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 7.6;	A[0][1] = 5.8;	A[0][2] = 4.7;	b[0] = 10.1;
	A[1][0] = 3.8;	A[1][1] = 4.1;	A[1][2] = 2.7;	b[1] = 9.7;
	A[2][0] = 2.9;	A[2][1] = 2.1;	A[2][2] = 3.8;	b[2] = 7.8;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}
int vvod_Slau_metod_zeydel3(int& n, vector<vector<double>>& A, vector<double>& b) 
{
	n = 3;
	A[0][0] = 4;	A[0][1] = -1;	A[0][2] = 1;	b[0] = 4;
	A[1][0] = 1;	A[1][1] = 6;	A[1][2] = 2;	b[1] = 9;
	A[2][0] = -1;	A[2][1] = -2;	A[2][2] = 5;	b[2] = 2;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}


int vvod_Slau_metod_zeydel_2VER(int& n, vector<vector<double>>& A, vector<double>& b)  
{
	n = 4;

	A[0][0] = 1.15;	 A[0][1] = 0.62;	A[0][2] = -0.83;	A[0][3] = 0.92;	 b[0] = 2.15;
	A[1][0] = 0.82;	 A[1][1] = -0.54;	A[1][2] = 0.43;		A[1][3] = -0.25; b[1] = 0.62;
	A[2][0] = 0.24;	 A[2][1] = 1.15;	A[2][2] = -0.33;	A[2][3] = 1.42;  b[2] = -0.62;
	A[3][0] = 0.73;	 A[3][1] = -0.81;   A[3][2] = 1.27;		A[3][3] = -0.67; b[3] = 0.88;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}
int vvod_Slau_metod_zeydel_2VER1(int& n, vector<vector<double>>& A, vector<double>& b)  
{
	n = 3;

	A[0][0] = 2;	A[0][1] = 2;	A[0][2] = 10;	b[0] = 14;
	A[1][0] = 10;	A[1][1] = 1;	A[1][2] = 1;	b[1] = 12;
	A[2][0] = 2;	A[2][1] = 10;	A[2][2] = 1;	b[2] = 13;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}
int vvod_Slau_metod_zeydel_2VER2(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 7.6;	A[0][1] = 5.8;	A[0][2] = 4.7;	b[0] = 10.1;
	A[1][0] = 3.8;	A[1][1] = 4.1;	A[1][2] = 2.7;	b[1] = 9.7;
	A[2][0] = 2.9;	A[2][1] = 2.1;	A[2][2] = 3.8;	b[2] = 7.8;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}
int vvod_Slau_metod_zeydel_2VER3(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 4;	A[0][1] = -1;	A[0][2] = 1;	b[0] = 4;
	A[1][0] = 1;	A[1][1] = 6;	A[1][2] = 2;	b[1] = 9;
	A[2][0] = -1;	A[2][1] = -2;	A[2][2] = 5;	b[2] = 2;

	vivod(A, n);
	vivod(b, n);
	return 0;
}

int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy(int& n, vector<vector<double>>& A, vector<double>& b)  
{
	n = 4;

	A[0][0] = 1.15;	 A[0][1] = 0.62;	A[0][2] = -0.83;	A[0][3] = 0.92;	 b[0] = 2.15;
	A[1][0] = 0.82;	 A[1][1] = -0.54;	A[1][2] = 0.43;		A[1][3] = -0.25; b[1] = 0.62;
	A[2][0] = 0.24;	 A[2][1] = 1.15;	A[2][2] = -0.33;	A[2][3] = 1.42;  b[2] = -0.62;
	A[3][0] = 0.73;	 A[3][1] = -0.81;   A[3][2] = 1.27;		A[3][3] = -0.67; b[3] = 0.88;

	vivod(A, n); 
	vivod(b, n);
	return 0;
}


int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy1(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;

	A[0][0] = 2;	A[0][1] = 2;	A[0][2] = 10;	b[0] = 14;
	A[1][0] = 10;	A[1][1] = 1;	A[1][2] = 1;	b[1] = 12;
	A[2][0] = 2;	A[2][1] = 10;	A[2][2] = 1;	b[2] = 13;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}

int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy2(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 7.6;	A[0][1] = 5.8;	A[0][2] = 4.7;	b[0] = 10.1;
	A[1][0] = 3.8;	A[1][1] = 4.1;	A[1][2] = 2.7;	b[1] = 9.7;
	A[2][0] = 2.9;	A[2][1] = 2.1;	A[2][2] = 3.8;	b[2] = 7.8;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}

int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy3(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 4;	A[0][1] = -1;	A[0][2] = 1;	b[0] = 4;
	A[1][0] = 1;	A[1][1] = 6;	A[1][2] = 2;	b[1] = 9;
	A[2][0] = -1;	A[2][1] = -2;	A[2][2] = 5;	b[2] = 2;

	vivod(A, n);
	vivod(b, n);
	return 0;
}
int vvod_Slau_metod_GAUSS_MAIN_ITEM_po_stolbcy4(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 4;

	A[0][0] = 3;	 A[0][1] = 4;	 A[0][2] = -9;	 A[0][3] = 5;	 b[0] = -14;
	A[1][0] = -15;	 A[1][1] = -12;	 A[1][2] = 50;   A[1][3] = -16;	 b[1] = 44;
	A[2][0] = -27;	 A[2][1] = -36;	 A[2][2] = 73;   A[2][3] = 8;    b[2] = 142;
	A[3][0] = 9;	 A[3][1] = 12;   A[3][2] = -10;  A[3][3] = -16;  b[3] = -76;

	vivod(A, n);
	vivod(b, n);
	return 0;
}


int vvod_Slau_metod_GRAD(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 4;

	A[0][0] = 1.15;	 A[0][1] = 0.62;	A[0][2] = -0.83;	A[0][3] = 0.92;	 b[0] = 2.15;
	A[1][0] = 0.82;	 A[1][1] = -0.54;	A[1][2] = 0.43;		A[1][3] = -0.25; b[1] = 0.62;
	A[2][0] = 0.24;	 A[2][1] = 1.15;	A[2][2] = -0.33;	A[2][3] = 1.42;  b[2] = -0.62;
	A[3][0] = 0.73;	 A[3][1] = -0.81;   A[3][2] = 1.27;		A[3][3] = -0.67; b[3] = 0.88;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
};

int vvod_Slau_metod_GRAD1(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;

	A[0][0] = 2;	A[0][1] = 2;	A[0][2] = 10;	b[0] = 14;
	A[1][0] = 10;	A[1][1] = 1;	A[1][2] = 1;	b[1] = 12;
	A[2][0] = 2;	A[2][1] = 10;	A[2][2] = 1;	b[2] = 13;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
}
int vvod_Slau_metod_GRAD2(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 7.6;	A[0][1] = 5.8;	A[0][2] = 4.7;	b[0] = 10.1;
	A[1][0] = 3.8;	A[1][1] = 4.1;	A[1][2] = 2.7;	b[1] = 9.7;
	A[2][0] = 2.9;	A[2][1] = 2.1;	A[2][2] = 3.8;	b[2] = 7.8;

	vivod(A, n); 
	vivod(b, n); 
	return 0;
	
};

int vvod_Slau_metod_GRAD3(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 3;
	A[0][0] = 4;	A[0][1] = -1;	A[0][2] = 1;	b[0] = 4;
	A[1][0] = 1;	A[1][1] = 6;	A[1][2] = 2;	b[1] = 9;
	A[2][0] = -1;	A[2][1] = -2;	A[2][2] = 5;	b[2] = 2;

	vivod(A, n);
	vivod(b, n);
	return 0;
};

int vvod_Slau_metod_GRAD4(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 4;

	A[0][0] = 3;	 A[0][1] = 4;	 A[0][2] = -9;	 A[0][3] = 5;	 b[0] = -14;
	A[1][0] = -15;	 A[1][1] = -12;	 A[1][2] = 50;   A[1][3] = -16;	 b[1] = 44;
	A[2][0] = -27;	 A[2][1] = -36;	 A[2][2] = 73;   A[2][3] = 8;    b[2] = 142;
	A[3][0] = 9;	 A[3][1] = 12;   A[3][2] = -10;  A[3][3] = -16;  b[3] = -76;

	vivod(A, n);
	vivod(b, n);
	return 0;
}

int vvod_Slau_metod_GRAD5(int& n, vector<vector<double>>& A, vector<double>& b)
{
	n = 4;

	A[0][0] = 8;	 A[0][1] = -1;	 A[0][2] = -2;	A[0][3] = 0;	b[0] = -2.3;
	A[1][0] = 0;	 A[1][1] = 10;	 A[1][2] = -2;  A[1][3] = 2;	b[1] = 0.5;
	A[2][0] = -1;	 A[2][1] = 0;	 A[2][2] = 6;   A[2][3] = 2;    b[2] = 1.2;
	A[3][0] = 3;	 A[3][1] = -1;   A[3][2] = 2;	A[3][3] = 12;	b[3] = -3.7;

	vivod(A, n);
	vivod(b, n); 
	return 0;
};

