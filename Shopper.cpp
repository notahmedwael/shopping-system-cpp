#include "shopper.h"
#include <bits/stdc++.h>
using namespace std;
// Defining static variables from Shopper class.
int Shopper :: current_shoppers_total = 0;
int Shopper :: shoppers_items_total = 0;
float Shopper :: max_item_price = 0;
string Shopper::max_item_name = "Nothing yet";
string Shopper :: max_shopper_name = "No One Yet";
//Method to print the items.
void Item::printitem() {
    cout << "--> " << item_name << ": " << item_price << endl;
}
// Paremetrized constructor that sets the name of the shopper and number of items that he can buy.
Shopper::Shopper(const string& name, int num_of_items) : shopper_name(name), number_of_items(num_of_items), count(0){
    
    purchased_items = new Item[number_of_items];
    current_shoppers_total++;
}
// Copy constructor that copies content of a shopper to antoher shopper.
Shopper::Shopper(const Shopper& obj) {
    shopper_name = obj.shopper_name;
    number_of_items = obj.number_of_items;
    count = obj.count;
    purchased_items = new Item[number_of_items];
    for (int i = 0; i < count; i++) {
        purchased_items[i] = obj.purchased_items[i];
    }
    current_shoppers_total++;
}
//Destructor that frees memory and decreases number of active shoppers.
Shopper::~Shopper() {
    delete[] purchased_items;
    current_shoppers_total--;
}
// Method that allows shopper to buy items to be added to the cart, also increments number of bought items by shopper 
// and the total items in the system are incremented.
void Shopper::buyitem(const string& item_name, float price) {
    if (count >= number_of_items) {
        cout << "Sorry, " << shopper_name << " you have reached your buy limit of " << number_of_items << " items!" << endl;
    } else {
        if (max_item_price < price) {
            max_item_price = price;
            max_item_name = item_name;
            max_shopper_name = this->shopper_name;
        }
        purchased_items[count] = Item(item_name, price);
        count++;
        cout << item_name << " added to "<< shopper_name << "'s cart successfully!" << endl;
        cout << endl;
        shoppers_items_total++;
    }
}
// Method that prints content of the shopper by calling the print item from item class method upon each shopper's cart.
void Shopper::print_shopper_content() {
    cout << "Shopper Name: " << shopper_name << endl << "Purchased items: " << endl;
    for (int i = 0; i < count; i++) {
        purchased_items[i].printitem();
    }
    cout << endl;
}
// Mehod that prints most expensive item with its name, and also who bought it.
void Shopper::printmax() {
    cout << "Most expensive Item: " << max_item_name << ", Bought by: " << max_shopper_name << ", Bought for: " << max_item_price << endl;
}
// Overloading + constructor to add two objects' content into a third object, the method skips if the cart has empty items.
Shopper Shopper::operator+(Shopper s2) {
    Shopper s3("Grouped Shopper", count + s2.count);
    for (int i = 0; i < number_of_items; i++) {
        if (purchased_items[i].item_price == 0) {
            continue;
        }
        s3.buyitem(purchased_items[i].item_name, purchased_items[i].item_price);
    }
    for (int i = 0; i < s2.number_of_items; i++) {
        if (s2.purchased_items[i].item_price == 0) {
            continue;
        }
        s3.buyitem(s2.purchased_items[i].item_name, s2.purchased_items[i].item_price);
    }
    shoppers_items_total += s3.count;
    return s3;
    }
// Overloading postfix -- operator to remove an item from the shopper's cart by index entered by user.
    Shopper& Shopper::operator--() {
    int index;
    cout << "Enter index of the item to be deleted (The first index is 0): " << endl;
    cin >> index;    
    if (count > 0){
        if (index >= 0 && index <= count)
        {
            count--;
        for (int i = index; i < number_of_items - 1; i++) {
            purchased_items[i] = purchased_items[i+1];
        }
        shoppers_items_total--;
        }
        else{
        cout << "Invalid index." << endl;
        }
    }else {
        cout << "The cart is empty, you can't remove items from it." << endl;
    }
    return *this;
    }
// Overloading prefix -- operator to do the same job as the postfix one 
// (There is no difference in the implementation, just doing it so it can be called like this: "s--" or "--s")    
    Shopper& Shopper::operator--(int) {
        int index;
    cout << "Enter index of the item to be deleted (The first index is 0): " << endl;
    cin >> index;    
    if (count > 0){
        if (index >= 0 && index <= count)
        {
            count--;
        for (int i = index; i < number_of_items - 1; i++) {
            purchased_items[i] = purchased_items[i+1];
        }
        shoppers_items_total--;
        }
        else{
        cout << "Invalid index." << endl;
        }
    }else {
        cout << "The cart is empty, you can't remove items from it." << endl;
    }
    return *this;
    }
// Overloading the << operator to print the content of the shopper's items.    
    ostream& operator<<(ostream& os, const Shopper& s) {
    if (s.count == 0) {
        os << "The cart is empty, nothing to print.";
    }
    else {
        os << "Shopper name: " << s.shopper_name << endl;
        os << "Purchased items: " << endl;
        for (int i = 0; i < s.count; i++) {
            s.purchased_items[i].printitem();
        }
    }
    os << endl;
    return os;
    }
// Getter method that return the current total shoppers active on the system.    
    int Shopper::get_current_shoppers_total(){
        return current_shoppers_total;
    }
// Getter method that returns the current total items of the whole shoppers on the system.    
    int Shopper::get_shoppers_items_total(){
        return shoppers_items_total;
    }
// Getter method that returns the most expensive item price.
    float Shopper::get_max_item_price(){
        return max_item_price;
    }
// Getter method that returns the most expensive item name.    
    string Shopper::get_max_item_name(){
        return max_item_name;
    }
// Getter method that returns the most expensive item buyer.    
    string Shopper::get_max_shopper_name(){
        return max_shopper_name;
    }