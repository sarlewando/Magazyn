// zadanie 1 na nowo.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <functional>


using namespace std; 
int tab[200];
int licznik = 0, ktora = -1;
int pierwsza;
int najwiecej = -1, ta_liczba;
int taliczba_roznych;
int najwiecej_roznych = 0;
int ile3 = 0, ile5 = 0;

bool dobra3(int liczba1, int liczba2, int liczba3) 
{
	return liczba3 % liczba2 == 0 && liczba2 % liczba1 == 0;
}

bool dobra5(int liczba1, int liczba2, int liczba3, int liczba4, int liczba5)
{
	return liczba5 % liczba4 == 0 && liczba4 % liczba3 == 0 && liczba3 % liczba2 == 0 && liczba2 % liczba1 == 0;
}

int main()
{
	ifstream plik;
	plik.open("przyklad.txt");

	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku!";
		exit(0);
	}

	cout << "Wszystkie liczby: " << endl;


	int pomocnicze;
	while (!plik.eof())
	{
		//4.1
		for (int i = 0; i < 200; i++)
		{
			plik >> pomocnicze;
			tab[i] = pomocnicze;
			cout << tab[i] << " ";
		}


		for (int i = 0; i < 200; i++)
		{
			int a;
			a = tab[i];

			int ostatnia = a % 10;

			while (a > 0)
			{
				pierwsza = a % 10;
				a /= 10;
			}

			if (pierwsza == ostatnia)
			{
				if (ktora == -1)
				{
					ktora = tab[i];
				}
				licznik++;
			}

		}

		//4.2

		for (int i = 0; i < 200; i++)
		{
			int c = 2;
			int a = tab[i];
			int poprzednia = 0;
			int licznik_czynnikow = 0;
			int roznych = 0;

			while (a > 1)
			{
				if (a % c == 0)
				{
					a /= c;
					licznik_czynnikow++;

					if (c != poprzednia)
					{
						roznych++;

					} poprzednia = c;

					if (poprzednia == 0)
					{
						poprzednia = c;
					}

				}
				else c++;
			}

			if (roznych > najwiecej_roznych)
			{
				najwiecej_roznych = roznych;
				taliczba_roznych = tab[i];
			}

			if (licznik_czynnikow > najwiecej)
			{
				najwiecej = licznik_czynnikow;
				ta_liczba = tab[i];
			}
		}

		//4.3
		
		sort(tab, tab + 200);
		ofstream out3;
		out3.open("trojki.txt", ios::out);

		for (int i = 0; i < 200; i++)
			for (int j = i+1; j < 200; j++)
				for (int k = j+1; k < 200; k++)
				{
					int r = dobra3(tab[i], tab[j], tab[k]);
					ile3 += r;
						if (r == 1)
							out3 << tab[i] << " " << tab[j] << " " << tab[k] << endl;

				}
		out3.close();


		ofstream out5;
		out5.open("piatki.txt", ios::out);

		for (int i = 0; i < 200; i++)
			for (int j = i + 1; j < 200; j++)
				for (int k = j + 1; k < 200; k++)
					for (int l = k + 1; l < 200; l++)
						for (int m = l + 1; m < 200; m++)
						{
							int r = dobra5(tab[i], tab[j], tab[k], tab[l], tab[m]);
							ile5 += r;

							if (r==1)
							{
								out5 << tab[i] << " " << tab[j] << " " << tab[k] << " " << tab[l] << " " << tab[m] << endl;
							}

						}
		out5.close();

		

		cout << endl;
		cout << "4.1 Ilosc liczb o takim samym koncu i poczatku: " << licznik << endl;
		cout << "4.1 Pierwsza taka liczba: " << ktora << endl;
		cout << "4.2 Liczba z najwieksza iloscia czynnikow pierwszych: " << ta_liczba << endl;
		cout << "4.2 Liczba jej czynnikow: " << najwiecej << endl;
		cout << "4.2 Liczba z najwieksza iloscia roznych czynnikow pierwszych: " << taliczba_roznych << endl;
		cout << "4.2 Liczba jej czynnikow: " << najwiecej_roznych << endl;
		cout << "4.3 Liczba trojek: " << ile3 << endl;
		cout << "4.3 Liczba piatek: " << ile5 << endl;

		plik.close();
		return 0;
	}
} 


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
