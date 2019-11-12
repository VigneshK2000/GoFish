#include "deck.h"
#include "player.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <stdlib.h>


using namespace std;

Player::Player() {
    srand(time(NULL));
    myName = "Agatha";

}

void Player::addCard(Card c) {
    myHand.push_back(c);

}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);

}

bool Player::cardInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++){
        if (c.getRank() == myHand[i].getRank()){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {

    for(vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
       if ((*it).getRank() == c.getRank()){

            Card temp = *it;
            myHand.erase(it);
            return temp;
        }
    }
    return c;
}

string Player::showHand() const {
    string Hand;
    for(int i = 0; i < myHand.size(); i++){
        Hand += myHand[i].toString();
    }
    return Hand;
}

string Player::showBooks() const {
    string Books;
    for(int i = 0; i < myBook.size(); i++){
        Books += myBook[i].toString();
    }
    return Books;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

Card Player::chooseCardFromHand() const {
    int q = rand() % myHand.size();
    return myHand[q];
}
