//
// Created by Daniel on 05.06.2019.
//

#ifndef WAZ_SNAKE_H
#define WAZ_SNAKE_H

#include <SFML/Graphics.hpp>
#include "fruit.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
enum GS {RUNNING,FINISHED};
struct direc {
    float x;
    float y;
};
struct entitySnake {
    float blocksize;
    sf::Clock tick;
    sf::RectangleShape blok[900];
    int blocknumber;
};
struct windowsize {
    float x;
    float y;
};
struct windowposition {
    float x;
    float y;
};
struct window{
    windowsize size;
    windowposition position;
};

class snake {
    GS GameState;
    entitySnake EntSnake;
    window plansza;
    direc direction;
    sf::RenderWindow &okno;
    float moveVal;
    float speed;
    float movespace;
    int randVal;
    fruit &owocek;
public:
    snake(sf::RenderWindow &okno, fruit &owocek);
    void MoveSnake(sf::Event &event);
    void DrawSnake(sf::RenderWindow &okno, fruit &owocek);
    void DrawOwocek(sf::RenderWindow &okno, fruit &owocek);
    float getBlockSize();
    float getMoveSpace();
    int getSnakeSize();
    sf::Vector2f getBoardPos();
    sf::Vector2f getBoardSize();
    GS getGameState();


};


#endif //WAZ_SNAKE_H
