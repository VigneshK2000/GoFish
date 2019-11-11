#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main() {

    Card c1;
    cout << c1.toString() << endl;
    Card c3;
    cout << c1.sameSuitAs(c3) << endl;

    Card c2(11, Card::Suit(0));

    cout << c2.getRank() << endl;

    cout << c2.toString() << endl;

    Deck d;
    d.shuffle();

    Card test;
    test = d.dealCard();
    cout << test;

    return 0;
}