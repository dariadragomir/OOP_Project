#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Eveniment {
protected:
    string nume;
    vector<string> artistiInvitati;
    string locatie;
    string data;
    string genMuzical;
    static int nrParticipanti;
    static const int durata = 2; // ore
    void afiseazaNume() const {
            cout << nume;
        }

public:
    Eveniment(string nume, string locatie, string data, string genMuzical)
        : nume(nume), locatie(locatie), data(data), genMuzical(genMuzical) {}

    static void mesajEveniment() {
        cout << "Bine ati venit la evenimentele noastre!" << '\n';
    }

    virtual void detaliiEveniment() const = 0; // met pur virtuale
    virtual void modificaGenMuzical(string gen) = 0;
    
    static void setNrParticipanti(int nr) {
        nrParticipanti = nr;
    }

    static int getNrParticipanti() {
        return nrParticipanti;
    }
};

int Eveniment::nrParticipanti = 0; // initializare variabila membra statica

// clasa Concert mosteneste virtual din Eveniment
class Concert : public virtual Eveniment {
protected:
    string scena;
    int nrPiese;

public:
    Concert(string nume, string locatie, string data, string genMuzical, string scena, int nrPiese)
        : Eveniment(nume, locatie, data, genMuzical), scena(scena), nrPiese(nrPiese) {}

    void detaliiEveniment() const override {
        cout << "Concertul";
        afiseazaNume();
        cout<<'\n';
        cout << "Locatie: " << locatie << '\n';
        cout << "Data: " << data << '\n';
        cout << "Gen muzical: " << genMuzical << '\n';
        cout << "Scena: " << scena << '\n';
        cout << "Nr piese: " << nrPiese << '\n';
    }

    void modificaGenMuzical(string gen) override {
            genMuzical = gen;
            cout << "Genul muzical a fost modificat in: " << gen << '\n';
        }
};

// clasa AtelierMuzical mosteneste virtual din Eveniment
class AtelierMuzical : public virtual Eveniment {
protected:
    string activitate;

public:
    AtelierMuzical(string nume, string locatie, string data, string genMuzical, string activitate)
        : Eveniment(nume, locatie, data, genMuzical), activitate(activitate) {}

    void detaliiEveniment() const override {
        cout << "Atelierul muzical ";
        afiseazaNume();
        cout << '\n';
        cout << "Locatie: " << locatie << '\n';
        cout << "Data: " << data << '\n';
        cout << "Gen muzical: " << genMuzical << '\n';
        cout << "Activitate: " << activitate << '\n';
    }

    void modificaGenMuzical(string gen) override {
            genMuzical = gen;
            cout << "Genul muzical a fost modificat in: " << gen << '\n';
        }
};

// Clasa Festival mosteneste din Concert si din AtelierMuzical
class Festival : public Concert, public AtelierMuzical {
public:
    //se apeleaza constructorul cu parametri al clasei de baza folosind lista de initializare din constructorul clasei derivate
    Festival(string nume, string locatie, string data, string genMuzical, string scena, int nrPiese, string activitate)
        : Eveniment(nume, locatie, data, genMuzical), Concert(nume, locatie, data, genMuzical, scena, nrPiese),
          AtelierMuzical(nume, locatie, data, genMuzical, activitate) {}

    void detaliiEveniment() const override {
        cout << "Festivalul ";
        afiseazaNume();
        cout << '\n';
        cout << "Locatie: " << locatie << '\n';
        cout << "Data: " << data << '\n';
        cout << "Gen muzical: " << genMuzical << '\n';
        cout << "Scena: " << scena << '\n';
        cout << "Nr piese: " << nrPiese << '\n';
        cout << "Activitate: " << activitate << '\n';
    }

    void modificaGenMuzical(string gen) override {
            genMuzical = gen;
            cout << "Genul muzical a fost modificat in: " << gen << '\n';
        }
};

class MyException : public exception {
public:
    const char* what() const throw() {
        return "Caz invalid!";
    }
};
class OutOfRangeException : public exception {
public:
    const char* what() const throw() {
        return "Valoare în afara intervalului permis!";
    }
};

// functii care arunca exceptii in functie de nr de participanti, durata
void verificareParticipanti(int nrParticipanti) {
    if (nrParticipanti < 0) {
        throw MyException();
    } else if (nrParticipanti == 0) {
        throw out_of_range("Nu există participanți!");
    } else {
        cout << "Numărul de participanți este valid: " << nrParticipanti << '\n';
    }
}
void verificaDurata(int durata) {
    if (durata <= 0) {
        throw OutOfRangeException();
    } else {
        cout << "Durata evenimentului este validă: " << durata << " ore." << '\n';
    }
}
int main() {
    Concert concert("Concert1", "Locatie1", "23-08-2025", "Rock", "Scena1", 10);
    AtelierMuzical atelier("Atelier1", "Locatie2", "02-01-2025", "Jazz", "Curs de chitara");

    // Polimorfism la execuție (dynamic dispatch)
    const Eveniment* ptrEveniment1 = &concert;
    ptrEveniment1->detaliiEveniment(); // Polimorfism la execuție

    const Eveniment* ptrEveniment2 = &atelier;
    ptrEveniment2->detaliiEveniment(); // Polimorfism la execuție

    // Upcasting
    const Eveniment& evenimentConcert = concert;
    const Eveniment& evenimentAtelier = atelier;

    // Bloc try...catch pentru prinderea excepțiilor
    try {
        verificareParticipanti(-1);
    } catch (const MyException& e) {
        cerr << "Eroare: " << e.what() << '\n';
    } catch (const out_of_range& e) {
        cerr << "Eroare: " << e.what() << '\n';
    }

    try {
           verificaDurata(-2);
       } catch (const OutOfRangeException& e) {
           cerr << "Eroare: " << e.what() << '\n';
       }
    try {
           verificaDurata(5);
       } catch (const OutOfRangeException& e) {
           cerr << "Eroare: " << e.what() << '\n';
       }
    return 0;
}
