//
// Created by Daniel on 13.06.2019.
//

#ifndef WAZ_GAMEMANAGER_H
#define WAZ_GAMEMANAGER_H
#include "snake.h"
#include "fruit.h"
#include <string>
struct napis {
    sf::Font font;
    sf::Text Counter;
    sf::Text CounterVal;
    sf::Text GState;
};
class GameManager {
    sf::RectangleShape wall;
    snake &wunsz;
    fruit &owocek;
    napis text;
public:
    GameManager(snake &wunsz, fruit &owocek);
    void drawGameManager(sf::RenderWindow &okno);
    sf::Vector2f getPosForSizeCounter();
    void CounterValUpdate();
    void DefineGstate();
    void restartGame(sf::Event &event);
};


#endif //WAZ_GAMEMANAGER_H
