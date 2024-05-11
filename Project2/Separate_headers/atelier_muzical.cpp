#include "atelier_muzical.h"
#include <iostream>

AtelierMuzical::AtelierMuzical(std::string nume, std::string locatie, std::string data, std::string genMuzical, std::string activitate)
    : Eveniment(nume, locatie, data, genMuzical), activitate(activitate) {}

void AtelierMuzical::detaliiEveniment() const {
    std::cout << "Atelierul muzical ";
    afiseazaNume();
    std::cout << '\n';
    std::cout << "Locatie: " << locatie << '\n';
    std::cout << "Data: " << data << '\n';
    std::cout << "Gen muzical: " << genMuzical << '\n';
    std::cout << "Activitate: " << activitate << '\n';
}

void AtelierMuzical::modificaGenMuzical(std::string gen) {
    genMuzical = gen;
    std::cout << "Genul muzical a fost modificat in: " << gen << '\n';
}
