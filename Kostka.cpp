#include "Kostka.h"

Kostka::Kostka(sf::Texture &pT)
{
    sprite.setTexture(pT);
    sprite.setTextureRect(sf::IntRect(317,317,58,58));
}
void Kostka::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}
void Kostka::ustawKostke(int stan)
{
    switch (stan)
    {
    case 1:
        sprite.setTextureRect(sf::IntRect(2,317,58,58));
        break;
    case 2:
        sprite.setTextureRect(sf::IntRect(65,317,58,58));
        break;
    case 3:
        sprite.setTextureRect(sf::IntRect(128,317,58,58));
        break;
    case 4:
        sprite.setTextureRect(sf::IntRect(191,317,58,58));
        break;
    case 5:
        sprite.setTextureRect(sf::IntRect(254,317,58,58));
        break;
    case 6:
        sprite.setTextureRect(sf::IntRect(317,317,58,58));
        break;

    }
}
