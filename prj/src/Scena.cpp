#include <iostream>
#include "Scena.hh"

using namespace std;

void Scena::Dodaj_Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID)
{
    ObiektySceny.push_back(make_shared<Lazik>(sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,KolorID));
    (ObiektySceny.back())->get_ktory()=ile_lazik+1;
    ++ile_lazik;
} 
void Scena::Dodaj_LazikFSR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID)
{
    ObiektySceny.push_back(make_shared<LazikFSR>(sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,KolorID));
    (ObiektySceny.back())->get_ktory()=ile_lazik+1;
    ++ile_lazik;
} 


void Scena::Dodaj_Probke(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID)
{
    ObiektySceny.push_back(make_shared<Probka_Regolitu>(sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,KolorID));
    (ObiektySceny.back())->get_ktory()=ile_lazik+1;
    ++ile_lazik;
}


 void Scena::wybor_obiektu(int x)
 {
    shared_ptr<ObiektGeom> wybor;
  int numer=1;
  for(std::list<std::shared_ptr<ObiektGeom>>::iterator L=ObiektySceny.begin();L!=ObiektySceny.end();++L)
  {
    if (numer == x)(wybor=*L);
    //cout<<"ile tutaj"<<endl;
    numer++;
  }
  Aktywny_Lazik=dynamic_pointer_cast<Lazik>(wybor);
    
  

    
 }

  
 std::string Scena::nazwa_aktywnego_obiektu()
 {  
     return (*Aktywny_Lazik).get_Nazwa_Obiektu();
 }

void Scena::Wypisz_Probki_Sceny()
{
  int numer;
  
  for(std::list<std::shared_ptr<ObiektGeom>>::iterator L=ObiektySceny.begin();L!=ObiektySceny.end();++L)
  {
    

    if ((**L).get_ktory() > 3){
      cout<<(**L).get_Nazwa_Obiektu()<<endl;
    }
    
    
  }

 
}