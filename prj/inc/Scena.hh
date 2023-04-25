#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "Lazik.hh"
#include "Probka.hh"
#include <memory>
#include <list>
#include "FSR.hh"
/**
 * @brief Klasa zawierająca Liste pointerów na Laziki oraz pointer aktywnego Lazika
 * 
 */
class Scena
{
    
    std::list< std::shared_ptr<ObiektGeom>> ObiektySceny;
    std::shared_ptr<Lazik> Aktywny_Lazik;

    int ile_lazik;
public:
    Scena(){ile_lazik=0;}
/**
 * @brief Tworzy pointer na nowy Obiekt i dodaje go do listy
 * 
 * @param sNazwaPliku_BrylaWzorcowa Zmienne do konstrukotra obiektu geometrycznego
 * @param sNazwaObiektu Zmienne do konstrukotra obiektu geometrycznego
 * @param KolorID Zmienne do konstrukotra obiektu geometrycznego
 * @param Skala Zmienne do konstrukotra obiektu geometrycznego
 * @param Polozenie Zmienne do konstrukotra obiektu geometrycznego
 */
    void Wypisz_Probki_Sceny();

    void Dodaj_Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);

    void Dodaj_LazikFSR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);

    //void Dodaj_LazikFSR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);

    void Dodaj_Probke(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID);
    /**
     * @brief Funkcja dostepowa do pola Aktywny_Lazik
     * 
     * @return std::shared_ptr<Lazik> Zwraca wskaznik na Lazik
     */
    std::shared_ptr<Lazik> get_Aktywny_Lazik(){return Aktywny_Lazik;};
    
    /**
     * @brief Funckja odstepowa do listy pointerów
     * @return std::list< std::shared_ptr<Lazik>> Zwraca Liste pointerów
     */
    std::list< std::shared_ptr<ObiektGeom>> get_ObiektySceny(){return ObiektySceny;};
    /**
     * @brief Wybiera obiekt obiektu na podstawie parametu x i wstawia do Aktywny Lazik wybrany obiekt
     * 
     * @param x nr obiektu z listy ktory chcemy wybrać
     */
    void wybor_obiektu(int x);

    
    /**
     * @brief Dostęp do nazwy aktywnego obiektu
     * 
     * @return std::string Zwraca nazwe Aktywnego Obiektu
     */
    std::string nazwa_aktywnego_obiektu();
};

#endif