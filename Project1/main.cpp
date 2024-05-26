#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Piesa {
private:
    float durata;
    string nume_piesa;
    string gen_muzical;

public:
    Piesa() {} // Constructor implicit

    Piesa(float durata, string nume_piesa, string gen_muzical) : durata(durata), nume_piesa(nume_piesa), gen_muzical(gen_muzical) {}

    float getDurata() const { return durata; }
    string getNumePiesa() const { return nume_piesa; }
    string getGenMuzical() const { return gen_muzical; }

    void setDurata(float durata) { this->durata = durata; }
    void setNumePiesa(string nume_piesa) { this->nume_piesa = nume_piesa; }
    void setGenMuzical(string gen_muzical) { this->gen_muzical = gen_muzical; }

    friend ostream& operator<<(ostream& out, const Piesa& piesa) {
        out << "Nume Piesa: " << piesa.nume_piesa << ", Durata: " << piesa.durata << ", Gen Muzical: " << piesa.gen_muzical;
        return out;
    }
};


class Repertoriu {
private:
    int nrsongs;
    vector<Piesa> piese;

public:
    Repertoriu() {} // Constructor implicit

    Repertoriu(int nrsongs, const vector<Piesa>& piese) : nrsongs(nrsongs), piese(piese) {}

    int getNrSongs() const { return nrsongs; }

    void adaugaPiesa(const Piesa& piesa) {
        piese.push_back(piesa);
        nrsongs++;
    }

    float durataTotala() const {
        float durata_totala = 0;
        for (const auto& piesa : piese)
            durata_totala += piesa.getDurata();
        return durata_totala;
    }
};


class Artist {
private:
    string nume;
    string cel_mai_popular_album;
    int varsta;
    bool live;
    string tara_origine;

public:
    Artist() {} // Constructor implicit

    Artist(string nume, string cel_mai_popular_album, int varsta, bool live, string tara_origine) : nume(nume), cel_mai_popular_album(cel_mai_popular_album), varsta(varsta), live(live), tara_origine(tara_origine) {}

    string getNume() const { return nume; }
    string getCelMaiPopularAlbum() const { return cel_mai_popular_album; }
    int getVarsta() const { return varsta; }
    bool isLive() const { return live; }
    string getTaraOrigine() const { return tara_origine; }

    void setNume(string nume) { this->nume = nume; }
    void setCelMaiPopularAlbum(string cel_mai_popular_album) { this->cel_mai_popular_album = cel_mai_popular_album; }
    void setVarsta(int varsta) { this->varsta = varsta; }
    void setLive(bool live) { this->live = live; }
    void setTaraOrigine(string tara_origine) { this->tara_origine = tara_origine; }

    friend ostream& operator<<(ostream& out, const Artist& artist) {
        out << "Nume Artist: " << artist.nume << ", Varsta: " << artist.varsta << ", Tara de origine: " << artist.tara_origine;
        return out;
    }
};

class Bilet {
private:
    string tip_bilet;
    float pret;

public:
    Bilet() {} // Constructor implicit

    Bilet(string tip_bilet, float pret)
        : tip_bilet(tip_bilet), pret(pret) {}


    string getTipBilet() const { return tip_bilet; }
    float getPret() const { return pret; }

    void setTipBilet(string tip_bilet) { this->tip_bilet = tip_bilet; }
    void setPret(float pret) { this->pret = pret; }

    void aplicareReducereUnder25() {
            if (tip_bilet == "Under25")
                pret *= 0.8; // Reducere de 20%
    }
    
    friend ostream& operator<<(ostream& out, const Bilet& bilet) {
        out << "Tip Bilet: " << bilet.tip_bilet << ", Pret: " << bilet.pret;
        return out;
    }
};

class Concert {
private:
    vector<Artist> artisti;
    vector<string> bilete;
    vector<Repertoriu> repertoriu;
    string data;
    string scena;

public:
    Concert() {} // Constructor implicit

    Concert(const vector<Artist>& artisti, const vector<string>& bilete, const vector<Repertoriu>& repertoriu, string data, string scena) : artisti(artisti), bilete(bilete), repertoriu(repertoriu), data(data), scena(scena) {}

    // Constructor de copiere
    Concert(const Concert& other) {
        artisti = other.artisti;
        bilete = other.bilete;
        repertoriu = other.repertoriu;
        data = other.data;
        scena = other.scena;
    }

