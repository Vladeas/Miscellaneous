#include<iostream>
#include<fstream>

using namespace std;

void citire(int &n, int x[100], int &a, int &b)// sirul dat este ordonat descrescator
{
	ifstream f("text.txt");
	f >> n;// citesc numarul de elemnte din sir
	for (int i = 0; i < n; i++)
		f >> x[i];// citesc cele n elemente ale sirului
	f >> a >> b;// citesc intervalul [a,b] , in care a<=b
	f.close();
}

int binar(int n, int x[100], int a, int b)
{
	int st=0, dr=n-1, m,ok=0;
	while (st <= dr && ok==0)
	{
		m = (st + dr) / 2;
		if (x[m]<b && x[m]>a)// daca mijlocul se afla in interval
		{
			if (x[m - 1] < b)// daca elemetul din stanga se afla de asemenea in interval Mijlocul devine dreapta
				dr = m;
			if (x[m - 1] > b || m==0)// daca elemetul din stanga nu se afla in interval se returneaza maximul
				return x[m];// cond. m==0 este necesara in cazul in care nu exita element la stanga lui x[m]
		}
		else
		{// daca mijlocul nu se afla in interval mijlocul devine Dr sau St in functie de Mijloc
			if (x[m] > b)
				st = m+1;
			if (x[m] < a)
				dr = m;
		}
		if ((x[m]>b && x[m + 1]<a) || (x[m - 1]>b && x[m] < a))// Daca se verifica conditia, atunci nu exita elemente cuprise in interval
			ok = 1;
	}
	return -1;// daca nu s-a gasit un element care sa apartina intervalului se returneaza -1
}

int main()
{
	int i, a, b, x[100], n, k;
	citire(n, x, a, b);// apelez citirea datelor
	k = binar(n, x, a, b);// apelez cautarea binara
	if (k == -1)
		cout << "Nu exista \n";
	else cout << k << endl;
	system("pause");
	return 0;
}