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
        faces.insert((int)_hand[i]->face);

    auto start = faces.begin();
        auto last = faces.end();
            last--;

    if (faces.size() == 5)
    {

        if (*start == *last - (faces.size() - 1))
        {
            return true;
        }
        else if (*start == 0)
        {
            faces.insert(13);
            start++;
            last = faces.end();
            last--;
            if (*start == *last - (_hand.size() - 1))
            {
                return true;
            }
        }
        else {
            return false;
        }

    }
    else {
    return false;
    }
}


bool Hand::isFlush()const
{
    std::set<Suit> suit;
    for (int i = 0; i != _hand.size(); i++)
        suit.insert(_hand[i]->suit);

    if (suit.size() == 1)
        return true;
}
bool Hand::isStraightFlush() const
{
    std::set<Suit> suit;
    for(int i = 0; i != _hand.size(); i++)
    {
        suit.insert(_hand[i]->suit);
    }
    while(suit.size() == 1)
    {
        std::set<int> faces;

        for (int i = 0; i < _hand.size(); i++)
            faces.insert((int)_hand[i]->face);

        auto start = faces.begin();
            auto last = faces.end();
                last--;

        if (faces.size() == 5)
        {

            if (*start == *last - (faces.size() - 1))
            {
                return true;
            }
            else if (*start == 0)
            {
                faces.insert(13);
                start++;
                last = faces.end();
                last--;
                if (*start == *last - (_hand.size() - 1))
                {
                    return true;
                }
            }
            else {
                return false;
            }

        }
        else {
        return false;
        }
    }
}

bool Hand::isRoyalStraight()
{
    std::set<Suit> suit;
    for(int i = 0; i != _hand.size(); i++)
    {
        suit.insert(_hand[i]->suit);
    }
    while(suit.size() == 1)
    {

          std::set<int> faces;

          for (int i = 0; i < _hand.size(); i++)
              faces.insert((int)_hand[i]->face);

          auto start = faces.begin();
              auto last = faces.end();
                  last--;

          if (faces.size() == 5)
          {

              if (*start == *last - (faces.size() - 1))
              {
                  return true;
              }
              else if (*start == 0)
              {
                  faces.insert(13);
                  start++;
                  last = faces.end();
                  last--;
                  if (*start == *last - (_hand.size() - 1))
                  {
                      return true;
                  }
              }
              else {
                  return false;
              }

          }
          else {
          return false;
          }

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
