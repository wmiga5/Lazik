#ifndef SMACIERZ_HH
#define SMACIERZ_HH


#include <iostream>
#include "SWektor.hh"


/**
 * @brief Macierz 
 * 
 * @tparam STyp Typy jakie macierz przechowuje
 * @tparam SWymiar Wymiar macierzy
 */
template <typename STyp, int SWymiar>
class SMacierz {
   SWektor<STyp,SWymiar>  _Wsp[SWymiar];
  public:
    /**
     * @brief Funkcje dostępowe do konkretnych pól Macierzy
     * 
     * @param Wiersz Wiersz Macierzy
     * @param Kolumna Kolumna Macierzy
     * @return STyp Zwraca wartośc lub referencje do pola
     */
    STyp  operator () (unsigned int Wiersz, unsigned int Kolumna) const { return (_Wsp[Wiersz])[Kolumna]; }
    STyp &operator () (unsigned int Wiersz, unsigned int Kolumna)       { return (_Wsp[Wiersz])[Kolumna];  }
    /**
     * @brief Funkcje dostępowe do wektorów w macierzy
     * 
     * @param Ind nr wektora 
     * @return SWektor<STyp,SWymiar>  Zwraca wartośc lub referencje do wektora
     */
    SWektor<STyp,SWymiar>  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    SWektor<STyp,SWymiar>  &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }
    /**
     * @brief Mnożenie macierzy przez wektor
     * 
     * @param Arg2 Wektor przez ,który chcemy pomnożyć macierz
     * @return SWektor<STyp,SWymiar> Zwraca Wektor Wynikowy
     */
    SWektor<STyp,SWymiar> operator*(SWektor<STyp,SWymiar> Arg2);
    /**
     * @brief Oblicza wyznacznik dla macierzy
     * 
     * @return STyp Zwraca wyznacznik
     */
    STyp det();
    
    
};



template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator*(SWektor<STyp,SWymiar> Arg2)
{
    SWektor<STyp,SWymiar> wynik;
    SMacierz<STyp,SWymiar> Macierz=*this;
    for(int i=0;i<SWymiar;++i)
    {
        for(int j=0;j<SWymiar;j++)
        {
            wynik[i]=wynik[i]+(Macierz(j,i)*Arg2[j]);
            
        }
    }
    
    return wynik;
}

template <typename STyp, int SWymiar>
STyp SMacierz<STyp,SWymiar>::det()
{
  
    SMacierz<STyp,SWymiar> Macierz; 
    STyp det ;
    det=1;  //Wyznacznik ustawiam jeden żeby tam go później mnożyć

    for(int i=0; i < SWymiar; i++){                     //kopiowanie macierzy do maceirzy tymczasowej
        for(int j = 0; j < SWymiar; j++){
            Macierz(i,j) = (*this)(i,j);      
        }
    }
    
   



    for (int i=0;i<SWymiar;i++)  //Główna pętla, przelatująca po wierszach 
    {
        if (Macierz(i,i)==0) //Sprawdzanie przekątnej czy jest 0
        {
            
            for (int j=i+1;j<SWymiar;j++) //Tutaj zamienimy sobie i z j żeby przelatywać po tej kolumnie co chcemy sprawdzić
            {   
                if (Macierz(j,i) !=0) // Jeśli różne od zera no to zamienimy sobie komórki
                {
                    for(int z=i;z<SWymiar;z++) 
                    {
                        STyp help=Macierz(i,z); 
                        Macierz(i,z)=Macierz(j,z); 
                        Macierz(j,z)= help; 
                    }
                    det=det*(-1); //Tutaj jak zamieniamy kolumny to zmieniamy znak wyznacznika, wynika to z teori
                    break; 
                }
            }
        }
        for (int k=i+1;k<SWymiar;k++) // Petla leci po kolumnie i ją zeruje
        {
            if(Macierz(k,i)==0) 
                {/*nic*/}
            else
            {
                STyp dzielnik= Macierz(k,i)/Macierz(i,i); //Znajdujemy liczbe przez która trzeba trzemnożyć, żeby po odjęciu zerować
                for (int l=i+1;l<SWymiar;l++) 
                {
                    Macierz(k,l)= Macierz(k,l)-(dzielnik*Macierz(i,l)); 
                }
            } 
        
        }
   

    }
     for(int i=0;i<SWymiar;i++) 
    {
        //std::cout<<det<<std::endl;
        det= det*Macierz(i,i);  //Mnożę przekątną i to jest mój wyznacznik
    }
    
    return det;
}
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &StrmWyj,  SMacierz<STyp,SWymiar>& M)
{
    for(int i=0;i<SWymiar;++i)
    {
        for(int j=0;j<SWymiar;++j)
        {
            StrmWyj>>M(i,j);
        }
      
    }


  return StrmWyj;
}
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj,  SMacierz<STyp,SWymiar>& M)
{
   
    for(int i=0;i<SWymiar;++i)
    {
        for(int j=0;j<SWymiar;++j)
        {
           std::cout<<M(i,j)<<"|";
           if(j==SWymiar-1) {
               std::cout<<std::endl;
           }
        }
        
    }


  return StrmWyj;
}




#endif