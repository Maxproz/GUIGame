//
//  button.cpp
//  GUIGame
//
//  Created by max dietz on 9/18/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include "button.hpp"

gui::button::button()
{
    
}

gui::button::button(std::string s, sf::Font& font, sf::Vector2f position, sf::Uint32 style)
{
    // set position
    _position = position;
    
    // set inital state
    _btnstate = gui::state::normal;
    
    // set button style
    _style = style;
    
    switch (_style)
    {
        case gui::style::none:
        {
            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(255,255,255,100);
            _bgHover = sf::Color(200,200,200,100);
            _bgClicked = sf::Color(150,150,150);
            _border = sf::Color(255,255,255,100);
        }
        break;
        
        case gui::style::save:
        {
            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(0,255,0,100);
            _bgHover = sf::Color(0,200,0,100);
            _bgClicked = sf::Color(0,150,0);
            _border = sf::Color(0,0,0,100);
        }
        break;
            
        case gui::style::cancel:
        {
            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(255,0,0,100);
            _bgHover = sf::Color(200,0,0,100);
            _bgClicked = sf::Color(150,0,0);
            _border = sf::Color(255,255,255,100);
        }
        break;
            
        case gui::style::clean:
        {
            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(0,255,255,100);
            _bgHover = sf::Color(0,200,200,100);
            _bgClicked = sf::Color(0,150,150);
            _border = sf::Color(255,255,255,100);
        }
        break;
            
            
        default:
            break;
    }
    
    // set up text
    _text.setString(s);
    _text.setFont(font);
    _text.setOrigin(_text.getGlobalBounds().width/2, _text.getGlobalBounds().height/2);
    _text.setFillColor(_textNormal);
    
    // set some defaults
    _borderRadius = 5.f;
    _borderThickness = 0.f;
    _size = sf::Vector2f(_text.getGlobalBounds().width * 1.5f, _text.getGlobalBounds().height * 1.5f);
    
    _button = thor::Shapes::roundedRect(_size, _borderRadius, _bgNormal, _borderThickness, _border);
    _button.setOrigin(_button.getGlobalBounds().width/2, _button.getGlobalBounds().height/2);
    _button.setPosition(_position);
    
    sf::Vector2f textPosition = sf::Vector2f(_button.getPosition().x,
                                             _button.getPosition().y - _button.getGlobalBounds().height/4);
    
    _text.setPosition(textPosition);
    
    _shadow.setFont(font);
    _shadow = _text;
    _shadow.setOrigin(_shadow.getGlobalBounds().width/2, _shadow.getGlobalBounds().height/2);
    _shadow.setPosition(_text.getPosition().x + 3.f, _text.getPosition().y + 3.f);
}

gui::button::~button()
{
    
}

void gui::button::setSize(unsigned int size)
{
    _fontSize = size;
    _text.setCharacterSize(_fontSize);
    _text.setOrigin(_text.getGlobalBounds().width/2, _text.getGlobalBounds().height/2);
    _shadow.setCharacterSize(_fontSize);
    _shadow.setOrigin(_shadow.getGlobalBounds().width/2, _shadow.getGlobalBounds().height/2);
    _size = sf::Vector2f(_text.getGlobalBounds().width * 1.5f, (_text.getGlobalBounds().height +
                                                                _text.getGlobalBounds().height) * 1.5f);
    _button = thor::Shapes::roundedRect(_size, _borderRadius, _bgNormal, _borderThickness, _border);
}

