
#ifndef Score_hpp
#define Score_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <fstream>

class Score{
    
public:
    sf::Text score;
    sf::Font font;
    std::string scoreValue;
    int scr;
    int highscr;
    int scrSaver;
    
    Score();
    
    void updateScore(sf::Clock clock);
    
    void saveHighscoreToFile();
    
};

#endif /* Score_hpp */
