#include <iostream>

using namespace std;

class Magazin {
public:
	string oras;
	int nrAngajati;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;

	Magazin() :anDeschidere(2024), nrAngajati(2) {
		this->oras = "Bucuresti";
		this->suprafata = 50.0;

	}

	Magazin(
		string oras,
		int nrAngajati,
		float suprafata,
		int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;

	}

	void afisare() {
		cout
			<< "Oras: "
			<< this->oras
			<< endl;
		cout
			<< "Angajati: "
			<< this->nrAngajati
			<< endl;
		cout
			<< "Suprafata: "
			<< this->suprafata
			<< endl;
		cout
			<< "An deschidere: "
			<< this->anDeschidere
			<< endl;
		cout
			<< endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati)
			return this->suprafata / this->nrAngajati;
		else return 0;
	}

	static void modificaImpozit(int impozitNou) {
		if (impozitNou > 0)
			Magazin::impozitM2 = impozitNou;
	}

	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++)
			suma += vector[i].suprafata;
		return suma;
	}
};

int Magazin::impozitM2 = 2;

void main() {
	Magazin m;
	m.afisare();
	Magazin::modificaImpozit(3);

	Magazin m2("Iasi", 7, 200.0, 2019);
	m2.afisare();
	m2.modificaImpozit(4);

	Magazin* pointer = new Magazin("Timisoara", 4, 170.0, 2020);
	pointer->afisare();

	cout
		<< "Suprafata medie: "
		<< m2.calculeazaSuprafataMedie();

	cout
		<< "Suprafata medie: "
		<< pointer->calculeazaSuprafataMedie();

	int nrMagazine = 3;
	Magazin* vector = new Magazin[nrMagazine];

	cout
		<< "Vector\n";
	for (int i = 0; i < nrMagazine; i++)
		vector[i].afisare();

	cout
		<< "Suprafata totala: "
		<< Magazin::calculeazaSuprafataTotala(vector, nrMagazine)
		<< endl;

	delete[] vector;
	delete pointer;
}
