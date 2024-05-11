#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <string>
#include <vector>

class Eveniment {
protected:
    std::string nume;
    std::vector<std::string> artistiInvitati;
    std::string locatie;
    std::string data;
    std::string genMuzical;
    static int nrParticipanti;
    static const int durata = 2; // ore
    void afiseazaNume() const;

public:
    Eveniment(std::string nume, std::string locatie, std::string data, std::string genMuzical);

    static void mesajEveniment();

    virtual void detaliiEveniment() const = 0; // met pur virtuale
    virtual void modificaGenMuzical(std::string gen) = 0;

    static void setNrParticipanti(int nr);
    static int getNrParticipanti();
};

#endif
