//
//  Deck.cpp
//  GUIGame
//
//  Created by max dietz on 9/17/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "Deck.hpp"

//Deck::Deck()
//{
////    _deck.reserve(52);
////    for (int i = 0; i < 52; ++i)
////    {
////        Card tmpCard;
////        _deck.push_back(tmpCard);
////    }
////    
////    int card = 0;
////    for (int suits = 0; suits < static_cast<int>(SUITS::MAX_SUITS); ++suits)
////    {
////        for (int ranks = 0; ranks < static_cast<int>(RANKS::MAX_RANKS); ++ranks)
////        {
////            _deck[card]._suit = static_cast<SUITS>(suits);
////            _deck[card]._rank = static_cast<RANKS>(ranks);
////        }
////    }
//}

void Deck::fillDeckWithCards()
{
    Deck deck;
    std::vector<Card> mydeck;
    
    mydeck.reserve(52);
    for (int i = 0; i < 52; ++i)
    {
        Card tmpCard;
        mydeck.push_back(tmpCard);
    }
    
    int card = 0;
    for (int suits = 0; suits < static_cast<int>(SUITS::MAX_SUITS); ++suits)
    {
        for (int ranks = 0; ranks < static_cast<int>(RANKS::MAX_RANKS); ++ranks)
        {
            mydeck[card]._suit = static_cast<SUITS>(suits);
            mydeck[card]._rank = static_cast<RANKS>(ranks);
            ++card;
        }
    }
    _deck = mydeck;
}

void Deck::shuffleDeck()
{
    for (int i = 0; i < 52; ++i)
    {
        std::swap(_deck.at(i), _deck.at(randomMersenne()));
        isShuffeled = true;
    }
}