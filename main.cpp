//main.cpp
//Driver for Engine class and Inventory class
#include "inventory.h"
#include "engine.h"

int main()
{
    Engine game;
    game.init();

    while(game.getState() != Engine::State::END)
    {
        game.run();

        if(game._isOver)
            game.exit();
    }

    std::cout << "Game ended!" << std::endl;
    std::cout << "Press a key to exit." << std::endl;
    std::cin.get();
    return 0;
};