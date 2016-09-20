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
#include <Thor/Input.hpp>
#include "DataTables.hpp"
#include "Typewriter.hpp"
#include "HexGrid.hpp"
#include <thread>




// Blackjack random number generator for values (0 - 51)
boost::mt19937 gen;

//// Enumeration for user-defined actions
//enum MyAction
//{
//    Location,
//    Quit,
//    Resize,
//};
//
//
//void onLocation(thor::ActionContext<MyAction> context)
//{
//    // context.Window is a pointer to the sf::Window passed to the thor::ActionMap constructor. It can
//    // be used for mouse input relative to a window, as follows:
//    sf::Vector2i mousePosition = sf::Mouse::getPosition(*context.window);
//    std::cout << "Location: " << thor::toString(mousePosition) << std::endl;
//}
//
//void onResize(thor::ActionContext<MyAction> context)
//{
//    // The sf::Event member variable called type has always the value
//    // - sf::Event::Resized, as specified in the thor::Action constructor.
//    // Since the Resize action has been triggered by an sf::Event
//    // - (and not by a sf::Keyboard, sf::Mouse or sf::Joystick),
//    // - we can also be sure that context.event is no null pointer.
//    sf::Event event = *context.event;
//    std::cout << "Resized!   New size = (" << event.size.width << ", " << event.size.height << ")" << std::endl;
//}

// The default position of a transformable object is (0, 0).
// The default rotation of a transformable object is 0.
// The default scale of a transformable object is (1, 1).
// for now, forget money and set the starting chips to 300

// TODO: add a get value function and add the values together of my first 2 cards
// for animation idea:
// http://pushbuttonreceivecode.com/blog/simple-boss-example-using-sfml-and-thor


int getCardValue(const Card& card, int& totalValueBefore)
{
    switch (card._rank)
    {
        case RANKS::RANK_TWO:		return 2;
        case RANKS::RANK_THREE:		return 3;
        case RANKS::RANK_FOUR:		return 4;
        case RANKS::RANK_FIVE:		return 5;
        case RANKS::RANK_SIX:		return 6;
        case RANKS::RANK_SEVEN:		return 7;
        case RANKS::RANK_EIGHT:		return 8;
        case RANKS::RANK_NINE:		return 9;
        case RANKS::RANK_TEN:		return 10;
        case RANKS::RANK_JACK:		return 10;
        case RANKS::RANK_QUEEN:	    return 10;
        case RANKS::RANK_KING:		return 10;
        case RANKS::RANK_ACE:
        {
            if ((totalValueBefore + 11) > 21)
            {
                return 1;
            }
            else
            {
                return 11;
            }
        }
    }
    
    return 0;
}



