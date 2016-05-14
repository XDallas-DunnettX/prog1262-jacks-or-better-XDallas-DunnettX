#ifndef CARD_H
#define CARD_H


#include <string>
#include <set>
#include <map>

enum class Suit{CLUB = 1, DIAMOND, HEART, SPADE};
enum class Face{TWO = 1,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE};

struct Card
{
    Card(Face f, Suit s) : face(f), suit(s){}
    const Suit suit;
    const Face face;
    std::string toString() const;

    bool operator<(const Card& r)const;
    friend std::ostream& operator<<(std::ostream& os, const Card& c);

    //class members
    static const std::set<Suit> suits;
    static const std::set<Face> faces;

    static const std::map<Suit, std::string> suitNames;
    static const std::map<Face, std::string> faceNames;
};

std::ostream& operator<<(std::ostream& os, const Card& c);

#endif // CARD_H
