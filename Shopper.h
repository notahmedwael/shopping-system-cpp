#ifndef SHOPPER_H
#define SHOPPER_H
#include<bits/stdc++.h>
using namespace std;

class Item {
private:
    string item_name;
    float item_price;
public:
    Item(){}
    Item(const string& name, float price) : item_name(name), item_price(price) {}
    void printitem();
    friend class Shopper;
};
/*Item class header, defined private attributes name and price of the item,
It has a paremterized constructor that sets the name and price, also has a print method, and the function is friend to the class Shopper.*/
class Shopper {
private:
    string shopper_name;
    Item* purchased_items;
    int number_of_items;
    int count = 0;
    static int current_shoppers_total;
    static int shoppers_items_total;
    static float max_item_price;
    static string max_item_name;
    static string max_shopper_name;
public:
    friend class Item;
    Shopper(){}
    Shopper(const string& name, int num_of_items);
    Shopper(const Shopper& obj);
    ~Shopper();
    void buyitem(const string& item_name, float price);
    void print_shopper_content();
    void printmax();
    Shopper operator+(Shopper s2);
    Shopper& operator--();
    Shopper& operator--(int);
    friend ostream& operator<<(ostream& os,const Shopper& s);
    int get_current_shoppers_total();
    int get_shoppers_items_total();
    float get_max_item_price();
    string get_max_item_name();
    string get_max_shopper_name();
};
/*Shopper class header, defined private attributes shopper name, purchased items which is an object array of the class item, number of items the user is gonna buy,
the count of the items bought by the user which is set to 0 by default till changed also has static attributes which are meant to get the max shopper stats and also
total shoppers registered and also total of items bought. The class has public mehods an empty constructor, a paremeterized constructor, and a copy constructor, also has a destructor.
The class also has methods to print shopper content, max stats, and has overloaded operators for -- (prefix and postfix), << and also +
The class has getter that get current shoppers total, shoppers item total, max item price, max item name, and max shopper name.
*/
#endif