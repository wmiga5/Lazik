#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"


using namespace std;
void ObiektGeom::skala(double x, double y, double z)
{
  _Skala[0]=x;
  _Skala[1]=y;
  _Skala[2]=z;
}

void ObiektGeom::polozenie(double x, double y, double z)
{
  _Polozenie[0]=x;
  _Polozenie[1]=y;
  _Polozenie[2]=z;
}

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa,
		        const char*  sNazwaObiektu,
		        int          KolorID
       
		       ):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";


}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki ()
{

  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  Wektor3D wektor;
  Wektor2D help;
  int Indeks_Wiersza = 0;
  
  StrmWe >> wektor;
  
  if (StrmWe.fail())return false;

  
  


  do {
   
    
    
    wektor=(*this).Mac_rotacji()*wektor*_Skala+_Polozenie;
    
    help[0]=wektor[0];
    help[1]=wektor[1];
    
    if(help[0]<=Obrys.get_Dolny_Lewy()[0])
    {
       
      Obrys.get_Dolny_Lewy()[0]=help[0];
    }
    if(help[1]<=Obrys.get_Dolny_Lewy()[1])
    {
       
      Obrys.get_Dolny_Lewy()[1]=help[1];
    }



     if(help[0]>=Obrys.get_Gorny_Prawy()[0])
    {
   
      Obrys.get_Gorny_Prawy()[0]=help[0];
    }

     if(help[1]>=Obrys.get_Gorny_Prawy()[1])
    {
   
      Obrys.get_Gorny_Prawy()[1]=help[1];
    }

    StrmWy << wektor[0] << " " << wektor[1] << " " << wektor[2] << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    StrmWe >> wektor;
    
    
  } while (!StrmWe.fail());

  

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}


Macierz3D ObiektGeom::Mac_rotacji()
{
  Macierz3D wynik;
 
  wynik(0,0)=cos(kat);
  wynik(0,1)=-sin(kat);
  wynik(0,2)=0;
  wynik(1,0)=sin(kat);
  wynik(1,1)=cos(kat);
  wynik(1,2)=0;
  wynik(2,0)=0;
  wynik(2,1)=0;
  wynik(2,2)=1;
  
  return wynik;


}

