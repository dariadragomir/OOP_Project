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

## Referințe
https://github.com/mcmarius/poo/blob/master/tema-1/intro_recap_c_cpp.md
https://github.com/mcmarius/poo/blob/master/tema-1/README.md
https://en.cppreference.com/w/cpp/error/assert
https://en.cppreference.com/w/cpp/language/default_constructor
https://en.cppreference.com/w/cpp/language/operators
