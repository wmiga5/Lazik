#ifndef OBRYS__HH
#define OBRYS__HH
#include "Wektor3D.hh"

#include <cmath>

class ObrysXY
{   
    Wektor2D Dolny_Lewy;
    Wektor2D Gorny_Prawy;

    public:

    ObrysXY(){Dolny_Lewy[0]=100;Dolny_Lewy[1]=110;Gorny_Prawy[0]=-100;Gorny_Prawy[1]=-100;}
    Wektor2D get_Dolny_Lewy() const{return Dolny_Lewy;}

    Wektor2D get_Gorny_Prawy() const {return Gorny_Prawy;}

    Wektor2D& get_Dolny_Lewy() {return Dolny_Lewy;}
    
    Wektor2D& get_Gorny_Prawy() {return Gorny_Prawy;}

    void set_default(){Dolny_Lewy[0]=100;Dolny_Lewy[1]=110;Gorny_Prawy[0]=-100;Gorny_Prawy[1]=-100;}
};






#endif