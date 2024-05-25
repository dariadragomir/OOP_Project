#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <numeric>

class Piesa {
private:
    std::string titlu;
    int durata;
    std::string genMuzical;
public:
    Piesa(const std::string& titlu, int durata) : titlu(titlu), durata(durata) {}

    const std::string& getTitlu() const {
        return titlu;
    }

    int getDurata() const {
        return durata;
    }
    const std::string& getGenMuzical() const {
            return genMuzical;
        }

};

// clasa template pentru listele de piese sau artisti
template <typename T>
class Lista {
private:
    std::vector<T> elemente;
    std::string genMuzical;

public:
    Lista(const std::string& genMuzical) : genMuzical(genMuzical) {}
    
    std::string genMuzicalCelMaiPopular() const {
        std::map<std::string, int> count;
        for (const auto& element : elemente) {
            count[element.getGenMuzical()]++;
        }
        std::string celMaiPopular;
        int maxCount = 0;
        for (const auto& pair : count) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                celMaiPopular = pair.first;
            }
        }
        return celMaiPopular;
    }

    void sorteazaAlfabeticDupaGen() {
        std::sort(elemente.begin(), elemente.end(), [](const T& a, const T& b) {
            return a.getGenMuzical() < b.getGenMuzical();
        });
    }

    Lista<T> filtreazaDupaGen(const std::string& gen) const {
        Lista<T> listaFiltrata(gen);
        for (const auto& element : elemente) {
            if (element.getGenMuzical() == gen) {
                listaFiltrata.adaugaElement(element);
            }
        }
        return listaFiltrata;
    }

    std::map<std::string, int> numaraPiesePeGenuri() const {
        std::map<std::string, int> count;
        for (const auto& element : elemente) {
            count[element.getGenMuzical()]++;
        }
        return count;
    }

    void adaugaElement(const T& element) {
            elemente.push_back(element);
        }

    const std::vector<T>& getElemente() const {
            return elemente;
        }
    const std::string& getGenMuzical() const {
            return genMuzical;
        }


};

class Repertoriu {
private:
    Lista<Piesa> piese;
public:
    Repertoriu(const std::string& genMuzical) : piese(genMuzical) {}
    void adaugaPiesa(const Piesa& piesa) {
        piese.adaugaElement(piesa);
    }

    const std::vector<Piesa>& getPiese() const {
        return piese.getElemente();
    }
};

class Artist {
private:
    std::string nume;
    std::string genMuzical;
    Repertoriu repertoriu;
public:
    Artist(const std::string& nume, const std::string& genMuzical) : nume(nume), genMuzical(genMuzical), repertoriu(genMuzical) {}

    void adaugaPiesaInRepertoriu(const Piesa& piesa) {
        repertoriu.adaugaPiesa(piesa);
    }

    const Repertoriu& getRepertoriu() const {
        return repertoriu;
    }

    const std::string& getNume() const {
        return nume;
    }
};

// observer pattern pt notificarea schimbarilor de stare a concertelor
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class ConcertNotifier {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void notify(const std::string& message) {
        for (auto observer : observers) {
            observer->update(message);
        }
    }
};

class ConsoleObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Observer received message: " << message << std::endl;
    }
};

class Concert {
private:
    std::string data;
    std::string locatie;
    std::vector<std::unique_ptr<Artist>> artisti;
    std::map<std::string, double> bilete;
    std::unique_ptr<ConcertNotifier> notifier;
public:
    Concert(const std::string& data, const std::string& locatie) : data(data), locatie(locatie) {
            notifier = std::make_unique<ConcertNotifier>();
        }
    void start() {
            std::string message = "Concertul la locatia " + locatie + " in data de " + data + " a inceput!";
            notifier->notify(message);
        }

    ConcertNotifier* getNotifier() const {
            return notifier.get();
        }
    
    void adaugaArtist(std::unique_ptr<Artist> artist) {
        artisti.push_back(std::move(artist));
    }

    const std::vector<std::unique_ptr<Artist>>& getArtisti() const {
        return artisti;
    }

    void adaugaBilet(const std::string& tip, double pret) {
        bilete[tip] = pret;
    }

    const std::map<std::string, double>& getBilete() const {
        return bilete;
    }

    const std::string& getData() const {
        return data;
    }

    const std::string& getLocatie() const {
        return locatie;
    }
    
};

class Bilet {
private:
    double pret;
    std::string tip;
    std::shared_ptr<Concert> concert;
public:
    Bilet(double pret, const std::string& tip, const std::shared_ptr<Concert>& concert) : pret(pret), tip(tip), concert(concert) {}

    double getPret() const {
        return pret;
    }
};

// singleton pattern pt gestionarea unui singur festival
class Festival {
private:
    static Festival* instance;
    Festival() {}
    std::vector<std::shared_ptr<Concert>> concerte;

public:
    static Festival* getInstance() {
        if (!instance)
            instance = new Festival();
        return instance;
    }

    const std::vector<std::shared_ptr<Concert>>& getConcerte() const {
        return concerte;
    }

    void adaugaConcert(const std::shared_ptr<Concert>& concert) {
        concerte.push_back(concert);
    }
};

Festival* Festival::instance = nullptr;

// strategy pattern pt calculul pretului biletelor
class CalculPret {
public:
    virtual double calculeazaPret(double baza) const = 0;
};

