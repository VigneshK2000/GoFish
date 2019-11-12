#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <fstream>

using namespace std;

int main() {
    ofstream myfile("gofish_results.txt");
    Player p1("Vignesh");
    Player p2("Tejal");

    Deck d;
    d.shuffle();
    int handSizep1 = 0;
    int handSizep2 = 0;


    for (int i = 0; i <7 ; i++) {
        p1.addCard(d.dealCard());
        handSizep1 ++;
    }
    myfile << p1.getName() << " has: " << p1.showHand() << endl;

    for (int i = 0; i <7 ; i++) {
        p2.addCard(d.dealCard());
        handSizep2++;
    }

    while(d.size() > 0) {

        myfile << p2.getName() << " has: " << p2.showHand() << endl;
        Card m = p2.chooseCardFromHand();
        int r = m.getRank();

        myfile << p2.getName() << " asks - Do you have a " << m.rankString(r) << "?" << endl;

        bool result = p1.cardInHand(m);

        if (result) {
            myfile << p1.getName() << " says - Yes. I have a " << m.rankString(r) << endl;
            Card outputp1 = p1.removeCardFromHand(m);
            handSizep1--;
            Card outputp2 = p2.removeCardFromHand(m);
            p2.bookCards(outputp1, outputp2);
            handSizep2--;
            myfile << p2.getName() << " books " << p2.showBooks() << endl;
        } else {
            myfile << p1.getName() << " says - Go Fish" << endl;
            Card draw = d.dealCard();
            p2.addCard(draw);
            myfile << p2.getName() << " draws " << draw << endl;
            handSizep2++;

        }

        // second player turn

        myfile << p1.getName() << " has: " << p1.showHand() << endl;

        myfile << p2.getName() << " has: " << p2.showHand() << endl;
        Card n = p1.chooseCardFromHand();
        int a = n.getRank();

        myfile << p1.getName() << " asks - Do you have a " << n.rankString(a) << "?" << endl;

        bool res = p2.cardInHand(n);

        if (res) {
            myfile << p2.getName() << " says - Yes. I have a " << n.rankString(a) << endl;
            Card outputp2 = p2.removeCardFromHand(n);
            handSizep2--;
            Card outputp1 = p1.removeCardFromHand(n);
            handSizep1--;
            p1.bookCards(outputp1, outputp2);
            myfile << p1.getName() << " books " << p1.showBooks() << endl;
        } else {
            myfile << p2.getName() << " says - Go Fish" << endl;
            Card draw = d.dealCard();
            p1.addCard(draw);
            myfile << p1.getName() << " draws " << draw << endl;
            handSizep1++;
        }

        if(handSizep1 == 0 || handSizep2 == 0){
            p1.addCard(d.dealCard());
            handSizep1++;
            p2.addCard(d.dealCard());
            handSizep2++;
        }
    }

    myfile << endl;
    myfile << endl;

    myfile << "Deck empty" << endl;

    myfile << p1.getName() << " books:" << p1.showBooks() << endl;
    myfile << p2.getName() << " books:" << p2.showBooks() << endl;

    int p1book = p1.getBookSize();
    int p2book = p2.getBookSize();

    if(p1book > p2book){
        myfile << p1.getName() << " wins!" << endl;
    }
    else if(p2book > p1book){
        myfile << p2.getName() << " wins!" << endl;
    } else {
        myfile << "Tie!" << endl;
    }

    myfile.close();

    return 0;
}