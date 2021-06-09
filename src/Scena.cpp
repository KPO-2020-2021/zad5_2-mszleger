#include "../include/Scena.hh"

Scena::Scena()
{
  this->minx = -100;
  this->maxx =  100;
  this->miny = -100;
  this->maxy =  100;
  this->minz =  -10;
  this->maxz =  120;
  lacze.ZmienTrybRys(PzG::TR_3D);
  lacze.UstawZakresX(minx,maxx);
  lacze.UstawZakresY(miny,maxy);
  lacze.UstawZakresZ(minz,maxz);
  double wspolrzedne0[] = { 10,0,0};
  double wspolrzedne1[] = {-10,0,0};
  Wektor3D przesuniecie0(wspolrzedne0);
  Wektor3D przesuniecie1(wspolrzedne1);
  drony.push_back(std::make_shared<Dron>(lacze, this->drony.size()));
  drony.push_back(std::make_shared<Dron>(lacze, this->drony.size()));
  drony[0]->ustawPrzesuniecie(przesuniecie0);
  drony[1]->ustawPrzesuniecie(przesuniecie1);
  this->rysujPodloze();
}

bool Scena::rysujPodloze()
{
  std::fstream plik;                                                 // Tworzenie uchwytu do pliku
  plik.open("../datasets/tmp_podloze.dat", std::fstream::out);       // Otwieranie pliku
  if(plik.is_open() == false)                                        // Sprawdzanie czy udało się otworzyć plik - zwracanie false jeśli nie
    return false;
  // Rysowanie linii równoległych do osi OX
  for(int x = 0; x <= ((maxx-minx) / 10); ++x)
  {
    plik << minx + (x * 10) << " " << miny << " " << 0 << std::endl;
    plik << minx + (x * 10) << " " << maxy << " " << 0 << std::endl;
    plik << std::endl << std::endl;
  }

  // Rysowanie linii równoległych do osi OY
  for(int y = 0; y <= ((maxy-miny) / 10); ++y)
  {
    plik << minx << " " << miny + (y * 10) << " " << 0 << std::endl;
    plik << maxx << " " << miny + (y * 10) << " " << 0 << std::endl;
    plik << std::endl << std::endl;
  }


  if(plik.fail())                                                    // Sprawdzanie czy wystąpił błąd podczas zapisywania
  {
    plik.close();                                                    // Zamykanie pliku
    return false;                                                    // Zwracanie false
  }
  plik.close();                                                      // Zamykanie pliku
  this->lacze.DodajNazwePliku("../datasets/tmp_podloze.dat");        // Dodawanie nazwy pliku przechowywującego rysunek podłoża do pliku
  return true;                                                       // Zwracanie true
}

void Scena::animuj()
{
  bool czyZankonczonoRysowanie = false;
  while(!czyZankonczonoRysowanie)
  {
    czyZankonczonoRysowanie = true;
    for(std::shared_ptr<Dron>& dron : drony)
    {
      if(dron->wykonajKrok(20) == true)
        czyZankonczonoRysowanie = false;
    }
    this->wyswietl();
    std::this_thread::sleep_for (std::chrono::milliseconds(50)); // Odczekanie 50ms
  }
}

bool Scena::wyswietl()
{
  for(std::shared_ptr<Dron>& dron : this->drony)
    dron->rysuj(lacze);
  lacze.Rysuj();
  return true;
}

void Scena::gdzieDron(int numerDrona)
{
  Wektor3D wektorPrzesuniecia = this->drony[numerDrona]->zwrocWektorPrzesuniecia();
  if((wektorPrzesuniecia[0] < 0.001) && (wektorPrzesuniecia[0] > -0.001))
    wektorPrzesuniecia[0] = 0;
  if((wektorPrzesuniecia[1] < 0.001) && (wektorPrzesuniecia[1] > -0.001))
    wektorPrzesuniecia[1] = 0;
  std::cout << wektorPrzesuniecia[0] << " " << wektorPrzesuniecia[1];
}
