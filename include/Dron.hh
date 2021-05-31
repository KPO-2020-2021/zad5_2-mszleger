#ifndef DRON_HH
#define DRON_HH

#include <vector>
#include <fstream>
#include <cmath>
#include <string.h>

#include "Wektor3D.hh"
#include "MacierzObrotu.hh"
#include "Bryla_Geometryczna.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "lacze_do_gnuplota.hh"

struct Ruch {
  double katObrotu;
  double odleglosc;
};

/**
 * Rzuca wyjątkiem nr. 1 jeśli nie uda się wczytać brył tworzących dron
 */

class Dron {
  private:
    Prostopadloscian korpus;
    Graniastoslup6 rotory[4];
    Wektor3D przesuniecieGlobalne;
    double obrotLokalny;
    std::list <Ruch> zaplanowaneRuchy;
    double predkoscKatowa;
    double predkoscLiniowa;
    int numerIdentyfikacyjny;
  public:
    /**
     * Konstruktor parametryczny inicjujący rysowanie drona w danym łączu do gnuplota
     */
    Dron(PzG::LaczeDoGNUPlota& lacze, int numerDrona);
    Wektor3D zwrocWektorPrzesuniecia();
    void przesun(const Wektor3D &wektor);
    void ustawPrzesuniecie(const Wektor3D &wektor);
    double zwrocKatObrotu();
    void obroc(double kat);
    void ustawObrot(double kat);
    bool dodajPrzelot(double kat, double odleglosc);
    double zwrocPredkoscKatowa();
    bool ustawPredkoscKatowa(double nowaPredkosc);
    double zwrocPredkoscLiniowa();
    bool ustawPredkoscLiniowa(double nowaPredkosc);
    bool wykonajKrok(double fps); // zwraca false gdy już nie ma kroków do wykonania
    bool rysuj(PzG::LaczeDoGNUPlota& lacze);
    void wykonajPrzelotZwiadowczy();
};

#endif