#include<iostream>
using namespace std;
//structura de is a
class Angajat {
protected://am acces la ele direct din clase mostenite
	string nume;
	int marca;//codul dupa care e identificat ang
	float salariu;

public:
	Angajat() {
		this->marca = 1234;
		this->nume = "No name";
		this->salariu = 3000;
	}

	Angajat(int marca, string nume, float salariu) {
		this->marca = marca;
		this->nume = nume;
		this->salariu = salariu;

	}

	/*float getSalariu() {
		return this->salariu;
	}*/

	//virtuala ptr ca fiecare angajat are mai multe sporuri-in fct de ce fel de ang este primeste mai mult/putine sporuri; 
	//tabela de pointeri la functii virtuale
	//fct virtual pura-> pointerul rrspectiv este initializat automat cu null =0
	//dc fct virt=0; o clasa care are cel putin o fct virtual pura-> clasa abstracta
	// cls abstracta -> nu pot sa mi declar obiecte de tipul acelei clase (abstracte)/ nu poate fi instantiata;
	//->la randul ei clasa manager nu poate fi instantiata; e mostenita a fi cls abstracta
	//-fac o suprascriere in clasa m de proiect si de dep ptr a functiona
	//o cls abstracta ne permite sa vem constructori- pe care ii va folosi cls fiu-manager...
	//permite sa extindem codul-mostenire + destructor..
	//nu mi permite crearea de obiecte dar pot declara pointeri la obiecte;!!!!!!!!!
	//pointer= new Angajat() nu ma lasa
	//pointer =NULL DA
	//ma lsa sa pun un obiect de tipul clasei fiu


	virtual float getVenitIncasat() = 0;
};

class Manager :public Angajat {
private:
	int nrSubordonati;
	float sporPerSubordonat;//in fct de cati sub are

public:
	Manager() :Angajat()//constr fara param apeleaza constr de la ang fara parametrii{
	{
		this->nrSubordonati = 0;
		this->sporPerSubordonat = 0;
	}

	Manager(int nr, float spor) :Angajat() {
		this->nrSubordonati = nr;
		this->sporPerSubordonat = spor;
	}
	//metoda ptr sal
	float getSporConducere() {
		return this->nrSubordonati * this->sporPerSubordonat;
	}

};

//angajat-manager -manager de dep
//                - manager de 

class ManagerDepartament : public Manager {
private:
	string numeDepartament;
	bool deCercetare;// dc e true e dep de cercetare-> primeste bonus

public:

	ManagerDepartament() : Manager() {
		this->numeDepartament = "Departament";
		this->deCercetare = false;
	}

	ManagerDepartament(string nume, bool deCercetare, int nrSubordonati, float sporPerSubordonat) : Manager(nrSubordonati, sporPerSubordonat) {
		this->numeDepartament = nume;
		this->deCercetare = deCercetare;

	}
	//automat pointerul resp- din tab nu mai e nul-> aceasta clasa nu mai e abstracta si putem initializa/crea ob de acest tip
	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		if (this->deCercetare) {
			venit += (10 / 100) * salariu;
		}
		return venit;
	}

};

class ManagerDeProiect :public Manager {
private:
	string numeProiect;
	int nrZile;
	float sporPerZi;
public:
	ManagerDeProiect() :Manager() {
		this->numeProiect = "Project";
		this->nrZile = 0;
		this->sporPerZi = 0;
	}

	ManagerDeProiect(string nume, int nrZile, float sporPeZi, int nrSubordonati, float sporPerSubordonati) :
		Manager(nrSubordonati, sporPerSubordonati) {
		this->numeProiect = nume;
		this->nrZile = nrZile;
		this->sporPerZi = sporPeZi;
	}
	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		venit += (this->nrZile * this->sporPerZi);
		return venit;
	}

};


int main() {
	//Angajat a;//nu putem instantia un ob de tip clasei abstracte
	//manager m;-la fel


	ManagerDepartament md;
	ManagerDeProiect mp;


	Angajat* pointer;
	//pointer=new Angajat NUUU
	pointer = NULL;
	pointer = new ManagerDepartament();
	pointer->getVenitIncasat();//va fi apelata metoda din manager dep ptr ca se realizeaza o leg tarzie-- latebiding la mom executie
	//earlybiding la mo compilarii

	int nrAngajati = 5;
	Angajat** vector;//vector de pointeri
	vector = new Angajat * [nrAngajati];
	vector[0] = new ManagerDepartament();
	vector[1] = new ManagerDeProiect();
	vector[2] = new ManagerDeProiect("TODO list", 10, 30, 3, 15);
	vector[3] = new ManagerDepartament("AI", true, 10, 15);
	vector[4] = new ManagerDepartament();

	for (int i = 0; i < nrAngajati; i++) {
		cout << (i + 1) << "." << vector[i]->getVenitIncasat() << endl;
	}


	return 345;
}