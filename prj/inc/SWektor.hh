#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>




/**
 * @brief Wektor zawierający zmienne, zawiera dodatkowo statyczne pola zliczające ilość ogólnych i aktywnych wektorów
 * 
 * @tparam STyp Typ przechowywanych zmiennych
 * @tparam SWymiar Rozmiar Wektora
 */

template <typename STyp, int SWymiar>
class SWektor {
  
  static int ilosc_ogolnie;
  static int ilosc_aktywnych;
  private:
  STyp  _Wsp[SWymiar];
  public:
  /**
   * @brief Konstruktor bez parametryczny oraz kopiujący
   * 
   */
    SWektor(); 
    SWektor(const SWektor& xxx);
    /**
     * @brief Zwraca ilosc ogolnych lub aktywnych wektorów
     * 
     * @return int 
     */
     static int ilosc_ogolnie_podaj() {return ilosc_ogolnie;}  // funkcja podająca ilość obecnie używanych wektorów

     static int ilosc_aktywnych_podaj() {return ilosc_aktywnych;} // funkcja podająca sumaryczną ilość wektorów
    /**
     * @brief Funkcje dostępowe do pól wektora
     * 
     * @param Ind Numer pola do którego chcemy dostęp
     * @return STyp Zwraca wartośc lub referencje wybranego pola
     */
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }
    /**
     * @brief Pozwala na 
     * 
     * @param Odjemnik 
     * @return SWektor<STyp,SWymiar> 
     */
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    SWektor<STyp,SWymiar> operator * (SWektor<STyp,SWymiar> Mnoznik) const;
    
    ~SWektor() {  ilosc_aktywnych--;}
};
template<typename STyp, int SWymiar>
int SWektor<STyp, SWymiar>:: ilosc_ogolnie;

template<typename STyp, int SWymiar>
int SWektor<STyp, SWymiar> :: ilosc_aktywnych;

template <typename STyp,int SWymiar>
SWektor<STyp,SWymiar>::SWektor()
{
   for (int i=0; i< SWymiar;i++)
  {
    _Wsp[i]=0;
  }
 ++ilosc_ogolnie;
 ++ilosc_aktywnych;
}

template <typename STyp, int SWymiar>
 SWektor<STyp,SWymiar>::SWektor(const SWektor& xxx)
{
  for(int i=0;i<SWymiar;i++)
  {
    _Wsp[i]=xxx[i];
  }
  ++ilosc_aktywnych;
  ++ilosc_ogolnie;
}






template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + Odjemnik[Ind];
  return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (SWektor<STyp,SWymiar> Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for(int i=0;i<SWymiar;++i)
  {
    Wynik[i]=(*this)[i]*Mnoznik[i];
  }

  return Wynik;  
}


template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " " << W[Ind];
  }  
  return StrmWyj;
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &StrmWyj,  SWektor<STyp,SWymiar>& W)
{
    for(int i=0;i<SWymiar;++i)
    {
      StrmWyj>>W[i];
    }


  return StrmWyj;
}

#endif
