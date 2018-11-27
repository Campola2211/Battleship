/*
 * File: main.cpp
 * Code: Utlizes the gameClass.h and list.h files to simulate a game of battleship
 * Name: Nicholas Campola
 * Date: 10/12/2018
 * CPSC 340
 */

#include<iostream>
#include<cstdlib>
#include"list.h"
#include"gameClass.h"
using namespace std;


int main(){
    
    int totalBombs; //total attempts at bombing the ships
    char boardpiece; //the requested index of the board
    char cheat; //used to enable and disable the cheat view
    int targetsOpen =0; //number of spaces all ships occupy
    int shipNum = 0; //number of ships total
    int gridSize = SIZE*SIZE; //total size of the board space
    char shipSizeBool = 'N'; //if the number of ships is reasonable or not
    int shipSize = 4; //number of spaces each ship occupies
    int num = 0; //maximum number of ships
    int beginBomb = 0; //begining amount of totalBombs, used to print out first statement
    
    
    srand(10);
    gameClass battleship;
    cout<<"Do you want to cheat? (Y/N)"<<endl;
    cin>>cheat;
    
    
    battleship.rules();
    num = (((gridSize - (shipSize * SIZE))/shipSize)+shipSize/* - (SIZE - shipSize)*/);
    cout<<"How many ships would you like to play with? ";
    cin>>shipNum;
    
    if(shipNum <= num){
        shipSizeBool = 'Y';
    }
    
    while(shipSizeBool == 'N'){
        cout<<"That number will not work for this board. Try again: "<<endl;
        cin>>shipNum;
        if(shipNum <= num){
            shipSizeBool = 'Y';
        }
    }
    
    totalBombs = (SIZE*2 + (shipNum * 4));
    beginBomb = (SIZE*2 + (shipNum * 4));
    
    for(int i = 0; i < 10; i++){
        battleship.fillBoard(' ', '.');
    }
    for(int i = 0; i < shipNum; i++){
        battleship.placeShip(targetsOpen);
    }
    while(totalBombs > 0 && targetsOpen > 0){
        if(cheat == 'Y'){
            cout<<"Cheat Board"<<endl;
            battleship.dispBoardCheat();
        }
        cout<<"User Board"<<endl;
        battleship.dispBoard();

        if(totalBombs == beginBomb){
            cout<<"You have "<<totalBombs<<" bombs.";
        }
        battleship.dropBomb(targetsOpen);
        totalBombs--;
        cout<<"You have "<<totalBombs<<" bombs left." << endl;
        if(totalBombs == 0){
            if(cheat == 'Y'){
                cout<<"Cheat Board"<<endl;
                battleship.dispBoardCheat();
            }
            cout<<"User Board"<<endl;
            battleship.dispBoard();
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout << "End Game   ";
            battleship.dispBoard();
            cout<<"Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed"<<endl;
            cout<<"You LOSE.....loser"<<endl;
        }
        if(targetsOpen == 0){
            if(cheat == 'Y'){
                cout<<"Cheat Board"<<endl;
                battleship.dispBoardCheat();
            }
            cout<<"User Board"<<endl;
            battleship.dispBoard();
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout << "End Game   ";
            battleship.dispBoard();
            cout<<"Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed"<<endl;
            cout<<"You Won!!  To bad, you blew all the ships up." <<endl;
        }
    }
    
    
    
    
    
    return 0;
}