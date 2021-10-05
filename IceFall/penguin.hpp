

#ifndef penguin_hpp
#define penguin_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class penguin{

public:
    sf::Texture penguTexture;
    sf::Texture penguMovingTex;
    sf::Texture penguDeadTex;
    
    sf::Sprite pengu;
    sf::Sprite dedPengu;
    
    float speed = 0.3f;
    
    penguin();
    
    void movePengu(sf::Event event);
    
    void returnPenguToMap();
};


#endif /* penguin_hpp */
