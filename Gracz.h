#ifndef GRACZ_H
#define GRACZ_H
#include "Pionek.h"
#include <string>

class Gracz
{
public:
    std::string nazwa;
    float gotowka;
    Pionek* pionek;
    sf::Vector2f wektorPrzesuniecia;
    sf::Vector2f wektorPrzesuniecia2;
    friend class Interfejs;

    Gracz(std::string n="Gracz", float g=1500.0f, Pionek* p=nullptr);
    int rzucKoscmi();
    void ruszPionkiem(int tura);
};

#endif // GRACZ_H
