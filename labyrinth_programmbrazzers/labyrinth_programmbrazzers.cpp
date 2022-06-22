// labyrinth_programmbrazzers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML\Graphics.hpp>
#include "controller.h"
#include <time.h>
#include <cstdlib>
#include "dirActionCreator.hpp"
using namespace std;
int dx = 1;
int dy = 0;
Vector2i cases[2][4] = 
{ 
    {{0, 1}, {1, 0}, {0, -1}, {-1, 0} },
    {{-1, 0}, {1, 0}, {0, 1}, {0, -1} }
};
int k = 0;
Vector2i d  = {  1, 0 };
Vector2i db = { -1, 0 };
int main()
{
    srand(time(NULL));
    Controller a;
    
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
                {
                    a.step();
                    //a.find();
                    //  1  0 down
                    // -1  0 up
                    //  0 -1 left
                    //  0  1 right
                    //for (int i = 0; i < 100000/2; i++)
                    //{
                        //d = cases[0][rand() % 5];
                        //a.moveCrawler(d);
                        //a.updateCrawler();
                    //}
                    /*if (a.moveCrawler(d))
                    {
                        
                        if (k == 0)
                            k = rand() % 5;
                        counter++;
                        if (counter > 10)
                        {
                            counter = 0;
                            k--;
                        }
                    }
                    else if (!a.moveCrawler(d))
                    {
                        k = (k+1) % 5;
                        d = cases[0][k];
                        
                    }*/
                    
                    //if (a.moveCrawler({ dx, dy }) || (dx == 0 && dy == 0))
                    //{
                    //    dx = rand() % 3 - 1;
                    //    dy = rand() % 3 - 1;
                    //}
                }
            }
        }
        
            
        
        //a.moveCrawler();
        a.updateCrawler();
        a.draw();
        //cout << a.field.matrix[a.crawler.position.x][a.crawler.position.y].wall << endl;
        
    }
    return 0;
}
