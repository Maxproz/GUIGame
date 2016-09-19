//
//  DataTables.cpp
//  GUIGame
//
//  Created by max dietz on 9/19/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "DataTables.hpp"

// implementation details
std::vector<WelcomeScreenMessages> initalizeEnemyProfileData()
{
    std::vector<WelcomeScreenMessages> data(NUMBER_OF_WELCOME_SCREEN_MESSAGES);
    
    data[0].name        =   "Welcome to BlackJack.";
    data[0].description =   "The rules for this game are very simple, \n"
    "Press Enter\n";
    
    data[1].name        =   "First you must decide how much you want to bet.";
    data[1].description =   "You start off with 300$ in chips \n"
    "Press Enter\n";
    
    data[2].name        =   "The three kinds of chips will be in the bottom right.";
    data[2].description =   "Click on these chips and press Submit Bet to place a bet. \n"
    "4 purple chips - 25$ each\n"
    "30 red chips   -  5$ each\n"
    "50 white chips -  1$ each\n"
    "Press Enter\n";
    
    data[3].name        =   "You will then get 2 cards.";
    data[3].description =   "The goal is to get as close to 21 as possible. \n"
    "There will be HIT or STAY buttons you can press. \n"
    "If you go over 21 you will lose. \n"
    "If you get closer to 21 then the dealer you win. \n"
    "You can re-read rules by pressing the left arrow.";
    
    return data;
}
