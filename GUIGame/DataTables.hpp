//
//  DataTables.hpp
//  GUIGame
//
//  Created by max dietz on 9/19/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef DataTables_hpp
#define DataTables_hpp

#include <string>
#include <vector>

const unsigned int NUMBER_OF_WELCOME_SCREEN_MESSAGES = 4;

struct WelcomeScreenMessages
{
    std::string name;
    std::string description;
};
std::vector<WelcomeScreenMessages> initalizeEnemyProfileData();

#endif /* DataTables_hpp */
