//
//  board.hpp
//  Battleship
//
//  Created by Jennifer Polack on 9/25/18.
//  Copyright © 2018 Jennifer Polack. All rights reserved.
//

/*
 * File: gameClass.h
 * Code: Creates two 2D board used for the game Battleship along with the methods to manipulate them
 * Name: Nicholas Campola
 * Date: 10/12/2018
 * CPSC 340
 */

#ifndef boardH
#define boardH
#include "list.h"
const int SIZE = 10; //Board size in the x and y directions (between 10 and 20)
class gameClass{
public:
    gameClass() ; //constructor
    const char BLANK = ' '; //Declare what a blank is
    const char SHIP = 'S';  //for final output & stored array
    const char MISS = 'o';  //Miss
    const char HIT = 'X';   //Hit
    const char NOBOMB = '.'; //Not bombed for user display
    
    
    /**
    Prints out the rules of Battleship.
    */
    void rules(); 
    
    /**
    Fills both boards with a respective character

    @param boardFill is the char used to fill the 2D board of the Cheat view
    @param userFill is the char used to fill the 2D board of the User view
    */
    void fillBoard(char boardFill, char userFill);
    
    /**
    Places ships of similar length onto the Cheat view board

    @param targetsOpen is incremented each time a ship space is placed
    */
    void placeShip(int& targetsOpen);
    
    /**
    Reintializes the boards to have no ships or other values, acts as a new game
    */
    void boardShipRewrite();
    
    /**
    Places bombs on the map, the value of the index specified by the user is determined by whether a ship space is located on that index

    @param targetsOpen decrements each time a ship spot has been bombed
    */
    void dropBomb(int& targetsOpen);
    
    /**
    Prints out the cheat view board
    */
    void dispBoardCheat();
    
    /**
    Prints out the cheat view board
    */
    void dispBoard();
private:
        List<char> board[SIZE];         //init main play board
        List<char> userView[SIZE];      //User view, only shows bombs dropped
};

#endif /* board_hpp */
