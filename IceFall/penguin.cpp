

#include "penguin.hpp"
#include <iostream>

penguin::penguin(){
    
    if(!penguin::penguTexture.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/PingwinWiekszy.png")){
        std::cout<<"Error loading texture"<<std::endl;
    }
    
    if(!penguin::penguMovingTex.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/PenguinMove.png")){
        std::cout<<"Error loading texture"<<std::endl;
    }
    
    penguin::pengu.setTexture(penguTexture);
    penguin::pengu.setPosition(512.f,800.f);
    if(!penguin::penguDeadTex.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/DeadPeng.png"))
        std::cout<<"Error loading texture"<<std::endl;
    
    
    penguin::dedPengu.setTexture(penguin::penguDeadTex);
    
}


void penguin::movePengu(sf::Event event){
    
    if (event.type == event.KeyPressed){
        
        if (event.key.code == sf::Keyboard::Left){
            penguin::pengu.move(-penguin::speed,0);
            penguin::pengu.setTexture(penguin::penguMovingTex);
        }
        if (event.key.code == sf::Keyboard::Right){
            penguin::pengu.move(speed,0);}
        penguin::pengu.setTexture(penguin::penguMovingTex);
    }
    if(event.type == event.KeyReleased){
        
        if(event.key.code == sf::Keyboard::Left){
            penguin::pengu.setTexture(penguin::penguTexture);
        }
        if(event.key.code == sf::Keyboard::Right){
            penguin::pengu.setTexture(penguin::penguTexture);
        }
    }
    
}

void penguin::returnPenguToMap(){
    
    
    if(penguin::pengu.getPosition().x > 1024){
        penguin::pengu.setPosition(0.f,800.f);
    }
    else if (penguin::pengu.getPosition().x < 0){
        penguin::pengu.setPosition(1024.f,800.f);}
    
}
