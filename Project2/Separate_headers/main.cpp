#include "concert.h"
#include "atelier_muzical.h"
#include "festival.h"
#include <iostream>
#include <stdexcept>

// functii care arunca exceptii in functie de nr de participanti, durata
void verificareParticipanti(int nrParticipanti) {
    if (nrParticipanti < 0) {
        throw std::invalid_argument("Caz invalid!");
    } else if (nrParticipanti == 0) {
        throw std::out_of_range("Nu există participanți!");
    } else {
        std::cout << "Numărul de participanți este valid: " << nrParticipanti << '\n';
    }
}
void verificaDurata(int durata) {
    if (durata <= 0) {
        throw std::out_of_range("Valoare în afara intervalului permis!");
    } else {
        std::cout << "Durata evenimentului este validă: " << durata << " ore." << '\n';
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
    } catch (const std::invalid_argument& e) {
        std::cerr << "Eroare: " << e.what() << '\n';
    } catch (const std::out_of_range& e) {
        std::cerr << "Eroare: " << e.what() << '\n';
    }

    try {
           verificaDurata(-2);
       } catch (const std::out_of_range& e) {
           std::cerr << "Eroare: " << e.what() << '\n';
       }
    try {
           verificaDurata(5);
       } catch (const std::out_of_range& e) {
           std::cerr << "Eroare: " << e.what() << '\n';
       }
    return 0;
}
