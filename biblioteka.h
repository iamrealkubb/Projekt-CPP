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
    void zmienZdrowie(int ilosc);
    string pobierzImie() const;
    virtual ~Postac() = default; // DESTRUKTOR

    friend class Druzyna; // DEKLARACJA PRZYJACIELA
    friend class Gra; // DEKLARACJA PRZYJACIELA
};

class Wojownik : public Postac { // DZIEDZICZENIE
    int wytrzymalosc_tarczy;
public:
    Wojownik(string &i, int z, int w); // KONSTRUKTOR
    Wojownik(Wojownik &inny); // KONSTRUKTOR KOPIUJACY
    void uderzMieczem(Postac* cel);
    void przedstaw() override;
    void przyjmijObrazenia(int ilosc) override;
};

class Mag : public Postac { // DZIEDZICZENIE
    int mana;
public:
    Mag(string &i, int z, int m); // KONSTRUKTOR
    Mag(Mag &inny); // KONSTRUKTOR KOPIUJACY
    void rzucZaklecie(Postac* cel);
    void przedstaw() override;
    void przyjmijObrazenia(int ilosc) override;
};

class Lucznik : public Postac { // DZIEDZICZENIE
    int strzaly;
public:
    Lucznik(string &i, int z, int s); // KONSTRUKTOR
    Lucznik(Lucznik &inny); // KONSTRUKTOR KOPIUJACY
    void strzelZLuku(Postac* cel);
    void przedstaw() override;
    void przyjmijObrazenia(int ilosc) override;
};

class Druzyna {
    string nazwa;
    vector <Postac*> czlonkowie; // SZABLON VECTOR
public:
    Druzyna(string &n); // KONSTRUKTOR
    void dodajCzlonka(Postac *czlonek);
    void czyZyje();
    void usunCzlonka(string imie);
    void przedstawDruzyne();
    ~Druzyna(); // DESTRUKTOR

    friend class Gra; // DEKLARACJA PRZYJACIELA
};

class Gra {
public:
    Gra(); // KONSTRUKTOR
    ~Gra(); // DESTRUKTOR
    void start();
};

template <typename T> // WLASNY SZABLON KLASY
class Przedmiot {
protected:
    T wartosc;
public:
    virtual void uzyj(Postac* postac);
};

class MiksturaZdrowia : public Przedmiot<int> {
public:
    MiksturaZdrowia(int wartosc);
};

int losowaLiczba(int dolnaGranica, int gornaGranica);

#endif