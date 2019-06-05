//
// Created by Daniel on 05.06.2019.
//

#include "snake.h"

snake::snake(sf::RenderWindow &temp1): okno(temp1)  {
    movespace=20;
    speed=300;
    EntSnake.blocknumber=3;
    direction.x=0;
    direction.y=-1;
    plansza.size.x = okno.getSize().x;
    plansza.size.y = okno.getSize().y;
    EntSnake.blocksize=plansza.size.x/movespace;
    moveVal=EntSnake.blocksize;
    for (int i = 1; i < 30; ++i) {
        EntSnake.blok[i].setSize(sf::Vector2f(EntSnake.blocksize,EntSnake.blocksize));
        EntSnake.blok[i].setFillColor(sf::Color(160, 8, 8));
    }


    EntSnake.blok[0].setSize(sf::Vector2f(EntSnake.blocksize,EntSnake.blocksize));
    EntSnake.blok[0].setFillColor(sf::Color(98, 66, 188));
    EntSnake.blok[0].setPosition(sf::Vector2f(10*EntSnake.blocksize,10*EntSnake.blocksize));
    EntSnake.blok[1].setPosition(sf::Vector2f(10*EntSnake.blocksize,11*EntSnake.blocksize));
    EntSnake.blok[2].setPosition(sf::Vector2f(10*EntSnake.blocksize,12*EntSnake.blocksize));


}

void snake::DrawSnake(sf::RenderWindow &okno, fruit &owocek) {

    std::cout << EntSnake.blocknumber << std::endl;
    sf::Vector2f pos[50];
    if (EntSnake.tick.getElapsedTime().asMilliseconds() > speed) {
        for (int i = 0; i < EntSnake.blocknumber-1 ; ++i) {
            pos[i]=EntSnake.blok[i].getPosition();
        }
            EntSnake.blok[0].move(sf::Vector2f(EntSnake.blocksize * direction.x, EntSnake.blocksize * direction.y));
        for (int i = 0; i < EntSnake.blocknumber-1 ; ++i) {
            EntSnake.blok[i+1].setPosition(pos[i]);
        }
        if(EntSnake.blok[0].getPosition().x == owocek.blok.getPosition().x
           and EntSnake.blok[0].getPosition().y == owocek.blok.getPosition().y) {
            owocek.blok.setFillColor(sf::Color(84, 82, 80));
            EntSnake.blocknumber += 1;
        }

            EntSnake.tick.restart();
    }
    for (int i = 0; i < EntSnake.blocknumber; ++i) {
        okno.draw(EntSnake.blok[i]);
    }

}





void snake::MoveSnake(sf::Event &event) {

    if (event.type == sf::Event::KeyPressed) {

        if (event.key.code == sf::Keyboard::Left) {
           direction.x=-1;
           direction.y=0;
        } else if (event.key.code == sf::Keyboard::Right) {
            direction.x=1;
            direction.y=0;

        } else if (event.key.code == sf::Keyboard::Up) {
            direction.x=0;
            direction.y=-1;

        } else if (event.key.code == sf::Keyboard::Down) {
            direction.x=0;
            direction.y=1;
        }
    }

}

float snake::getBlockSize() {
    return EntSnake.blocksize;
}

void snake::SetFruitPos(fruit &owocek) {
    owocek.size=EntSnake.blocksize;
    owocek.blok.setSize(sf::Vector2f(owocek.size,owocek.size));
    owocek.blok.setPosition(owocek.size*5,owocek.size*5);
}

bool snake::isCollision(sf::RectangleShape a, sf::RectangleShape b) {
    a.getGlobalBounds().intersects(b.getGlobalBounds());
    b.setPosition(sf::Vector2f(-100,-100));
}

void snake::DrawOwocek(sf::RenderWindow &okno, fruit &owocek) {
    SetFruitPos(owocek);
    okno.draw(owocek.blok);
}

void snake::ExpandSnake(bool isCol) {
    isCol==true;
    EntSnake.blocknumber+=3;
}