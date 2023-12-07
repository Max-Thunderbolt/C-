#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(int w, int h, string chars)
{
    this->map = new Map(w, h);
    this->player = NULL;

    for (int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == '#')
        {
            this->map->add(new Wall(i % w, i / w));
        }
        else if (chars[i] == '.')
        {
            this->map->add(new Floor(i % w, i / w));
        }
        else if (chars[i] == '&')
        {
            this->player = new Player(i % w, i / w);
            this->player->below = new Floor(i % w, i / w);
            this->player->below->above = this->player;
            this->map->add(this->player->below);
        }
    }
}

Game::~Game()
{
    delete this->player;
    delete this->map;
}

string Game::display()
{
    return this->map->print();
}

void Game::update(char input)
{
    int x = this->player->getCoord(0);
    int y = this->player->getCoord(1);

    int c = input;

    switch (c)
    {
    case 1: // Diagonally down and left
        this->player->move(-1, 1);

    case 2: // Down
        this->player->move(0, 1);

    case 3: // Diagonally down and right
        this->player->move(1, 1);

    case 4: // Left
        this->player->move(-1, 0);

    case 5: // Stay

    case 6: // Right
        this->player->move(1, 0);

    case 7: // Diagonally up and left
        this->player->move(-1, -1);

    case 8: // Up
        this->player->move(0, -1);

    case 9: // Diagonally up and right
        this->player->move(1, -1);
    }
}