#include "eveniment.h"
#include <iostream>

int Eveniment::nrParticipanti = 0; // initializare variabila membra statica

Eveniment::Eveniment(std::string nume, std::string locatie, std::string data, std::string genMuzical)
    : nume(nume), locatie(locatie), data(data), genMuzical(genMuzical) {}

void Eveniment::mesajEveniment() {
    std::cout << "Bine ati venit la evenimentele noastre!" << '\n';
}

void Eveniment::afiseazaNume() const {
    std::cout << nume;
}

void Eveniment::setNrParticipanti(int nr) {
    nrParticipanti = nr;
}

int Eveniment::getNrParticipanti() {
    return nrParticipanti;
}
