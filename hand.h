#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include <memory>
#include <card.h>
#include <iostream>

struct Card;
using CardPtr = std::shared_ptr<Card>;

class Hand
{
public:
    Hand();
    void addCard(CardPtr);
    std::string toString() const;

    bool isPair()const;
    bool isThreeOfKind()const;
    bool isFourOfKind()const;
    bool isFullHouse()const;
    bool isTwoPair()const;
    bool isStraight()const;
    bool isFlush()const;
    bool isStraightFlush() const;
    bool isRoyalFlush()const;
    bool isJacksOrBetter() const;
    bool isHighCard() const;
    void clear();
    int size();
    friend std::ostream& operator<<(std::ostream& os, const Hand& h);
    void checkHand();
    void welcome();
    void payTable();
    void play();
    //void hold();


private:
    std::vector <CardPtr> _hand;
    int _bank = 0;
};

std::ostream& operator<<(std::ostream& os, const Hand& h);
#endif // HAND_H
