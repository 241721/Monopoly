#include "Interfejs.h"

void Interfejs::ustawTure()
{
    kolorTury=(gracz+turaGracza)->pionek->pionekSprite;
    kolorTury.setPosition(1770,70);
    kolorTury.scale(1.6,1.6);
    if(turaGracza==0) turaGracza++;
    else turaGracza=0;
}
Interfejs::Interfejs(sf::Font & czcionka, Gracz * gra ): turaGracza(0),licznikPrzycisku(0)
{
    gracz=gra;
    TURA.setFont(czcionka);
    ECTS1.setFont(czcionka);
    ECTS2.setFont(czcionka);
    TURA.setPosition(1750,25);
    ECTS1.setPosition(1430,95);
    ECTS2.setPosition(1430,135);
    TURA.setCharacterSize(50);
    ECTS1.setCharacterSize(30);
    ECTS2.setCharacterSize(30);
    TURA.setStyle(sf::Text::Style::Bold);
    ECTS1.setStyle(sf::Text::Style::Bold);
    ECTS2.setStyle(sf::Text::Style::Bold);
    TURA.setColor(sf::Color::Black);
    ECTS1.setColor(sf::Color::Black);
    ECTS2.setColor(sf::Color::Black);
    TURA.setString("TURA:");
    ECTS1.setString(std::to_string(int(gracz->gotowka)));
    ECTS2.setString(std::to_string(int((gracz+1)->gotowka)));
    ustawTure();
}
void Interfejs::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(kolorTury,states);
    target.draw(TURA, states);
    target.draw(ECTS1, states);
    target.draw(ECTS2, states);
}
void Interfejs::sprawdzPrzyciski()
{
    sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition();
    if(pozycjaMyszki.x>=1761&&pozycjaMyszki.x<1900&&pozycjaMyszki.y>=918&&pozycjaMyszki.y<=1057 ) //PRZYCISK KOÑCA TURY
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(licznikPrzycisku==0)   {ustawTure(); licznikPrzycisku++;}
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) licznikPrzycisku=0;
    }
}
void Interfejs::aktualizujStanKonta()
{
    ECTS1.setString(std::to_string(int(gracz->gotowka)));
    ECTS2.setString(std::to_string(int((gracz+1)->gotowka)));
}