    // Operator de atribuire
    Concert& operator=(const Concert& other) {
        if (this != &other) {
            artisti = other.artisti;
            bilete = other.bilete;
            repertoriu = other.repertoriu;
            data = other.data;
            scena = other.scena;
        }
        return *this;
    }

    vector<Artist> getArtisti() const { return artisti; }
    vector<string> getBilete() const { return bilete; }
    vector<Repertoriu> getRepertoriu() const { return repertoriu; }
    string getData() const { return data; }
    string getScena() const { return scena; }
    void setArtisti(const vector<Artist>& new_artisti) { artisti = new_artisti; }

    void setBilete(const vector<string>& new_bilete) { bilete = new_bilete; }
    void setRepertoriu(const vector<Repertoriu>& new_repertoriu) { repertoriu = new_repertoriu; }
    void setData(const string& new_data) { data = new_data; }
    void setScena(const string& new_scena) { scena = new_scena; }

    float durataTotala() const {
        float durata_totala = 0;
        for (const auto& repertoriu_item : repertoriu)
            durata_totala += repertoriu_item.durataTotala();
        return durata_totala;
    }
    
    int numarTotalBileteVandute() const {
            return bilete.size();
    }

    friend ostream& operator<<(ostream& out, const Concert& concert) {
        out << "Concertul are loc pe data de " << concert.data << " pe scena " << concert.scena << endl;
        out << "Artisti participanti:\n";
        for (const auto& artist : concert.artisti)
            out << "- " << artist << '\n';
        out << "Durata totala a concertului: " << concert.durataTotala() << " minute\n";
        return out;
    }
    
    // Destructorul
    ~Concert() {
        artisti.clear();
        bilete.clear();
        repertoriu.clear();
    }
};

void citestePiesa(Piesa& piesa) {
    float durata;
    string nume_piesa, gen_muzical;
    cout << "Introduceti numele piesei: ";
    getline(cin, nume_piesa);
    cout << "Introduceti durata piesei (minute): ";
    cin >> durata;
    cin.ignore();
    cout << "Introduceti genul muzical al piesei: ";
    getline(cin, gen_muzical);
    piesa.setNumePiesa(nume_piesa);
    piesa.setDurata(durata);
    piesa.setGenMuzical(gen_muzical);
}

void citesteArtist(Artist& artist) {
    string nume, cel_mai_popular_album, tara_origine;
    int varsta;
    bool live;
    cout << "Introduceti numele artistului: ";
    getline(cin, nume);
    cout << "Introduceti varsta artistului: ";
    cin >> varsta;
    cin.ignore();
    cout << "Cel mai popular album: ";
    getline(cin, cel_mai_popular_album);
    cout << "Este live? (1 - Da, 0 - Nu): ";
    cin >> live;
    cin.ignore();
    cout << "Tara de origine: ";
    getline(cin, tara_origine);
    artist.setNume(nume);
    artist.setVarsta(varsta);
    artist.setCelMaiPopularAlbum(cel_mai_popular_album);
    artist.setLive(live);
    artist.setTaraOrigine(tara_origine);
}

void citesteBilet(Bilet& bilet) {
    string tip_bilet;
    float pret;
    cout << "Introduceti tipul biletului (VIP/AccesGeneral/Under25): ";
    getline(cin, tip_bilet);
    cout << "Introduceti pretul biletului: ";
    cin >> pret;
    bilet.setTipBilet(tip_bilet);
    bilet.setPret(pret);
}
void citesteConcert(Concert& concert) {
    int numar_artisti;
    cout << "Introduceti numarul de artisti participanti la concert: ";
    cin >> numar_artisti;
    cin.ignore();
    vector<Artist> artisti;
    for (int i = 0; i < numar_artisti; ++i) {
        Artist artist;
        cout << "Artistul #" << i + 1 << ":\n";
        citesteArtist(artist);
        artisti.push_back(artist);
    }
    concert.setArtisti(artisti);
    
    vector<Repertoriu> repertorii;
    Repertoriu repertoriu_gol;
    repertorii.push_back(repertoriu_gol);

    int numar_repertorii;
    cout << "Introduceti numarul de repertorii pentru concert: ";
    cin >> numar_repertorii;
    cin.ignore();
    for (int i = 0; i < numar_repertorii; ++i) {
        vector<Piesa> piese;
        cout << "Repertoriul #" << i + 1 << ":\n";
        int numar_piese;
        cout << "Introduceti numarul de piese din acest repertoriu: ";
        cin >> numar_piese;
        cin.ignore();
        for (int j = 0; j < numar_piese; ++j) {
            Piesa piesa;
            cout << "Piesa #" << j + 1 << ":\n";
            citestePiesa(piesa);
            piese.push_back(piesa);
        }
        Repertoriu repertoriu(numar_piese, piese);
        repertorii.push_back(repertoriu);
    }
    concert.setRepertoriu(repertorii);

    int numar_bilete;
    cout << "Introduceti numarul de bilete disponibile: ";
    cin >> numar_bilete;
    cin.ignore();
    vector<string> bilete;
    for (int i = 0; i < numar_bilete; ++i) {
        Bilet bilet;
        cout << "Biletul #" << i + 1 << ":\n";
        citesteBilet(bilet);
        bilete.push_back(bilet.getTipBilet());
    }
    concert.setBilete(bilete);

    string data, scena;
    cout << "Introduceti data concertului (dd/mm/yyyy): ";
    getline(cin, data);
    concert.setData(data);
    cout << "Introduceti numele scenei: ";
    getline(cin, scena);
    concert.setScena(scena);
}

