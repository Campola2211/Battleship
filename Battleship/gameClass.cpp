/*
 * File: gameClass.cpp
 * Code: Creates two 2D board used for the game Battleship along with the methods to manipulate them
 * Name: Nicholas Campola
 * Date: 10/12/2018
 * CPSC 340
 */
#ifndef boardCPP
#define boardCPP
#include "gameClass.h"
#include <iostream>
#include <iomanip>

gameClass::gameClass(){
          //init main play board
}


void gameClass::rules(){
    cout << "340 Battleship is a guessing game for one person." << endl;
    cout<< "The board is created by a 10 by 10 grid.  The " << endl;
    cout<<"locations of the fleets are concealed from the"<<endl;
    cout<<"player.  The columns of the grid are numbered"<<endl;
    cout<<"and the rows are numbers.  The user must enter "<<endl;
    cout<<"the desired target as a coordinate pair separated"<<endl;
    cout<<"by a space or a newline."<<endl;
    cout<<endl;
}
    void gameClass::fillBoard(char boardFill, char userFill){
        for(int i = 0; i < SIZE; i++){
            board[i].insert(boardFill);
            userView[i].insert(userFill);
            }
        }

    void gameClass::placeShip(int& targetsOpen){
        int row; //index for the row of the board
        int col; //index for the column of the board
        int Yfactor; //how the direction of the columns is decided
        int Xfactor; //how the direction of the rows is decided
        char place_one; //the first place of the ship
        char place_two; //the second place of the ship 
        char place_three; //the third place of the ship
        char place_four; //the fourth place of the ship
        char rowReset = 'N'; //the third place of the ship
        int iter = 1; //iterates the loop until false
        int reset = 0; //used as a counter for when all possible y-xfactor combinations have been used
        
        while(iter > 0){
            rowReset = 'N';
            row = rand()%SIZE;
            col = rand()%SIZE;
            int combo[23] = {-1,0, 2, -1,1, 2, -1,-1, 2, 1,1, 2, 1,0, 2, 1,-1, 2, 0,1, 2, 0,-1};//all possible combinations of y-xfactors
            int check[23] = { 3,3, 3,  3,3, 3,  3, 3, 3, 3,3, 3, 3,3, 3, 3, 3, 3, 3,3, 3, 3, 3};//used to cross reference y-x factors to see which have been used
         
         
            while(rowReset == 'N'){
                do
                {   Xfactor = rand()%3 - 1;
                    Yfactor = rand()%3 - 1;
                }while(Xfactor == 0 && Yfactor == 0);
        
                for(int i = 0; i < 22; i++){
                    if(Xfactor == combo[i] && Yfactor == combo[i+1]){
                        if(combo[i] != check[i] && combo[i+1] != check[i+1]){
                            check[i] = combo[i];
                            check[i+1] = combo[i+1];
                            reset = reset + 1;
                        }
                    }
                }
        
                if((row + 3 * (Xfactor)) > -1 && (row + 3 * (Xfactor)) < 10){
                    if((col + 3 * (Yfactor)) > -1 && (col + 3 * (Yfactor)) < 10){
                        board[col].retrieve(row, place_one);
                        board[col + 1 * (Yfactor)].retrieve(row + 1 * (Xfactor), place_two);
                        board[col + 2 * (Yfactor)].retrieve(row + 2 * (Xfactor), place_three);
                        board[col + 3 * (Yfactor)].retrieve(row + 3 * (Xfactor), place_four);
                        if(place_one == SHIP){
                            rowReset = 'Y';
                        }
                        if(place_one != SHIP && place_two != SHIP && place_three != SHIP && place_four != SHIP){
                            board[col].replace(SHIP,row);
                            targetsOpen++;
                            board[col + 1 * (Yfactor)].replace(SHIP,(row + 1 * (Xfactor)));
                            targetsOpen++;
                            board[col + 2 * (Yfactor)].replace(SHIP,(row + 2 * (Xfactor)));
                            targetsOpen++;
                            board[col + 3 * (Yfactor)].replace(SHIP,(row + 3 * (Xfactor)));
                            targetsOpen++;
                            iter = 0;
                            rowReset = 'Y';
                        }
                    }
                }
                if(reset == 8){
                    reset = 0;
                rowReset = 'Y';
                }
            }
        }
    }
    
    
    void gameClass::boardShipRewrite(){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                board[i].replace(BLANK, j);
                userView[i].replace(NOBOMB, j);
            }
        }
    }
    
    void gameClass::dropBomb(int& targetsOpen){
        char boardPiece; //the requested index of the board
        int row = -1;   //index for the row of the board
        int col = -1;  //index for the column of the board
        cout<<"Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed"<<endl;
        while(row == -1 && col == -1){
            cout<<"Please enter coord pair to drop bomb (Col,Row): ";
            cin >> row >> col;
            if((col < 0 || col >= SIZE) && (row < 0 || row >= SIZE)){
                cout<<"Index out of bounds, try again"<<endl;
                col = -1;
                row = -1;
            }
            board[col].retrieve(row, boardPiece);
            if(boardPiece == MISS || boardPiece == HIT){
               cout<<"Selection already bombed, please try again (Col,Row): ";
               col = -1;
               row = -1;
            }
        }
        cout<<endl;
        
        //cout<<boardPiece<<endl;
        if(boardPiece == BLANK){
            cout<<"Miss ";
            board[col].replace(MISS,row);
            userView[col].replace(MISS,row);
        }
        else if(boardPiece == SHIP){
            targetsOpen--;
            cout<<"HIT! ";
            board[col].replace(HIT,row);
            userView[col].replace(HIT,row);
        }
    }
    void gameClass::dispBoardCheat(){
        cout << "  ";
        for(int i = 0; i < SIZE; i++){
            cout <<  setw(2) << i;
        }
        cout<<endl;
        cout<<"  ---------------------"<<endl;
        for(int i = 0; i < SIZE; i++){
            cout << i;
            board[i].print();
    
        }
        cout<<"  ---------------------"<<endl;
    }
    void gameClass::dispBoard(){
        cout << "  ";
        for(int i = 0; i < SIZE; i++){
            cout <<  setw(2) << i;
        }
        cout<<endl;
        cout<<"  ---------------------"<<endl;
        for(int i = 0; i < SIZE; i++){
            cout << i;
            userView[i].print();
            
        }
        cout<<"  ---------------------"<<endl;
    }
#endif /* board_hpp */