//
//  Card.cpp
//  GUIGame
//
//  Created by max dietz on 9/17/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "Card.hpp"
#include "MPErrors.hpp"

void swapCard(Card& card1, Card& card2)
{
    Card tmp;
    tmp = card1;
    card1 = card2;
    card2 = tmp;
}

std::ostream& operator<<(std::ostream& os, const Card& r)
{
    using namespace std;
    switch (r._rank)
    {
        case RANKS::RANK_TWO:    os << "2";  break;
        case RANKS::RANK_THREE:  os << "3";  break;
        case RANKS::RANK_FOUR:   os << "4";  break;
        case RANKS::RANK_FIVE:   os << "5";  break;
        case RANKS::RANK_SIX:    os << "6";  break;
        case RANKS::RANK_SEVEN:  os << "7";  break;
        case RANKS::RANK_EIGHT:  os << "8";  break;
        case RANKS::RANK_NINE:   os << "9";  break;
        case RANKS::RANK_TEN:    os << "10"; break;
        case RANKS::RANK_JACK:   os << "J";  break;
        case RANKS::RANK_QUEEN:  os << "Q";  break;
        case RANKS::RANK_KING:   os << "K";  break;
        case RANKS::RANK_ACE:    os << "A";  break;
        default:
            error("Unable to process Rank of card");
    }
    
    switch (r._suit)
    {
        case SUITS::SUIT_SPADE:     os << "S"; break;
        case SUITS::SUIT_CLUB:      os << "C"; break;
        case SUITS::SUIT_DIAMOND:   os << "D"; break;
        case SUITS::SUIT_HEART:     os << "H"; break;
        default:
            error("Unable to process Suit of card");
    }
    
    
    return os;
}


