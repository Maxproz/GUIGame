//
//  Deck.hpp
//  GUIGame
//
//  Created by max dietz on 9/17/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include "Card.hpp"
#include "RandomGenerators.hpp"

class Deck
{
private:
    bool isShuffeled = false;
public:
    std::vector<Card> _deck;
    
    // Fill the deck up with 52 cards.
    Deck();
    
    void shuffleDeck();
};

#endif /* Deck_hpp */
