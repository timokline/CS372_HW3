//modernc++.h
//Header file for an Inventory class that utilises Modern C++ (c++11>=) features
#include<unordered_map>
#include<string>


struct Item
{
    Item &Item::operator=(const Item &);
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
    template<typename I, typename Q>
    void giveItems(const I &itemName, const Q &quantity)
    {

    };

    template <typename I, typename Q, typename... Args>
    void giveItems(const I &itemName, const Q &quantity, Args... otherItems)
    {
        giveItems(itemName, quantity);
        giveItems(otherItems...);
    };

    void setCurrItem(const std::string &itemName)
    {
        _currItem = getItem(itemName);
    }

    void itemObtained()
    {};

protected:
    container_element getItem(const std::string &itemName)
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

private:
    container_element _currItem;
    container_type _data;
};