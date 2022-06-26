// labyrinth_programmbrazzers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML\Graphics.hpp>
#include "controller.h"
#include <time.h>
#include <cstdlib>
#include "rightHand.h"
#include "left_hand.h"
using namespace std;

int main()
{
    srand(time(NULL));
    Controller a;
    //a.setStrategy(new RightHand);
    Clock clock;
    while (a.status())
    {
        Time time = clock.restart();
        sf::Event event;
        int counter = 0;
        while (a.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                a.window.close();
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::W)
                    a.moveCrawler(a.actions.UpActionCreator());
                    //a.crawler.moveUp();
                if (event.key.code == Keyboard::A)
                    a.moveCrawler(a.actions.LeftActionCreator());
                    //a.crawler.moveLeft();
                if (event.key.code == Keyboard::S)
                    a.moveCrawler(a.actions.DownActionCreator());
                    //a.crawler.moveDown();
                if (event.key.code == Keyboard::D)
                    a.moveCrawler(a.actions.RightActionCreator());
                    //a.crawler.moveRight();
                if (event.key.code == Keyboard::Space) 
                    a.step();
                if (event.key.code == Keyboard::Num1)
                    a.setStrategy(new RightHand);
                if (event.key.code == Keyboard::Num2)
                    a.setStrategy(new LeftHand);
            }
        }
        
            
        
        //a.moveCrawler();
        a.updateCrawler();
        a.draw();
        //cout << a.field.matrix[a.crawler.position.x][a.crawler.position.y].wall << endl;
        
    }
    return 0;
}
