//
//  main.cpp
//  GUIGame
//
//  Created by max dietz on 9/16/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MPErrors.hpp"
//#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>



const int firstCardInDeck = 0;
const int secondCardInDeck = 1;

class UIButton : public sf::Transformable, public sf::Drawable
{
public:
    sf::RectangleShape _rectangle;
    sf::Text _text;

    UIButton()
    {
        _rectangle.setSize(sf::Vector2f(120, 50));
        _rectangle.setFillColor(sf::Color::Black);
        
        sf::Font tempFont;
        if (!tempFont.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Fonts/Kyoto.ttf"))
            error("Unable to load font from file");
        _text.setFont(tempFont);
        _text.setString("Temp");
        _text.setCharacterSize(24);
        _text.setFillColor(sf::Color::Red);
    }
    
    bool isClicked()
    {
        return _isClicked;
    }
    
    void setClickedTrue() { _isClicked = true; }
    void setClickedFalse() { _isClicked = false; }
    
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool _isClicked = false;
};


// for now, forget money and set the starting chips to 300
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    // get the size of the window, might use these later.
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    
    // call it once, after creating the window
    window.setVerticalSyncEnabled(true);

    
    // Prepare Player chips
    // Players will get:
    // 4 purple chip for 25$ each - total value - (100$)
    // 30 red chips for 5$ each - total value - (150$)
    // 50 white chips for 1$ each - total value - (50$) - (300$) all together.
    // Load the chip png's from file.
    sf::Texture chipFileWhite;
    if (!chipFileWhite.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Chips/chipWhite.png"))
        error("Unable to load white chip");
    sf::Texture chipFileRed;
    if (!chipFileRed.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Chips/chipRed.png"))
        error("Unable to load red chip");
    sf::Texture chipFilePurple;
    if (!chipFilePurple.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Chips/chipPurple.png"))
        error("Unable to load purple chip");
    
    sf::Sprite whiteChip;
    whiteChip.setTexture(chipFileWhite);
    sf::Sprite redChip;
    redChip.setTexture(chipFileRed);
    sf::Sprite purpleChip;
    purpleChip.setTexture(chipFilePurple);
    
    // Move the Chips into their starting position.
    whiteChip.scale(0.8, 0.8);
    redChip.scale(0.8, 0.8);
    purpleChip.scale(0.8, 0.8);
    
    whiteChip.move(470, 490);
    redChip.move(575, 490);
    purpleChip.move(680, 490);
    
    
    // Prepare Cards
    sf::Texture texture1;
    if (!texture1.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Cards/c02.png"))
        error("unable to load first card from file");
    sf::Texture texture2;
    if (!texture2.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Cards/c03.png"))
        error("unable to load first card from file");
    
    
    // code to load first 2 cards with one off to the right
    sf::Sprite two_of_clubs;
    sf::Sprite three_of_clubs;
    two_of_clubs.setTexture(texture1);
    three_of_clubs.setTexture(texture2);
    two_of_clubs.move(150, 0);
    two_of_clubs.scale(0.2, 0.2);
    three_of_clubs.scale(0.2,0.2);
    
    
    sf::FloatRect boundingBox = two_of_clubs.getGlobalBounds();
    
    std::vector<sf::Sprite> sprites;
    sprites.push_back(two_of_clubs);
    sprites.push_back(three_of_clubs);
    
    
    // code could be useful for saving code space, would prevent the excess pushback, dunno if it actually work.
//    std::vector<sf::Sprite> sprites = std::vector < sf::Sprite >
//    {
//        sf::Sprite(texture1), sf::Sprite(texture2),
//    };
    
    
    // Create a sf::Music and put it to play for the program duration.
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Sounds/loopmus.ogg"))
        error("unable to load first card from file");
    // Play the music
    music.setLoop(true);
    music.play();
    music.setVolume(70);
    
    
    
    // create and prepare texts for displaying.
    sf::Font font;
    if (!font.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Fonts/Kyoto.ttf"))
        error("Unable to load font from file");
    sf::Text welcomeMessage("Welcome to BlackJack.", font, 60);
    sf::Text betDisplay1("Your bet starts at 0.", font, 40);
    sf::Text betDisplay2("Press the Up Arrow to increase the bet by 10", font, 40);
    sf::Text beginMessage("Press Enter to Begin playing.", font, 60);
    welcomeMessage.move(0, 0);
    betDisplay1.move(0, 90);
    betDisplay2.move(0, 130);
    beginMessage.move(0, 300);
    
    
    bool hasStartingChips = true; // need better idea for this chip tracking later.
    bool hasPlayerMadeABet = false;

    
    // Try to setup the Buttons for Hit/Stay
    UIButton hitButton;
    
    
    // Program loop
    while(window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // left mouse button is pressed:
                
            }
            
            // TODO: make a check for the bet being greater than 0 before executing this code.
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {
                // left key is pressed:
                // increase the bet from Player class.
                hasPlayerMadeABet = true;
            }
            
            
            sf::Vector2f tempMouse(sf::Mouse::getPosition(window));
            if (two_of_clubs.getGlobalBounds().contains(tempMouse) &&
                      event.type == sf::Event::MouseButtonReleased &&
                      event.key.code == sf::Mouse::Left)
            {
               /*
                
                Add code here to the chip sprites on screen, so when you click the bet goes up in intervals.
                
                */
            }
        }
        
        // Clear the whole window before rendering a new frame
        window.clear();
        
        // Try to draw UI Buttons
        window.draw(hitButton);
        
        if (hasStartingChips == true && hasPlayerMadeABet == true)
        {
            window.draw(whiteChip);
            window.draw(redChip);
            window.draw(purpleChip);
        }
        
        if (hasPlayerMadeABet == false)
        {
            window.draw(welcomeMessage);
            window.draw(betDisplay1);
            window.draw(betDisplay2);
            window.draw(beginMessage);
        }
        
        // Draw some graphical entities
        if (hasPlayerMadeABet == true)
        {
            /*
             
             // add a card drawing noise here to play quickly for 2 cards.
             
             */
            
            window.draw(sprites[firstCardInDeck]);
            window.draw(sprites[secondCardInDeck]);
        }

        // End the current frame and display its contents on screen.
        window.display();
    }
    
}


/* Code to get and set mouse position if I need it.
 
 
 // Get mouse position stuff
 // get the global mouse position (relative to the desktop)
 sf::Vector2i globalPosition = sf::Mouse::getPosition();
 // get the local mouse position (relative to a window)
//  sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
 
 // Set mouse position stuff
 // set the mouse position globally (relative to the desktop)
 sf::Mouse::setPosition(sf::Vector2i(10, 50));
 // set the mouse position locally (relative to a window)
 sf::Mouse::setPosition(sf::Vector2i(10, 50), window); // window is a sf::Window
 
 */
