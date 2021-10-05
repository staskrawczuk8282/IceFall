

#ifndef icicle_hpp
#define icicle_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

class icicle
{
public:
sf::Texture texture;
sf::Sprite Icicle;
sf::Texture fallingTexture;
sf::Clock fallingClock;
int xCoord;
bool isFalling =false;
float speed;
int timeFall;


icicle();

void randomizePosition();
    
bool detectCollision(sf::Sprite peng);
    
void icicleDecideFall();

void icicleFall();
    

};
#endif /* icicle_hpp */
