#ifndef INTERFEJS_H
#define INTERFEJS_H
#include "Gracz.h"
#include <SFML/Graphics.hpp>

class Interfejs: public sf::Drawable
{
    public:
        sf::Text ECTS1,ECTS2,TURA;
        Gracz * gracz;
        int turaGracza;
        sf::Sprite kolorTury;
        void ustawTure();
        Interfejs(sf::Font & czcionka,Gracz * gra=nullptr);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void sprawdzPrzyciski();
        void aktualizujStanKonta();
    private:
        int licznikPrzycisku;
};

#endif // INTERFEJS_H
