#include<iostream>

#include "modernc++.h"

class Engine
{
public:
    Engine(){};
    ~Engine(){};
public:
    enum class State{END, START, RUNNING, IDLE};
public:
    void init()
    {
        _worldInv.giveItems("apple", 10,
                            "rock", 14,
                            "sticks", 7,
                            "armor", 1,
                            "lasersword", 1,
                            "coins", 100);
        _playerInv.giveItems("apple", 4);
        _playerInv.giveItems("sword", 1);

        _currState = State::START;
        std::cout << "Game start!" << std::endl;
    }

    void run()
    {
        if(_currState == State::START)
        {
            _currState = State::RUNNING;
            std::cout << "Game running!" << std::endl;
        }
        else
            _isOver = true;
        //auto& itr = _playerInv.find("lasersword");
        //if(itr != _playerInv.end())
        _currState = State::IDLE;
    }

    void exit()
    {
        _currState = State::END;
        std::cout << "Game exiting!" << std::endl;
    }

    State getState()
    {
        return _currState;
    }

public:
    bool _isOver = false;
private:
    State _currState = State::IDLE;
    Inventory _worldInv;
    Inventory _playerInv;
};

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
    return 0;
};