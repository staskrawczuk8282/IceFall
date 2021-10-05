

#include "Score.hpp"
#include <iostream>

Score::Score(){
    
    if(!Score::font.loadFromFile("/Users/stas/Desktop/SnakePJC/SnakePJC/Textures/Pixeboy-z8XGD.ttf"))
        std::cout<<"Error Loading Font"<<std::endl;
    
    Score::score.setFont(Score::font);
    Score::score.setPosition(30.f, 950.f);
    Score::scoreValue = "SCORE:";
    
    Score::score.setString(scoreValue);
    Score::score.setCharacterSize(40);
    Score::score.setFillColor(sf::Color::Black);
}


void Score::updateScore(sf::Clock clock){
    
    Score::scr = clock.getElapsedTime().asSeconds();
    if(scr>0)
        Score:scrSaver = scr;
    Score::scoreValue = "SCORE:" + std::to_string(scr);
    Score::score.setString(scoreValue);
}


void Score::saveHighscoreToFile(){
    std::string path = "/Users/stas/Desktop/SnakePJC/SnakePJC/Saves/highscore.txt";
    std::ifstream file;
    file.open(path);
    if(!file.good())
        std::cout<<"Error loading highscores"<<std::endl;
    
    std::string helpingstr;
    file>>helpingstr;
    file.close();
    Score::highscr = std::stoi(helpingstr);
    
    
    if(highscr<scr){
        std::ofstream copyFile("copy.txt");
        copyFile<<Score::scr;
        
        std::remove(path.c_str());
        std::rename("copy.txt", path.c_str());
        copyFile.close();
    }
}
