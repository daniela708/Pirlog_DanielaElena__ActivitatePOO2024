#include <iostream>

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

class Telefon {
public:
    int baterie;
    int camera;

    Telefon& operator=(const Telefon& other) {
        if (this != &other) {
            this->baterie = other.baterie;
            this->camera = other.camera;
        }
        return *this;
    }

    bool operator==(const Telefon& other) const {
        return (this->baterie == other.baterie && this->camera == other.camera);
    }

    bool operator!=(const Telefon& other) const {
        return !(*this == other);
    }

    Telefon operator+(const Telefon& other) const {
        Telefon result;
        result.baterie = this->baterie + other.baterie;
        result.camera = this->camera + other.camera;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Telefon& obj) {
        os << "Telefon(baterie: " << obj.baterie << ", camera: " << obj.camera << ")";
        return os;
    }
};

class Tableta {
public:
    int dimensiuneEcran;
    int capacitate;

    Tableta& operator=(const Tableta& other) {
        if (this != &other) {
            this->dimensiuneEcran = other.dimensiuneEcran;
            this->capacitate = other.capacitate;
        }
        return *this;
    }

    bool operator==(const Tableta& other) const {
        return (this->dimensiuneEcran == other.dimensiuneEcran && this->capacitate == other.capacitate);
    }

    bool operator!=(const Tableta& other) const {
        return !(*this == other);
    }

    Tableta operator+(const Tableta& other) const {
        Tableta result;
        result.dimensiuneEcran = this->dimensiuneEcran + other.dimensiuneEcran;
        result.capacitate = this->capacitate + other.capacitate;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Tableta& obj) {
        os << "Tableta(dimensiuneEcran: " << obj.dimensiuneEcran << ", capacitate: " << obj.capacitate << ")";
        return os;
    }
};

void afisare(const Laptop& laptop, const Telefon& telefon, const Tableta& tableta) {
    std::cout << laptop << std::endl;
    std::cout << telefon << std::endl;
    std::cout << tableta << std::endl;
}

int main() {
    Laptop laptop1, laptop2;
    laptop1.memorie = 8;
    laptop1.pret = 1000;
    laptop2.memorie = 16;
    laptop2.pret = 1500;

    Telefon telefon1, telefon2;
    telefon1.baterie = 3000;
    telefon1.camera = 12;
    telefon2.baterie = 4000;
    telefon2.camera = 16;

    Tableta tableta1, tableta2;
    tableta1.dimensiuneEcran = 10;
    tableta1.capacitate = 64;
    tableta2.dimensiuneEcran = 12;
    tableta2.capacitate = 128;

    Laptop laptop3 = laptop1 + laptop2;
    Telefon telefon3 = telefon1 + telefon2;
    Tableta tableta3 = tableta1 + tableta2;

    afisare(laptop3, telefon3, tableta3);

    return 0;
}
