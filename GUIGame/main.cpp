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
#include <SFML/Audio.hpp>
#include <fstream>
#include "RandomGenerators.hpp"
#include "Deck.hpp"

// Blackjack random number generator for values (0 - 51)
boost::mt19937 gen;



sf::Sprite* getFirstCardSprite(const Deck& blackJackDeck, std::vector<sf::Sprite>& spriteVector, int index)
{
    sf::Sprite* cardSprite = new sf::Sprite;
    switch (blackJackDeck._deck.at(index)._suit)
    {
        case::SUITS::SUIT_CLUB:
        {
            switch (blackJackDeck._deck.at(index)._rank)
            {
                case RANKS::RANK_ACE: cardSprite = &spriteVector.at(0); break;
                case RANKS::RANK_TWO: cardSprite = &spriteVector.at(1); break;
                case RANKS::RANK_THREE: cardSprite = &spriteVector.at(2); break;
                case RANKS::RANK_FOUR: cardSprite = &spriteVector.at(3); break;
                case RANKS::RANK_FIVE: cardSprite = &spriteVector.at(4); break;
                case RANKS::RANK_SIX: cardSprite = &spriteVector.at(5); break;
                case RANKS::RANK_SEVEN: cardSprite = &spriteVector.at(6); break;
                case RANKS::RANK_EIGHT: cardSprite = &spriteVector.at(7); break;
                case RANKS::RANK_NINE: cardSprite = &spriteVector.at(8); break;
                case RANKS::RANK_TEN: cardSprite = &spriteVector.at(9); break;
                case RANKS::RANK_JACK: cardSprite = &spriteVector.at(10); break;
                case RANKS::RANK_QUEEN: cardSprite = &spriteVector.at(11); break;
                case RANKS::RANK_KING: cardSprite = &spriteVector.at(12); break;
            }
        }
        case::SUITS::SUIT_SPADE:
        {
            switch (blackJackDeck._deck.at(index)._rank)
            {
                case RANKS::RANK_ACE: cardSprite = &spriteVector.at(13); break;
                case RANKS::RANK_TWO: cardSprite = &spriteVector.at(14); break;
                case RANKS::RANK_THREE: cardSprite = &spriteVector.at(15); break;
                case RANKS::RANK_FOUR: cardSprite = &spriteVector.at(16); break;
                case RANKS::RANK_FIVE: cardSprite = &spriteVector.at(17); break;
                case RANKS::RANK_SIX: cardSprite = &spriteVector.at(18); break;
                case RANKS::RANK_SEVEN: cardSprite = &spriteVector.at(19); break;
                case RANKS::RANK_EIGHT: cardSprite = &spriteVector.at(20); break;
                case RANKS::RANK_NINE: cardSprite = &spriteVector.at(21); break;
                case RANKS::RANK_TEN: cardSprite = &spriteVector.at(22); break;
                case RANKS::RANK_JACK: cardSprite = &spriteVector.at(23); break;
                case RANKS::RANK_QUEEN: cardSprite = &spriteVector.at(24); break;
                case RANKS::RANK_KING: cardSprite = &spriteVector.at(25); break;
            }
        }
        case SUITS::SUIT_HEART:
        {
            switch (blackJackDeck._deck.at(index)._rank)
            {
                case RANKS::RANK_ACE: cardSprite = &spriteVector.at(26); break;
                case RANKS::RANK_TWO: cardSprite = &spriteVector.at(27); break;
                case RANKS::RANK_THREE: cardSprite = &spriteVector.at(28); break;
                case RANKS::RANK_FOUR: cardSprite = &spriteVector.at(29); break;
                case RANKS::RANK_FIVE: cardSprite = &spriteVector.at(30); break;
                case RANKS::RANK_SIX: cardSprite = &spriteVector.at(31); break;
                case RANKS::RANK_SEVEN: cardSprite = &spriteVector.at(32); break;
                case RANKS::RANK_EIGHT: cardSprite = &spriteVector.at(33); break;
                case RANKS::RANK_NINE: cardSprite = &spriteVector.at(34); break;
                case RANKS::RANK_TEN: cardSprite = &spriteVector.at(35); break;
                case RANKS::RANK_JACK: cardSprite = &spriteVector.at(36); break;
                case RANKS::RANK_QUEEN: cardSprite = &spriteVector.at(37); break;
                case RANKS::RANK_KING: cardSprite = &spriteVector.at(38); break;
            }
        }
        case SUITS::SUIT_DIAMOND:
        {
            switch (blackJackDeck._deck.at(index)._rank)
            {
                case RANKS::RANK_ACE: cardSprite = &spriteVector.at(39); break;
                case RANKS::RANK_TWO: cardSprite = &spriteVector.at(40); break;
                case RANKS::RANK_THREE: cardSprite = &spriteVector.at(41); break;
                case RANKS::RANK_FOUR: cardSprite = &spriteVector.at(42); break;
                case RANKS::RANK_FIVE: cardSprite = &spriteVector.at(43); break;
                case RANKS::RANK_SIX: cardSprite = &spriteVector.at(44); break;
                case RANKS::RANK_SEVEN: cardSprite = &spriteVector.at(45); break;
                case RANKS::RANK_EIGHT: cardSprite = &spriteVector.at(46); break;
                case RANKS::RANK_NINE: cardSprite = &spriteVector.at(47); break;
                case RANKS::RANK_TEN: cardSprite = &spriteVector.at(48); break;
                case RANKS::RANK_JACK: cardSprite = &spriteVector.at(49); break;
                case RANKS::RANK_QUEEN: cardSprite = &spriteVector.at(50); break;
                case RANKS::RANK_KING: cardSprite = &spriteVector.at(51); break;
            }
        }
    }
    cardSprite->scale(0.2, 0.2);
    return cardSprite;
}

