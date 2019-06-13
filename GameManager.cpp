//
// Created by Daniel on 13.06.2019.
//

#include "GameManager.h"
GameManager::GameManager(snake &temp, fruit &temp2): wunsz(temp), owocek(temp2) {
    wall.setPosition((wunsz.getMoveSpace()+1)*wunsz.getBlockSize(),0);
    wall.setSize(sf::Vector2f(wunsz.getBlockSize(),wunsz.getBlockSize()*wunsz.getMoveSpace()));
    wall.setFillColor(sf::Color(255,255,255));
    text.font.loadFromFile("resources/Pixeled.ttf");

    text.Counter.setFont(text.font);
    text.Counter.setPosition(getPosForSizeCounter());
    text.Counter.setCharacterSize(30);
    text.Counter.setFillColor(sf::Color::White);
    text.Counter.setString("SNAKE SIZE: ");

    text.CounterVal.setFont(text.font);
    text.CounterVal.setPosition(text.Counter.getPosition().x+text.Counter.getGlobalBounds().width,text.Counter.getPosition().y);
    text.CounterVal.setFillColor(sf::Color::White);
    text.CounterVal.setCharacterSize(30);

    text.GState.setFont(text.font);
    text.GState.setPosition(sf::Vector2f(text.Counter.getPosition().x,text.Counter.getPosition().y+60));
    text.GState.setFillColor(sf::Color::White);
    text.GState.setCharacterSize(40);

}
void GameManager::drawGameManager(sf::RenderWindow &okno) {
    CounterValUpdate();
    DefineGstate();
    okno.draw(wall);
    okno.draw(text.Counter);
    okno.draw(text.CounterVal);
    okno.draw(text.GState);
}

sf::Vector2f GameManager::getPosForSizeCounter() {
    return sf::Vector2f(wall.getPosition().x+50,50);
}

void GameManager::CounterValUpdate() {
    std::string Snakesize = std::to_string(wunsz.getSnakeSize());
    text.CounterVal.setString(Snakesize);
}

void GameManager::DefineGstate() {
    if(wunsz.getGameState()==RUNNING){
        text.GState.setString(" ");
    }
    else if (wunsz.getGameState()==FINISHED){
        text.GState.setString("GAME OVER R TO RESTART" );
        text.GState.setPosition(wunsz.getBlockSize()*wunsz.getMoveSpace()/2 - text.GState.getGlobalBounds().width/2,
                wunsz.getBlockSize()*wunsz.getMoveSpace()/2 - text.GState.getGlobalBounds().height/2);
    }
}

void GameManager::restartGame(sf::Event &event) {
    if(wunsz.getGameState()==FINISHED) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 114) {
                wunsz.setupGameStart();
            }
        }
    }
}