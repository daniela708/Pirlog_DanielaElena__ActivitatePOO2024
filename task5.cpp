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
    int n;

    std::cout << "Introduceți numărul de laptopuri: ";
    std::cin >> n;
    std::vector<Laptop> laptopuri(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Laptop " << i + 1 << " memorie: ";
        std::cin >> laptopuri[i].memorie;
        std::cout << "Laptop " << i + 1 << " pret: ";
        std::cin >> laptopuri[i].pret;
    }

    std::cout << "Introduceți numărul de telefoane: ";
    std::cin >> n;
    std::vector<Telefon> telefoane(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Telefon " << i + 1 << " baterie: ";
        std::cin >> telefoane[i].baterie;
        std::cout << "Telefon " << i + 1 << " camera: ";
        std::cin >> telefoane[i].camera;
    }

    std::cout << "Introduceți numărul de tablete: ";
    std::cin >> n;
    std::vector<Tableta> tablete(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Tableta " << i + 1 << " dimensiune ecran: ";
        std::cin >> tablete[i].dimensiuneEcran;
        std::cout << "Tableta " << i + 1 << " capacitate: ";
        std::cin >> tablete[i].capacitate;
    }

    std::cout << "\nLaptopuri:\n";
    for (const auto& laptop : laptopuri) {
        std::cout << laptop << std::endl;
    }

    std::cout << "\nTelefoane:\n";
    for (const auto& telefon : telefoane) {
        std::cout << telefon << std::endl;
    }

    std::cout << "\nTablete:\n";
    for (const auto& tableta : tablete) {
        std::cout << tableta << std::endl;
    }

    std::cout << "\nIntroduceți dimensiunea matricei de laptopuri (linii și coloane): ";
    int linii, coloane;
    std::cin >> linii >> coloane;
    std::vector<std::vector<Laptop>> matriceLaptopuri(linii, std::vector<Laptop>(coloane));
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < coloane; ++j) {
            std::cout << "Laptop [" << i << "][" << j << "] memorie: ";
            std::cin >> matriceLaptopuri[i][j].memorie;
            std::cout << "Laptop [" << i << "][" << j << "] pret: ";
            std::cin >> matriceLaptopuri[i][j].pret;
        }
    }

    std::cout << "\nMatricea de laptopuri:\n";
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < coloane; ++j) {
            std::cout << "Laptop [" << i << "][" << j << "]: " << matriceLaptopuri[i][j] << std::endl;
        }
    }

    return 0;
}
