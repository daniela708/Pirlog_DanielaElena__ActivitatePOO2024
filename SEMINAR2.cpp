#include<iostream>
using namespace std;

struct Apartament {
	char* adresa;
	string proprietar;
	int nrCamere;
	float suprafata;
};

void afisareApartament(Apartament* ap) {
	cout << "Adresa:" << ap->adresa << endl;
	cout << "Proprietar:" << ap->proprietar << endl;
	cout << "Numar camere:" << ap->nrCamere << endl;
	cout << "Suprafata:" << ap->suprafata << endl;
};
Apartament citireApartament() {
	Apartament ap;
	cout << "Adresa:"; //cout afiseaza
	char buffer[100]; //citesc in cadrul acestui buffer adresa
	cin >> buffer;
	ap.adresa = new char[strlen(buffer) + 1];
	strcpy_s(ap.adresa, strlen(buffer) + 1, buffer);

	cout << "Proprietar:";
	cin >> ap.proprietar;
	cout << "Numar camere:";
	cin >> ap.nrCamere;
	cout << "Suprafata:";
	cin >> ap.suprafata;
	return ap;

		//cin citeste
};

int main() {
	Apartament ap;
	ap.nrCamere = 3; //initializez adica atriui o valoare

	Apartament* pointer;
	pointer = new Apartament(); //am alocat cu paranteze rotunde pt ca avem un singur element
	pointer->nrCamere = 5;
	pointer->proprietar = "Gigel"; 
	pointer->adresa = new char[strlen("Bucuresti")+1]; //strlen=calculeaza nr de caractere din bucuresti, strlen e o functie ; 
	strcpy_s(pointer->adresa, strlen("Bucuresti") + 1, "Bucuresti"); // strcpy este o functie care copiaza
	pointer->suprafata = 120;

	afisareApartament(pointer);
	delete pointer;
	int nrApartamente = 2;
	Apartament* apartamente;
	apartamente = new Apartament[nrApartamente];
	for (int i = 0; i < nrApartamente; i++) {
		apartamente[i] = citireApartament();

	}

	for (int i = 0; i < nrApartamente; i++) {
		afisareApartament(&(apartamente[i]));
	}
	for (int i = 0; i < nrApartamente; i++)
	{
		delete[]apartamente[i].adresa;
	}
	delete[]apartamente;
	//declar un vector de apartamente 
	Apartament* apartamente; //alocare dinamica
	//initializez vectorul
	apartamente = new Apartament[2]; //paranteze patrate cand aloc spatiu pentru mai multe apartamente
	Apartament** pointeri; //fac un vector de pointer la apartamente, il declar 
	pointeri = new Apartament * [3]; //initializez vectorul, avem 3 pointeri la apartament


	return 0;
}
