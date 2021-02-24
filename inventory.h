//inventory.h
//Header file for an Inventory class that utilises Modern C++ (c++11>=) features
//FEATURES:
//  - structured binding
//  - unordered_map
//  - templated variadic function (w/ recursion method)
//  - auto
//  - brace initialization
#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<string>
#include<unordered_map>



struct Item
{
    Item &operator=(const Item &);
    const std::string name;
    int amount;
};

class Inventory
{
public:
    Inventory(){};
    ~Inventory(){};

    //MEMBER TYPES
    using container_key = std::string;
    using container_element = Item;
    using container_type = std::unordered_map<container_key, container_element>;

///RECURSIVE TEMPLATED VARIADIC FUNCTION USE-CASE
public:
    //1-PARAM BASE CASE
    //[PRECOND] - "Args" must be the container_key type & struct Item.name type
    template<typename Args>
    void giveItems(const Args &param)
    {
        if(!isDigit(param))
        {
            ///brace initialization vs. make_pair/pair<,>
            _data.insert{param, {param,0} };
        }
    }

    //2-PARAM BASE CASE
    //[PRECOND] - "I" must be the container_key type & struct Item.name type
    //          - "Q" must be the struct Item.amount type
    template<typename I, typename Q>
    inline void giveItems(const I &itemName, const Q &quantity)
    {
        ///brace initialization vs. make_pair/pair<,>
        _data.insert({itemName, {itemName, quantity}});
    };

    //RECURSIVE CASE
    //[PRECOND] - "I" must be the container_key type & struct Item.name type
    //          - "Q" must be the struct Item.amount type
    //          - "Args" must have at least 2 params that are type
    //            "I" and "Q" consecutively.
    template <typename I, typename Q, typename... Args>
    void giveItems(const I &itemName, const Q &quantity, Args... otherItems)
    {
        giveItems(itemName, quantity);
        giveItems(otherItems...);
    };

    inline void setCurrItem(const std::string& itemName)
    {
        _currItem = getItem(itemName);
    }

    void printInventory()
    {
        ///structure binding
        for(const auto &[key, item] : _data)
        {
            std::cout << item.name << " (x" << item.amount << ")" << std::endl;
        }
    }

    inline bool itemObtained(const container_key& key)
    {
        auto invItr = _data.find(key);
        return invItr != _data.end();
    };

protected:
    container_element getItem(const std::string& itemName)
    {
        auto itr = _data.find(itemName);
        if(itr != _data.end())
        {
            auto& item = itr->second;
            return item;
        }
        else
        {
            return {"",0};
        }
    };

public:
    std::string _name;
private:
    container_element _currItem;
    container_type _data;
};

#endif //!INVENTORY_H