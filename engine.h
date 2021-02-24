//engine.h
//Header for a simple Engine class utilising the Inventory class
#ifndef ENGINE_H
#define ENGINE_H

#include "inventory.h"

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
        _worldInv._name = "World";
        _worldInv.giveItems("apple", 10,
                            "rock", 14,
                            "sticks", 7,
                            "armor", 1,
                            "lasersword", 1,
                            "coins", 100);
        std::cout << "Items given to " << _worldInv._name << "!" << std::endl;
        _playerInv._name = "Player";
        _playerInv.giveItems("apple", 4);
        _playerInv.giveItems("sword", 1);
        std::cout << "Items given to " << _playerInv._name << "!" << std::endl;

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
        {
            _isOver = true;
            return;
        }
        
        std::cout << "\nThe Player has these items: " << std::endl;
        _playerInv.printInventory();
        std::cout << "\nThese items still exist in the world: " << std::endl;
        _worldInv.printInventory();
        std::cout << std::endl;

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

#endif //!ENGINE_H
