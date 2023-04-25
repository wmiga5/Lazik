#pragma once    
#include "ObiektGeom.hh"
#include <memory>
#include "TK.hh"

class Probka_Regolitu: public ObiektGeom
{

    public:
    Probka_Regolitu(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);
   
   Typ_Kolizji Czy_Kolizja(std::shared_ptr<ObiektGeom> wsk_Obiekt) override
    {
        



    }



}; 