class PretStandard : public CalculPret {
public:
    double calculeazaPret(double baza) const override {
        return baza;
    }
};

class PretVIP : public CalculPret {
public:
    double calculeazaPret(double baza) const override {
        return baza * 2;
    }
};

// functia template pt cautarea unui element in container
template <typename T, typename Container>
bool gasesteElement(const T& element, const Container& container) {
    return std::find(container.begin(), container.end(), element) != container.end();
}

int main() {
    auto artist1 = std::make_unique<Artist>("ACDC", "Rock");
    auto artist2 = std::make_unique<Artist>("Delia", "Pop");

    artist1->adaugaPiesaInRepertoriu(Piesa("Back in Black", 300));
    artist2->adaugaPiesaInRepertoriu(Piesa("Ramai", 250));

    auto concert = std::make_shared<Concert>("23-08-2024", "Brasov");
    concert->adaugaArtist(std::move(artist1));
    concert->adaugaArtist(std::move(artist2));
    concert->adaugaBilet("Standard", 100.0);
    concert->adaugaBilet("VIP", 200.0);

    Festival::getInstance()->adaugaConcert(concert);

    Bilet biletStandard(100.0, "Standard", concert);
    Bilet biletVIP(100.0, "VIP", concert);

    PretStandard pretStandard;
    PretVIP pretVIP;

    std::cout << "Pret bilet standard: " << pretStandard.calculeazaPret(biletStandard.getPret()) << "\n";
    std::cout << "Pret bilet VIP: " << pretVIP.calculeazaPret(biletVIP.getPret()) << "\n";

    for (const auto& concert : Festival::getInstance()->getConcerte()) {
        std::cout << "Concert la locația: " << concert->getLocatie() << " in data de: " << concert->getData() <<":\n";
        for (const auto& artist : concert->getArtisti()) {
            std::cout << "Artist: " << artist->getNume() << "\n";
            for (const auto& piesa : artist->getRepertoriu().getPiese()) {
                std::cout << "  Piesa: " << piesa.getTitlu() << ", Durata: " << piesa.getDurata() << " secunde\n";
            }
        }
    }

    std::vector<int> durate;
    for (const auto& concert : Festival::getInstance()->getConcerte()) {
        for (const auto& artist : concert->getArtisti()) {
            for (const auto& piesa : artist->getRepertoriu().getPiese()) {
                durate.push_back(piesa.getDurata());
            }
        }
    }

    std::sort(durate.begin(), durate.end());
    int sumaDuratelor = std::accumulate(durate.begin(), durate.end(), 0);

    std::cout << "Duratele pieselor: ";
    for (int durata : durate) {
        std::cout << durata << " ";
    }
    std::cout << "\n";

    std::cout << "Suma duratelor pieselor: " << sumaDuratelor << "\n";

    int searchedDuration = 300;
        bool found = gasesteElement(searchedDuration, durate);
        if (found) {
            std::cout << "Durata de " << searchedDuration << " secunde a fost gasita in vectorul de durate.\n";
        } else {
            std::cout << "Durata de " << searchedDuration << " secunde nu a fost gasita in vectorul de durate.\n";
        }
    
    auto observer = std::make_unique<ConsoleObserver>();
    concert->getNotifier()->attach(observer.get());
    concert->start();

    Lista<Piesa> lista1("Rock");
    lista1.adaugaElement(Piesa("Stairway to Heaven", 482));
    lista1.adaugaElement(Piesa("Bohemian Rhapsody", 354));
    lista1.adaugaElement(Piesa("Hotel California", 390));

    Lista<Piesa> lista2("Pop");
    lista2.adaugaElement(Piesa("Shape of You", 233));
    lista2.adaugaElement(Piesa("Billie Jean", 293));
    lista2.adaugaElement(Piesa("Thriller", 357));

    Lista<Piesa> lista3("Hip Hop");
    lista3.adaugaElement(Piesa("Lose Yourself", 326));
    lista3.adaugaElement(Piesa("Sicko Mode", 312));
    lista3.adaugaElement(Piesa("Juicy", 294));

    Lista<Piesa> lista4("Jazz");
    lista4.adaugaElement(Piesa("Take Five", 325));
    lista4.adaugaElement(Piesa("So What", 320));
    lista4.adaugaElement(Piesa("My Favorite Things", 392));

    std::cout << "Genul muzical cel mai popular: " << lista1.genMuzicalCelMaiPopular() << "\n";

     lista1.sorteazaAlfabeticDupaGen();
    std::cout << "Lista sortată alfabetic după gen muzical:\n";
    for (const auto& piesa : lista1.getElemente()) {
        std::cout << piesa.getTitlu() << " (" << piesa.getGenMuzical() << ")\n";
    }

    Lista<Piesa> pieseFiltrate = lista2.filtreazaDupaGen("Pop");
    std::cout << "Piese filtrate după genul muzical Pop:\n";
    for (const auto& piesa : pieseFiltrate.getElemente()) {
        std::cout << piesa.getTitlu() << " (" << piesa.getGenMuzical() << ")\n";
    }

    std::map<std::string, int> numarPiesePeGenuri = lista3.numaraPiesePeGenuri();
    std::cout << "Numărul de piese pe genuri muzicale:\n";
    for (const auto& pair : numarPiesePeGenuri) {
        std::cout << pair.first << ": " << pair.second << " piese\n";
    }

    return 0;
}