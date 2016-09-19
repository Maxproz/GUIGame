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
    _deck.reserve(52);
    for (int i = 0; i < 52; ++i)
    {
        Card tmpCard;
        _deck.push_back(tmpCard);
    }
    
    int card = 0;
    for (int suits = 0; suits < static_cast<int>(SUITS::MAX_SUITS); ++suits)
    {
        for (int ranks = 0; ranks < static_cast<int>(RANKS::MAX_RANKS); ++ranks)
        {
            _deck[card]._suit = static_cast<SUITS>(suits);
            _deck[card]._rank = static_cast<RANKS>(ranks);
            ++card;
        }
    }
}

//void Deck::fillDeckWithCards()
//{
//    Deck deck;
//    std::vector<Card> mydeck;
//    
//    mydeck.reserve(52);
//    for (int i = 0; i < 52; ++i)
//    {
//        Card tmpCard;
//        mydeck.push_back(tmpCard);
//    }
//    
//    int card = 0;
//    for (int suits = 0; suits < static_cast<int>(SUITS::MAX_SUITS); ++suits)
//    {
//        for (int ranks = 0; ranks < static_cast<int>(RANKS::MAX_RANKS); ++ranks)
//        {
//            mydeck[card]._suit = static_cast<SUITS>(suits);
//            mydeck[card]._rank = static_cast<RANKS>(ranks);
//            ++card;
//        }
//    }
//    _deck = mydeck;
//}

void Deck::shuffleDeck()
{
    for (int i = 0; i < 52; ++i)
    {
        std::swap(_deck.at(i), _deck.at(randomMersenne()));
        isShuffeled = true;
    }
}

void Deck::printDeck()
{
    for (int i = 0; i < 52; ++i)
    {
        std::cout << _deck[i] << std::endl;
    }
}

sf::Sprite* getFirstCardSprite(const Deck& blackJackDeck, std::vector<sf::Sprite>& spriteVector, int index)
{
    sf::Sprite* cardSprite = new sf::Sprite;
    
    if (blackJackDeck._deck.at(index)._suit == SUITS::SUIT_CLUB)
    {
        switch (blackJackDeck._deck.at(index)._rank)
        {
            case RANKS::RANK_ACE: cardSprite = &spriteVector.at(0); break;
            case RANKS::RANK_TWO: cardSprite = &spriteVector.at(1); break;
            case RANKS::RANK_THREE: cardSprite = &spriteVector.at(2); break;
            case RANKS::RANK_FOUR: cardSprite = &spriteVector.at(3); break;
            case RANKS::RANK_FIVE: cardSprite = &spriteVector.at(4); break;
            case RANKS::RANK_SIX: cardSprite = &spriteVector.at(5); break;
            case RANKS::RANK_SEVEN: cardSprite = &spriteVector.at(6); break;
            case RANKS::RANK_EIGHT: cardSprite = &spriteVector.at(7); break;
            case RANKS::RANK_NINE: cardSprite = &spriteVector.at(8); break;
            case RANKS::RANK_TEN: cardSprite = &spriteVector.at(9); break;
            case RANKS::RANK_JACK: cardSprite = &spriteVector.at(10); break;
            case RANKS::RANK_QUEEN: cardSprite = &spriteVector.at(11); break;
            case RANKS::RANK_KING: cardSprite = &spriteVector.at(12); break;
        }
    }
    
    if (blackJackDeck._deck.at(index)._suit == SUITS::SUIT_SPADE)
    {
        switch (blackJackDeck._deck.at(index)._rank)
        {
            case RANKS::RANK_ACE: cardSprite = &spriteVector.at(13); break;
            case RANKS::RANK_TWO: cardSprite = &spriteVector.at(14); break;
            case RANKS::RANK_THREE: cardSprite = &spriteVector.at(15); break;
            case RANKS::RANK_FOUR: cardSprite = &spriteVector.at(16); break;
            case RANKS::RANK_FIVE: cardSprite = &spriteVector.at(17); break;
            case RANKS::RANK_SIX: cardSprite = &spriteVector.at(18); break;
            case RANKS::RANK_SEVEN: cardSprite = &spriteVector.at(19); break;
            case RANKS::RANK_EIGHT: cardSprite = &spriteVector.at(20); break;
            case RANKS::RANK_NINE: cardSprite = &spriteVector.at(21); break;
            case RANKS::RANK_TEN: cardSprite = &spriteVector.at(22); break;
            case RANKS::RANK_JACK: cardSprite = &spriteVector.at(23); break;
            case RANKS::RANK_QUEEN: cardSprite = &spriteVector.at(24); break;
            case RANKS::RANK_KING: cardSprite = &spriteVector.at(25); break;
        }
    }
    
    
    if (blackJackDeck._deck.at(index)._suit == SUITS::SUIT_HEART)
    {
        switch (blackJackDeck._deck.at(index)._rank)
        {
            case RANKS::RANK_ACE: cardSprite = &spriteVector.at(26); break;
            case RANKS::RANK_TWO: cardSprite = &spriteVector.at(27); break;
            case RANKS::RANK_THREE: cardSprite = &spriteVector.at(28); break;
            case RANKS::RANK_FOUR: cardSprite = &spriteVector.at(29); break;
            case RANKS::RANK_FIVE: cardSprite = &spriteVector.at(30); break;
            case RANKS::RANK_SIX: cardSprite = &spriteVector.at(31); break;
            case RANKS::RANK_SEVEN: cardSprite = &spriteVector.at(32); break;
            case RANKS::RANK_EIGHT: cardSprite = &spriteVector.at(33); break;
            case RANKS::RANK_NINE: cardSprite = &spriteVector.at(34); break;
            case RANKS::RANK_TEN: cardSprite = &spriteVector.at(35); break;
            case RANKS::RANK_JACK: cardSprite = &spriteVector.at(36); break;
            case RANKS::RANK_QUEEN: cardSprite = &spriteVector.at(37); break;
            case RANKS::RANK_KING: cardSprite = &spriteVector.at(38); break;
        }
    }
    
    if (blackJackDeck._deck.at(index)._suit == SUITS::SUIT_DIAMOND)
    {
        switch (blackJackDeck._deck.at(index)._rank)
        {
            case RANKS::RANK_ACE: cardSprite = &spriteVector.at(39); break;
            case RANKS::RANK_TWO: cardSprite = &spriteVector.at(40); break;
            case RANKS::RANK_THREE: cardSprite = &spriteVector.at(41); break;
            case RANKS::RANK_FOUR: cardSprite = &spriteVector.at(42); break;
            case RANKS::RANK_FIVE: cardSprite = &spriteVector.at(43); break;
            case RANKS::RANK_SIX: cardSprite = &spriteVector.at(44); break;
            case RANKS::RANK_SEVEN: cardSprite = &spriteVector.at(45); break;
            case RANKS::RANK_EIGHT: cardSprite = &spriteVector.at(46); break;
            case RANKS::RANK_NINE: cardSprite = &spriteVector.at(47); break;
            case RANKS::RANK_TEN: cardSprite = &spriteVector.at(48); break;
            case RANKS::RANK_JACK: cardSprite = &spriteVector.at(49); break;
            case RANKS::RANK_QUEEN: cardSprite = &spriteVector.at(50); break;
            case RANKS::RANK_KING: cardSprite = &spriteVector.at(51); break;
        }
    }
    cardSprite->scale(0.2, 0.2);
    return cardSprite;
}

