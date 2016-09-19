//
//  opstruct.hpp
//  GUIGame
//
//  Created by max dietz on 9/18/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef opstruct_hpp
#define opstruct_hpp

#include <iostream>
#include <fstream>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/nvp.hpp>

namespace BJ
{

    class opstruct
    {
    public:
        opstruct();
        ~opstruct();
        bool saveOptions(BJ::opstruct& op, const char* filename);
        bool loadOptions(BJ::opstruct& op, const char* filename);
        
        int _volume;
        int _effects;
        int _difficulty;
        
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            ar& BOOST_SERIALIZATION_NVP(_volume);
            ar& BOOST_SERIALIZATION_NVP(_effects);
            ar& BOOST_SERIALIZATION_NVP(_difficulty);
        }
    };
    
}

#endif /* opstruct_hpp */
