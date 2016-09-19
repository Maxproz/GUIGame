//
//  HexGrid.hpp
//  GUIGame
//
//  Created by max dietz on 9/19/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef HexGrid_hpp
#define HexGrid_hpp

#include <vector>
#include <SFML/Graphics.hpp>
#include <Thor/Shapes.hpp>

namespace mpbgs
{
    class hexgrid : public sf::Drawable
    {
    public:
        hexgrid(sf::RenderWindow& window, sf::Uint32 style, const float& scale);
        ~hexgrid();
        
        void update(sf::RenderWindow& window, sf::Time dt);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
        enum hexStyle
        {
            translucent,
            colorful,
            green,
            cyan
        };
        
    private:
        //set up background elements
        sf::Uint32 m_style;
        sf::ConvexShape hexagon;
        std::vector<sf::ConvexShape> hexagrid;
        float m_scale;
    };
}

#endif /* HexGrid_hpp */
