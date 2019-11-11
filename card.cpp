#include "card.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const{
    return (c.mySuit == this->mySuit);
}

int Card::getRank()const{
    return this->myRank;
}

string Card::suitString(Card::Suit s) const {
    string str1;
    switch(s)
    {
        case 2:
            str1 = "d";
            break;
        case 0:
            str1 = "s";
            break;
        case 3:
            str1 = "c";
            break;
        case 1:
            str1 = "h";
            break;
    }
    return str1;
}

string Card::rankString(int r) const {
    string rank;

    switch (r) {
        case 1:
            rank = "A";
            break;
        case 11:
            rank = "J";
            break;
        case 12:
            rank = "Q";
            break;
        case 13:
            rank = "K";
            break;
        default:
            break;
    }

    return rank;
}

bool Card::operator == (const Card& rhs) const{
    return (myRank == rhs.myRank);
}
bool Card::operator != (const Card& rhs) const{
    return (myRank != rhs.myRank);
}

ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}