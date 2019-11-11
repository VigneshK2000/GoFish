//
// Created by kvigg on 11/10/2019.
//
#include "deck.h"
#include <iostream>
#include <string>
#include <ctime>


using namespace std;

Deck::Deck() {
    srand(time(NULL));

    myIndex = 0;
    for(int i = 1; i <= 13; i++){
        for(int j = 0; j <= 3; j++){
            myCards[myIndex] = Card(i, Card::Suit(j));
            myIndex += 1;
        }
    }
    myIndex = 0;
}

void Deck::shuffle() {

    for(int i = 0; i <20 ; i++) {
        int r = rand() % 52;
        int s = rand() % 52;
        Card temp;
        temp = myCards[r];
        myCards[r] = myCards[s];
        myCards[s] = temp;
    }

}

Card Deck::dealCard() {
    Card temp = myCards[0];
    myIndex += 1;
    return temp;
}

int Deck::size() const {
    return 52 - myIndex;
}
