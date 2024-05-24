#include <iostream>
#include <algorithm>
#include "biblioteka.h"

using namespace std;

string *imieDoUsuniecia_zmienna = nullptr;

string Postac::pobierzImie() {
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

void Wojownik::uderzMieczem(Postac &cel) {
    cout << "Wojownik " << imie << " uderza mieczem " << cel.pobierzImie() << "!" << endl; // PRZECIAZENIE OPERATORA
}

void Wojownik::przedstaw() {
    cout << "Jestem wojownikiem o imieniu " << imie << ". Mam " << zdrowie << " punktow zdrowia i "
         << wytrzymalosc_tarczy << " wytrzymalosci tarczy." << endl;
}

void Wojownik::przyjmijObrazenia(int ilosc) {
    zdrowie -= ilosc;
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

void Mag::rzucZaklecie(Postac &cel) {
    cout << "Mag " << imie << " rzuca zaklecie na " << cel.pobierzImie() << "!" << endl;
}

void Mag::przedstaw() {
    cout << "Jestem magiem o imieniu " << imie << ". Mam " << zdrowie << " punktow zdrowia i "
         << mana << " many." << endl;
}

void Mag::przyjmijObrazenia(int ilosc) {
    zdrowie -= ilosc;
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

void Lucznik::strzelZLuku(Postac &cel) {
    cout << "Lucznik " << imie << " strzela z luku do " << cel.pobierzImie() << "!" << endl;
}

void Lucznik::przedstaw() {
    cout << "Jestem lucznikiem o imieniu " << imie << ". Mam " << zdrowie << " punktow zdrowia i "
         << strzaly << " strzal." << endl;
}

void Lucznik::przyjmijObrazenia(int ilosc) {
    zdrowie -= ilosc;
    cout << "Lucznik " << imie << " przyjmuje " << ilosc << " obrazen!" << endl;
}


Druzyna::Druzyna(string &n) {
   nazwa = n;
}

void Druzyna::dodajCzlonka(Postac *czlonek) {
    czlonkowie.push_back(czlonek);
}

void Druzyna::usunCzlonka(string &imie) {
    imieDoUsuniecia_zmienna = &imie;
    auto nowy_koniec = remove_if(czlonkowie.begin(), czlonkowie.end(), imieDoUsuniecia); // ITERATOR I ALGORYTM

    if (nowy_koniec != czlonkowie.end()) {
        delete *nowy_koniec;
        czlonkowie.erase(nowy_koniec);
    }
    imieDoUsuniecia_zmienna = nullptr;
}

void Druzyna::przedstawDruzyne() {
    for (auto &czlonek: czlonkowie) { // PETLA ZAKRESOWA FOR
        czlonek->przedstaw();
    }
}

Druzyna::~Druzyna() {
    for (auto czlonek: czlonkowie) {
        delete czlonek;
    }
}


Gra::Gra() {}

void Gra::start() {

}

Gra::~Gra() {}

bool imieDoUsuniecia(Postac *czlonek) {
    return czlonek->pobierzImie() == *imieDoUsuniecia_zmienna;
}