void gui::button::setStyle(sf::Uint32 style)
{
    // set button style
    _style = style;
    
    switch (_style)
    {
        case gui::style::none:
        {
            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(255,255,255,100);
            _bgHover = sf::Color(200,200,200,100);
            _bgClicked = sf::Color(150,150,150);
            _border = sf::Color(255,255,255,100);
        }
            break;
            
        case gui::style::save:
        {
            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(0,255,0,100);
            _bgHover = sf::Color(0,200,0,100);
            _bgClicked = sf::Color(0,150,0);
            _border = sf::Color(0,0,0,100);
        }
            break;
            
        case gui::style::cancel:
        {
            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(255,0,0,100);
            _bgHover = sf::Color(200,0,0,100);
            _bgClicked = sf::Color(150,0,0);
            _border = sf::Color(255,255,255,100);
        }
            break;
            
        case gui::style::clean:
        {
            _textNormal = sf::Color(255,255,255);
            _textHover = sf::Color(255,255,255);
            _textClicked = sf::Color(255,255,255);
            _bgNormal = sf::Color(0,255,255,100);
            _bgHover = sf::Color(0,200,200,100);
            _bgClicked = sf::Color(0,150,150);
            _border = sf::Color(255,255,255,100);
        }
            break;
            
            
        default:
            break;
    }
}

void gui::button::setFont(sf::Font& font)
{
    _text.setFont(font);
    _shadow.setFont(font);
}

