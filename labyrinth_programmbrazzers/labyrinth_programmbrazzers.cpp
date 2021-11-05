// labyrinth_programmbrazzers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML\Graphics.hpp>
#include "controller.h"

using namespace std;

int main()
{
    Controller a;
    
    while (a.status())
    {
        sf::Event event;
        while (a.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                a.window.close();
            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::W)
                    a.crawler.moveUp();
                if (event.key.code == Keyboard::A)
                    a.crawler.moveLeft();
                if (event.key.code == Keyboard::S)
                    a.crawler.moveDown();
                if (event.key.code == Keyboard::D)
                    a.crawler.moveRight();
            }
        }
        
            
        a.updateCrawler();
        a.draw();
    }
    return 0;
}
