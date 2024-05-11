#include "concert.h"
#include <iostream>

Concert::Concert(std::string nume, std::string locatie, std::string data, std::string genMuzical, std::string scena, int nrPiese)
    : Eveniment(nume, locatie, data, genMuzical), scena(scena), nrPiese(nrPiese) {}

void Concert::detaliiEveniment() const {
    std::cout << "Concertul ";
    afiseazaNume();
    std::cout << '\n';
    std::cout << "Locatie: " << locatie << '\n';
    std::cout << "Data: " << data << '\n';
    std::cout << "Gen muzical: " << genMuzical << '\n';
    std::cout << "Scena: " << scena << '\n';
    std::cout << "Nr piese: " << nrPiese << '\n';
}

void Concert::modificaGenMuzical(std::string gen) {
    genMuzical = gen;
    std::cout << "Genul muzical a fost modificat in: " << gen << '\n';
}
