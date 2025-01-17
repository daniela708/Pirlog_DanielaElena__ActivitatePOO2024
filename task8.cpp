#include <iostream>
#include <fstream>
#include <string>

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

    // Functii pentru fisiere text
    void scrieInFisierText(const std::string& filename) const {
        std::ofstream fout(filename);
        if (fout.is_open()) {
            fout << "Laptop: " << brand << "\n";
            fout << "RAM: " << memorieRAM << " GB\n";
            fout.close();
        }
    }

    void citesteDinFisierText(const std::string& filename) {
        std::ifstream fin(filename);
        if (fin.is_open()) {
            std::getline(fin, brand);
            fin >> memorieRAM;
            fin.close();
        }
    }

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

    // Functii pentru fisiere binare
    void scrieInFisierBinar(const std::string& filename) const {
        std::ofstream fout(filename, std::ios::binary);
        if (fout.is_open()) {
            size_t len = model.size();
            fout.write(reinterpret_cast<const char*>(&len), sizeof(len));
            fout.write(model.c_str(), len);
            fout.write(reinterpret_cast<const char*>(&pret), sizeof(pret));
            fout.close();
        }
    }

    void citesteDinFisierBinar(const std::string& filename) {
        std::ifstream fin(filename, std::ios::binary);
        if (fin.is_open()) {
            size_t len;
            fin.read(reinterpret_cast<char*>(&len), sizeof(len));
            model.resize(len);
            fin.read(&model[0], len);
            fin.read(reinterpret_cast<char*>(&pret), sizeof(pret));
            fin.close();
        }
    }

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

class GamingLaptop : public Laptop {
private:
    std::string placaVideo;
    bool areRGB;

public:
    // Constructor
    GamingLaptop(const std::string& brand, int memorieRAM, const std::string& placaVideo, bool areRGB)
        : Laptop(brand, memorieRAM), placaVideo(placaVideo), areRGB(areRGB) {}

    // Getteri si setteri
    std::string getPlacaVideo() const { return placaVideo; }
    void setPlacaVideo(const std::string& newPlacaVideo) { placaVideo = newPlacaVideo; }

    bool getAreRGB() const { return areRGB; }
    void setAreRGB(bool newAreRGB) { areRGB = newAreRGB; }
};

class Smartphone : public Telefon {
private:
    int capacitateBaterie;
    bool are5G;

public:
    // Constructor
    Smartphone(const std::string& model, double pret, int capacitateBaterie, bool are5G)
        : Telefon(model, pret), capacitateBaterie(capacitateBaterie), are5G(are5G) {}

    // Getteri si setteri
    int getCapacitateBaterie() const { return capacitateBaterie; }
    void setCapacitateBaterie(int newCapacitateBaterie) { capacitateBaterie = newCapacitateBaterie; }

    bool getAre5G() const { return are5G; }
    void setAre5G(bool newAre5G) { are5G = newAre5G; }
};

// Functii globale
void procesareLaptop(Laptop& laptop) {
    laptop.setMemorieRAM(laptop.getMemorieRAM() * 2); // Dublam memoria RAM
    std::cout << "Laptopul " << laptop.getBrand() << " acum are " << laptop.getMemorieRAM() << " GB RAM.\n";
}

void procesareTelefon(Telefon& telefon) {
    telefon.setPret(telefon.getPret() - 100); // Reducem pretul cu 100
    std::cout << "Telefonul " << telefon.getModel() << " acum costa " << telefon.getPret() << " RON.\n";
}

int main() {
    // Crearea obiectelor
    Laptop l1("Dell", 8);
    Telefon t1("iPhone", 5000);
    Tableta tab1("10.5 inci", true);
    GamingLaptop gl1("Asus ROG", 16, "NVIDIA RTX 3080", true);
    Smartphone sm1("Samsung Galaxy S21", 4000, 5000, true);

    // Lucru cu fisiere text
    l1.scrieInFisierText("laptop.txt");
    l1.citesteDinFisierText("laptop.txt");
    std::cout << "Laptop din fisier text: " << l1.getBrand() << ", RAM: " << l1.getMemorieRAM() << " GB\n";

    // Lucru cu fisiere binare
    t1.scrieInFisierBinar("telefon.bin");
    t1.citesteDinFisierBinar("telefon.bin");
    std::cout << "Telefon din fisier binar: " << t1.getModel() << ", Pret: " << t1.getPret() << " RON\n";

    // Apelarea metodelor si functiilor
    std::cout << "Laptop: " << l1.getBrand() << ", RAM: " << l1.getMemorieRAM() << " GB\n";
    std::cout << "Telefon: " << t1.getModel() << ", Pret: " << t1.getPret() << " RON\n";
    std::cout << "Tableta: " << tab1.getDimensiuneEcran() << ", Are stylus: " << (tab1.getAreStylus() ? "Da" : "Nu") << "\n";
    std::cout << "GamingLaptop: " << gl1.getBrand() << ", RAM: " << gl1.getMemorieRAM() << " GB, Placa Video: " << gl1.getPlacaVideo() << ", RGB: " << (gl1.getAreRGB() ? "Da" : "Nu") << "\n";
    std::cout << "Smartphone: " << sm1.getModel() << ", Pret: " << sm1
