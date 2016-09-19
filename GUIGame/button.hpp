//
//  button.hpp
//  GUIGame
//
//  Created by max dietz on 9/18/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#ifndef button_hpp
#define button_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Thor/Shapes.hpp>
#include <Thor/Graphics.hpp>

namespace gui
{
    namespace style
    {
        enum
        {
            none = 0,
            save = 1,
            cancel = 2,
            clean = 3
        };
    };
    
    namespace state
    {
        enum
        {
            normal = 0,
            hovered = 1,
            clicked = 2
        };
    };
    
    class button : public sf::Drawable
    {
    private:
        sf::Color _bgNormal;
        sf::Color _bgHover;
        sf::Color _bgClicked;
        sf::Color _textNormal;
        sf::Color _textHover;
        sf::Color _textClicked;
        sf::Color _border;
        
        float _borderThickness;
        float _borderRadius;
        sf::Vector2f _size;
        sf::Vector2f _position;
        sf::Uint32 _style;
        sf::Uint32 _btnstate;
        
        sf::ConvexShape _button;
        sf::Font _font;
        unsigned int _fontSize;
        sf::Text _text;
        sf::Text _shadow;
        
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
    public:
        button();
        button(std::string s, sf::Font& font, sf::Vector2f position, sf::Uint32 style);
        
        ~button();
        
        void setColorTextNormal(sf::Color text) { _textNormal = text; };
        void setColorTextHover(sf::Color text) { _textHover = text; };
        void setColorTextClicked(sf::Color text) { _textClicked = text; };
        void setColorNormal(sf::Color bgNormal) { _bgNormal = bgNormal; };
        void setColorHover(sf::Color bgHover) { _bgHover = bgHover; };
        void setColorClicked(sf::Color bgClicked) { _bgClicked = bgClicked; };
        void setBorderColor(sf::Color border) { _border = border; };
        void setBorderThickness(float t) { _borderThickness = t; };
        void setBorderRadius(float r) { _borderRadius = r; };
        void setPosition(sf::Vector2f position) { _position = position; };
        void setSize(unsigned int size);
        void setText(std::string s)
        {
            _text.setString(s);
            _shadow = _text;
        };
        void setStyle(sf::Uint32 style);
        void setFont(sf::Font& font);
        
        sf::Vector2f getPosition() { return _position; };
        sf::Vector2f getDimensions() { return sf::Vector2f(_button.getGlobalBounds().width,
                                                           _button.getGlobalBounds().height);};
        sf::Uint32 getState() { return _btnstate; };
        
        void update(sf::Event& e, sf::RenderWindow& window);
        
    };
}

#endif /* button_hpp */

