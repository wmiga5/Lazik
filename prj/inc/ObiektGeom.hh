#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH
#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"
#include <string>
#include "ObrysXY.hh"
#include "Wektor3D.hh"
#include "cmath"
#include <memory>
#include "TK.hh"


class ObiektGeom {
  protected:
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;
    Wektor3D _Polozenie;
    Wektor3D _Skala;
    
    double kat=0;

    ObrysXY Obrys;
    int ktory;
    
  public:
    int get_ktory()const {return ktory;}
    int& get_ktory(){return ktory;}

    ObrysXY get_Obrys() {return Obrys; }
  /**
   * @brief Metoda zwracająca nazwe obiektu
   * 
   * @return std::string Nazwa obiektu
   */
    std::string get_Nazwa_Obiektu(){return _NazwaObiektu;}
  /**
   * @brief Ustawia skale obiektu
   * 
   * @param x Skala w osi x
   * @param y Skala w osi y
   * @param z Skala w osi z
   */
    void skala(double x, double y, double z); 
  /**
   * @brief Ustawia polozenie obiektu
   * 
   * @param x Polozenie na osi x
   * @param y Polozenie na osi y
   * @param z Polozenie na osi z
   */
    void polozenie(double x, double y, double z); 
  /**
   * @brief Kostrukot Obiektu geometrycznego
   * 
   * @param sNazwaPliku_BrylaWzorcowa Nazwa pliku z wzorcem bryły
   * @param sNazwaObiektu Nazwa obiektu
   * @param KolorID Kolor obiektu
   * @param Skala Skala
   * @param Polozenie Polozenie
   */
    
    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);
    
  /**
   * @brief Funcka dostępowa do Koloru
   * 
   * @return int koloru
   */
    int WezKolorID() const { return _KolorID; }
  /**
   * @brief Zwraca nazwe obiektu
   * 
   * @return const std::string& 
   */
    const std::string & WezNazweObiektu() const { return _NazwaObiektu; }
    /**
     * @brief Zwraca nazwe pliku wzorcowego
     * 
     * @return const std::string& 
     */
  
    const std::string & WezNazwePliku_BrylaRysowana() const
                 { return _NazwaPliku_BrylaRysowana; }
      
     /**
      * @brief Liczy I zapisuje do pliku przeliczone wierzchołki po operacjach
      * 
      * @return true Jak się uda
      * @return false Jak się nie uda
      */

    bool Przelicz_i_Zapisz_Wierzcholki();
    /**
     * @brief Tworzy macierz rotacji
     * 
     * @return Macierz3D Zwraca macierz rotacji dla obiektu 
     */
    Macierz3D Mac_rotacji();

   
    
	virtual Typ_Kolizji  Czy_Kolizja(std::shared_ptr<ObiektGeom> wsk_Obiekt)=0;
 
};


#endif