void gui::button::update(sf::Event& e, sf::RenderWindow& window)
{
    // preform updates for settings from user
    switch (_style)
    {
        case gui::style::none:
        {
            _size = sf::Vector2f(_text.getGlobalBounds().width * 1.5f,
                                 _text.getGlobalBounds().height * 1.75f);
            _button = thor::Shapes::roundedRect(_size, _borderRadius, _bgNormal, _borderThickness, _border);
            _button.setOrigin(_button.getGlobalBounds().width/2, _button.getGlobalBounds().height/2);
            _button.setPosition(_position);
            _text.setOrigin(_text.getGlobalBounds().width/2, _text.getGlobalBounds().height/2);
            sf::Vector2f textPosition = sf::Vector2f(_button.getPosition().x,
                                                     _button.getPosition().y - _button.getGlobalBounds().height/4);
            _text.setPosition(textPosition);
            _text.setFillColor(_textNormal);
            _shadow.setOrigin(_shadow.getGlobalBounds().width/2, _shadow.getGlobalBounds().height/2);
            _shadow.setPosition(_text.getPosition().x + 3.f, _text.getPosition().y + 3.f);
            _shadow.setFillColor(sf::Color(0,0,0));
        }
        break;
            
        case gui::style::save:
        {
            _size = sf::Vector2f(_text.getGlobalBounds().width * 1.5f,
                                 _text.getGlobalBounds().height * 1.75f);
            _button = thor::Shapes::roundedRect(_size, _borderRadius, _bgNormal, _borderThickness, _border);
            _button.setOrigin(_button.getGlobalBounds().width/2, _button.getGlobalBounds().height/2);
            _button.setPosition(_position);
            _text.setOrigin(_text.getGlobalBounds().width/2, _text.getGlobalBounds().height/2);
            sf::Vector2f textPosition = sf::Vector2f(_button.getPosition().x,
                                                     _button.getPosition().y - _button.getGlobalBounds().height/4);
            _text.setPosition(textPosition);
            _text.setFillColor(_textNormal);
            _shadow.setOrigin(_shadow.getGlobalBounds().width/2, _shadow.getGlobalBounds().height/2);
            _shadow.setPosition(_text.getPosition().x + 3.f, _text.getPosition().y + 3.f);
            _shadow.setFillColor(sf::Color(0,0,0));
        }
        break;
            
        case gui::style::cancel:
        {
            _size = sf::Vector2f(_text.getGlobalBounds().width * 1.5f,
                                 _text.getGlobalBounds().height * 1.75f);
            _button = thor::Shapes::roundedRect(_size, _borderRadius, _bgNormal, _borderThickness, _border);
            _button.setOrigin(_button.getGlobalBounds().width/2, _button.getGlobalBounds().height/2);
            _button.setPosition(_position);
            _text.setOrigin(_text.getGlobalBounds().width/2, _text.getGlobalBounds().height/2);
            sf::Vector2f textPosition = sf::Vector2f(_button.getPosition().x,
                                                     _button.getPosition().y - _button.getGlobalBounds().height/4);
            _text.setPosition(textPosition);
            _text.setFillColor(_textNormal);
            _shadow.setOrigin(_shadow.getGlobalBounds().width/2, _shadow.getGlobalBounds().height/2);
            _shadow.setPosition(_text.getPosition().x + 3.f, _text.getPosition().y + 3.f);
            _shadow.setFillColor(sf::Color(0,0,0));
        }
        break;
            
        case gui::style::clean:
        {
            _size = sf::Vector2f(_text.getGlobalBounds().width * 1.5f,
                                 _text.getGlobalBounds().height * 1.75f);
            _button = thor::Shapes::roundedRect(_size, _borderRadius, _bgNormal, _borderThickness, _border);
            _button.setOrigin(_button.getGlobalBounds().width/2, _button.getGlobalBounds().height/2);
            _button.setPosition(_position);
            _text.setOrigin(_text.getGlobalBounds().width/2, _text.getGlobalBounds().height/2);
            sf::Vector2f textPosition = sf::Vector2f(_button.getPosition().x,
                                                     _button.getPosition().y - _button.getGlobalBounds().height/4);
            _text.setPosition(textPosition);
            _text.setFillColor(_textNormal);
            _shadow.setOrigin(_shadow.getGlobalBounds().width/2, _shadow.getGlobalBounds().height/2);
            _shadow.setPosition(_text.getPosition().x + 3.f, _text.getPosition().y + 3.f);
            _shadow.setFillColor(sf::Color(0,0,0));
        }
        break;
            
        default:
            break;
    }
    
    //perform updates for user mouse interactions
    sf::Vector2i _mousePosition = sf::Mouse::getPosition(window);
    
    bool mouseInButton =
                _mousePosition.x >= _button.getPosition().x - _button.getGlobalBounds().width/2 &&
                _mousePosition.x <= _button.getPosition().x + _button.getGlobalBounds().width/2 &&
                _mousePosition.y >= _button.getPosition().y - _button.getGlobalBounds().height/2 &&
                _mousePosition.y <= _button.getPosition().y + _button.getGlobalBounds().height/2;
    
    if (e.type == sf::Event::MouseMoved)
    {
        if (mouseInButton)
        {
            _btnstate = gui::state::hovered;
        }
        else
        {
            _btnstate = gui::state::normal;
        }
    }
    
    if (e.type == sf::Event::MouseButtonPressed)
    {
        switch (e.mouseButton.button)
        {
            case sf::Mouse::Left:
            {
                if (mouseInButton)
                {
                    _btnstate = gui::state::clicked;
                }
                else
                {
                    _btnstate = gui::state::normal;
                }
            }
            break;
        }
    }
    
    if (e.type == sf::Event::MouseButtonReleased)
    {
        switch (e.mouseButton.button)
        {
            case sf::Mouse::Left:
            {
                if (mouseInButton)
                {
                    _btnstate = gui::state::hovered;
                }
                else
                {
                    _btnstate = gui::state::normal;
                }
            }
        }
    }
    
    switch (_btnstate)
    {
        case gui::state::normal:
        {
            _button.setFillColor(_bgNormal);
            _text.setFillColor(_textNormal);
        }
        break;
            
        case gui::state::hovered:
        {
            _button.setFillColor(_bgHover);
            _text.setFillColor(_textHover);
        }
        break;
            
        case gui::state::clicked:
        {
            _button.setFillColor(_bgClicked);
            _text.setFillColor(_textClicked);
        }
        break;
    }
}

void gui::button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    switch (_style)
    {
        case gui::style::none:
        {
            target.draw(_button, states);
            target.draw(_shadow, states);
            target.draw(_text, states);
        }
        break;
            
        case gui::style::save:
        {
            target.draw(_button, states);
            target.draw(_shadow, states);
            target.draw(_text, states);
        }
        break;
            
        case gui::style::cancel:
        {
            target.draw(_button, states);
            target.draw(_shadow, states);
            target.draw(_text, states);
        }
        break;
            
        case gui::style::clean:
        {
            target.draw(_button, states);
            target.draw(_shadow, states);
            target.draw(_text, states);
        }
        break;
            
        default:
            break;
    }
}

























