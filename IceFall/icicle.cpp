

#include <SFML/Graphics.hpp>
#include "icicle.hpp"
#include <iostream>
#include <time.h>

icicle::icicle(){
    if(!icicle::texture.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/BiggerIcicle.png"))
        std::cout<<"Error Loading File"<<std::endl;
    if(!icicle::fallingTexture.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/FallingBiggerIcicle.png"))
        std::cout<<"Error Loading File"<<std::endl;
    
    icicle::Icicle.setTexture(icicle::texture);
    icicle::xCoord = rand() % 1024+1;
    icicle::Icicle.setPosition(icicle::xCoord, 0.f);
    icicle::fallingClock.restart();
    static int timeNum = 1;
    if(timeNum==5){
        icicle::timeFall=timeNum;
        timeNum = 1;
    }
    else{
        icicle::timeFall = timeNum;
        timeNum++;
    }
    speed = 0.1;
}

void icicle::randomizePosition(){
    xCoord = rand() % 1024+1;
    icicle::Icicle.setPosition(icicle::xCoord, 0.f);
}

bool icicle::detectCollision(sf::Sprite peng){
    if(
       (peng.getPosition().x<icicle::Icicle.getPosition().x+40)&&
       (peng.getPosition().x+50>icicle::Icicle.getPosition().x)&&
       (icicle::Icicle.getPosition().y > 710.f)&&
       (icicle::Icicle.getPosition().y < 900)
       )
        return true;
    else
        return false;
}

void icicle::icicleDecideFall(){
    
    if(icicle::fallingClock.getElapsedTime().asSeconds()>timeFall){
        icicle::isFalling =true;
    }
    
}

void icicle::icicleFall(){
    
    if(icicle::isFalling){
        icicle::Icicle.move(0.f, icicle::speed);
    }
        if(icicle::Icicle.getPosition().y>1024){
            icicle::randomizePosition();
            icicle::fallingClock.restart();
        }
    
}
