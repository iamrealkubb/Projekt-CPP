#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <synchapi.h>
#include "biblioteka.h"

using namespace std;

void Postac::zmienZdrowie(int ilosc) {
    zdrowie += ilosc;
}

string Postac::pobierzImie() const {
    return imie;
}

Wojownik::Wojownik(string &i, int z, int w) {
    imie = i;
    zdrowie = z;
    wytrzymalosc_tarczy = w;
}

Wojownik::Wojownik(Wojownik &inny) {
    imie = inny.imie;
    zdrowie = inny.zdrowie;
    wytrzymalosc_tarczy = inny.wytrzymalosc_tarczy;
}

void Wojownik::uderzMieczem(Postac* cel) {
    cout << "Wojownik " << imie << " uderza mieczem " << cel->pobierzImie() << "!" << endl; // PRZECIAZENIE OPERATORA
    wytrzymalosc_tarczy-=10;
}

void Wojownik::przedstaw() {
    cout << "Jestem wojownikiem o imieniu " << imie << ". Mam " << zdrowie << " punktow zdrowia i "
         << wytrzymalosc_tarczy << " wytrzymalosci tarczy." << endl;
}

void Wojownik::przyjmijObrazenia(int ilosc) {
    zdrowie -= ilosc;
    if (zdrowie <= 0) { // WYJATEK
        throw 0;
    }
    cout << "Wojownik " << imie << " przyjmuje " << ilosc << " obrazen!" << endl;
}


Mag::Mag(string &i, int z, int m) {
    imie = i;
    zdrowie = z;
    mana = m;
}

Mag::Mag(Mag &inny) {
    imie = inny.imie;
    zdrowie = inny.zdrowie;
    mana = inny.mana;
}

void Mag::rzucZaklecie(Postac* cel) {
    cout << "Mag " << imie << " rzuca zaklecie na " << cel->pobierzImie() << "!" << endl;
    mana-=20;
}

void Mag::przedstaw() {
    cout << "Jestem magiem o imieniu " << imie << ". Mam " << zdrowie << " punktow zdrowia i "
         << mana << " many." << endl;
}

void Mag::przyjmijObrazenia(int ilosc) {
    zdrowie -= ilosc;
    if (zdrowie <= 0) { // WYJATEK
        throw 0;
    }
    cout << "Mag " << imie << " przyjmuje " << ilosc << " obrazen!" << endl;
}


Lucznik::Lucznik(string &i, int z, int s) {
    imie = i;
    zdrowie = z;
    strzaly = s;
}

Lucznik::Lucznik(Lucznik &inny) {
    imie = inny.imie;
    zdrowie = inny.zdrowie;
    strzaly = inny.strzaly;
}

void Lucznik::strzelZLuku(Postac* cel) {
    cout << "Lucznik " << imie << " strzela z luku do " << cel->pobierzImie() << "!" << endl;
    strzaly--;
}

void Lucznik::przedstaw() {
    cout << "Jestem lucznikiem o imieniu " << imie << ". Mam " << zdrowie << " punktow zdrowia i "
         << strzaly << " strzal." << endl;
}

void Lucznik::przyjmijObrazenia(int ilosc) {
    zdrowie -= ilosc;
    if (zdrowie <= 0) { // WYJATEK
        throw 0;
    }
    cout << "Lucznik " << imie << " przyjmuje " << ilosc << " obrazen!" << endl;
}


Druzyna::Druzyna(string &n) {
   nazwa = n;
}

void Druzyna::dodajCzlonka(Postac *czlonek) {
    czlonkowie.push_back(czlonek);
}

void Druzyna::czyZyje() {
    for (auto &czlonek: czlonkowie) { // PETLA ZAKRESOWA FOR
        if (czlonek->zdrowie <= 0) {
            cout << "Postac " << czlonek->pobierzImie() << " nie zyje!" << endl;
            usunCzlonka(czlonek->pobierzImie());
        }
    }
}

void Druzyna::usunCzlonka(string imie) {
    auto iterator = remove_if( // ALGORYTM I ITERATOR
            czlonkowie.begin(),
            czlonkowie.end(),
            [imie](Postac* czlonek) {
                return czlonek->pobierzImie() == imie;
            }
    );

    czlonkowie.erase(iterator, czlonkowie.end());
}

void Druzyna::przedstawDruzyne() {
    for (auto &czlonek: czlonkowie) { // PETLA ZAKRESOWA FOR
        if (czlonek->zdrowie > 0) {
        czlonek->przedstaw();
        }
    }
}

Druzyna::~Druzyna() {
    for (auto czlonek: czlonkowie) {
        delete czlonek;
    }
}


Gra::Gra() {}

