#include "Shopper.h"
#include "Shopper.cpp"
#include <bits/stdc++.h>
using namespace std;
int main(){
    /*
    Shopper Moh("Mohamed", 5);
    Moh.buyitem("Candy", 12);
    Moh.buyitem("Chips", 3);
    Moh.buyitem("Chocolate", 10);
    Moh.buyitem("Cake", 20);
    Moh.print_shopper_content();
    cout << Moh;
    Shopper Ahm("Ahmed", 4);
    Ahm.buyitem("Bataes", 20);
    Ahm.buyitem("Chips", 23);
    Ahm.buyitem("Chocobars", 12);
    Ahm.buyitem("Kite", 30);
    Ahm.print_shopper_content();
    cout << Ahm;
    Shopper Israa = Ahm + Moh;
    Israa.print_shopper_content();
    cout << "Total current shoppers count: "<< Israa.get_current_shoppers_total() << endl;
    cout << "Total shoppers items count: " << Israa.get_shoppers_items_total() << endl;
    Israa.printmax();
    Ahm--;
    Ahm.print_shopper_content();*/
    Shopper one("First", 3);
    one.buyitem("Candy", 12);
    one.buyitem("Fruits", 10);
    one.buyitem("Chips",15);
    one.print_shopper_content();
    Shopper two(one);
    two.print_shopper_content();
    two--;
    two.print_shopper_content();
    --one;
    one.print_shopper_content();
    Shopper three = one + two;
    three.print_shopper_content();
    cout << "Total shoppers on the system: " << three.get_current_shoppers_total() << endl;
    cout << "Total items bought by all users: " << two.get_shoppers_items_total() << endl;
    one.printmax();
    cout << one;
    cout << two;
    cout << three;
    return 0;
}