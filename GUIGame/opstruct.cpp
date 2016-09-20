//
//  opstruct.cpp
//  GUIGame
//
//  Created by max dietz on 9/18/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "opstruct.hpp"

BJ::opstruct::opstruct()
{
    
}

BJ::opstruct::~opstruct()
{
    
}

bool BJ::opstruct::saveOptions(BJ::opstruct& op, const char* filename)
{
    std::ofstream ofs(filename);
    boost::archive::xml_oarchive xml(ofs);
    xml << boost::serialization::make_nvp("Options", op);
    return true;
}

bool BJ::opstruct::loadOptions(BJ::opstruct& op, const char* filename)
{
    std::ifstream ifs(filename);
    if (!ifs) return false;
    boost::archive::xml_iarchive xml(ifs);
    xml >> boost::serialization::make_nvp("Options", op);
    return true;
}