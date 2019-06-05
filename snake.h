//
// Created by Daniel on 05.06.2019.
//

#ifndef WAZ_SNAKE_H
#define WAZ_SNAKE_H

#include <SFML/Graphics.hpp>
#include "fruit.h"
#include <iostream>
struct direc {
    float x;
    float y;
};
struct entitySnake {
    float blocksize;
    sf::Clock tick;
    sf::RectangleShape blok[50];
    float blocknumber;
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
    entitySnake EntSnake;
    window plansza;
    direc direction;
    sf::RenderWindow &okno;
    float moveVal;
    float speed;
    float movespace;
public:
    snake(sf::RenderWindow &okno);
    void MoveSnake(sf::Event &event);
    void DrawSnake(sf::RenderWindow &okno, fruit &owocek);
    void DrawOwocek(sf::RenderWindow &okno, fruit &owocek);
    void SetFruitPos(fruit &owocek);
    float getBlockSize();
    bool isCollision(sf::RectangleShape a, sf::RectangleShape b);
    void ExpandSnake(bool isCol);

};


#endif //WAZ_SNAKE_H
