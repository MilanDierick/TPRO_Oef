// ExtraOef03.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void invoer(double *getallen, unsigned int aantalGetallen);
void sorteerGetallen(double *getallen, unsigned int aantalGetallen);
void outputGesorteerdeGetallen(double *getallen, unsigned int aantalGetallen);
double berekenSom(const double *getallen, unsigned int aantalGetallen);
double berekenGemiddelde(const double *getallen, unsigned int aantalGetallen);
double berekenMediaan(const double *getallen, unsigned int aantalGetallen);

int main()
{
	double *getallen;
	unsigned int aantalGetallen;
	bool geenGetal;

	do
	{
		geenGetal = false;
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

	cout << "De som van de getallen is: " << berekenSom(getallen, aantalGetallen) << "." << endl;
	cout << "Het gemiddelde van de getallen is: " << berekenGemiddelde(getallen, aantalGetallen) << "." << endl;
	cout << "De mediaan van de getallen is: " << berekenMediaan(getallen, aantalGetallen) << "." << endl;
	cout << "Het kleinste ingegeven getal is: " << getallen[0] << "." << endl;
	cout << "Het grootste ingegeven getal is: " << getallen[aantalGetallen - 1] << "." << endl;

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

double berekenSom(const double *getallen, unsigned int aantalGetallen)
{
	double som = 0.0;

	for (int i = 0; i < aantalGetallen; i++)
	{
		som += getallen[i];
	}
	return som;
}

double berekenGemiddelde(const double *getallen, unsigned int aantalGetallen)
{
	return berekenSom(getallen, aantalGetallen) / aantalGetallen;
}

double berekenMediaan(const double * getallen, unsigned int aantalGetallen)
{
	if (aantalGetallen % 2 == 0)
	{
		return (getallen[aantalGetallen / 2] + getallen[aantalGetallen / 2 + 1]) / 2;
	}
	else
	{
		return getallen[static_cast<int>(aantalGetallen / 2)];
	}
}
