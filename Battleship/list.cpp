/*
 * File: list.cpp
 * Code: ADT list - array-based implementation
 * Name: Nicholas Campola
 * Date: 10/12/2018
 * CPSC 340
 */

#ifndef LISTCPP
#define LISTCPP
#include "list.h"
#include <iomanip>

template<typename LISTTYPE>
List<LISTTYPE>::List(){
    size = 0;
}

template<typename LISTTYPE>
bool List<LISTTYPE>::isEmpty() const{
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}
template<typename LISTTYPE>
int List<LISTTYPE>::getSize() const{
    return size;
}

template<typename LISTTYPE>
void List<LISTTYPE>::insert(const LISTTYPE newItem){
    if(size<MAX_SIZE){
        items[size] = newItem;
        size++;
       // cout<<newItem<< " has been inserted"<<endl;
    }
}
//Inserts an item into the list at position index.
template<typename LISTTYPE>
void List<LISTTYPE>::replace(const LISTTYPE newItem, int index){
    items[index] = newItem;
    //cout<<items[index]<<endl;
}

template<typename LISTTYPE>
LISTTYPE List<LISTTYPE>::remove(int index){
    LISTTYPE removed; //the index value to be removed
    LISTTYPE temp; //used to temporarily save a value before transfering a new value
    if(index < MAX_SIZE){
        //cout<< items[index]<< " was removed"<<endl;
        removed = items[index];
        for(int i = index; i < size-1; i++){
            temp = items[i+1];
            items[i] = temp;
            
        }
        size = size - 1;
    } else {
        cout << "position out of bound" << endl;
    }
    return removed;
}
template<typename LISTTYPE>
bool List<LISTTYPE>::retrieve(int index, LISTTYPE &value) const{
    //item at position <position>  is: <element>
    if(index < MAX_SIZE){
        value = items[index];
        return true;
        }
    else {
        return false;
    }

}

template<typename LISTTYPE>    
void List<LISTTYPE>::print() const{
    cout<<"|";
    for(int i = 0; i < size; i++){
        cout<< setw(2) << items[i];
    }
    cout<<" |"<<endl;
}

template<typename LISTTYPE> 
void List<LISTTYPE>::sort(){
	cout<<"Sorting .........."<<endl;
    for(int i = 0; i < size; i++){
        for(int j = 0; j <  size - 1 - i; j++){
            if(items[j] > items[j+1]){
                LISTTYPE temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}
#endif