int main() {
    Piesa piesa;
    citestePiesa(piesa);
    Artist artist;
    citesteArtist(artist);
    Bilet bilet;
    citesteBilet(bilet);
    Concert concert;
    citesteConcert(concert);
    
    vector<Piesa> piese;
    piese.push_back(piesa);
    Repertoriu repertoriu(1, piese);

    vector<Artist> artisti;
    artisti.push_back(artist);

    vector<string> bilete;
    bilete.push_back(bilet.getTipBilet());

    vector<Repertoriu> repertoriile;
    repertoriile.push_back(repertoriu);

    Bilet bilet1("Under25", 400.0);
    cout << "Pret initial: " << bilet1.getPret() << endl;
    bilet1.aplicareReducereUnder25();
    cout << "Pret dupa aplicarea reducerii pentru Under25: " << bilet1.getPret() << endl;

    Bilet bilet2("VIP", 700.0);
    cout << "Pret initial: " << bilet2.getPret() << endl;
    bilet2.aplicareReducereUnder25();
    cout << "Pret dupa aplicarea reducerii pentru VIP: " << bilet2.getPret() << endl;

    
    // Teste assert
    Piesa piesatest(3.5, "Nume Piesa Test", "Gen Muzical Test");
    assert(piesatest.getDurata() == 3.5);
    assert(piesatest.getNumePiesa() == "Nume Piesa Test");
    assert(piesatest.getGenMuzical() == "Gen Muzical Test");
    cout << "Teste trecute cu succes!\n";

    Artist artisttest("Nume Artist Test", "Album Test", 30, true, "Tara Test");
    assert(artisttest.getNume() == "Nume Artist Test");
    assert(artisttest.getCelMaiPopularAlbum() == "Album Test");
    assert(artisttest.getVarsta() == 30);
    assert(artisttest.isLive() == true);
    assert(artisttest.getTaraOrigine() == "Tara Test");
    cout << "Teste trecute cu succes!\n";


    Bilet bilettest("VIP", 600.0);
    assert(bilettest.getTipBilet() == "VIP");
    cout << "Test trecut cu succes!\n";
    assert(bilettest.getPret() == 600.0);
    cout << "Test trecut cu succes!\n";


    Piesa piesa1(3.0, "Piesa1", "Rock");
    Piesa piesa2(4.0, "Piesa2", "Pop");
    vector<Piesa> piesetest;
    piese.push_back(piesa1);
    piese.push_back(piesa2);
    Repertoriu repertoriutest(2, piesetest);

    vector<Piesa> pieseConcert;
    pieseConcert.push_back(piesa1);
    pieseConcert.push_back(piesa2);
    
    vector<Artist> artistiConcert;
    artistiConcert.push_back(artist);
    
    vector<string> bileteConcert;
    bileteConcert.push_back("VIP");
    
    vector<Repertoriu> repertoriiConcert;
    Repertoriu repertoriuConcert(pieseConcert.size(), pieseConcert);
    repertoriiConcert.push_back(repertoriuConcert);
    
    Concert concertTest(artistiConcert, bileteConcert, repertoriiConcert, "23/08/2025", "Scena Test");
    assert(concertTest.durataTotala() == 7.0);
    cout << "Test trecut cu succes!\n";

    Bilet bilet3("Under25", 300.0);
    bilet3.aplicareReducereUnder25();
    float pret_redus_asteptat = 300.0 * 0.8;
    assert(bilet3.getPret() == pret_redus_asteptat);
    cout << "Test trecut cu succes!";

    return 0;
}
