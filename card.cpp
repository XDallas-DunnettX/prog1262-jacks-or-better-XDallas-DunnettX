#include "card.h"
#include <iostream>
#include <string>
#include <set>
#include <map>

std::string Card::toString() const
{
    return faceNames.at(face) + " of " + suitNames.at(suit);
}

const std::set<Suit> Card::suits
{
            Suit::CLUB,
            Suit::DIAMOND,
            Suit::HEART,
            Suit::SPADE,
};
const std::set<Face> Card::faces
{

            Face::TWO,
            Face::THREE,
            Face::FOUR,
            Face::FIVE,
            Face::SIX,
            Face::SEVEN,
            Face::EIGHT,
            Face::NINE,
            Face::TEN,
            Face::JACK,
            Face::QUEEN,
            Face::KING,
            Face::ACE
};
const std::map<Suit, std::string> Card::suitNames
{
            {Suit::CLUB,       "Clubs ♣"},
            {Suit::DIAMOND, "Diamonds ♦"},
            {Suit::HEART,     "Hearts ♠"},
            {Suit::SPADE,     "Spades ♥"}
};
const std::map<Face, std::string> Card::faceNames
{

            {Face::TWO,   "2"},
            {Face::THREE, "3"},
            {Face::FOUR,  "4"},
            {Face::FIVE,  "5"},
            {Face::SIX,   "6"},
            {Face::SEVEN, "7"},
            {Face::EIGHT, "8"},
            {Face::NINE,  "9"},
            {Face::TEN,  "10"},
            {Face::JACK,  "J"},
            {Face::QUEEN, "Q"},
            {Face::KING,  "K"},
            {Face::ACE,   "A"}
};


bool Card::operator<(const Card &r) const // Member Function.
{
    if(face < r.face)
    {
        return true;
    }
    if(face == r.face && suit < r.suit)
    {
        return true;
    }
    return false;
};

std::ostream& operator<<(std::ostream& os, const Card& c)
{
    os << Card::faceNames.at(c.face) << Card::suitNames.at(c.suit);
    return os;
}
