#include <iostream>
#include "ObiektGeom.hh"
#include "Lazik.hh"
#include "Wektor3D.hh"

using namespace std;


Lazik:: Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID)
:ObiektGeom(sNazwaPliku_BrylaWzorcowa,  sNazwaObiektu,  KolorID)
{
    
    Szybkosc=5;
    
 
}
  
void Lazik::jedz(double dystans,PzG::LaczeDoGNUPlota  Lacze,list<shared_ptr<ObiektGeom>> lista)
{   
    Szybkosc=5;
    double czas=dystans/abs(Szybkosc);
    double kawalek=Szybkosc*czas/30;
    //Wektor3D help=polozenie;
    shared_ptr<ObiektGeom> wybor;
    int numer=1;
    int ktory=1;
    Typ_Kolizji typ=Tk_brak_kolizji;
    Wektor3D help;
    help=(*this)._Polozenie;
    
    for(double i=0;abs(i)<=abs(dystans);i=i+kawalek)
    {
        
        (*this).polozenie(_Polozenie[0]+kawalek*cos(kat),_Polozenie[1]+kawalek*(-sin(kat)),0);
       
        (*this).Obrys.set_default();
        (*this).Przelicz_i_Zapisz_Wierzcholki();

        for(std::list<std::shared_ptr<ObiektGeom>>::iterator L=lista.begin();L!=lista.end();++L)
        {
               // cout<<"ile"<<endl;
            if(ktory!=numer)
            {   
                   // cout<<" sprawdzam drugi lub trzeci"<<endl;
                    wybor=*L;
                     typ=Czy_Kolizja(wybor);
                     
            }

            ktory++;
            
            if(typ==Tk_Kolizja){
                (*this).polozenie(_Polozenie[0]-kawalek*cos(kat),_Polozenie[1]-kawalek*(-sin(kat)),0);
                (*this).Obrys.set_default();
                (*this).Przelicz_i_Zapisz_Wierzcholki();
                Lacze.Rysuj();

                break;}
        }

            ktory=1;
            if(typ==Tk_Kolizja){cout<<"Kolizja"<<endl;break;}
        

        Lacze.Rysuj();
        usleep((czas/30)*1000000);
    }
    if(typ==Tk_brak_kolizji)
    {
        (*this).polozenie(help[0]+dystans*cos(kat),help[1]+dystans*(-sin(kat)),0);
        (*this).Przelicz_i_Zapisz_Wierzcholki();
        Lacze.Rysuj();
    }
    
  
}

void Lazik::obroc(double stopnie,PzG::LaczeDoGNUPlota  Lacze,std::list<std::shared_ptr<ObiektGeom>> lista)
{   double rad=stopnie*M_PI/180;
   double czas=rad/Szybkosc;
  double help=kat;
  double kawalek=Szybkosc*czas/30;
    int numer=1;
    int ktory=1;
    Typ_Kolizji typ=Tk_brak_kolizji;
    shared_ptr<ObiektGeom> wybor;
   for(double i=0;i<=abs(rad);i=i+kawalek)
    {
        kat=kat+kawalek;
        (*this).Obrys.set_default();
        (*this).Przelicz_i_Zapisz_Wierzcholki();
            for(std::list<std::shared_ptr<ObiektGeom>>::iterator L=lista.begin();L!=lista.end();++L)
        {
               // cout<<"ile"<<endl;
            if(ktory!=numer)
            {   
                   // cout<<" sprawdzam drugi lub trzeci"<<endl;
                    wybor=*L;
                     typ=Czy_Kolizja(wybor);
                     
            }

            ktory++;
            
            if(typ==Tk_Kolizja){break;}
        }

            ktory=1;
            if(typ==Tk_Kolizja)
            {   
                kat=kat-kawalek;
                (*this).Obrys.set_default();
                (*this).Przelicz_i_Zapisz_Wierzcholki();
                Lacze.Rysuj();
                break;
            }
        Lacze.Rysuj();
        usleep((czas/30)*1000000);
    }
     if(typ==Tk_brak_kolizji)
    {
        kat=help+rad;
        (*this).Przelicz_i_Zapisz_Wierzcholki();
        Lacze.Rysuj();
    }
    

}

