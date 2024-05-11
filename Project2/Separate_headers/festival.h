#ifndef FESTIVAL_H
#define FESTIVAL_H

#include "concert.h"
#include "atelier_muzical.h"

class Festival : public Concert, public AtelierMuzical {
public:
    Festival(std::string nume, std::string locatie, std::string data, std::string genMuzical, std::string scena, int nrPiese, std::string activitate);

    void detaliiEveniment() const override;
    void modificaGenMuzical(std::string gen) override;
};

#endif
