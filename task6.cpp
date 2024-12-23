#include <iostream>
#include <vector>

class Laptop {
public:
    int memorie;
    int pret;

    Laptop& operator=(const Laptop& other) {
        if (this != &other) {
            this->memorie = other.memorie;
            this->pret = other.pret;
        }
        return *this;
    }

    bool operator==(const Laptop& other) const {
        return (this->memorie == other.memorie && this->pret == other.pret);
    }

    bool operator!=(const Laptop& other) const {
        return !(*this == other);
    }

    Laptop operator+(const Laptop& other) const {
        Laptop result;
        result.memorie = this->memorie + other.memorie;
        result.pret = this->pret + other.pret;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Laptop& obj) {
        os << "Laptop(memorie: " << obj.memorie << ", pret: " << obj.pret << ")";
        return os;
    }
};

class Magazin {
private:
    std::vector<Laptop> laptopuri;
    std::string nume;
    std::string locatie;

public:
    // Constructor
    Magazin(std::string nume, std::string locatie) : nume(nume), locatie(locatie) {}

    // Getteri și setteri
    const std::vector<Laptop>& getLaptopuri() const {
        return laptopuri;
    }

    void setLaptopuri(const std::vector<Laptop>& laptopuri) {
        this->laptopuri = laptopuri;
    }

    std::string getNume() const {
        return nume;
    }

    void setNume(const std::string& nume) {
        this->nume = nume;
    }

    std::string getLocatie() const {
        return locatie;
    }

    void setLocatie(const std::string& locatie) {
        this->locatie = locatie;
    }

    // Operatori
    Magazin& operator=(const Magazin& other) {
        if (this != &other) {
            this->nume = other.nume;
            this->locatie = other.locatie;
            this->laptopuri = other.laptopuri;
        }
        return *this;
    }

    bool operator==(const Magazin& other) const {
        return (this->nume == other.nume && this->locatie == other.locatie && this->laptopuri == other.laptopuri);
    }

    bool operator!=(const Magazin& other) const {
        return !(*this == other);
    }

    // Metodă pentru a adăuga un laptop
    void adaugaLaptop(const Laptop& laptop) {
        laptopuri.push_back(laptop);
    }

    // Prietenă funcție pentru a afișa detalii despre magazin
    friend std::ostream& operator<<(std::ostream& os, const Magazin& obj) {
        os << "Magazin(nume: " << obj.nume << ", locatie: " << obj.locatie << ")\nLaptopuri:\n";
        for (const auto& laptop : obj.laptopuri) {
            os << laptop << std::endl;
        }
        return os;
    }
};

int main() {
    Magazin magazin("TechStore", "Bucuresti");

    Laptop laptop1;
    laptop1.memorie = 8;
    laptop1.pret = 1000;

    Laptop laptop2;
    laptop2.memorie = 16;
    laptop2.pret = 1500;

    magazin.adaugaLaptop(laptop1);
    magazin.adaugaLaptop(laptop2);

    std::cout << magazin << std::endl;

    return 0;
}
