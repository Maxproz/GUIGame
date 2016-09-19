//
//  Typewriter.cpp
//  GUIGame
//
//  Created by max dietz on 9/19/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "Typewriter.hpp"


#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>

class Typewriter::impl
{
public:
    explicit impl(std::string s, sf::Font& f, sf::Uint32 charSize, float timeOffSet);
    ~impl();
    
public:
    std::string _string;
    sf::Text _text;
    float _offset;
    sf::Vector2f _position;
    std::size_t _itr;
    sf::Clock _timer;
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
};

Typewriter::impl::impl(std::string s, sf::Font& f, sf::Uint32 charSize, float timeOffSet)
: _text{s,f,charSize}
, _string{s}
, _offset{timeOffSet}
, _itr{0}
{
    _text.setFillColor(sf::Color(255,255,255,255));
    _text.setOrigin(_text.getGlobalBounds().width/2.f, 0.f);
    
    _buffer.loadFromFile("/MP/type.wav");
    _sound.setBuffer(_buffer);
    _sound.setVolume(50.f);
}

Typewriter::impl::~impl()
{
    
}

Typewriter::Typewriter(std::string s, sf::Font& f, sf::Uint32 charSize, float timeOffSet)
: _impl{new impl(s,f,charSize,timeOffSet)}
{
    
}

Typewriter::~Typewriter()
{
    
}

void Typewriter::setString(std::string s)
{
    _impl->_string = s;
}

std::string const Typewriter::getString() const
{
    return _impl->_string;
}

void Typewriter::setPosition(sf::Vector2f position)
{
    _impl->_text.setPosition(position);
}

void Typewriter::reset()
{
    _impl->_timer.restart();
    _impl->_itr = 0;
}

void Typewriter::write()
{
    // std::cout << "Writing...." << std::endl;
    if (_impl->_timer.getElapsedTime().asSeconds() > _impl->_offset &&
        _impl->_itr < _impl->_string.size())
    {
        _impl->_timer.restart();
        _impl->_itr++;
        
        if (_impl->_sound.getStatus() == sf::Sound::Stopped)
            _impl->_sound.play();
        
        _impl->_text.setString(sf::String(_impl->_string.substr(0, _impl->_itr)));
        
        _impl->_text.setOrigin(_impl->_text.getGlobalBounds().width/2.f, 0.f);
        
        // std::cout << _impl->_string.substr(0, _impl->_itr) << std::endl;
    }
}

void Typewriter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_impl->_text, states);
}
