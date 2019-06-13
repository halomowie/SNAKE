//
// Created by Daniel on 05.06.2019.
//

#include "snake.h"

snake::snake(sf::RenderWindow &temp1, fruit &temp): okno(temp1), owocek(temp)  {

    movespace=30;
    randVal=movespace;
    plansza.size.x = okno.getSize().x;
    plansza.size.y = okno.getSize().y;
    EntSnake.blocksize=plansza.size.y/movespace;
    moveVal=EntSnake.blocksize;
    for (int i = 1; i < randVal*randVal; ++i) {
        EntSnake.blok[i].setSize(sf::Vector2f(EntSnake.blocksize,EntSnake.blocksize));
        EntSnake.blok[i].setFillColor(sf::Color(160, 8, 8));
    }


    EntSnake.blok[0].setSize(sf::Vector2f(EntSnake.blocksize,EntSnake.blocksize));
    EntSnake.blok[0].setFillColor(sf::Color(98, 66, 188));

    owocek.size=EntSnake.blocksize;
    owocek.blok.setRadius(owocek.size/2);


    setupGameStart();




}

void snake::DrawSnake(sf::RenderWindow &okno, fruit &owocek) {

    collisionWalls();
    collisionWithSelf();
    sf::Vector2f pos[randVal*randVal];
    if(GameState==RUNNING) {
        if (EntSnake.tick.getElapsedTime().asMilliseconds() > speed) {
            for (int i = 0; i < EntSnake.blocknumber - 1; ++i) {
                pos[i] = EntSnake.blok[i].getPosition();
            }
            EntSnake.blok[0].move(sf::Vector2f(EntSnake.blocksize * direction.x, EntSnake.blocksize * direction.y));
            for (int i = 0; i < EntSnake.blocknumber - 1; ++i) {
                EntSnake.blok[i + 1].setPosition(pos[i]);
            }
            if (EntSnake.blok[0].getPosition().x == owocek.blok.getPosition().x
                and EntSnake.blok[0].getPosition().y == owocek.blok.getPosition().y) {
                EntSnake.blocknumber += 1;
                if (EntSnake.blocknumber % 5 == 0) {
                    speed -= speed * 0.1;
                }
                owocek.blok.setPosition(owocek.size * (std::rand() % randVal), owocek.size * (std::rand() % randVal));
                for (int j = 0; j < 100; ++j) {
                    if (owocek.blok.getPosition() == EntSnake.blok[j].getPosition()) {
                        owocek.blok.setPosition(owocek.size * (std::rand() % randVal),
                                                owocek.size * (std::rand() % randVal));
                    }
                }

            }

            EntSnake.tick.restart();
        }
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




void snake::DrawOwocek(sf::RenderWindow &okno, fruit &owocek) {
    okno.draw(owocek.blok);
}


float snake::getMoveSpace() {
    return movespace;
}

int snake::getSnakeSize() {
    return EntSnake.blocknumber;
}

sf::Vector2f snake::getBoardSize() {

}

GS snake::getGameState() {
    return GameState;
}

void snake::collisionWithSelf() {
    for (int i = 1; i < EntSnake.blocknumber ; ++i) {
        if (EntSnake.blok[0].getPosition() == EntSnake.blok[i].getPosition()){
            GameState=FINISHED;
        }
    }
}

void snake::collisionWalls() {
    if(EntSnake.blok[0].getPosition().x<0
            or EntSnake.blok[0].getPosition().x> EntSnake.blocksize*movespace
            or EntSnake.blok[0].getPosition().y> EntSnake.blocksize*movespace
            or EntSnake.blok[0].getPosition().y<0){
        GameState=FINISHED;
    }
}

void snake::setupGameStart() {
    speed=150;
    EntSnake.blocknumber=3;
    direction.x=0;
    direction.y=-1;
    EntSnake.blok[0].setPosition(sf::Vector2f(10*EntSnake.blocksize,10*EntSnake.blocksize));
    EntSnake.blok[1].setPosition(sf::Vector2f(10*EntSnake.blocksize,11*EntSnake.blocksize));
    EntSnake.blok[2].setPosition(sf::Vector2f(10*EntSnake.blocksize,12*EntSnake.blocksize));
    for (int k = EntSnake.blocknumber; k <randVal*randVal ; ++k) {
        EntSnake.blok[k].setPosition(sf::Vector2f(-100,-100));

    }
    owocek.blok.setPosition(owocek.size*(std::rand() % randVal),owocek.size*(std::rand()% randVal));
    for (int j = 0; j < EntSnake.blocknumber; ++j) {
        if(owocek.blok.getPosition()==EntSnake.blok[j].getPosition()){
            owocek.blok.setPosition(owocek.size*(std::rand() % randVal),owocek.size*(std::rand()% randVal));
        }
    }

    GameState=RUNNING;

}