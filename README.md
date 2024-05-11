# Sistem de gestiune a festivalului Untold

## Descriere

Proiectul descrie un sistem de gestiune al unui festival de muzică de tipul Untold, folosind programare orientată pe obiecte.

## Funcționalități:

- Adăugarea datelor despre artiști (nume, cel mai popular album, varsta, modul in care cântă, țara de origine), despre piese (durată, nume, gen muzical), despre repertoriu(numărul de piese, piesele), despre bilete(tipul: VIP, Under25 și GeneralAccess și prețul) și despre concert(artiștii invitați, repertoriile pe care le vor cânta, informațiile despre bilete, data și scena pe care se va desfășura concertul respectiv). 
- Cu ajutorul setter-ilor și getter-ilor se pot accesa toate informațiile din fiecare clasa.
- Metoda aplicareReducereUnder25() aplică o reducere de 20% la prețul biletelor Under25.
- Metoda durataTotala() calculează durata unui concert, adunând duratele pieselor care vor fi cântate la concertul respectiv.
- Supraîncărcare operator<<.
- Definirea operatorului de atribuire operator=.
- Definirea constructorului de copiere.
- Definirea destructorului pentru eliberarea memoriei. 
- Testele assert verifică metodele de tip get și set din fiecare clasă, dar si metodele aplicareReducereUnder25() și durataTotala().

## Proiect 2

- Moștenire în diamant: Clasa Eveniment este mostenita virtual de clasele Concert AtelierMuzical, care sunt mostenite de clasa Festival.
- Date membru și metode care să aibă modificatorul de acces protected (accesate din clasele derivate).
- Metode pur virtuale: detaliiEveniment(), modificaGenMuzical(string gen) definite in clasa Eveniment, care sunt suprascrise in clasele mostenitoare.
- Polimorfism la executie (dynamic dispatch) pentru apelarea functiei virtuale detaliiEveniment().
- Upcasting (atribuirea unor obiecte de tipul unor clase moștenite la referințe către clasa de bază): const Eveniment& evenimentConcert = concert; const Eveniment& evenimentAtelier = atelier;
- Exceptii custom MyException, OutOfRangeException, aruncate in functiile verificareParticipanti(), verificaDurata().
- Implementarea blocurilor try...catch care prind exceptiile definite de mine, in verificareParticipanti(), verificaDurata() si trimit mesaje de eroare către consolă.
- Definirea variabilelor membru statice static int nrParticipanti, static const int durata = 2; in clasa de baza Eveniment si a metodelor statice static void mesajEveniment(), setNrParticipanti(int nr), static int getNrParticipanti().
- Separarea declarațiilor și implementărilor din program folosind fișiere header (.h) și sursă (.cpp) distincte pentru fiecare clasa. 

## Referințe
https://github.com/mcmarius/poo/blob/master/tema-1/intro_recap_c_cpp.md

https://github.com/mcmarius/poo/blob/master/tema-1/README.md

https://en.cppreference.com/w/cpp/error/assert

https://en.cppreference.com/w/cpp/language/default_constructor

https://en.cppreference.com/w/cpp/language/operators

https://en.cppreference.com/w/cpp/error/exception
