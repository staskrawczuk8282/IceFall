
#include "menu.hpp"
#include <iostream>

menu::menu(){
    
    menu::titleFont.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/IceCaps.ttf");
    menu::font.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/Pixeboy-z8XGD.ttf");
    menu::menuTexture.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/MenuBackgrnd.png");
    menu::penguChooseTex.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/PenguChoose.png");
    
    menu::title.setFont(titleFont);
    menu::title.setString("ICEFALL");
    menu::title.setPosition(220, -15.f);
    menu::title.setCharacterSize(150);
    menu::title.setFillColor(sf::Color::White);
    
    menu::play.setFont(font);
    menu::play.setString("PLAY");
    menu::play.setPosition(400, 312.f);
    menu::play.setFillColor(sf::Color::Black);
    menu::play.setCharacterSize(60);
    
    menu::leave.setFont(font);
    menu::leave.setString("EXIT");
    menu::leave.setPosition(400.f, 512.f);
    menu::leave.setFillColor(sf::Color::Black);
    menu::leave.setCharacterSize(60);
    
    menu::penguChoose.setTexture(penguChooseTex);
    menu::penguChoose.setPosition(350.f, 330.f);
    
    menu::menuBackground.setTexture(menuTexture);
    
    
    menu::selectedIndex =0;
    menu::gameState = 0; 
}



void menu::chooseUp(){
    menu::play.setFillColor(sf::Color::Red);
    menu::leave.setFillColor(sf::Color::Black);
    menu::penguChoose.setPosition(350.f, 330.f);
    selectedIndex=0;
}

void menu::chooseDown(){
    menu::leave.setFillColor(sf::Color::Red);
    menu::play.setFillColor(sf::Color::Black);
    menu::penguChoose.setPosition(350.f,530.f);
    selectedIndex=1;
}
    
    

        
    
    
    
    
    
    

