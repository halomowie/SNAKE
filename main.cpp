#include <iostream>
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "GameManager.h"
int main() {
    srand( time( NULL ) );
    // create the window
    sf::RenderWindow okno(sf::VideoMode(950, 600, 32), "Snake");
    //ark.setVerticalSyncEnabled(true);
    okno.setFramerateLimit(60);
    fruit pomarancza;
    snake wunsz(okno, pomarancza);
    GameManager mgr(wunsz,pomarancza);

    // run the program as long as the window is open
    while (okno.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (okno.pollEvent(event))
        {
            wunsz.MoveSnake(event);
            mgr.restartGame(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                okno.close();
            else if(event.key.code == sf::Keyboard::Escape)
                okno.close();
        }

        // clear the window with black color
        okno.clear(sf::Color(0,0,0));

        // draw everything here...
        wunsz.DrawOwocek(okno,pomarancza);
        wunsz.DrawSnake(okno,pomarancza);
        mgr.drawGameManager(okno);

        // end the current frame
        okno.display();
    }

    return 0;
}