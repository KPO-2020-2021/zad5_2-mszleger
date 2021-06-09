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
  /*
  Wektor3D wektor1;
  Wektor3D wektor2;
  Wektor3D wektor3;
  Wektor3D wektor4;

  wektor2[0] = 10;
  wektor3[1] = 10;
  wektor4[2] = 10;

  PzG::LaczeDoGNUPlota lacze;

  lacze.ZmienTrybRys(PzG::TR_3D);
  lacze.UstawZakresX(-20,20);
  lacze.UstawZakresY(-20,20);
  lacze.UstawZakresZ(-20,20);

  Sciezka sciezka(lacze);
  sciezka.dodajWektor(wektor1, wektor2);
  sciezka.dodajWektor(wektor1, wektor3);
  sciezka.dodajWektor(wektor1, wektor4);
  lacze.Rysuj();

  std::cin >> wektor1;
  */
  
  Scena scena;
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
    case 'a':
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
    case 'p':
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
    case 'd':
      break;
    case 'u':
      break;
    case 'z':
      break;
    case 'm':
      wyswietlMenu();
      break;
    case 'k':
      return 0;
      break;
    
    default:
      std::cout << "Podano niewłaściwą opcję" << std::endl;
      break;
    }
  }


  
}
