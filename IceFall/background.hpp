

#ifndef background_hpp
#define background_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class background{
public:
    
    sf::Texture backgroundTex;
    sf::Texture movedBackTex;
    sf::Sprite backgroundSprite;
    sf::Clock animationClock;
    bool moved;
    
    background();
    
    void animateBackground();
    
};

#endif /* background_hpp */
