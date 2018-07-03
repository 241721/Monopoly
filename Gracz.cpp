#include "Gracz.h"
#include <ctime>
#include <iostream>

Gracz::Gracz(std::string n, float g, Pionek* p): nazwa(n)
{
    gotowka=1500;
    wektorPrzesuniecia.x=-44.5; wektorPrzesuniecia.y=0;
    wektorPrzesuniecia2.x=-70; wektorPrzesuniecia2.y=0;
}

int Gracz::rzucKoscmi()
{
    int rzut =( std::rand() % 6 ) + 1;
    return rzut;
}

void Gracz::ruszPionkiem(int tura)
{
    if(tura==1)
    {
        sf::Vector2f pozycja=this->pionek->pionekSprite.getPosition();
        if(pozycja.x==139&&pozycja.y==990) {wektorPrzesuniecia.x=-55; wektorPrzesuniecia.y=-25;}
        if(pozycja.x==29&&pozycja.y==940) {wektorPrzesuniecia.x=0; wektorPrzesuniecia.y=-44.5;}
        if(pozycja.x==29&&pozycja.y==139) {wektorPrzesuniecia.x=25; wektorPrzesuniecia.y=-55;}
        if(pozycja.x==79&&pozycja.y==29) {wektorPrzesuniecia.x=44.5; wektorPrzesuniecia.y=0;}
        if(pozycja.x==880&&pozycja.y==29) {wektorPrzesuniecia.x=55; wektorPrzesuniecia.y=25;}
        if(pozycja.x==990&&pozycja.y==79) {wektorPrzesuniecia.x=0; wektorPrzesuniecia.y=44.5;}
        if(pozycja.x==990&&pozycja.y==880) {wektorPrzesuniecia.x=-25; wektorPrzesuniecia.y=55;}
        if(pozycja.x==940&&pozycja.y==990) {wektorPrzesuniecia.x=-44.5; wektorPrzesuniecia.y=0;}
        this->pionek->pionekSprite.move(wektorPrzesuniecia);
    }
    if(tura==0)
    {
        sf::Vector2f pozycja=this->pionek->pionekSprite.getPosition();
        if(pozycja.x==880&&pozycja.y==990) {wektorPrzesuniecia2.x=-44.5; wektorPrzesuniecia2.y=0;}
        if(pozycja.x==168&&pozycja.y==990) {wektorPrzesuniecia2.x=-69.5; wektorPrzesuniecia2.y=+0;}
        if(pozycja.x==29&&pozycja.y==990) {wektorPrzesuniecia2.x=0; wektorPrzesuniecia2.y=-55;}
        if(pozycja.x==29&&pozycja.y==880) {wektorPrzesuniecia2.x=0; wektorPrzesuniecia2.y=-44.5;}
        if(pozycja.x==29&&pozycja.y==168) {wektorPrzesuniecia2.x=0; wektorPrzesuniecia2.y=-69.5;}
        if(pozycja.x==29&&pozycja.y==29) {wektorPrzesuniecia2.x=55; wektorPrzesuniecia2.y=0;}
        if(pozycja.x==139&&pozycja.y==29) {wektorPrzesuniecia2.x=44.5; wektorPrzesuniecia2.y=0;}
        if(pozycja.x==851&&pozycja.y==29) {wektorPrzesuniecia2.x=69.5; wektorPrzesuniecia2.y=0;}
        if(pozycja.x==990&&pozycja.y==29) {wektorPrzesuniecia2.x=0; wektorPrzesuniecia2.y=55;}
        if(pozycja.x==990&&pozycja.y==139) {wektorPrzesuniecia2.x=0; wektorPrzesuniecia2.y=44.5;}
        if(pozycja.x==990&&pozycja.y==851) {wektorPrzesuniecia2.x=15; wektorPrzesuniecia2.y=69.5;}
        if(pozycja.x==1020&&pozycja.y==990) {wektorPrzesuniecia2.x=-70; wektorPrzesuniecia2.y=0;}

        this->pionek->pionekSprite.move(wektorPrzesuniecia2);
    }

}
