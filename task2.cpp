#include <iostream>

using namespace std;

// Clasa 1: Laptop
class Laptop {
public:
    std::string brand;
    int ram; // în GB
    double* price; // pointer alocat dinamic
    static int totalLaptops;
    const int id;

    // Constructori
    Laptop() : id(++totalLaptops) {
        brand = "Unknown";
        ram = 0;
        price = new double(0.0);
    }

    Laptop(std::string b, int r) : id(++totalLaptops) {
        brand = b;
        ram = r;
        price = new double(0.0);
    }

    Laptop(std::string b, int r, double p) : id(++totalLaptops) {
        brand = b;
        ram = r;
        price = new double(p);
    }

    static void displayTotalLaptops() {
        std::cout << "Total laptops created: " << totalLaptops << std::endl;
    }

    ~Laptop() {
        delete price;
    }
};

int Laptop::totalLaptops = 0;

// Clasa 2: Telefon
class Telefon {
public:
    std::string brand;
    std::string model;
    double* batteryCapacity; // pointer alocat dinamic
    static int totalPhones;
    const std::string countryOfOrigin;

    // Constructori
    Telefon() : countryOfOrigin("China") {
        brand = "Unknown";
        model = "Unknown";
        batteryCapacity = new double(0.0);
    }

    Telefon(std::string b, std::string m) : countryOfOrigin("China") {
        brand = b;
        model = m;
        batteryCapacity = new double(0.0);
    }

    Telefon(std::string b, std::string m, double bCap, std::string origin) : countryOfOrigin(origin) {
        brand = b;
        model = m;
        batteryCapacity = new double(bCap);
    }

    static void displayTotalPhones() {
        std::cout << "Total phones created: " << totalPhones << std::endl;
    }

    ~Telefon() {
        delete batteryCapacity;
    }
};

int Telefon::totalPhones = 0;

// Clasa 3: Tablet?
class Tableta {
public:
    std::string brand;
    double screenSize; // în inch
    int* storage; // pointer alocat dinamic
    static int totalTablets;
    const double weight;

    // Constructori
    Tableta() : weight(0.0) {
        brand = "Unknown";
        screenSize = 0.0;
        storage = new int(0);
    }

    Tableta(std::string b, double s) : weight(0.0) {
        brand = b;
        screenSize = s;
        storage = new int(0);
    }

    Tableta(std::string b, double s, int st, double w) : weight(w) {
        brand = b;
        screenSize = s;
        storage = new int(st);
    }

    static void displayTotalTablets() {
        std::cout << "Total tablets created: " << totalTablets << std::endl;
    }

    ~Tableta() {
        delete storage;
    }
};

int Tableta::totalTablets = 0;

// Func?ia main
int main() {
    // Testare clasa Laptop
    Laptop l1;
    Laptop l2("Dell", 16);
    Laptop l3("HP", 32, 1500.0);

    std::cout << "Laptop 1: " << l1.brand << ", RAM: " << l1.ram << ", Price: $" << *l1.price << std::endl;
    std::cout << "Laptop 2: " << l2.brand << ", RAM: " << l2.ram << ", Price: $" << *l2.price << std::endl;
    std::cout << "Laptop 3: " << l3.brand << ", RAM: " << l3.ram << ", Price: $" << *l3.price << std::endl;
    Laptop::displayTotalLaptops();

    // Testare clasa Telefon
    Telefon t1;
    Telefon t2("Samsung", "Galaxy S21");
    Telefon t3("Apple", "iPhone 14", 3200.0, "USA");

    std::cout << "Telefon 1: " << t1.brand << ", Model: " << t1.model << ", Battery: " << *t1.batteryCapacity << "mAh" << std::endl;
    std::cout << "Telefon 2: " << t2.brand << ", Model: " << t2.model << ", Battery: " << *t2.batteryCapacity << "mAh" << std::endl;
    std::cout << "Telefon 3: " << t3.brand << ", Model: " << t3.model << ", Battery: " << *t3.batteryCapacity << "mAh" << std::endl;
    Telefon::displayTotalPhones();

    // Testare clasa Tablet?
    Tableta tb1;
    Tableta tb2("Apple", 10.2);
    Tableta tb3("Samsung", 12.4, 128, 0.5);

    std::cout << "Tableta 1: " << tb1.brand << ", Screen Size: " << tb1.screenSize << " inch, Storage: " << *tb1.storage << "GB" << std::endl;
    std::cout << "Tableta 2: " << tb2.brand << ", Screen Size: " << tb2.screenSize << " inch, Storage: " << *tb2.storage << "GB" << std::endl;
    std::cout << "Tableta 3: " << tb3.brand << ", Screen Size: " << tb3.screenSize << " inch, Storage: " << *tb3.storage << "GB" << std::endl;
    Tableta::displayTotalTablets();

    return 0;
}
