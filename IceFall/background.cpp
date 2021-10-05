
#include "background.hpp"
#include <iostream>

background::background(){
    
    if(!background::backgroundTex.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/Background.png")){
        std::cout<<"Error Loading Texture"<<std::endl;
    }

    if(!background::movedBackTex.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/Background1.png"))
        std::cout<<"BLAD"<<std::endl;
    
    background::backgroundSprite.setTexture(background::backgroundTex);
    background::moved = false;
    background::animationClock.restart();
}


void background::animateBackground(){
    
    
    if(background::animationClock.getElapsedTime().asSeconds()>1){
        if(background::moved){
            background::backgroundSprite.setTexture(background::backgroundTex);
            moved=false;
            background::animationClock.restart();
        }
        else{
            background::backgroundSprite.setTexture(background::movedBackTex);
            moved=true;
            background::animationClock.restart();
        }
    }
}
