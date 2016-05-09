#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>
#include <memory>

struct Card;
using CardPtr = std::shared_ptr<Card>;

class Deck
{
public:
    Deck();

    void shuffle();

    CardPtr draw();
    bool isEmpty() const;
    void sort();
    CardPtr cut();
private:
    std::vector<CardPtr> _deck;
    int _topOfDeck;
};

#endif // DECK_H
