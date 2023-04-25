#include "FSR.hh"

using namespace std;

 void LazikFSR::Zbierz_Probke(std::list<std::shared_ptr<ObiektGeom>> lista)
 {
         for(std::list<std::shared_ptr<ObiektGeom>>::iterator L=lista.begin();L!=lista.end();++L)
        {
            if((**L).get_ktory()>3)
            {
               // (**L).CzyKolizja(make_shared)
            }



        }



 }



void LazikFSR::Wypisz_Probki(){

    }
