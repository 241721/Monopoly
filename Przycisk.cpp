#include "Przycisk.h"

Przycisk::Przycisk(sf::Texture &pT, float x, float y)
{
    wcisniety=0;
    przyciskSprite.setTexture(pT);
    przyciskSprite.setTextureRect(sf::IntRect(0,0,118,118));
    przyciskSprite.setScale(0.6,0.6);
    przyciskSprite.setPosition(x,y);
}

void Przycisk::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(przyciskSprite, states);
}

void Przycisk::wcisnij()
{
    int i=0;
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) i=0;
    if (wcisniety==0 && i==0)
    {
        przyciskSprite.setTextureRect(sf::IntRect(0,120,118,118));
        i++;
        wcisniety=1;
    }
    else if(wcisniety==1 && i==0)
    {
        przyciskSprite.setTextureRect(sf::IntRect(0,0,118,118));
        i++;
        wcisniety=0;

    }

}
