//
//  Typewriter.hpp
//  GUIGame
//
//  Created by max dietz on 9/19/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef Typewriter_hpp
#define Typewriter_hpp

#include <iostream>
#include <string>
#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics//Transformable.hpp>

/*
 This helps clean up as well, and hides some of the things
 - that are used inside the class implentation (Typewriter.cpp) file.
 */

namespace sf
{
    class Font;
    class RenderTarget;
    class RenderStates;
}

/*
 The Typewriter class inherits from sf::Drawable/sf::Transformable
 - so that we can make the window.draw(Typewriter) call,
 - instead of a slightly weird looking Typewriter.draw(window) call
 - not necessary but cleaner.
 */

class Typewriter : public sf::Drawable, sf::Transformable
{
private:
    class impl;
    std::unique_ptr<impl> _impl;
    
public:
    explicit Typewriter(std::string s, sf::Font& f, sf::Uint32 charSize, float timeOffSet);
    ~Typewriter();
    
    void write();
    
    void reset();
    
    void setString(std::string s);
    std::string const getString() const;
    
    void setPosition(sf::Vector2f position);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif /* Typewriter_hpp */
