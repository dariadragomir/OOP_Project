#include "festival.h"
#include <iostream>

Festival::Festival(std::string nume, std::string locatie, std::string data, std::string genMuzical, std::string scena, int nrPiese, std::string activitate)
    : Eveniment(nume, locatie, data, genMuzical), Concert(nume, locatie, data, genMuzical, scena, nrPiese),
      AtelierMuzical(nume, locatie, data, genMuzical, activitate) {}

void Festival::detaliiEveniment() const {
    std::cout << "Festivalul ";
    afiseazaNume();
    std::cout << '\n';
    std::cout << "Locatie: " << locatie << '\n';
    std::cout << "Data: " << data << '\n';
    std::cout << "Gen muzical: " << genMuzical << '\n';
    std::cout << "Scena: " << scena << '\n';
    std::cout << "Nr piese: " << nrPiese << '\n';
    std::cout << "Activitate: " << activitate << '\n';
}

void Festival::modificaGenMuzical(std::string gen) {
    genMuzical = gen;
    std::cout << "Genul muzical a fost modificat in: " << gen << '\n';
}
