#ifndef FSR_HH
#define FSR_HH

#include "Lazik.hh"

#include "Probka.hh"



class LazikFSR:public Lazik
{

   std::list<std::shared_ptr<Probka_Regolitu>> lista_probek;
public:
    LazikFSR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID):Lazik(sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,KolorID){}
    
   void Zbierz_Probke(std::list<std::shared_ptr<ObiektGeom>> lista);

   void Wypisz_Probki();
   Typ_Kolizji  Czy_Kolizja(std::shared_ptr<ObiektGeom> wsk_Obiekt) override 
    {
           Typ_Kolizji kolizja=Tk_brak_kolizji;
            double X1,Y1,X2,Y2;
            double x1,x2,y2,y1;
        
            //std::cout<<(*wsk_Obiekt).get_ktory()<<std::endl;

            x1= (*wsk_Obiekt).get_Obrys().get_Dolny_Lewy()[0];
            y1=(*wsk_Obiekt).get_Obrys().get_Dolny_Lewy()[1];
            x2= (*wsk_Obiekt).get_Obrys().get_Gorny_Prawy()[0];
            y2=(*wsk_Obiekt).get_Obrys().get_Gorny_Prawy()[1];

            X1=(*this).get_Obrys().get_Dolny_Lewy()[0];
            Y1=(*this).get_Obrys().get_Dolny_Lewy()[1];
            X2=(*this).get_Obrys().get_Gorny_Prawy()[0];
            Y2=(*this).get_Obrys().get_Gorny_Prawy()[1];

          

       

            if((*wsk_Obiekt).get_ktory()<=3)
            {
                  if(((((x1>=X1)&&(x1<=X2))||((x2>=X1)&&(x2<=X2)))&&((((y1>=Y1)&&(y1<=Y2))||((y2>=Y1)&&(y2<=Y2))))))

                    {   
                    // std::cout<<S1<<S2<<std::endl;
                      
                        kolizja=Tk_Kolizja;
                    }
                    else
                    {
                        //std::cout<<S1<<S2<<std::endl;
                        kolizja=Tk_brak_kolizji;
                    }
            }
            else
            {   
                   

                    if(((((x1>=X1)&&(x1<=X2))||((x2>=X1)&&(x2<=X2)))&&((((y1>=Y1)&&(y1<=Y2))||((y2>=Y1)&&(y2<=Y2))))))
                    {   
                    // std::cout<<S1<<S2<<std::endl;
                        std::cout<<"kolizja probki"<<std::endl;
                        kolizja=Tk_Kolizja;
                    }
                    else
                    {
                        std::cout<<"pod kołami"<<std::endl;
                        kolizja=Tk_brak_kolizji;
                    }
            }
           
      

        return kolizja;
    }

};


#endif