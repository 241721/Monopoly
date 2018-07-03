#ifndef PRZYCISK_H
#define PRZYCISK_H
#include <SFML/Graphics.hpp>

class Przycisk: public sf::Drawable, sf::Transformable
{
    public:
    sf::Sprite przyciskSprite;
    bool wcisniety;

    Przycisk(sf::Texture &pT, float x, float y);
    void wcisnij();
    void draw(sf::RenderTarget & target, sf::RenderStates states) const; //To skopiowaliœmy z internetu
};

#endif // PRZYCISK_H
