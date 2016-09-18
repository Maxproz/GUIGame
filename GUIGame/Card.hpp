//
//  Card.hpp
//  GUIGame
//
//  Created by max dietz on 9/17/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <iostream>

enum class SUITS
{
    SUIT_HEART,
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_SPADE,
    MAX_SUITS
};

enum class RANKS
{
    RANK_TWO,
    RANK_THREE,
    RANK_FOUR,
    RANK_FIVE,
    RANK_SIX,
    RANK_SEVEN,
    RANK_EIGHT,
    RANK_NINE,
    RANK_TEN,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};

class Card
{
private:
public:
    SUITS _suit;
    RANKS _rank;
};

// Helper functions for cards.
void swapCard(Card& card1, Card& card2);
std::ostream& operator<<(std::ostream& os, const Card& r);

#endif /* Card_hpp */