int main()
{
    gen.seed(static_cast<unsigned int>(std::time(0)));
    
    Deck blackJackDeck;
//    blackJackDeck.fillDeckWithCards();
    blackJackDeck.shuffleDeck();
    blackJackDeck.printDeck();
    
    std::vector<Card>::iterator cardPtr = blackJackDeck._deck.begin();
//    const Card* cardPtr = &blackJackDeck._deck[0];
    std::cout << std::endl;
    int playersTotal = 0;
    int dealersTotal = 0;
    
    std::cout << *cardPtr << std::endl;
    playersTotal += getCardValue((*cardPtr++), playersTotal);
    std::cout << *cardPtr << std::endl;
    playersTotal += getCardValue((*cardPtr++), playersTotal);
    std::cout << "Player Cards Value: " << playersTotal << std::endl;
    
    
    std::cout << *cardPtr << std::endl;
    dealersTotal += getCardValue((*cardPtr++), dealersTotal);
    
    std::cout << *cardPtr << std::endl;
    dealersTotal += getCardValue((*cardPtr++), dealersTotal);
    std::cout << "Dealer Cards Value: " << dealersTotal << std::endl;


    
    // setup XML file tracking
    BJ::opstruct op;
    int vol;
    int eff;

    // If we can't load the options file it's their first time playing.
    if (!op.loadOptions(op, "options.xml"))
    {
        std::cerr << "Sound options not loaded." << std::endl;
        std::cout << "Music volume: " << vol << "\n" << "Effects volume: " << eff << std::endl;
        std::cout << "Enter music volume: " << std::endl;
        std::cin >> vol;
        std::cout << "Enter sound effects volume: " << std::endl;
        std::cin >> eff;
        op._volume = vol;
        op._effects = eff;
        vol = op._volume;
        eff = op._effects;
        std::cout << "Music volume: " << vol << "\n" << "Effects volume: " << eff << std::endl;
    }
    
    if (!op.saveOptions(op, "options.xml"))
    {
        std::cerr << "Could not save options." << std::endl;
    }
    
    // seed the random number generator for the blackjack deck shuffle.
    
    
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
    // 50 white chips for 1$ each - total value - (50$)
    // (300$) all together.
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
    sf::Text welcomeMessage("Welcome to the BlackJack table!.", font, 60);
    sf::Text beginMessage("Click      to Begin playing.", font, 60);
    sf::Text loseMessage("YOU LOSE", font, 120);
    sf::Text winMessage("YOU WIN", font, 120);
    sf::Text pushMessage("PUSH - SAME SCORE", font, 120);
    
    pushMessage.move(300.f,300.f);
    winMessage.move(300.f, 300.f);
    loseMessage.move(300.f, 300.f);
    welcomeMessage.move(0, 0);
    beginMessage.move(0, 500.f);
    
    // Try to setup updated Buttons
    gui::button playBtn("Play!", font, sf::Vector2f(100.f,100.f), gui::style::save);
    gui::button hitBtn("Hit", font, sf::Vector2f(100.f, 200.f), gui::style::clean); // changed from cancel
    gui::button stayBtn("Stay", font, sf::Vector2f(300.f, 100.f), gui::style::clean);
    gui::button submitBetBtn("Submit Bet", font, sf::Vector2f(300.f, 200.f), gui::style::none);
    
    playBtn.setPosition(sf::Vector2f(160.f,550.f));
    playBtn.setColorNormal(sf::Color::Black);
    
//    hitBtn.setPosition(sf::Vector2f(100.f,520.f));
//    hitBtn.setSize(42);
    hitBtn.setBorderColor(sf::Color(255,255,255,255));
    hitBtn.setBorderRadius(10.f);
    hitBtn.setColorNormal(sf::Color::Red);
    
//    stayBtn.setPosition(sf::Vector2f(250.f,520.f));
//    stayBtn.setSize(34);
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
//    submitBetBtn.setPosition(sf::Vector2f(200.f,520.f));
//    submitBetBtn.setSize(50);
    
    
    
//    // Maybe map some actions out later: reference areas below
//    // https://github.com/Bromeon/Thor/blob/master/examples/Action.cpp
//    // http://www.bromeon.ch/libraries/thor/tutorials/v2.0/actions.html
//    thor::Action leftClickedOnce(sf::Mouse::Left, thor::Action::PressOnce);
//    thor::Action rightClickedOnce(sf::Mouse::Right, thor::Action::PressOnce);
//    thor::Action leftOrRightClickOnce = leftClickedOnce || rightClickedOnce;
//    thor::Action resizeTheWindow = thor::Action(sf::Event::Resized);
//    thor::Action quitTheGame = // Quit: Release the escape key or click the [X] (single events)
//    thor::Action(sf::Keyboard::Escape, thor::Action::ReleaseOnce) || thor::Action(sf::Event::Closed);
//    
//    // Setup mouse cord and resize actions with map
//    // Create thor::EventSystem to connect Resize and Shoot actions with callbacks
//    // Use connect0() instead of connect() when callback has no parameter
//    
//    thor::ActionMap<MyAction> map;
//    map[Location] = (leftClickedOnce || rightClickedOnce);
//    map[Resize] = resizeTheWindow;
//    map[Quit] = quitTheGame;
//    
//    thor::ActionMap<MyAction>::CallbackSystem system;
//    system.connect(Location, &onLocation);
//    system.connect(Resize, &onResize);
    
    // big scoped variables
    bool hasStartingChips = true; // Player starts with Chips, need better idea for this chip tracking later.
    bool isWelcomeScreen = true;
    bool isBetSubmitted = false;
    bool hasReachedEndOfTutorial = false;
    bool isDealersTurn = false;
    bool playerWins = false;
    bool playerLoses = false;
    bool isPush = false;
    int hitCounter = 0;
    
    sf::Sprite* firstCard = getFirstCardSprite(blackJackDeck, spriteVector, 0);
    sf::Sprite* secondCard = getFirstCardSprite(blackJackDeck, spriteVector, 1);
    secondCard->move(160, 0);
    
    
    // setup the dealers card positions and the dealers hidden card.
    sf::Texture cardBackTexture;
    if (!cardBackTexture.loadFromFile("/MP/cardback.png"))
        error("Unable to load cardbacktexture.");
    sf::Sprite cardBack;
    cardBack.setTexture(cardBackTexture);
    
    
    
    sf::Sprite* dealerFirstCard = getFirstCardSprite(blackJackDeck, spriteVector, 2);
    dealerFirstCard->move(485.f, 0.f);
    
    cardBack.scale(1.12f, 1.12f);
    cardBack.move(488.f,-12.f);
    
    sf::Sprite* dealerSecondCard = getFirstCardSprite(blackJackDeck, spriteVector, 3);
    dealerSecondCard->move(645.f, 0.f);
    
    sf::Sprite* HitCard1 = getFirstCardSprite(blackJackDeck, spriteVector, 4);
    HitCard1->scale(0.7, 0.7);
    HitCard1->move(200, 270);
    
    sf::Sprite* HitCard2 = getFirstCardSprite(blackJackDeck, spriteVector, 5);
    HitCard2->scale(0.7, 0.7);
    HitCard2->move(220, 270);
    
    sf::Sprite* HitCard3 = getFirstCardSprite(blackJackDeck, spriteVector, 6);
    HitCard3->scale(0.7, 0.7);
    HitCard3->move(240, 270);
    
    sf::Sprite* HitCard4 = getFirstCardSprite(blackJackDeck, spriteVector, 7);
    HitCard4->scale(0.7, 0.7);
    HitCard4->move(260, 270);
    
    sf::Sprite* HitCard5 = getFirstCardSprite(blackJackDeck, spriteVector, 8);
    HitCard5->scale(0.7, 0.7);
    HitCard5->move(280, 270);
    
    // setup typewriter to replace the inital welcome messages.
    std::vector<WelcomeScreenMessages> welcomeMsgData = initalizeEnemyProfileData();
    
    std::map<sf::Uint32, std::string> welcomeMsgInfo;
    welcomeMsgInfo[0] = welcomeMsgData[0].name + "\n\n" + welcomeMsgData[0].description;
    welcomeMsgInfo[1] = welcomeMsgData[1].name + "\n\n" + welcomeMsgData[1].description;
    welcomeMsgInfo[2] = welcomeMsgData[2].name + "\n\n" + welcomeMsgData[2].description;
    welcomeMsgInfo[3] = welcomeMsgData[3].name + "\n\n" + welcomeMsgData[3].description;
    
    std::size_t currItem = 0;
    std::size_t maxIter = welcomeMsgInfo.size()-1;
    std::cout << maxIter << std::endl;
    
    sf::Font myFont;
    if (!myFont.loadFromFile("/MP/cont.ttf"))
        std::cerr << "Could not load font cont.ttf" << std::endl;
    
    Typewriter myTypeWriter("empty", myFont, 32, .01f);
    myTypeWriter.setPosition(sf::Vector2f(400.f, 200.f));
    
    
    // typewriter works, try to setup background grid
    mpbgs::hexgrid backgroundGrid(window, mpbgs::hexgrid::hexStyle::colorful, 0.90f);
    
    // Program loop
    while(window.isOpen())
    {
//        map.update(window);
//        
//        if (map.isActive(Quit))
//            window.close();
        // The map is interfereing with my other button events, gonna think of a solution.
        // maybe one here - http://www.gamefromscratch.com/?tag=/SFML&page=2
        
        // variable to hold the temp mouse position on the current frame.
        sf::Vector2f tempMouse(sf::Mouse::getPosition(window));
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                    {
                        window.close();
                        return 0;
                    }
                    break;
                        
                    case sf::Keyboard::Left:
                    {
                        if (currItem <= 0)
                            currItem = 0;
                        else
                            currItem--;
                        
                        myTypeWriter.reset();
                    }
                    break;
                        
                    case sf::Keyboard::Right:
                    {
                        if (currItem >= maxIter)
                            currItem = maxIter;
                        else
                            currItem++;
                        
                        myTypeWriter.reset();
                    }
                    break;
                        
                    case sf::Keyboard::Return:
                    {
                        if (currItem >= maxIter)
                            currItem = maxIter;
                        else
                            currItem++;
                        
                        myTypeWriter.reset();
                    }
                    
                    default:
                        break;
                }
            }
            
            // Welcome screen is drawn first.
            // TODO: make a check for the bet being greater than 0 before executing this code.
            if (isWelcomeScreen && playBtn.getState() == gui::state::clicked)
            {
                submitBetBtn.setPosition(sf::Vector2f(200.f,520.f));
                submitBetBtn.setSize(50);
                // Need to increase the bet from Player class or subtract chip total
                isWelcomeScreen = false;
            }
            
            
            if (submitBetBtn.getState() == gui::state::clicked)
            {
                    stayBtn.setPosition(sf::Vector2f(250.f,520.f));
                    stayBtn.setSize(34);
                    hitBtn.setPosition(sf::Vector2f(100.f,520.f));
                    hitBtn.setSize(42);

                
                isBetSubmitted = true;
               /*
                Add code here to the chip sprites on screen, so when you click the bet goes up in intervals.
               */
            }
            
            if (stayBtn.getState() == gui::state::clicked)
            {
                isDealersTurn = true;
            }
            
            if (hitBtn.getState() == gui::state::clicked)
            {
                hitCounter += 1;
                if (hitCounter == 5)
                {
                    
                    playersTotal += getCardValue((*cardPtr++), playersTotal);
                    std::cout << "Hit Requested, new total: " << playersTotal << std::endl;
                }
                
                if (hitCounter == 4)
                {
                    
                    playersTotal += getCardValue((*cardPtr++), playersTotal);
                    std::cout << "Hit Requested, new total: " << playersTotal << std::endl;
                }
                
                if (hitCounter == 3)
                {
                   
                    playersTotal += getCardValue((*cardPtr++), playersTotal);
                    std::cout << "Hit Requested, new total: " << playersTotal << std::endl;
                }
                
                if (hitCounter == 2)
                {
                  
                    playersTotal += getCardValue((*cardPtr++), playersTotal);
                    std::cout << "Hit Requested, new total: " << playersTotal << std::endl;
                }
                
                if (hitCounter == 1)
                {
          
                    playersTotal += getCardValue((*cardPtr++), playersTotal);
                    std::cout << "Hit Requested, new total: " << playersTotal << std::endl;
                }
            }
            

            
            // Code for updating the events of my buttons
            playBtn.update(event,window);
            hitBtn.update(event,window);
            stayBtn.update(event,window);
            submitBetBtn.update(event,window);
            
            if (dealersTotal < 17 && isDealersTurn == true)
            {
                hitCounter += 1;
                if (hitCounter == 5)
                {
                    
                    HitCard5->move(280, 0);
                    dealersTotal += getCardValue((*cardPtr++), dealersTotal);
                    std::cout << "Hit Requested, new total: " << dealersTotal << std::endl;

                }
                
                if (hitCounter == 4)
                {
                    
                    HitCard4->move(260, 0);
                    dealersTotal += getCardValue((*cardPtr++), dealersTotal);
                    std::cout << "Hit Requested, new total: " << dealersTotal << std::endl;
  
                }
                
                if (hitCounter == 3)
                {
                    
                    HitCard3->move(240, 0);
                    dealersTotal += getCardValue((*cardPtr++), dealersTotal);
                    std::cout << "Hit Requested, new total: " << dealersTotal << std::endl;
   
                }
                
                if (hitCounter == 2)
                {
                    
                    HitCard2->move(220, 0);
                    dealersTotal += getCardValue((*cardPtr++), dealersTotal);
                    std::cout << "Hit Requested, new total: " << dealersTotal << std::endl;

                }
                
                if (hitCounter == 1)
                {
                    HitCard1->move(200, 0);
                    dealersTotal += getCardValue((*cardPtr++), dealersTotal);
                    std::cout << "Hit Requested, new total: " << dealersTotal << std::endl;
                    
                }
            }
        }
        // POLL EVENT ENDS HERE
        

        
        if (dealersTotal > 21)
        {
            playerWins = true;
        }
        
        if (playersTotal > 21)
        {
            playerLoses = true;
        }
        
        if (dealersTotal >= 17 && dealersTotal <= 21 && isDealersTurn == true)
        {
            if (dealersTotal > playersTotal)
            {
                playerLoses = true;
                
            }
            else if (dealersTotal < playersTotal)
            {
                playerWins = true;
            }
            else
            {
                isPush = true;
            }
        }
        
        // Update typewriter current item
        myTypeWriter.setString(welcomeMsgInfo[currItem]);
        myTypeWriter.write();
            
        window.setTitle("Welcome: " + std::to_string(welcomeMsgInfo.size()) +
                        " --------- Current: " + welcomeMsgData[currItem].name);
        
        
        // Clear the whole window before rendering a new frame
        window.clear();
        
        // always draw the background grid.
        window.draw(backgroundGrid);
        

        if (hitCounter == 5)
        {
            window.draw(*HitCard1);
            window.draw(*HitCard2);
            window.draw(*HitCard3);
            window.draw(*HitCard4);
            window.draw(*HitCard5);
            
        }
        
        if (hitCounter == 4)
        {
            window.draw(*HitCard1);
            window.draw(*HitCard2);
            window.draw(*HitCard3);
            window.draw(*HitCard4);
            
        }
        
        if (hitCounter == 3)
        {
            window.draw(*HitCard1);
            window.draw(*HitCard2);
            window.draw(*HitCard3);
            
        }
        
        if (hitCounter == 2)
        {
            window.draw(*HitCard1);
            window.draw(*HitCard2);
        }
        if (hitCounter == 1)
        {
            window.draw(*HitCard1);
        }
        
        
        // need to setup the logic for these draws.
        
        
        if (isWelcomeScreen == true)
        {
            if (currItem == 3)
            {
                hasReachedEndOfTutorial = true;
                window.draw(playBtn);
                window.draw(beginMessage);
                window.draw(myTypeWriter);
                window.draw(welcomeMessage);
            }
            // The inital load screen
            // Draw the messeges and the playBtn
            
            window.draw(myTypeWriter);
            window.draw(welcomeMessage);
        }
        
        // Then the Submit bet button and chips appear until the player submits the bet.
        // - after submitting the chips will stay on screen and the submit bet button will be
        // replaced by the hit and stay buttons.
        if (hasStartingChips == true && isWelcomeScreen == false && isDealersTurn == false)
        {
            if (isBetSubmitted == false)
            {
                window.draw(submitBetBtn);
                window.draw(whiteChip);
                window.draw(redChip);
                window.draw(purpleChip);
            }
            else
            {
                // Replace the submit bet button with these
                window.draw(stayBtn);
                window.draw(hitBtn);
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
            // card back displays until player presses stay.
            
            window.draw(*dealerSecondCard);
            if (isDealersTurn == false)
                window.draw(cardBack);
        }
        
        // its the dealers turn if the player selects "stay" and they havent busted
        if (isDealersTurn == true)
        {
            // show the hidden card
            window.draw(*dealerFirstCard);
        }
            
        if (playerWins == true)
        {
            window.draw(winMessage);
        }
        if (playerLoses == true)
        {
            window.draw(loseMessage);
        }
        if (isPush == true)
        {
            window.draw(pushMessage);
        }
        
        

        
        // the window resized callback <-- probably wont use
        // map.invokeCallbacks(system, &window);
        
        // End the current frame and display its contents on screen.
        window.display();
        
        
        
        if (dealersTotal > 21)
        {
            playerWins = true;
            sleep(4);
            std::cout << "You win, dealer is over 21" << std::endl;
            window.close();
        }
        
        if (playersTotal > 21)
        {
            playerLoses = true;
            sleep(4);
            std::cout << "You lose, you went over 21" << std::endl;
            window.close();
        }
        
        if (dealersTotal >= 17 && dealersTotal <= 21 && isDealersTurn == true)
        {
            if (dealersTotal > playersTotal)
            {
                playerLoses = true;
                sleep(4);
                std::cout << "You lose, dealer has a higher score!" << std::endl;
                window.close();
            }
            else if (dealersTotal < playersTotal)
            {
                playerWins = true;
                sleep(4);
                std::cout << "You win, dealer has a lower score!" << std::endl;
                window.close();
            }
            else
            {
                isPush = true;
                sleep(4);
                std::cout << "You push, same score!" << std::endl;
                window.close();
            }
        }
    }
}