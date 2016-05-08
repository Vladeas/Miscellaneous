#include<iostream>
#include<fstream>

using namespace std;


struct ore{// structura care contine ora de inceput si sfarsit a spectacolului
	int a, b;
};


void inserare(int &n,ore x[],int y,int z)//inserez orele direct ordonate in sir, crescator dupa ora la care se termina
{
	int i,j;
	for(i=0;i<n && x[i].b<z;i++);
	for(j=n;j>i;j--)
		x[j]=x[j-1];
	n++;
	x[i].a=y;
	x[i].b=z;
}


void citire(int &n,ore x[])//citesc toate spectacolele din acea zi
{
	ifstream f("orar.txt");
	int y,z;
	n=0;
	while(f>>y)
	{
		f>>z;
		inserare(n,x,y,z);//apelez inserarea
	}
}


void program(int n,ore x[])//afisez primul spectacol iar apoi urmatoarele cat timp au ora de inceput >= decat ora de sfarsit al celui dinainte 
{
	int j=0,i;
	cout<<x[j].a<<" "<<x[j].b<<endl;
	for(i=1;i<n;i++)
		if(x[j].b<=x[i].a)
		{
			j=i;
			cout<<x[j].a<<" "<<x[j].b<<endl;
		}
}


int main()
{
	int n;
	ore x[100];
	citire(n,x);
	program(n,x);
	system("pause");
	return 0;
}