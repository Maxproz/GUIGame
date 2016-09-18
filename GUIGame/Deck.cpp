//
//  Deck.cpp
//  GUIGame
//
//  Created by max dietz on 9/17/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "Deck.hpp"

Deck::Deck()
{
    for (int suits = 0; suits < static_cast<int>(SUITS::MAX_SUITS); ++suits)
    {
        for (int ranks = 0; ranks < static_cast<int>(RANKS::MAX_RANKS); ++ranks)
        {
            Card tmpCard;
            tmpCard._suit = static_cast<SUITS>(suits);
            tmpCard._rank = static_cast<RANKS>(ranks);
            _deck.push_back(tmpCard);
        }
    }
}

void Deck::shuffleDeck()
{
    for (int i = 0; i < 52; ++i)
    {
        std::swap(_deck.at(i), _deck.at(randomMersenne()));
        isShuffeled = true;
    }
}