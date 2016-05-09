//#include "mainwindow.h"
//#include <QApplication>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "hand.h"



int main()
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    int payout = 0;
    Deck deck;
    Hand hand;
    deck.shuffle();

    for(int  i=0;i<5;++i)
    {
        hand.addCard(deck.draw());
        std::cout << hand.toString() << std::endl;

    }
    if(hand.isPair())
    {
        std::cout << "Found a Pair!" << std::endl;

    }
    if(hand.isThreeOfKind())
    {
        std::cout << "Found a Three of a kind!" << std::endl;
        payout = 3;
        std::cout << "You win " << payout << std::endl;
    }
    if(hand.isFourOfKind())
    {
        std::cout << "Found a Four of a kind!" << std::endl;
        payout = 25;
        std::cout << "You win " << payout << std::endl;
    }
    if(hand.isFullHouse())
    {
        std::cout << "Found a FullHouse!" << std::endl;
        payout = 9;
        std::cout << "You win " << payout << std::endl;
    }
    if(hand.isTwoPair())
    {
        std::cout << "Found Two pairs!" << std::endl;
        payout = 2;
        std::cout << "You win " << payout << std::endl;
    }
    if(hand.isStraight())
    {
        std::cout << "Found a Straight!" << std::endl;
        payout = 4;
        std::cout << "You win " << payout << std::endl;
    }
    if(hand.isFlush())
    {
        std::cout << "Found a flush!" << std::endl;
        payout = 6;
        std::cout << "You win " << payout << std::endl;
    }
    if(hand.isStraightFlush())
    {
        std::cout << "Found a StraightFlush!" << std::endl;
        payout = 50;
        std::cout << "You win " << payout << std::endl;
    }
    if(hand.isRoyalStriaght())
    {
        std::cout << "Found a RoyalStraight!" << std::endl;
        payout = 250;
        std::cout << "You win " << payout << std::endl;
    }

    return 0;
}
