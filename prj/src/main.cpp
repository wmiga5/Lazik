#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Kolory.hh"
#include "Lazik.hh"
#include "Wektor3D.hh"
#include <unistd.h>
#include "Scena.hh"
#include <memory>
#include <list>
#include "ObrysXY.hh"
#include "Probka.hh"
#include "FSR.hh"
using namespace std;




/**
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */
void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);  
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}



void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());

  



}

/**
 * @brief Obsługuję menu ruchu i obrotu łazika
 * 
 * @param scena przekazuje scene
 * @param Lacze przekazuje Lacze żeby funkcje mogły rysować łazik
 */



void obsluga_lazika(Scena scena,PzG::LaczeDoGNUPlota Lacze)
{
  char opcja;
  int odleglosc,obrot;
  while(opcja!='w')
  {
   // system("clear");
    cout<<"Aktywny Łazik: "<< scena.nazwa_aktywnego_obiektu()<<endl;
  
  cout<<"j-jazda na wprost"<<endl;
  cout<<"o-zmiana orientacji"<<endl;
  cout<<"w- powrót do wyboru łazika"<<endl;
  cout<<"p- Wypisanie próbek na scenie"<<endl;
  cout<<(*scena.get_Aktywny_Lazik()).get_Obrys().get_Dolny_Lewy()<<endl;
  cout<<(*scena.get_Aktywny_Lazik()).get_Obrys().get_Gorny_Prawy()<<endl;
  cin>>opcja;
  
  //system("clear");
  switch (opcja)
  {
  case 'j':
      cout<<"Podaj odległość:"<<endl;
      cin>>odleglosc;
     (*scena.get_Aktywny_Lazik()).jedz(odleglosc,Lacze,scena.get_ObiektySceny());
    break;
  case 'o':
      cout<<"Podaj kat obrotu:"<<endl;
      cin>>obrot;
     (*scena.get_Aktywny_Lazik()).obroc(obrot,Lacze,scena.get_ObiektySceny());
    break;
  case 'p':
      scena.Wypisz_Probki_Sceny();

    break;
  
  default:cout<<"Nie ma takiej opcji"<<endl;
    break;
  }
 // system("clear");
  }
}


int main()
{
  Scena scena;
  Wektor3D polozenie;
  


  PzG::LaczeDoGNUPlota  Lacze;
  
  Inicjalizuj_Lacze(Lacze);
  if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) return 1;
  
  
  
  
  scena.Dodaj_LazikFSR("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski);
  (*(scena.get_ObiektySceny().back())).polozenie(20,20,0);
  (*(scena.get_ObiektySceny().back())).skala(20,20,10);
  DodajDoListyRysowania(Lacze,(*(scena.get_ObiektySceny().back())));
  (*scena.get_ObiektySceny().back()).Przelicz_i_Zapisz_Wierzcholki();

  scena.Dodaj_Lazik("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony);
  (*(scena.get_ObiektySceny().back())).polozenie(50,20,0);
  (*(scena.get_ObiektySceny().back())).skala(20,20,10);
  DodajDoListyRysowania(Lacze,(*(scena.get_ObiektySceny().back())));
  (*scena.get_ObiektySceny().back()).Przelicz_i_Zapisz_Wierzcholki();

  scena.Dodaj_Lazik("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony);
  (*(scena.get_ObiektySceny().back())).polozenie(-20,70,0);
  (*(scena.get_ObiektySceny().back())).skala(20,20,10);
  DodajDoListyRysowania(Lacze,(*(scena.get_ObiektySceny().back())));
  (*scena.get_ObiektySceny().back()).Przelicz_i_Zapisz_Wierzcholki();
  

  scena.Dodaj_Probke("bryly_wzorcowe/szescian1.dat","Regolit1",Probka);
  (*(scena.get_ObiektySceny().back())).polozenie(0,0,0);
  (*(scena.get_ObiektySceny().back())).skala(5,5,5);
  DodajDoListyRysowania(Lacze,(*(scena.get_ObiektySceny().back())));
  (*scena.get_ObiektySceny().back()).Przelicz_i_Zapisz_Wierzcholki();

  scena.Dodaj_Probke("bryly_wzorcowe/szescian1.dat","Regolit2",Probka);
  (*(scena.get_ObiektySceny().back())).polozenie(10,-30,0);
  (*(scena.get_ObiektySceny().back())).skala(5,5,5);
  DodajDoListyRysowania(Lacze,(*(scena.get_ObiektySceny().back())));
  (*scena.get_ObiektySceny().back()).Przelicz_i_Zapisz_Wierzcholki();

  scena.Dodaj_Probke("bryly_wzorcowe/szescian1.dat","Regolit3",Probka);
  (*(scena.get_ObiektySceny().back())).polozenie(-40,-20,0);
  (*(scena.get_ObiektySceny().back())).skala(5,5,5);
  DodajDoListyRysowania(Lacze,(*(scena.get_ObiektySceny().back())));
  (*scena.get_ObiektySceny().back()).Przelicz_i_Zapisz_Wierzcholki();

 cout<<(*scena.get_ObiektySceny().back()).get_Obrys().get_Dolny_Lewy()<<endl;
  cout<<(*scena.get_ObiektySceny().back()).get_Obrys().get_Gorny_Prawy()<<endl;
  Lacze.Rysuj();

  cout<<(*scena.get_ObiektySceny().back()).get_Nazwa_Obiektu()<<endl;
  int nr_lazika;
  while (nr_lazika!=4)
  {
    
  
  
  cout<<"Wybierz łazik którym chcesz obsługiwać"<<endl;
  cout<<"Łazik 1 FSR"<<endl;
  cout<<"Łazik 2 Perseverance"<<endl;
  cout<<"Łazik 3 Curiosity"<<endl;
  cout<<"Opcja 4 koniec programu"<<endl;
  cin>>nr_lazika;
  

  switch (nr_lazika)
  {
  case 1:{  
            scena.wybor_obiektu(1);
         
          obsluga_lazika(scena,Lacze);  

     
  break; 
  }

  case 2:{ scena.wybor_obiektu(2);
          obsluga_lazika(scena,Lacze); 
  break; 
  }
  case 3:{ scena.wybor_obiektu(3);
          obsluga_lazika(scena,Lacze); 
  break; 
  }
  default: cout<<"Koniec programu"<<endl;
    break;
  }

  cout<<tan(0.5*M_PI)<<endl;
  //system("clear");

  }




  
 cout<<polozenie.ilosc_aktywnych_podaj()<<endl;
 cout<<polozenie.ilosc_ogolnie_podaj()<<endl;
 

  
  
  
  


  
 

  
  cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
  cin.ignore(100,'\n');
  
  
   


}
