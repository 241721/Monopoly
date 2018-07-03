#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Gracz.h"
#include "Przycisk.h"
#include "Kostka.h"
#include "Interfejs.h"

using namespace sf;
using namespace std;

int main()
{
    ////// USTAWIENIA //////


    //ZMIENNE GLOBALNE:
    char scena = 1;
    int licznik_pozycji=0;
    int maxkat=450;
    int licznik_pozycji2=maxkat;
    float pozycja_poczatkowa=250.0f;
    int ilosc_graczy=2;
    srand( time( NULL ) );

    //KOLORY:
    Color wypelnienie = Color::Black;
    Color kolorTekstu = Color::White;

    //TEKSTURY I SPRIRTY:
    Texture tekstura_planszy;
    Texture interfejs;
    Texture przcisk1Tex;
    Texture tlo_wstepu;
    Texture tlo_ustawien;
    Texture kostkaTex;
    Texture przyciskTex;
    Texture czerwonyTex;
    Texture zielonyTex;
    Texture niebieskiTex;
    Texture zoltyTex;
    Texture czerwonyPrzycisk;
    Texture zielonyPrzycisk;
    Texture zoltyPrzycisk;
    Texture niebieskiPrzycisk;
    zoltyTex.loadFromFile("zolty.PNG");
    interfejs.loadFromFile("interfejs.PNG");
    zielonyTex.loadFromFile("zielony.PNG");
    niebieskiTex.loadFromFile("niebieski.PNG");
    czerwonyPrzycisk.loadFromFile("czerwonyPrzycisk.PNG");
    zoltyPrzycisk.loadFromFile("zoltyPrzycisk.PNG");
    zielonyPrzycisk.loadFromFile("zielonyPrzycisk.PNG");
    niebieskiPrzycisk.loadFromFile("niebieskiPrzycisk.PNG");
    czerwonyTex.loadFromFile("czerwony.PNG");
    przcisk1Tex.loadFromFile("przycisk1.PNG");
    przyciskTex.loadFromFile("przycisk.PNG");
    kostkaTex.loadFromFile("kostka.JPG");
    tlo_ustawien.loadFromFile("plansza2.PNG");
    tlo_wstepu.loadFromFile("wstep.PNG");
    tekstura_planszy.loadFromFile("plansza.PNG");
    Sprite interfejs2(interfejs);
    Sprite przycisk1(przcisk1Tex);
    Sprite przyciskSprite(przyciskTex);
    Sprite wstep(tlo_wstepu);
    Sprite ustawienia(tlo_ustawien);
    Sprite plansza;
    plansza.setTexture(tekstura_planszy);
    plansza.scale(0.9,0.9);
    przycisk1.setPosition(pozycja_poczatkowa,0);
    przycisk1.move(-20,150);
    przycisk1.scale(1.2,1);
    przyciskSprite.scale(0.7,0.7);
    przyciskSprite.setTextureRect(IntRect(0,0,110,100));
    przyciskSprite.move(-400,0);
    ustawienia.scale(2,2);
    ustawienia.move(0,-950);
    Przycisk przyciskCzerwony1(czerwonyPrzycisk,pozycja_poczatkowa,90);
    Przycisk przyciskZielony1(zielonyPrzycisk,pozycja_poczatkowa+80,90);
    Przycisk przyciskNiebieski1(niebieskiPrzycisk,pozycja_poczatkowa+160,90);
    Przycisk przyciskZolty1(zoltyPrzycisk,pozycja_poczatkowa+240,90);
    przyciskCzerwony1.wcisnij();

    Przycisk przyciskCzerwony2(czerwonyPrzycisk,pozycja_poczatkowa,190);
    Przycisk przyciskZielony2(zielonyPrzycisk,pozycja_poczatkowa+80,190);
    Przycisk przyciskNiebieski2(niebieskiPrzycisk,pozycja_poczatkowa+160,190);
    Przycisk przyciskZolty2(zoltyPrzycisk,pozycja_poczatkowa+240,190);
    przyciskZielony2.wcisnij();

    //TEKST I CZCIONKI:
    Font czcionka_naglowek;
    Font czcionka_wstep;
    czcionka_wstep.loadFromFile("WorkSans.otf");
    czcionka_naglowek.loadFromFile("Monopoly_font.ttf");

    Text tekst;
    tekst.setFont(czcionka_wstep);
    tekst.setCharacterSize(20);
    tekst.setFillColor(wypelnienie);
    tekst.setString("PROGRAMOWANIE OBIEKTOWE - PROJEKT\n\n"
                    "AUTOR:\nWojciech Jakiela\n\n"
                    "PROWADZACY: Mgr inz. Mariusz Ostrowski\n\n"
                    "UZYTE CZCIONKI:\nWork Sans by Wei Huang (SIL Open Font License)\nMonopoly Regular by Hyun S. Choi (Freeware) ");
    tekst.setPosition(270,35);

    Text naglowek;
    naglowek.setFont(czcionka_naglowek);
    naglowek.setCharacterSize(30);
    naglowek.setFillColor(wypelnienie);
    naglowek.setString("MONOPOLY");
    naglowek.setPosition(270,0);

    Text przycisk[3];
    for (int i=0; i<3; i++)
    {
        przycisk[i].setFont(czcionka_wstep);
        przycisk[i].setCharacterSize(43);
        przycisk[i].setFillColor(Color::Black);
    }
    przycisk[0].setString("2");
    przycisk[1].setString("3");
    przycisk[2].setString("4");
    przycisk[0].setPosition(pozycja_poczatkowa+30,250);
    przycisk[1].setPosition(pozycja_poczatkowa+145,250);
    przycisk[2].setPosition(pozycja_poczatkowa+265,250);
    //PRYMITYWY:

    RectangleShape prostokat(Vector2f(310,80));
    prostokat.setFillColor(Color::Black);
    prostokat.setPosition(pozycja_poczatkowa,0);

    //GŁÓWNE OBIEKTY:
    Gracz* gracz;
    Kostka kostka(kostkaTex);
    kostka.sprite.move(1200,700);
    Kostka kostka2(kostkaTex);
    kostka2.sprite.move(1270,700);
    Pionek p(czerwonyTex);
    Pionek p2(zielonyTex);

    //OKNA APLIKACJI:
    RenderWindow oknoWstep(VideoMode( 800,480,32 ), "Monopoly", Style::None );
    RenderWindow oknoGry;
    oknoGry.setFramerateLimit(60);
    oknoWstep.setFramerateLimit(60);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while(oknoWstep.isOpen())
    {
        Vector2i pozycjaMyszki = Mouse::getPosition(oknoWstep);
        Event zdarzenie;
        while( oknoWstep.pollEvent( zdarzenie ) )
        {
            if( Keyboard::isKeyPressed(Keyboard::Escape) )
            {
                oknoWstep.close();
            }
        }
        oknoWstep.clear();
        switch (scena)
        {
        case 1:
            oknoWstep.draw(wstep);
            oknoWstep.draw(naglowek);
            oknoWstep.draw(tekst);
            if( Keyboard::isKeyPressed(Keyboard::Enter) )
            {
                scena++;
            }
            break;
        case 2:
            if(pozycjaMyszki.x>=pozycja_poczatkowa-16&&pozycjaMyszki.x<pozycja_poczatkowa+100&&pozycjaMyszki.y>=230&&pozycjaMyszki.y<=317)  //Przycisk 1
            {
                przycisk[0].setFillColor(Color::Red);
                przycisk[1].setFillColor(kolorTekstu);
                przycisk[2].setFillColor(kolorTekstu);
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    Gracz* gracz1 = new Gracz[ilosc_graczy];
                    gracz=gracz1;
                    gracz->pionek=&p;
                    (gracz+1)->pionek=&p2;
                    scena++;
                }
            }
            else if(pozycjaMyszki.x>=pozycja_poczatkowa+100&&pozycjaMyszki.x<pozycja_poczatkowa+216&&pozycjaMyszki.y>=230&&pozycjaMyszki.y<=317)  //Przycisk 2
            {
                przycisk[1].setFillColor(Color::Red);
                przycisk[0].setFillColor(kolorTekstu);
                przycisk[2].setFillColor(kolorTekstu);
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    ilosc_graczy=3;
                    Gracz* gracz1=new Gracz[ilosc_graczy];
                    gracz=gracz1;
                    scena++;
                }
            }
            else if(pozycjaMyszki.x>=pozycja_poczatkowa+220&&pozycjaMyszki.x<=pozycja_poczatkowa+336&&pozycjaMyszki.y>=230&&pozycjaMyszki.y<=317)  //Przycisk 3
            {
                przycisk[2].setFillColor(Color::Red);
                przycisk[0].setFillColor(kolorTekstu);
                przycisk[1].setFillColor(kolorTekstu);
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    ilosc_graczy=4;
                    Gracz* gracz1=new Gracz[ilosc_graczy];
                    gracz=gracz1;
                    scena++;
                }
            }
            else
            {
                przycisk[0].setFillColor(kolorTekstu);
                przycisk[1].setFillColor(kolorTekstu);
                przycisk[2].setFillColor(kolorTekstu);
            }
            if(licznik_pozycji<=maxkat)
            {
                ustawienia.rotate(0.1);
                licznik_pozycji++;
            }
            else
            {
                ustawienia.rotate(-0.1);
                licznik_pozycji2--;
                if(licznik_pozycji2==0)
                {
                    licznik_pozycji=0;
                    licznik_pozycji2=maxkat;
                }
            }
            oknoWstep.draw(ustawienia);
            oknoWstep.draw(przycisk1);
            tekst.setString("Wybierz ilosc graczy:");
            tekst.setFillColor(kolorTekstu);
            tekst.setPosition(pozycja_poczatkowa,170);
            tekst.setCharacterSize(30);
            oknoWstep.draw(przycisk[0]);
            oknoWstep.draw(przycisk[1]);
            oknoWstep.draw(przycisk[2]);
            oknoWstep.draw(tekst);
            break;
        case 3:
            tekst.setCharacterSize(38);
            if(licznik_pozycji<=maxkat)
            {
                ustawienia.rotate(0.1);
                licznik_pozycji++;
            }
            else
            {
                ustawienia.rotate(-0.1);
                licznik_pozycji2--;
                if(licznik_pozycji2==0)
                {
                    licznik_pozycji=0;
                    licznik_pozycji2=maxkat;
                }
            }
            switch(ilosc_graczy)
            {
            case 2:
                tekst.setString("WYBIERZ KOLOR\nGracz nr 1\n\n\nGracz nr 2\n\n\n\n                   START");
                tekst.setPosition(pozycja_poczatkowa,10);
                tekst.setCharacterSize(30);
                if(pozycjaMyszki.x>=pozycja_poczatkowa&&pozycjaMyszki.x<pozycja_poczatkowa+65&&pozycjaMyszki.y>=90&&pozycjaMyszki.y<=155 )  //Przycisk 1 CZERW
                {
                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        if(przyciskCzerwony1.wcisniety!=1)
                        {
                            gracz->pionek->pionekSprite.setTexture(czerwonyTex);
                            if(przyciskCzerwony2.wcisniety==1)
                            {
                                przyciskCzerwony1.wcisnij();
                                przyciskCzerwony2.wcisnij();
                                przyciskZielony2.wcisnij();
                                (gracz+1)->pionek->pionekSprite.setTexture(zielonyTex);
                            }
                            else
                            {
                                przyciskCzerwony1.wcisnij();
                            }
                            if(przyciskZielony1.wcisniety==1) przyciskZielony1.wcisnij();
                            if(przyciskNiebieski1.wcisniety==1) przyciskNiebieski1.wcisnij();
                            if(przyciskZolty1.wcisniety==1) przyciskZolty1.wcisnij();
                        }
                    }
                }
                if(pozycjaMyszki.x>=pozycja_poczatkowa&&pozycjaMyszki.x<pozycja_poczatkowa+65&&pozycjaMyszki.y>=190&&pozycjaMyszki.y<=255 )  //Przycisk 2 CZERW
                {

                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        if(przyciskCzerwony2.wcisniety!=1)
                        {
                            (gracz+1)->pionek->pionekSprite.setTexture(czerwonyTex);
                            if(przyciskCzerwony1.wcisniety==1)
                            {
                                gracz->pionek->pionekSprite.setTexture(zielonyTex);
                                przyciskCzerwony2.wcisnij();
                                przyciskCzerwony1.wcisnij();
                                przyciskZielony1.wcisnij();
                                gracz->pionek->pionekSprite.setTexture(zielonyTex);
                            }
                            else
                            {
                                przyciskCzerwony2.wcisnij();
                            }
                            if(przyciskZielony2.wcisniety==1) przyciskZielony2.wcisnij();
                            if(przyciskNiebieski2.wcisniety==1) przyciskNiebieski2.wcisnij();
                            if(przyciskZolty2.wcisniety==1) przyciskZolty2.wcisnij();
                        }
                    }
                }

                if(pozycjaMyszki.x>=pozycja_poczatkowa+80&&pozycjaMyszki.x<pozycja_poczatkowa+145&&pozycjaMyszki.y>=90&&pozycjaMyszki.y<=155 )  //Przycisk 1 ZIEL
                {
                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        if(przyciskZielony1.wcisniety!=1)
                        {
                            gracz->pionek->pionekSprite.setTexture(zielonyTex);
                            if(przyciskZielony2.wcisniety==1)
                            {
                                (gracz+1)->pionek->pionekSprite.setTexture(czerwonyTex);
                                przyciskZielony1.wcisnij();
                                przyciskZielony2.wcisnij();
                                przyciskCzerwony2.wcisnij();
                            }
                            else
                            {
                                przyciskZielony1.wcisnij();
                            }
                            if(przyciskCzerwony1.wcisniety==1) przyciskCzerwony1.wcisnij();
                            if(przyciskNiebieski1.wcisniety==1) przyciskNiebieski1.wcisnij();
                            if(przyciskZolty1.wcisniety==1) przyciskZolty1.wcisnij();
                        }
                    }
                }
                if(pozycjaMyszki.x>=pozycja_poczatkowa+80&&pozycjaMyszki.x<pozycja_poczatkowa+145&&pozycjaMyszki.y>=190&&pozycjaMyszki.y<=255 )  //Przycisk 2 ZIEL
                {
                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        if(przyciskZielony2.wcisniety!=1)
                        {
                            (gracz+1)->pionek->pionekSprite.setTexture(zielonyTex);
                            if(przyciskZielony1.wcisniety==1)
                            {
                                gracz->pionek->pionekSprite.setTexture(czerwonyTex);
                                przyciskZielony2.wcisnij();
                                przyciskZielony1.wcisnij();
                                przyciskCzerwony1.wcisnij();
                                gracz->pionek->pionekSprite.setTexture(czerwonyTex);
                            }
                            else
                            {
                                przyciskZielony2.wcisnij();
                            }
                            if(przyciskCzerwony2.wcisniety==1) przyciskCzerwony2.wcisnij();
                            if(przyciskNiebieski2.wcisniety==1) przyciskNiebieski2.wcisnij();
                            if(przyciskZolty2.wcisniety==1) przyciskZolty2.wcisnij();
                        }
                    }
                }

                if(pozycjaMyszki.x>=pozycja_poczatkowa+160&&pozycjaMyszki.x<pozycja_poczatkowa+225&&pozycjaMyszki.y>=90&&pozycjaMyszki.y<=155 )  //Przycisk 1 NIEB
                {
                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        if(przyciskNiebieski1.wcisniety!=1)
                        {
                            gracz->pionek->pionekSprite.setTexture(niebieskiTex);
                            if(przyciskNiebieski2.wcisniety==1)
                            {
                                (gracz+1)->pionek->pionekSprite.setTexture(czerwonyTex);
                                przyciskNiebieski1.wcisnij();
                                przyciskNiebieski2.wcisnij();
                                przyciskCzerwony2.wcisnij();
                            }
                            else
                            {
                                przyciskNiebieski1.wcisnij();
                            }
                            if(przyciskCzerwony1.wcisniety==1) przyciskCzerwony1.wcisnij();
                            if(przyciskZielony1.wcisniety==1) przyciskZielony1.wcisnij();
                            if(przyciskZolty1.wcisniety==1) przyciskZolty1.wcisnij();
                        }
                    }
                }
                if(pozycjaMyszki.x>=pozycja_poczatkowa+160&&pozycjaMyszki.x<pozycja_poczatkowa+225&&pozycjaMyszki.y>=190&&pozycjaMyszki.y<=255 )  //Przycisk 2 NIEB
                {
                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        if(przyciskNiebieski2.wcisniety!=1)
                        {
                            (gracz+1)->pionek->pionekSprite.setTexture(niebieskiTex);
                            if(przyciskNiebieski1.wcisniety==1)
                            {
                                gracz->pionek->pionekSprite.setTexture(czerwonyTex);
                                przyciskNiebieski2.wcisnij();
                                przyciskNiebieski1.wcisnij();
                                przyciskCzerwony1.wcisnij();
                            }
                            else
                            {
                                przyciskNiebieski2.wcisnij();
                            }
                            if(przyciskCzerwony2.wcisniety==1) przyciskCzerwony2.wcisnij();
                            if(przyciskZielony2.wcisniety==1) przyciskZielony2.wcisnij();
                            if(przyciskZolty2.wcisniety==1) przyciskZolty2.wcisnij();
                        }
                    }
                }
                if(pozycjaMyszki.x>=pozycja_poczatkowa+240&&pozycjaMyszki.x<pozycja_poczatkowa+300&&pozycjaMyszki.y>=90&&pozycjaMyszki.y<=155 )  //Przycisk 1 ZÓŁTY
                {
                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        if(przyciskZolty1.wcisniety!=1)
                        {
                            gracz->pionek->pionekSprite.setTexture(zoltyTex);
                            if(przyciskZolty2.wcisniety==1)
                            {
                                (gracz+1)->pionek->pionekSprite.setTexture(czerwonyTex);
                                przyciskZolty1.wcisnij();
                                przyciskZolty2.wcisnij();
                                przyciskCzerwony2.wcisnij();
                            }
                            else
                            {
                                przyciskZolty1.wcisnij();
                            }
                            if(przyciskCzerwony1.wcisniety==1) przyciskCzerwony1.wcisnij();
                            if(przyciskNiebieski1.wcisniety==1) przyciskNiebieski1.wcisnij();
                            if(przyciskZielony1.wcisniety==1) przyciskZielony1.wcisnij();
                        }
                    }
                }
                if(pozycjaMyszki.x>=pozycja_poczatkowa+240&&pozycjaMyszki.x<pozycja_poczatkowa+300&&pozycjaMyszki.y>=190&&pozycjaMyszki.y<=255 )  //Przycisk 2 ZÓŁTY
                {
                    if (Mouse::isButtonPressed(Mouse::Left))
                    {
                        if(przyciskZolty2.wcisniety!=1)
                        {
                            (gracz+1)->pionek->pionekSprite.setTexture(zoltyTex);
                            if(przyciskZolty1.wcisniety==1)
                            {
                                gracz->pionek->pionekSprite.setTexture(czerwonyTex);
                                przyciskZolty2.wcisnij();
                                przyciskZolty1.wcisnij();
                                przyciskCzerwony1.wcisnij();
                            }
                            else
                            {
                                przyciskZolty2.wcisnij();
                            }
                            if(przyciskCzerwony2.wcisniety==1) przyciskCzerwony2.wcisnij();
                            if(przyciskZielony2.wcisniety==1) przyciskZielony2.wcisnij();
                            if(przyciskNiebieski2.wcisniety==1) przyciskNiebieski2.wcisnij();
                        }
                    }
                }
                break;
            case 3:
                tekst.setString("WYBIERZ KOLOR\nGracz nr 1\n\n\nGracz nr 2\n\n\nGracz nr 3");
                tekst.setPosition(pozycja_poczatkowa,10);
                tekst.setCharacterSize(30);
                break;
            case 4:
                tekst.setString("WYBIERZ KOLOR\nGracz nr 1\n\n\nGracz nr 2\n\n\nGracz nr 3\n\n\nGracz nr 4");
                tekst.setPosition(pozycja_poczatkowa,10);
                tekst.setCharacterSize(30);
                break;
            }
            oknoWstep.draw(ustawienia);
            oknoWstep.draw(tekst);
            oknoWstep.draw(przyciskSprite);
            oknoWstep.draw(przyciskCzerwony1);
            oknoWstep.draw(przyciskZielony1);
            oknoWstep.draw(przyciskZolty1);
            oknoWstep.draw(przyciskNiebieski1);
            oknoWstep.draw(przyciskCzerwony2);
            oknoWstep.draw(przyciskZielony2);
            oknoWstep.draw(przyciskZolty2);
            oknoWstep.draw(przyciskNiebieski2);
            break;
        }

        oknoWstep.display();
    }
    p.pionekSprite.setPosition(940,990);
    p2.pionekSprite.setPosition(1020,990);
    Interfejs inter(czcionka_wstep,gracz);
    oknoGry.create( VideoMode( 1920, 1080, 32 ), "Monopoly", Style::Fullscreen );
    while(oknoGry.isOpen())
    {

        Event zdarzenie;
        while( oknoGry.pollEvent( zdarzenie ) )
        {
            if( Keyboard::isKeyPressed(Keyboard::Enter) )
            {
                if(inter.turaGracza==0) {(gracz+1)->ruszPionkiem(inter.turaGracza);(gracz+1)->pionek->pozycja+=0.5; if((gracz+1)->pionek->pozycja==41) {(gracz+1)->pionek->pozycja=1; (inter.gracz+1)->gotowka+=300;}}
                else {(gracz)->ruszPionkiem(inter.turaGracza); gracz->pionek->pozycja+=0.5; if(gracz->pionek->pozycja==41) {gracz->pionek->pozycja=1; inter.gracz->gotowka+=300;}}
            }
            if( Keyboard::isKeyPressed(Keyboard::Q) )
            {
                kostka.ustawKostke(gracz->rzucKoscmi());
                kostka2.ustawKostke(gracz->rzucKoscmi());
            }
            if( Keyboard::isKeyPressed(Keyboard::Escape) )
            {
                oknoGry.close();
            }
        }
        inter.sprawdzPrzyciski();
        inter.aktualizujStanKonta();
        oknoGry.clear();
        oknoGry.draw(plansza);
        oknoGry.draw(interfejs2);
        oknoGry.draw(p);
        oknoGry.draw(p2);
        oknoGry.draw(kostka);
        oknoGry.draw(kostka2);
        oknoGry.draw(inter);

        oknoGry.display();
    }
    return 0;
}
