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
        }

        a.draw();
    }
    return 0;
}
