#include <SFML/Graphics.hpp>
#include "icicle.hpp"
#include "penguin.hpp"
#include "background.hpp"
#include "Score.hpp"
#include "menu.hpp"
#include "GameOver.hpp"
#include <iostream>
#include <vector>


int main ()
{
    sf::RenderWindow window(sf::VideoMode(1024.f,1024.f), "TEST");
    
    menu menu;
    
    GameOver gmover;
    
    background background;
    
    icicle i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
    
    icicle allIcicles [12] = {i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12};
    
    penguin test;
    
    Score results;

    sf::Clock kolejnyClock;
    sf::Clock gameClock;
    
    
    while(window.isOpen()){

        sf::Event event;
        
        while (window.pollEvent(event)){
            
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        if(menu.gameState==1){
        
      
        background.animateBackground();

        for(int i=0; i<12; i++){
            allIcicles[i].icicleDecideFall();
            
            if(allIcicles[i].isFalling)
                allIcicles[i].icicleFall();
            
            if(allIcicles[i].detectCollision(test.pengu)){
                results.saveHighscoreToFile();
                gameClock.restart();
                menu.gameState=2;
                for(int i=0; i<12; i++){
                    allIcicles[i].speed =0.1;
                    allIcicles[i].Icicle.setPosition(allIcicles[i].Icicle.getPosition().x, 0);
                }
            }
        }
        
        
        if(kolejnyClock.getElapsedTime().asSeconds() >3 ){
            for(int i=0; i<12; i++)
                allIcicles[i].speed+=0.01;
            
            kolejnyClock.restart();
        }
        
        results.updateScore(gameClock);
        
        test.movePengu(event);
        test.returnPenguToMap();
        

        
        window.clear();
        
        
        window.draw(background.backgroundSprite);
        for(int i=0; i<12; i++){
            window.draw(allIcicles[i].Icicle);
        }
        window.draw(results.score);
        window.draw(test.pengu);
        window.display();
        }
        else if (menu.gameState==0){
            
       
            if(event.type == event.KeyReleased){
                if(event.key.code == sf::Keyboard::Up)
                    menu.chooseUp();
                if(event.key.code == sf::Keyboard::Down)
                    menu.chooseDown();
                if(event.key.code == sf::Keyboard::Enter){
                    switch(menu.selectedIndex){
                        case 0:
                            menu.gameState=1;
                            static int newNum =1;
                            for(int i=0; i<12;i++){
                                if(newNum < 6){
                                    allIcicles[i].timeFall = newNum;
                                    newNum++;}
                                else{
                                    allIcicles[i].timeFall = newNum;
                                    newNum =1;
                                }
                                allIcicles[i].isFalling = false;
                                allIcicles[i].fallingClock.restart();
                            }
                            kolejnyClock.restart();
                            gameClock.restart();
                            break;
                        case 1:
                            window.close();
                            break;
                    }
                    
                }
            }
            
        window.clear();
            
        window.draw(menu.menuBackground);
        window.draw(menu.play);
        window.draw(menu.leave);
        window.draw(menu.title);
        window.draw(menu.penguChoose);
        window.display();
            
        }
        else if (menu.gameState==2){
            gmover.setScores(results.scrSaver, results.highscr, test.pengu.getPosition());
            
            if(event.type == event.KeyReleased){
                if(event.key.code == sf::Keyboard::Escape){
                    menu.gameState=0;
                }
            }
            
            window.clear();
            window.draw(gmover.bckgrnd);
            window.draw(gmover.dedPengu);
            window.draw(gmover.hscor);
            window.draw(gmover.scor);
            window.draw(gmover.esc);
            window.display();
            
        }
       
        
        
    }
    
    
    }
