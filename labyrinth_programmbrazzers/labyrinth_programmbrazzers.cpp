// labyrinth_programmbrazzers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML\Graphics.hpp>
#include "cell.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(810, 610), "Labyrinth");
    Texture background_texture;
    background_texture.loadFromFile("graphics/background.png");
    Sprite background_sprite(background_texture);
    background_sprite.setPosition(0, 0);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        window.draw(background_sprite);
        window.display();
    }

    return 0;
}
