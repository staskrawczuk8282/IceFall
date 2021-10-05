

#ifndef GameOver_hpp
#define GameOver_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class GameOver{
public:
    sf::Font font;
    sf::Font goFont;
    sf::Text gameovr;
    sf::Text scor;
    sf::Text hscor;
    sf::Text esc; 
    sf::Texture bckgrndTex;
    sf::Texture dedPenguTex;
    sf::Sprite bckgrnd;
    sf::Sprite dedPengu;
    
    
    GameOver();
    
    void setScores(int scr, int hscor, sf::Vector2f pengx);
    
    
};

#endif /* GameOver_hpp */
