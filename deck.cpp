#include "deck.h"
#include <card.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>


Deck::Deck()
{
    srand(unsigned(time(0)));
    for(auto f : Card::faces)
    {
        for(auto s : Card::suits)
        {
            _deck.push_back(std::make_shared<Card>(Card(f,s)));
        }
    }
     _topOfDeck = static_cast<int>(_deck.size()-1);
}

void Deck::shuffle()
{
    for(int i = 0; i < _deck.size();++i)
    {
        swap(_deck[i],_deck[i + rand() % _deck.size() - i]);
    }
    _topOfDeck = static_cast<int>(_deck.size()-1);
}
CardPtr Deck::draw()
{
    return _deck.at(_topOfDeck--);
}
CardPtr Deck::cut()
{
    return _deck[rand() % _deck.size()];
}

bool Deck::isEmpty() const
{

    return (_topOfDeck < 0);

}
void Deck::sort()
{
    std::sort(_deck.begin(), _deck.end(), [](CardPtr lhs, CardPtr rhs){return(*lhs < *rhs);});
}