void Gra::start() {
    string imie;
    string nazwa;

    // Tworzenie druzyny
    cout << "--------------TWORZENIE DRUZYNY--------------" << endl;
    cout << "Podaj nazwe druzyny: ";
    getline(cin, nazwa);
    Druzyna druzyna(nazwa);

    cout << "Podaj imie wojownika: ";
    getline(cin, imie);
    Wojownik* wojownik1 = new Wojownik(imie, 100, 50);

    cout << "Podaj imie maga: ";
    getline(cin, imie);
    Mag* mag1 = new Mag(imie, 80, 100);

    cout << "Podaj imie lucznika: ";
    getline(cin, imie);
    Lucznik* lucznik1 = new Lucznik(imie, 90, 20);

    druzyna.dodajCzlonka(wojownik1);
    druzyna.dodajCzlonka(mag1);
    druzyna.dodajCzlonka(lucznik1);

    cout << "--------------DRUZYNA--------------" << endl;

    druzyna.przedstawDruzyne();

    // Tworzenie druzyny przeciwnej
    string nazwa2 = "Czarne Pantery (druzyna przeciwna)";
    string imie2 = "Wojownik (przeciwnik)";
    string imie3 = "Mag (przeciwnik)";
    string imie4 = "Lucznik (przeciwnik)";

    Druzyna druzyna2(nazwa2);
    Wojownik* wojownik2 = new Wojownik(imie2, 100, 50);
    Mag* mag2 = new Mag(imie3, 80, 100);
    Lucznik* lucznik2 = new Lucznik(imie4, 90, 20);

    druzyna2.dodajCzlonka(wojownik2);
    druzyna2.dodajCzlonka(mag2);
    druzyna2.dodajCzlonka(lucznik2);

    // Gra
    cout << "--------------WALKA--------------" << endl;
    cout << druzyna.nazwa << " vs " << druzyna2.nazwa << endl;
    cout << "Nacisnij dowolny klawisz, aby rozpoczac walke..." << endl;
    getchar();

    MiksturaZdrowia* miksturaZdrowia = new MiksturaZdrowia(20);

    while (true) {
        try { // WYJATEK
            wojownik1->uderzMieczem(wojownik2);
            wojownik2->przyjmijObrazenia(losowaLiczba(40, 50));
        } catch (int) {
            break;
        }
        cout << endl;
        Sleep(2000);
        try { // WYJATEK
            wojownik2->uderzMieczem(wojownik1);
            wojownik1->przyjmijObrazenia(losowaLiczba(40, 50));
        } catch (int) {
            break;
        }
        cout << endl;
        Sleep(2000);
        try { // WYJATEK
        mag1->rzucZaklecie(mag2);
        mag2->przyjmijObrazenia(losowaLiczba(30, 45));
        } catch (int) {
            break;
        }
        cout << endl;
        Sleep(2000);
        try { // WYJATEK
        mag2->rzucZaklecie(mag1);
        mag1->przyjmijObrazenia(losowaLiczba(30, 45));
        } catch (int) {
            break;
        }
        miksturaZdrowia->uzyj(mag1);
        cout << endl;
        Sleep(2000);
        try { // WYJATEK
        lucznik1->strzelZLuku(lucznik2);
        lucznik2->przyjmijObrazenia(losowaLiczba(20, 30));
        } catch (int) {
            break;
        }
        cout << endl;
        Sleep(2000);
        try { // WYJATEK
        lucznik2->strzelZLuku(lucznik1);
        lucznik1->przyjmijObrazenia(losowaLiczba(20, 30));
        } catch (int) {
            break;
        }
        cout << endl;
        Sleep(2000);
    }
    cout << endl;
    druzyna.czyZyje();
    druzyna2.czyZyje();
    Sleep(1000);
    cout << endl;
    cout << "--------------PO WALCE--------------" << endl;
    if (wojownik2->zdrowie <= 0 || mag2->zdrowie <= 0 || lucznik2->zdrowie <= 0) {
        cout << "Druzyna przeciwna zostala zmuszona do odwrotu!" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Zywi z twojej druzyny: " << endl;
        druzyna.przedstawDruzyne();
    } else {
        cout << "Twoja druzyna zostala zmuszona do odwrotu!" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Zywi z twojej druzyny: " << endl;
        druzyna.przedstawDruzyne();
    }
    delete miksturaZdrowia;
}

Gra::~Gra() {}

template <typename T>
void Przedmiot<T>::uzyj(Postac *postac) {
    postac->zmienZdrowie(wartosc);
    cout << postac->pobierzImie() << " odzyskuje " << wartosc << " punktow zdrowia." << endl;
}

MiksturaZdrowia::MiksturaZdrowia(int w) {
    wartosc = w;
}

int losowaLiczba(int dolnaGranica, int gornaGranica) {
    srand(time(NULL));
    return dolnaGranica + rand() % (gornaGranica - dolnaGranica + 1);
}