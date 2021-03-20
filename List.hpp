#pragma once
#include "List.h"
#include "Sequence.h"

using namespace std;

template <class T>
List1<T>::List1() {


}// List Object -------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
List1<T>::~List1() {


}// List DECONSTRUCTOR ------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T> ::clear(void) {

    left.clear();
    right.clear();

}// Clear Function -------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T>::transferFrom(List1& source)
{
    
    left.transferFrom(source.left);
    right.transferFrom(source.right);

}// TransferFrom Function -------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
List1<T>& List1<T>::operator = (List1& rhs)
{
    left.operator = (rhs.left);
    right.operator = (rhs.right);
    return (*this);

}// Operator Function ------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T> ::moveToStart(void) {

    for (int i = 0; i < left.length(); i++) {

        right.add(left.entry(i), i);
        left.remove(left.entry(i), i);

    }//FOR STATEMENT

}// moveToStart Function ------------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T> ::moveToFinish(void) {

    for (int i = 0; i < right.length(); i++) {

        left.add(right.entry(i), i);
        right.remove(right.entry(i), i);

    }//FOR STATEMENT

}// moveToFinish Function -----------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T> ::advance(void) {

    if (right.length() == 0) {
        cout << "Right is empty\n";
    }//IF STATEMENT

    else {
        int x = right.entry(0);
        right.remove(x, 0);
        left.add(x, left.length());
    }//ELSE STATMENT

}// advance Function ------------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T> ::addRightFront(T& x) {

    right.add(x, 0);

}// addRightFront Function -------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T> ::removeRightFront(T& x) {

    if (right.length() == 0) {
        cout << "Right list is empty \n"; 
    }// IF STATEMENT
        
    else {
        right.remove(x, 0);
    }// ELSE STATEMENT

}// removeRightFront Function ----------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
T& List1<T>::rightFront() {
    
    return right.entry(0);

}// rightFront Function ----------------------------------------------------------------------------------------------------------------------------------------------------


template <class T>
void List1<T> ::replaceRightFront(T& x) {

    if (right.length() != 0) {
        T temp = x;
        right.remove(x, 0);
        right.add(temp, 0);
    }//IF STATEMENT

}// replaceRightFront Function -------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T>::swapRights(List1& otherS) {

    Sequence<T> temp;
    temp = right;
    right = otherS.right;
    otherS.right = temp;
    temp.clear();

}// swapRights Function -----------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
int List1<T>::leftLength(void) {

    return left.length();

}// leftLength Function -----------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
int List1<T>::rightLength(void) {

    return right.length();

}// rightLength Function ----------------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
void List1<T>::outputList(void) {

    cout << " ( ";
    left.outputSequence();
    cout << " , | ";
    right.outputSequence();
    cout << " ) ";
    cout << "\n";

}// output Function ----------------------------------------------------------------------------------------------------------------------------------------------------------
