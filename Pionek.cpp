#include "Pionek.h"


Pionek::Pionek(sf::Texture &pT)
{
    pionekSprite.setTexture(pT);
    pionekSprite.scale(0.12,0.12);
    pozycja=1;
}
void Pionek::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(pionekSprite, states);
}
