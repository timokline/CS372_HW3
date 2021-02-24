//modernc++.h
//Header file for an Inventory class that utilises Modern C++ (c++11>=) features
#include<unordered_map>
#include<string>


struct Item
{
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

public:
    container_element getItem(std::string itemName)
    {
        return {"",0};
    };
    void giveItem(std::string itemName, int quantity)
    {};
    void itemObtained()
    {};

private:
    container_element _currItem;
    container_type _data;
};