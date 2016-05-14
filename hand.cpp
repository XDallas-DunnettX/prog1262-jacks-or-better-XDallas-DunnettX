#include "hand.h"
#include "deck.h"
#include "card.h"
#include <map>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <sstream>

Hand::Hand()
{
    _bank = 100;
}

void Hand::addCard(CardPtr c)
{
    _hand.push_back(c);
}

std::string Hand::toString() const
{
    std::stringstream ss;
    for(auto c : _hand)
    {
        ss << *c << ", ";
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Hand& h)
{
    for (auto c : h._hand)
    {
        std::cout << *c << std::endl;
    }
    return os;
}

bool Hand::isPair()const
{
    std::map<Face,int> faces;
    for(auto e: _hand)
    {
        faces[e->face]++;
    }

    int count = std::count_if(faces.begin(), faces.end(), [](std::pair<Face,int> e){
            return (e.second == 2); // How many times a face value is found in hand.
});

    return (count == 1);// how many triplets found in hand.
}

bool Hand::isThreeOfKind()const
{
    std::map<Face,int> faces;
    for(auto e: _hand)
    {
        faces[e->face]++;
    }

    int count = std::count_if(faces.begin(), faces.end(), [](std::pair<Face,int> e){
            return (e.second == 3); // How many times a face value is found in hand.
});

    return (count == 1);// how many triplets found in hand.
}

bool Hand::isFourOfKind()const
{
    std::map<Face,int> faces;
    for(auto e: _hand)
    {
        faces[e->face]++;
    }

    int count = std::count_if(faces.begin(), faces.end(), [](std::pair<Face,int> e){
            return (e.second == 4); // How many times a face value is found in hand.
});

    return (count == 1);// how many triplets found in hand.
}

bool Hand::isFullHouse()const
{
    if(isThreeOfKind() && isPair())
    {
        return true;
    }
}

bool Hand::isTwoPair()const
{
    std::map<Face,int> faces;
    for(auto e: _hand)
    {
        faces[e->face]++;
    }

    int count = std::count_if(faces.begin(), faces.end(), [](std::pair<Face,int> e){
            return (e.second == 2); // How many times a face value is found in hand.
});

    return (count == 2);// how many triplets found in hand.
}

bool Hand::isStraight()const
{
    std::set<int> faces;

    for (int i = 0; i < _hand.size(); i++)
        faces.insert(static_cast<int>(_hand[i]->face));

    auto start = faces.begin();
    auto last = faces.end();
    last--;

    if (faces.size() == _hand.size())
    {

        if (*last == *start + (faces.size() - 1))  // lowest + highest card checking if cards are in order of value.
        {
            return true;
        }
        else if (*last == static_cast<int>(Face::ACE))  // Have an ace
        {
            faces.insert(0);
            last--;
            start = faces.begin();
            if (*last == *start - (_hand.size() - 1)) // lowest + highest card checking if cards are in order of value.
            {
                return true;
            }
        }
    }

    return false;   //returns false if no straight found.
}

bool Hand::isFlush()const
{
    std::set<Suit> suit;
    for (int i = 0; i != _hand.size(); i++)
        suit.insert(_hand[i]->suit);

    if (suit.size() == 1)
        return true;
    else
        return false;
}

bool Hand::isStraightFlush() const
{
    if ( isStraight() && isFlush())
        return true;
    else
        return false;
}

bool Hand::isRoyalFlush() const
{
    if(isStraightFlush())
    {
        if( (std::find_if(_hand.begin(), _hand.end(),[](CardPtr c){return (Face::ACE == c->face);} != _hand.end())) &&
             std::find_if(_hand.begin(), _hand.end(),[](CardPtr c){return (Face::KING == c->face);} != _hand.end()) )
        {
            return true;
        }

    }
    return false;
}

bool Hand::isJacksOrBetter() const
{

}

bool Hand::isHighCard() const
{
    std::set<int> faces;
    for (int i = 0; i < _hand.size(); i++)
    {
        faces.insert(static_cast<int>(_hand[i]->face));
    }
}

void Hand::clear()
{
    _hand.clear();
}

int Hand::size()
{
    return _hand.size();
}

void Hand::welcome()
{
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
                 "xx                        xx\n"
                 "xx        WELCOME         xx\n"
                 "xx                        xx\n"
                 "xxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
    std::cout << "Welcome to Jacks or better.\n In this game, you will be dealt 5 cards and essentially play a hand of poker." << std::endl;
}

void Hand::payTable()
{
    std::cout << "These are the payouts for the outcomes of winning hands!" << std::endl;
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
                 "xx Hand            xx pay xx\n"
                 "xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
                 "xx One Pair        xx   0 xx\n"
                 "xx Two Pair        xx   2 xx\n"
                 "xx Three of a kind xx   3 xx\n"
                 "xx Straight        xx   4 xx\n"
                 "xx Flush           xx   6 xx\n"
                 "xx FullHouse       xx   9 xx\n"
                 "xx Four of a kind  xx  25 xx\n"
                 "xx Straight Flush  xx  50 xx\n"
                 "xx Royal Flush     xx 250 xx\n"
                 "xxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
}

void Hand::checkHand()
{
    if(isPair())
    {
        std::cout << "Found a Pair!" << std::endl;

    }
    if(isThreeOfKind())
    {
        std::cout << "Found a Three of a kind!" << std::endl;
        _bank += 3;
        std::cout << "You win " << std::endl;
    }
    if(isFourOfKind())
    {
        std::cout << "Found a Four of a kind!" << std::endl;
        _bank += 25;
        std::cout << "You win " << std::endl;
    }
    if(isFullHouse())
    {
        std::cout << "Found a FullHouse!" << std::endl;
        _bank += 9;
        std::cout << "You win " << std::endl;
    }
    if(isTwoPair())
    {
        std::cout << "Found Two pairs!" << std::endl;
        _bank += 2;
        std::cout << "You win " << std::endl;
    }
    if(isStraight())
    {
        std::cout << "Found a Straight!" << std::endl;
        _bank += 4;
        std::cout << "You win " << std::endl;
    }
    if(isFlush())
    {
        std::cout << "Found a flush!" << std::endl;
        _bank += 6;
        std::cout << "You win " << std::endl;
    }
    if(isStraightFlush())
    {
        std::cout << "Found a StraightFlush!" << std::endl;
        _bank += 50;
        std::cout << "You win " << std::endl;
    }
    if(isRoyalFlush())
    {
        std::cout << "Found a RoyalStraight!" << std::endl;
        _bank += 250;
        std::cout << "You win " << std::endl;
    }
}

void Hand::play()
{
    Hand hand;
    Deck deck;
    deck.shuffle();
    for(int  i=0;i<5;++i)
    {
        hand.addCard(deck.draw());
        std::cout << hand.toString() << std::endl;

    }
    hand.checkHand();
}
//void Hand::hold()
//{
//    for (int i = 0; i < _hand.size(); i++)
//    {
//
//    }
//}
