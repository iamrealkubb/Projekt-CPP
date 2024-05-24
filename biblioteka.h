#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

#include <string>
#include <vector>

using namespace std;

class Postac { // KLASA ABSTRAKCYJNA (POLIMORFIZM)
protected:
    string imie;
    int zdrowie;
public:
    virtual void przedstaw() = 0; // CZYSTO WIRTUALNA METODA
    virtual void przyjmijObrazenia(int) = 0; // CZYSTO WIRTUALNA METODA
    string pobierzImie();
    virtual ~Postac() = default; // DESTRUKTOR
};

class Wojownik : public Postac { // DZIEDZICZENIE
    int wytrzymalosc_tarczy;
public:
    Wojownik(string &i, int z, int w); // KONSTRUKTOR
    Wojownik(Wojownik &inny); // KONSTRUKTOR KOPIUJACY
    void uderzMieczem(Postac &cel);
    void przedstaw() override;
    void przyjmijObrazenia(int ilosc) override;
};

class Mag : public Postac { // DZIEDZICZENIE
    int mana;
public:
    Mag(string &i, int z, int m); // KONSTRUKTOR
    Mag(Mag &inny); // KONSTRUKTOR KOPIUJACY
    void rzucZaklecie(Postac &cel);
    void przedstaw() override;
    void przyjmijObrazenia(int ilosc) override;
};

class Lucznik : public Postac { // DZIEDZICZENIE
    int strzaly;
public:
    Lucznik(string &i, int z, int s); // KONSTRUKTOR
    Lucznik(Lucznik &inny); // KONSTRUKTOR KOPIUJACY
    void strzelZLuku(Postac &cel);
    void przedstaw() override;
    void przyjmijObrazenia(int ilosc) override;
};

class Druzyna {
    string nazwa;
    vector <Postac*> czlonkowie; // SZABLON VECTOR
public:
    Druzyna(string &n); // KONSTRUKTOR
    void dodajCzlonka(Postac *czlonek);
    void usunCzlonka(string &imie);
    void przedstawDruzyne();
    ~Druzyna(); // DESTRUKTOR
};

class Gra {
public:
    Gra(); // KONSTRUKTOR
    ~Gra(); // DESTRUKTOR
    void start();
};

bool imieDoUsuniecia(Postac *czlonek);

#endif