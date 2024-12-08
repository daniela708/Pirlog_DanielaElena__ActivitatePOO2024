#include <iostream>
using namespace std;

class Laptop;
class Telefon;
class Tableta;

// Functii globale (prietene)
void procesareLaptop(Laptop&);
void procesareTelefon(Telefon&);

class Laptop {
private:
    std::string brand;
    int memorieRAM;
    static int numarLaptopuri;

public:
    // Constructori
    Laptop(const std::string& brand, int memorieRAM) : brand(brand), memorieRAM(memorieRAM) {
        ++numarLaptopuri;
    }

    // Constructor de copiere
    Laptop(const Laptop& other) : brand(other.brand), memorieRAM(other.memorieRAM) {
        ++numarLaptopuri;
    }

    // Destructor
    ~Laptop() {
        --numarLaptopuri;
    }

    // Getteri si setteri
    std::string getBrand() const { return brand; }
    void setBrand(const std::string& newBrand) { brand = newBrand; }

    int getMemorieRAM() const { return memorieRAM; }
    void setMemorieRAM(int newMemorieRAM) { memorieRAM = newMemorieRAM; }

    // Functii statice
    static int getNumarLaptopuri() { return numarLaptopuri; }

    // Prietenie cu functia globala
    friend void procesareLaptop(Laptop&);
};

int Laptop::numarLaptopuri = 0;

class Telefon {
private:
    std::string model;
    double pret;

public:
    // Constructori
    Telefon(const std::string& model, double pret) : model(model), pret(pret) {}

    // Constructor de copiere
    Telefon(const Telefon& other) : model(other.model), pret(other.pret) {}

    // Destructor
    ~Telefon() {}

    // Getteri si setteri
    std::string getModel() const { return model; }
    void setModel(const std::string& newModel) { model = newModel; }

    double getPret() const { return pret; }
    void setPret(double newPret) { pret = newPret; }

    // Prietenie cu functia globala
    friend void procesareTelefon(Telefon&);
};

class Tableta {
private:
    std::string dimensiuneEcran;
    bool areStylus;

public:
    // Constructori
    Tableta(const std::string& dimensiuneEcran, bool areStylus)
        : dimensiuneEcran(dimensiuneEcran), areStylus(areStylus) {}

    // Constructor de copiere
    Tableta(const Tableta& other)
        : dimensiuneEcran(other.dimensiuneEcran), areStylus(other.areStylus) {}

    // Destructor
    ~Tableta() {}

    // Getteri si setteri
    std::string getDimensiuneEcran() const { return dimensiuneEcran; }
    void setDimensiuneEcran(const std::string& newDimensiuneEcran) {
        dimensiuneEcran = newDimensiuneEcran;
    }

    bool getAreStylus() const { return areStylus; }
    void setAreStylus(bool newAreStylus) { areStylus = newAreStylus; }
};

// Functii globale
void procesareLaptop(Laptop& laptop) {
    laptop.memorieRAM *= 2; // Dublam memoria RAM
    std::cout << "Laptopul " << laptop.brand << " acum are " << laptop.memorieRAM << " GB RAM.\n";
}

void procesareTelefon(Telefon& telefon) {
    telefon.pret -= 100; // Reducem pretul cu 100
    std::cout << "Telefonul " << telefon.model << " acum costa " << telefon.pret << " RON.\n";
}

int main() {
    // Crearea obiectelor
    Laptop l1("Dell", 8);
    Telefon t1("iPhone", 5000);
    Tableta tab1("10.5 inci", true);

    // Apelarea metodelor si functiilor
    std::cout << "Laptop: " << l1.getBrand() << ", RAM: " << l1.getMemorieRAM() << " GB\n";
    std::cout << "Telefon: " << t1.getModel() << ", Pret: " << t1.getPret() << " RON\n";
    std::cout << "Tableta: " << tab1.getDimensiuneEcran() << ", Are stylus: " << (tab1.getAreStylus() ? "Da" : "Nu") << "\n";

    // Procesare prieteni
    procesareLaptop(l1);
    procesareTelefon(t1);

    // Testarea functiilor statice
    std::cout << "Numar total de laptopuri: " << Laptop::getNumarLaptopuri() << "\n";

    return 0;
}
