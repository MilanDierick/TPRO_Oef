// ExtraOef03.cpp : Defines the entry point for the console application.
// Milan Dierick | 5IT | 07 | VTI Lokeren | 20/11/2017

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void invoer(double *getallen, unsigned int aantalGetallen);
void sorteerGetallen(double *getallen, unsigned int aantalGetallen);
void outputGesorteerdeGetallen(double *getallen, unsigned int aantalGetallen);
double kleinsteGetal(double *getallen);
double grootsteGetal(double *getallen, unsigned int aantalGetallen);

int main()
{
	double *getallen;
	unsigned int aantalGetallen;

	do
	{
		bool geenGetal = false;
		system("CLS");
		cout << "Hoeveel getallen zou je willen ingeven?" << endl;
		cin >> aantalGetallen;

		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			geenGetal = true;
		}
	} while (aantalGetallen > 512 || aantalGetallen < 0 || !cin);

	getallen = new double[aantalGetallen];

	invoer(getallen, aantalGetallen);
	sorteerGetallen(getallen, aantalGetallen);
	outputGesorteerdeGetallen(getallen, aantalGetallen);

	cout << "Het kleinste ingegeven getal is: " << kleinsteGetal(getallen) << "." << endl;
	cout << "Het grootste ingegeven getal is: " << grootsteGetal(getallen, aantalGetallen) << "." << endl;

	delete[] getallen;
	system("PAUSE");
	return 0;
}

void invoer(double *getallen, unsigned int aantalGetallen)
{
	string tmp;

	system("CLS");
	for (int i = 0; i < aantalGetallen; i++)
	{
		cout << "Geef getal " << i + 1 << ": " << endl;
		cin >> tmp;
		getallen[i] = stod(tmp.c_str());
		system("CLS");
	}
}

void sorteerGetallen(double * getallen, unsigned int aantalGetallen)
{
	stable_sort(getallen, getallen + aantalGetallen);
}

void outputGesorteerdeGetallen(double * getallen, unsigned int aantalGetallen)
{
	cout << "De gesorteerde getallen zijn: " << endl;
	for (int i = 0; i < aantalGetallen; i++)
	{
		cout << setw(4) << getallen[i];
	}
	cout << endl;
}

double kleinsteGetal(double *getallen)
{
	return getallen[0];
}

double grootsteGetal(double *getallen, unsigned int aantalGetallen)
{
	return getallen[aantalGetallen - 1];
}