void printDeck(Deck& deck)
{
    for (int i = 0; i < 52; ++i)
    {
        std::cout << deck._deck.at(i)._rank << deck._deck.at(i)._suit << std::endl;
    }
}

// The default position of a transformable object is (0, 0).
// The default rotation of a transformable object is 0.
// The default scale of a transformable object is (1, 1).
// for now, forget money and set the starting chips to 300
int main()
{
    Deck blackJackDeck;
    blackJackDeck.shuffleDeck();
    printDeck(blackJackDeck);
    std::cout << std::endl;
    blackJackDeck.shuffleDeck();
    printDeck(blackJackDeck);
    
    // seed the random number generator for the blackjack deck shuffle.
    gen.seed(static_cast<unsigned int>(std::time(0)));
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    // get the size of the window, might use these later.
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    
    // call it once, after creating the window
    window.setVerticalSyncEnabled(true);
    
    
    // try to get the vector of cards working
    int textlinescounter = 0;
    sf::Texture textureName;
    sf::Sprite spriteName;
    std::string stringData;
    
    std::vector<sf::Texture> textureVector;
    std::vector<sf::Sprite> spriteVector;
    std::vector<std::string> fileNameVector;
    
    std::ifstream fileNameIfStream;
    fileNameIfStream.open("/Users/maxdietz/Desktop/GUIGame/GUIGame/mydata.txt");
    
    while(fileNameIfStream >> stringData)
    {
        textlinescounter++;
        fileNameVector.push_back(stringData);
    }
    
    for(int i=0; i < textlinescounter; i++)
    {
        textureVector.push_back(textureName);
        spriteVector.push_back(spriteName);
//        fileNameVector.push_back(fileNameVector[i]);
    }
    
    for(int i=0; i < textlinescounter; i++)
    {
        (textureVector[i]).loadFromFile(fileNameVector[i]);
        (spriteVector[i]).setTexture(textureVector[i]);
    }
    
//    // Loop to make all the cards smaller.
//    for (auto it = spriteVector.begin(); it != spriteVector.end(); ++it)
//    {
//        (*it).scale(0.14, 0.14);
//    }
    
//    //rescale the player and dealer cards.
//    spriteVector.at(0).scale(1.5, 1.5);
//    spriteVector.at(1).scale(1.5, 1.5);
//    spriteVector.at(2).scale(1.5, 1.5);
//    spriteVector.at(3).scale(1.5, 1.5);
//    spriteVector.at(1).move(160, 0);
//    spriteVector.at(2).move(480, 0);
//    spriteVector.at(3).move(640, 0);
//
//    // Potential hit cards.
//    spriteVector.at(4).move(150, 250);
//    spriteVector.at(5).move(250, 250);
//    spriteVector.at(6).move(350, 250);
//    spriteVector.at(7).move(450, 250);
//    spriteVector.at(8).move(550, 250);
    
    
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
    
    

    // User this later
    // sf::FloatRect boundingBox = two_of_clubs.getGlobalBounds();
    
    // Create a sf::Music and put it to play for the program duration.
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Sounds/loopmus.ogg"))
        error("unable to load loop music from file");
    // Play the music
    music.setLoop(true);
    music.setVolume(70);
    music.play();
    
    
    // create and prepare texts for displaying basic welcome messages on the first page.
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
    

    // Try to setup the Buttons for Hit/Stay
    sf::Texture texture3;
    if (!texture3.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Buttons/Stay.png"))
        error("unable to load Stay Button from file");
    sf::Sprite stayButton;
    stayButton.scale(0.4, 0.5);
    stayButton.setTexture(texture3);
    stayButton.move(50, 490);
    sf::Text stayButtonText("STAY", font, 80);
    stayButtonText.setPosition(stayButton.getPosition());
    
    sf::Texture texture4;
    if (!texture4.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Buttons/Hit.png"))
        error("unable to load Hit Button from file");
    sf::Sprite hitButton;
    hitButton.scale(0.4, 0.5);
    hitButton.setTexture(texture4);
    hitButton.move(250, 490);
    sf::Text hitButtonText("HIT", font, 80);
    hitButtonText.setPosition(hitButton.getPosition());
    hitButtonText.move(20, 0);
    
    
    // Setup a Submit Bet Button
    sf::Texture texture5;
    if (!texture5.loadFromFile("/Users/maxdietz/Desktop/GUIGame/GUIGame/Buttons/Submit.png"))
        error("Unable to load Submit Bet Button");
    sf::Sprite submitBetButton;
    submitBetButton.scale(1.0, 0.5);
    submitBetButton.setTexture(texture5);
    submitBetButton.move(20, 490);
    sf::Text submitBetButtonText("SUBMIT BET", font, 75);
    submitBetButtonText.setPosition(submitBetButton.getPosition());
    submitBetButtonText.move(15, 5);
    submitBetButtonText.setFillColor(sf::Color::Blue);
    
    
    // big scoped variables
    bool isWelcomeScreen = true;
    bool isBetSubmitted = false;
    bool hasStartingChips = true; // need better idea for this chip tracking later.


    sf::Sprite* firstCard = getFirstCardSprite(blackJackDeck, spriteVector, 0);
    sf::Sprite* secondCard = getFirstCardSprite(blackJackDeck, spriteVector, 1);
    secondCard->move(160, 0);
    
    // Program loop
    while(window.isOpen())
    {
        // variable to hold the temp mouse position on the current frame.
        sf::Vector2f tempMouse(sf::Mouse::getPosition(window));
        
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
                isWelcomeScreen = false;
            }
            
            
            if (submitBetButton.getGlobalBounds().contains(tempMouse) &&
                            event.type == sf::Event::MouseButtonReleased &&
                            event.key.code == sf::Mouse::Left)
            {
                
                isBetSubmitted = true;
               /*
                
                Add code here to the chip sprites on screen, so when you click the bet goes up in intervals.
                
                */
            }
        }
        
        // Clear the whole window before rendering a new frame
        window.clear();
        
        // Test code for checking card display.
//        for (auto it = spriteVector.begin(); it != spriteVector.end(); ++it)
//        {
//            window.draw(*it);
//        }

        
        // Welcome screen is drawn first.
        if (isWelcomeScreen == true)
        {
            // The inital load screen
            window.draw(welcomeMessage);
            window.draw(betDisplay1);
            window.draw(betDisplay2);
            window.draw(beginMessage);
        }
        
        // Then the Submit bet button and chips appear until the player submits the bet.
        // - after submitting the chips will stay on screen and the submit bet button will be
        // replaced by the hit and stay buttons.
        if (hasStartingChips == true && isWelcomeScreen == false)
        {
            if (isBetSubmitted == false)
            {
                window.draw(submitBetButton);
                window.draw(submitBetButtonText);
                window.draw(whiteChip);
                window.draw(redChip);
                window.draw(purpleChip);
            }
            else
            {
                // Replace the submit bet button with these
                window.draw(stayButton);
                window.draw(stayButtonText);
                window.draw(hitButton);
                window.draw(hitButtonText);
                window.draw(whiteChip);
                window.draw(redChip);
                window.draw(purpleChip);
            }
        }
        
        if (isBetSubmitted == true)
        {
            /*
             // add a card drawing noise here to play quickly for 2 cards.
             */
            
            window.draw(*firstCard);
            window.draw(*secondCard);
            

        }
                          
        // End the current frame and display its contents on screen.
        window.display();
    }
}

