#include <iostream>
#include <limits>

#include "Scena.hh"

// Wyświtla opcje obsługiwane przez menu
void wyswietlMenu()
{
  std::cout << std::endl;
  std::cout << "a - wybierz aktywnego drona" << std::endl;
  std::cout << "p - zadaj parametry przelotu" << std::endl;
  std::cout << "d - dodaj element powierzchni" << std::endl;
  std::cout << "u - usun element powierzchni" << std::endl;
  std::cout << "z - zmień położenie elementu powierzchni" << std::endl;
  std::cout << "m - wyświetl menu" << std::endl;
  std::cout << "k - koniec działania programu" << std::endl;
}


/**
 * \brief Metoda wyświetlająca informację o ilości stworzonych i obecnie istniejących obiektów typu Wektor
 *//*
static void PokazRaport()
{
//  std::cout << "Aktualna ilosc obiektow Wektor3D: " << iloscIstniejacych << std::endl;
//  std::cout << "  Laczna ilosc obiektow Wektor3D: " << iloscStworzonych << std::endl;
}*/



int main()
{
  Scena scena;
   
  Wektor3D wektor;
  wektor[1] = 20;
  scena.dodajPrzeszkode(1, wektor, 0, 1, 1, 5);
  wektor[1] = 40;
  scena.dodajPrzeszkode(2, wektor, 0, 1, 1, 5);
  wektor[1] = 60;
  scena.dodajPrzeszkode(3, wektor, 0, 1, 1, 5);
  wektor[0] = 20;
  scena.dodajPrzeszkode(3, wektor, 0, 1, 1, 5);
  
  scena.wyswietl();
  Ruch nowyRuch;
  char wybor;
  int numerAktywnegoDrona = 0;

  wyswietlMenu();

  while(true)
  {
    std::cout << std::endl;
    std::cout << "Polozenie Drona aktywnego (x,y): ";
    scena.gdzieDron(numerAktywnegoDrona);
    std::cout << std::endl << std::endl;
    std::cout << "Twoj wybor, m - menu > ";
    std::cin >> wybor;

    switch (wybor)
    {
    case 'a': /* Wybór aktywnego drona */
      std::cout << std::endl << "Wybor aktywnego drona" << std::endl << std::endl;
      for(int numerDrona = 0; numerDrona < static_cast<int>(scena.drony.size()); ++numerDrona)
      {
        std::cout << numerDrona + 1 << "  - Polozenie (x,y): ";
        scena.gdzieDron(numerDrona);
        if(numerDrona == numerAktywnegoDrona)
          std::cout << " <-- Dron aktywny";
        std::cout << std::endl;
      }
      std::cout << std::endl << "Wprowadz numer aktywnego drona > ";
      std::cin >> numerAktywnegoDrona;
      --numerAktywnegoDrona;
      std::cout << std::endl;
      break;
    case 'p': /* Zadanie przelotu drona */
      std::cout << "Podaj kierunek lotu (kat w stopniach) > ";
      std::cin >> nowyRuch.katObrotu;
      std::cout << "                   Podaj długość lotu > ";
      std::cin >> nowyRuch.odleglosc;
      scena.drony[numerAktywnegoDrona]->dodajPrzelot(nowyRuch.katObrotu, nowyRuch.odleglosc);
      std::cout << "Rysuje zaplanowana sciezke lotu ..." << std::endl;
      std::cout << "Realizacja przelotu ..." << std::endl;
      scena.animuj();
      std::cout << "Dron wyladowal ..." << std::endl;
      break;
    case 'd': /* Dodawanie elementu powierzchni */
      break;
    case 'u': /* Usuwanie elementu powierzchni */
      break;
    case 'z': /* Przesówanie elementu powierzchni */
      break;
    case 'm': /* Wyświetlenie menu */
      wyswietlMenu();
      break;
    case 'k': /* Zakończenie pracy programu */
      return 0;
      break;
    
    default:
      std::cout << "Podano niewłaściwą opcję" << std::endl;
      break;
    }
  }


  
}
