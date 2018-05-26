#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv)
{
	int tablica[8][4] = { {0,2,4,0},{1,4,4,0},{ 2,2,0 ,0} ,{ 3,5,0,0 } ,{ 4,2,0 ,0} ,{ 5,6,5 ,0} ,{ 6,2,0,0 } ,{ 7,2,4 ,0} };
	int tablica_wartosci[8];
	int tablica_zgodnosci[8];
	int spelnia_warunek[8];
	int vec_size = 0;
	int i;
	int ile_zero = 0;
	int iteracja = 1;
	int ile_odczekac = 0;
	int q = 2;
	int suma=0;
	double pom = 0;

	for (i = 0; i < 8; i++)
	{
		tablica_wartosci[i] = tablica[i][1];
		tablica_zgodnosci[i] = 0;
	}

	while (ile_zero != 8)
	{
		for (i = 0; i < 8; i++)
		{
			if (iteracja > tablica[i][2])
			{
				tablica_zgodnosci[i] = 1;
				if (q <= tablica[i][1])
				{
					ile_odczekac += q;
				}
				if (q > tablica[i][1])
				{
					ile_odczekac += tablica[i][1];
				}
			}
		}
		for (i = 0; i < 8; i++)
		{
		

			if ((tablica[i][3] != 1)&&(tablica_zgodnosci[i]==1))
			{
				if (q < tablica[i][1])
				{
					tablica[i][1] -= q;
					iteracja += q;
					cout << "Usuna³em " << q << " z " << tablica[i][0] << " pozostalo " << tablica[i][1] << endl;
					ile_odczekac -= q;
					tablica_zgodnosci[i] = 0;

				}
				if(q >= tablica[i][1])
				{
					iteracja += tablica[i][1];
					cout << "Usuna³em " << tablica[i][1] << " z " << tablica[i][0] << " pozostalo 0" << endl;
					ile_odczekac -= tablica[i][1];
					tablica[i][1] = 0;
					tablica_zgodnosci[i] = 0;
					tablica[i][3] = 1;
					ile_zero++;
					cout << "Usuwam " << tablica[i][0] << " w iteracji " << iteracja << " a oczekiwal " << iteracja - tablica[i][2] - 1 << endl;
					spelnia_warunek[i] = iteracja - tablica[i][2] - 1;
				}
			}
		}
		
	}
	for (i = 0; i < 8; i++)
	{
		suma += spelnia_warunek[i];
	}
	pom = suma / 8;
	cout << "Srednio zajelo im to " << pom << endl;

	system("PAUSE");
	return 0;
}