#ifndef CONCERT_H
#define CONCERT_H

#include "eveniment.h"

class Concert : public virtual Eveniment {
protected:
    std::string scena;
    int nrPiese;

public:
    Concert(std::string nume, std::string locatie, std::string data, std::string genMuzical, std::string scena, int nrPiese);

    void detaliiEveniment() const override;
    void modificaGenMuzical(std::string gen) override;
};

#endif
