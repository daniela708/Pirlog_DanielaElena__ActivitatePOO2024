#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Bloc {
    string strada;
    int numar;
    int scari;
    int apartamente;
    int etaje;


    void citire() {
        cout << "Introduceti strada: ";
        getline(cin >> ws, strada); 
        cout << "Introduceti numarul blocului: ";
        cin >> numar;
        cout << "Introduceti numarul de scari: ";
        cin >> scari;
        cout << "Introduceti numarul total de apartamente: ";
        cin >> apartamente;
        cout << "Introduceti numarul de etaje: ";
        cin >> etaje;
    }

    void afisare() const {
        cout << "Blocul de pe strada " << strada
            << ", numar " << numar
            << ", are " << scari << " scari"
            << ", un numar total de " << apartamente << " apartamente"
            << " si " << etaje << " etaje." << endl;
    }
};

int main() {
    vector<Bloc*> blocuri(10);

    for (int i = 0; i < 10; ++i) {
        blocuri[i] = new Bloc(); 
        cout << "Introduceti detalii pentru blocul " << i + 1 << ":" << endl;
        blocuri[i]->citire();    
    }

    
    cout << "\nDetalii despre blocuri:" << endl;
    for (int i = 0; i < 10; ++i) {
        blocuri[i]->afisare();   
    }

   
    for (int i = 0; i < 10; ++i) {
        delete blocuri[i];
    }

    return 0;
}
