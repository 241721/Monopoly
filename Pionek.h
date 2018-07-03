#ifndef PIONEK_H
#define PIONEK_H
#include <SFML/Graphics.hpp>

class Pionek: public sf::Drawable
{

public:
    float pozycja;
    sf::Sprite pionekSprite;

    Pionek(sf::Texture &pT);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const; //To skopiowaliœmy z internetu
};

#endif // PIONEK_H
