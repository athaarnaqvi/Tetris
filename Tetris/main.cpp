/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */


//ATHAAR NAQVI          22I-1166    E
#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <iostream>
using namespace sf;
using namespace std;
int main(){  //main


   //to create window of the menu
     RenderWindow window3(VideoMode(320, 480), "Menu");
     // to load frame and background
     Texture object1,object2;
     object1.loadFromFile("img/background.png");
     object2.loadFromFile("img/frame.png");
     
     Sprite sprite(object1) ,fr(object2);
     // text to display
     Font font;
     font.loadFromFile("arial.ttf");
     Text text("Menu", font, 40);
     text.setPosition(30,30);
     
     Text text1("1.Start a new game",font, 20);
     text1.setPosition(30,90);
      
     Text text2("2.See high scores",font, 20);
     text2.setPosition(30,130);
     
     Text text3("3.Help",font, 20);
     text3.setPosition(30,170);

     Text text4("4.Exit",font, 20);
     text4.setPosition(30,210);
     
   
     while(window3.isOpen()){ //1
     
     Event event;
      while(window3.pollEvent(event)){  //2
      if(event.type == Event::Closed)
      window3.close();
      
     if (event.type == Event::KeyPressed) {  
     //*******************************************************************************************************************************************************           
                if (event.key.code == Keyboard::Num1){  //game  // when 1 is pressed game will be started         
      window3.close();         
         srand(time(0));
    RenderWindow window(VideoMode(320, 480), "Tetris By Athaar");
    Texture obj1, obj2, obj3;
     
     obj1.loadFromFile("img/tiles.png");
     obj2.loadFromFile("img/background.png");
     obj3.loadFromFile("img/frame.png");
     
  
    Sprite sprite(obj1), background(obj2), frame(obj3);
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.3;
    bool rotate=0;
    int box=0;
    int scores=0; //for scores
  int scorecount=0; //scorecount simultaneously
    
    
    Clock clock;
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                           //Change in X-Axis - Positive
                else if (e.key.code == Keyboard::Space)    // Check if the other key pressed is Space key
                 delay=0;                                  // turns the time to zero so the box will drop
                 
            }
            
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
       
       
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
     
      
      fallingPiece(timer, delay , colorNum,box);  //Example: fallingPiece() function is called here 
      /*
      the falling piece function generates the shapes
      it also assign random colors to the boxes
      */
      
     if(box==0) {Bomb(gameGrid);} 
     /* when box=0 means the bomb will fall and destroy the rows and certain coloumns */
     
      move(delta_x,box);
     /*  it ensures the left and right movement of the shapes*/ 
      
      linesvanish(gameGrid,M,N,scorecount);
      //it clears the lines
      
      if(rotate){
      Rotate(box);     
   }  
    // it rotates the box
    
      scores = scoreboard(scorecount); 
      
      // it counts the score
  
    
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////

     delta_x=0; rotate=0; delay=0.3;
     
     // this loop terminates the window when the blocks reach the top 
     for(int i=0;i<2;i++){
     if(gameGrid[i][1]>0){
     window.close();
     /////////////////////////GAMEOVER WINDOW//////////////////////////////////
     RenderWindow window(VideoMode(320,480),"Game Over");
   Texture o1, o2;         //just for the sake of changing names
   o1.loadFromFile("img/background.png");
   o2.loadFromFile("img/frame.png");
   
     
     Sprite sprite(o1) ,fr(o2);
     // text to display
     Font font;
     font.loadFromFile("arial.ttf");
     Text text("GAME", font, 40);
     text.setPosition(45,50);
     
     Text text1("OVER", font, 40);
     text1.setPosition(45,90);
     
     Text text2("to close window press C",font,10);
     text2.setPosition(30,290);
                   
       while(window.isOpen()){
     Event eve;
      while(window.pollEvent(eve)){
      if(eve.type == Event::Closed)
      window.close();
       if (eve.type == Event::KeyPressed) {            
                if (eve.key.code == Keyboard::C)           
                    window.close();             
      }
      }
      
       window.clear();
      
      window.draw(sprite);
      window.draw(fr);
      
      window.draw(text);
  
       window.draw(text1);
          
      window.draw(text2); 
      
      window.display();
      
      }
      
     //////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!///////////////////////
     }}
        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
       window.display();
     
    }
   
     
     
    } //game
  //***************************************************************************************************************************************************//   
                                          
                 if (event.key.code == Keyboard::Num3){ //help   
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // window3.close(); 
   RenderWindow window(VideoMode(320,480),"Help");
   Texture o1, o2;         //just for the sake of changing names
   o1.loadFromFile("img/background.png");
   o2.loadFromFile("img/frame.png");
     
     Sprite sprite(object1) ,fr(object2);
     // text to display
     Font font;
     font.loadFromFile("arial.ttf");
     Text text("Rules:", font, 40);
     text.setPosition(30,30);
     
     Text text1("1.Be vigilant",font, 20);
     text1.setPosition(30,90);
      
     Text text2("2.I also don't know",font, 20);
     text2.setPosition(30,130);
     
     Text text3("the rules",font, 20);
     text3.setPosition(30,170);

     Text text4("3.Just adjust blocks",font, 20);
     text4.setPosition(30,210);
     
     Text text5("to complete the row",font, 20);
     text5.setPosition(30,250);
     
     Text text6("to close window press C",font,10);
     text6.setPosition(30,290);
                   
       while(window.isOpen()){
     Event eve;
      while(window.pollEvent(eve)){
      if(eve.type == Event::Closed)
      window.close();
       if (eve.type == Event::KeyPressed) {            
                if (eve.key.code == Keyboard::C)           
                    window.close();             
      }
      }
      
       window.clear();
      
      window.draw(sprite);
      window.draw(fr);
      
      window.draw(text);
  
      window.draw(text1);
      
      window.draw(text2);
      
      window.draw(text3);
      
      window.draw(text4);
        
      window.draw(text5);  
          
      window.draw(text6); 
      
      window.display();
      
      }
      
      
     } //help
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                 
                    
                    }                      
                 if (event.key.code == Keyboard::Num2){   
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           
            RenderWindow window(VideoMode(320,480),"High Scores");
   Texture o1, o2;         //just for the sake of changing names
   o1.loadFromFile("img/background.png");
   o2.loadFromFile("img/frame.png");
   
     
     Sprite sprite(o1) ,fr(o2);
     // text to display
     Font font;
     font.loadFromFile("arial.ttf");
     Text text("High Scores", font, 30);
     text.setPosition(45,50);
     
     Text text1("343434", font, 30);
     text1.setPosition(45,90);
     
     Text text2("to close window press C",font,10);
     text2.setPosition(30,290);
                   
       while(window.isOpen()){
     Event eve;
      while(window.pollEvent(eve)){
      if(eve.type == Event::Closed)
      window.close();
       if (eve.type == Event::KeyPressed) {            
                if (eve.key.code == Keyboard::C)           
                    window.close();             
      }
      }
      
       window.clear();
      
      window.draw(sprite);
      window.draw(fr);
      
      window.draw(text);
  
       window.draw(text1);
          
      window.draw(text2); 
      
      window.display();
      
      }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////             
                     }                    
                if (event.key.code == Keyboard::Num4) {
                 window3.close();}
                 
            
      } //2
      window3.clear();
      
      window3.draw(sprite);
      window3.draw(fr);
      
      window3.draw(text);
  
      window3.draw(text1);
      
      window3.draw(text2);
      
      window3.draw(text3);
      
      window3.draw(text4);  
          
      
      window3.display();
     }//1
    
        
   
   
    
    return 0;
}  //main
