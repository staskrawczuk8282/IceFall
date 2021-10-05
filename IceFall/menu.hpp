

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class menu{
    
public:
    
    sf::Texture penguChooseTex;
    sf::Sprite penguChoose;
    sf::Texture menuTexture;
    sf::Sprite menuBackground;
    sf::Text title, play, leave;
    sf::Font titleFont; 
    sf::Font font;
    int selectedIndex;
    int gameState;
    
    
    menu();
    
    void chooseUp();

    void chooseDown();
    
    
};

#endif /* menu_hpp */
