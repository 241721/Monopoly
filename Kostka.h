#ifndef KOSTKA_H
#define KOSTKA_H
#include <SFML/Graphics.hpp>

class Kostka: public sf::Drawable
{
    public:
        sf::Sprite sprite;
        Kostka(sf::Texture &pT);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const; //To skopiowaliœmy z internetu
        void ustawKostke(int stan);
};

#endif // KOSTKA_H
