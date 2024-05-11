#ifndef ATELIER_MUZICAL_H
#define ATELIER_MUZICAL_H

#include "eveniment.h"

class AtelierMuzical : public virtual Eveniment {
protected:
    std::string activitate;

public:
    AtelierMuzical(std::string nume, std::string locatie, std::string data, std::string genMuzical, std::string activitate);

    void detaliiEveniment() const override;
    void modificaGenMuzical(std::string gen) override;
};

#endif
