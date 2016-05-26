#include<iostream>
#include<string.h>


using namespace std;


int main()
{
	char sir[100], c[100], aux[100];
	int i, j, n;

	cin.get(sir, 100);
	cin.get();
	cin.get(c, 100);

	n = strlen(c);

	for (i = 0; i <= strlen(sir) - n; i++)
	{

		j = 0;
		strncpy_s(aux, sir + i, n);
		if (strcmp(aux, c) == 0)
		{

			while (j < n)
			{

				sir[i++] = '*';
				j++;
			}
		}
	}

	cout << sir << endl;

	system("pause");
}