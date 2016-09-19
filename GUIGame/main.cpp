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
//#include <Thor/Animations.hpp> <--- busted?
#include <Thor/Graphics.hpp>
#include "opstruct.hpp"
#include "button.hpp"

// Blackjack random number generator for values (0 - 51)
boost::mt19937 gen;





// The default position of a transformable object is (0, 0).
// The default rotation of a transformable object is 0.
// The default scale of a transformable object is (1, 1).
// for now, forget money and set the starting chips to 300

// TODO: add a get value function and add the values together of my first 2 cards
// - Then get the hit and stand buttons hooked up.

int main()
{
    Deck blackJackDeck;
//    blackJackDeck.fillDeckWithCards();
//    blackJackDeck.shuffleDeck();
    blackJackDeck.printDeck();
    
    
    // setup XML file tracking
    BJ::opstruct op;
    int vol, eff, diff;
    
// crashes the game first time if the file is not already in there.
// probably want to do a save first with basic info.
//    if (!op.loadOptions(op, "options.xml"))
//    {
//        std::cerr << "Could not load options." << std::endl;
//        vol = 2;
//        eff = 4;
//        diff = 1;
//    }
    
    vol = op._volume;
    eff = op._effects;
    diff = op._difficulty;
    
    std::cout << "Music volume: " << vol << "\n" << "Effects volume: " << eff << "\n" << "Difficulty: "
                                                                        << diff << std::endl;
    
    std::cout << "Enter music volume: " << std::endl;
    std::cin >> vol;
    
    std::cout << "Enter sound effects volume: " << std::endl;
    std::cin >> eff;
    
    std::cout << "Enter difficulty level: " << std::endl;
    std::cin >> diff;
    
    std::cout << "Music volume: " << vol << "\n" << "Effects volume: " << eff << "\n" << "Difficulty: "
                                                                        << diff << std::endl;
    
    op._volume = vol;
    op._effects = eff;
    op._difficulty = diff;
    
    if (!op.saveOptions(op, "options.xml"))
    {
        std::cerr << "Could not save options." << std::endl;
    }
    
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
        fileNameVector.push_back(fileNameVector[i]);
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
    sf::Text beginMessage("Click      to Begin playing.", font, 60);
    welcomeMessage.move(0, 0);
    betDisplay1.move(0, 90);
    betDisplay2.move(0, 130);
    beginMessage.move(0, 300);
    
    // Try to setup updated Buttons
    gui::button playBtn("Play!", font, sf::Vector2f(100.f,100.f), gui::style::save);
    gui::button hitBtn("Hit", font, sf::Vector2f(100.f, 200.f), gui::style::clean); // changed from cancel
    gui::button stayBtn("Stay", font, sf::Vector2f(300.f, 100.f), gui::style::clean);
    gui::button submitBetBtn("Enter Bet", font, sf::Vector2f(300.f, 200.f), gui::style::none);
    
    playBtn.setPosition(sf::Vector2f(160.f,340.f));

    
    hitBtn.setPosition(sf::Vector2f(100.f,520.f));
    hitBtn.setSize(42);
    hitBtn.setBorderColor(sf::Color(255,255,255,255));
    hitBtn.setBorderRadius(10.f);
    hitBtn.setColorNormal(sf::Color::Red);
    
    stayBtn.setPosition(sf::Vector2f(250.f,520.f));
    stayBtn.setSize(34);
    stayBtn.setBorderColor(sf::Color(255,255,255,255));
    stayBtn.setBorderRadius(10.f);
    stayBtn.setColorNormal(sf::Color::Red);
    
    submitBetBtn.setBorderThickness(2.f);
    submitBetBtn.setBorderRadius(20.f);
    submitBetBtn.setBorderColor(sf::Color(255,255,255,255));
    submitBetBtn.setColorNormal(sf::Color(200,0,200,255));
    submitBetBtn.setColorHover(sf::Color(255,0,255,100));
    submitBetBtn.setColorClicked(sf::Color(150,0,150,255));
    submitBetBtn.setColorTextNormal(sf::Color(255,255,255,255));
    submitBetBtn.setColorTextHover(sf::Color(255,255,0,255));
    submitBetBtn.setColorTextClicked(sf::Color(255,0,0,255));
    submitBetBtn.setPosition(sf::Vector2f(200.f,520.f));
    submitBetBtn.setSize(50);
    
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
        
        
        
        playBtn.update(event,window);
        hitBtn.update(event,window);
        stayBtn.update(event,window);
        submitBetBtn.update(event,window);
        
        
        // Clear the whole window before rendering a new frame
        window.clear();
        
        // Test code for checking card display.
//        for (auto it = spriteVector.begin(); it != spriteVector.end(); ++it)
//        {
//            window.draw(*it);
//        }
        window.draw(playBtn);
        window.draw(hitBtn);
        window.draw(stayBtn);
        window.draw(submitBetBtn);
        
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

