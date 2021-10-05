

#include "GameOver.hpp"

GameOver::GameOver(){
    
    GameOver::bckgrndTex.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/Background.png");
    GameOver::dedPenguTex.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/DeadPeng.png");
    font.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/Pixeboy-z8XGD.ttf");
    goFont.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/IceCaps.ttf");
    
    bckgrnd.setTexture(bckgrndTex);
    bckgrnd.setColor(sf::Color::Red);
    dedPengu.setTexture(dedPenguTex);
    
    esc.setFont(font);
    esc.setCharacterSize(40);
    esc.setPosition(120, 10);
    esc.setString("Press ESCAPE to go back to main menu");
    
    gameovr.setFont(goFont);
    gameovr.setCharacterSize(100);
    gameovr.setPosition(420, 300);
    gameovr.setFillColor(sf::Color::White);
    
    scor.setFont(font);
    scor.setCharacterSize(70);
    hscor.setFont(font);
    hscor.setCharacterSize(80);
    
    scor.setPosition(420, 550);
    hscor.setPosition(420, 650);
}


void GameOver::setScores(int scr, int hscr, sf::Vector2f pengx){
    
    dedPengu.setPosition(pengx);
    std::string score = "Score: ";
    std::string hscore = "HighScore: ";

    score += std::to_string(scr);
    hscore += std::to_string(hscr);
    
    
    scor.setString(score);
    hscor.setString(hscore);
}
