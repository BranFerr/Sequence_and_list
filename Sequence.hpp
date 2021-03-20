#pragma once
#include <iostream>
#include <cstdio>

using namespace std;
#include "Sequence.h"

template <class T>
Sequence<T>::Sequence()
{
    head = NULL;
    size = 0;
}// Sequence

template <class T>
Sequence<T>::~Sequence()
{
    reclaimAllNodes(head);
}    // ~Sequence


template <class T>
void Sequence<T>::clear(void)
{
    reclaimAllNodes(head);
    head = NULL;
    size = 0;
} // clear

template <class T>
void Sequence<T>::reclaimAllNodes(NodeRecord*& initialP)
// requires: Null(initialP)  or  Alive(initialP)
//  ensures: all nodes in linked list
//           beginning with initialP are reclaimed
{
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    } // end if
} // reclaimAllNodes

// You are required to implement add(+), remove(+), entry(+), length(+), and outputSequence(+) functions here.


//FUNCTIONS -------------------------------------------------------------------------------------------------------------
template <class T>
void Sequence<T> ::add(T& x, int pos) {

    //cout << "\n entering add function";

    if (pos > size)
        cout << "\n Invalid\n";

    else {

        if (pos == 0) {
            NodeRecord* temp = new NodeRecord;
            temp->next = head;
            head = temp;
            head->value = x;
            size++;
        }//If Statement

        else {
            NodeRecord* current = head;
            for (int a = 0; a < pos - 1; a++) {
                current = current->next;
            }//For Statement

            NodeRecord* temp = new NodeRecord;
            temp->next = current->next;
            current->next = temp;
            size++;
            temp->value = x;
        }

    }//Else

}// ADD FUNCTION ------------------------------------------------------------------------------------------------------------------------


template <class T>
void Sequence<T> ::remove(T& x, int pos) {
    if (pos >= size) {
        cout << "Invalid position\n";
        return;
    }// IF STATMENT

    if (pos == 0) {
        NodeRecord* temp = head;
        // HERE!!!! You need the next two statements! 
        x = temp->value; // 
        head = head->next;
        temp->next = NULL;
        delete temp;
    }// IF STAMTENT

    else {
        NodeRecord* current = head;
        for (int a = 0; a < pos - 1; a++) {
            current = current->next;
        }//FOR STATEMENT

        NodeRecord* temp = current->next;
        current->next = temp->next;
        x = temp->value;
        delete temp;
    }//ELSE STATEMENT

    size--; //DONT FORGET ABOUT THIS YOU SILLY GOOSE!

}// REMOVE FUNCTION----------------------------------------------------------------------------------------------------------------------


template <class T>
void Sequence <T> ::outputSequence(void) {

    if (size == 0) {
        cout << " <> ";
        return;
    }//if 
    else {
        NodeRecord* current = head;
        cout << "<";
        while (current != NULL) {

            cout << current->value;
            cout << ", ";
            current = current->next;
        }// while
    }// else
    cout << ">";

}//OUTPUT SEQUENCE FUNCTION--------------------------------------------------------------------------------------------------------------


template <class T>
int Sequence <T> ::length(void) {

    return size;

}// LENGTH FUNCTION ---------------------------------------------------------------------------------------------------------------------

template <class T>
T& Sequence<T>::entry(int pos) {

    if (pos < 0 || pos >= size) {
        cout << "Invalid, please check!\n";
        return head->value;
    }// IF STATMENT

    NodeRecord* current = head;
    for (int a = 0; a < pos; a++) {
        current = current->next;
    }//FOR STATMENT

    return current->value;


}// ENTRY FUNCTION


template <class T>
void Sequence<T>::transferFrom(Sequence& source)
{
    T temp;
    clear(); //clears self
    for (int i = 0; i < source.length(); i++)//traverses source
    {
        temp = source.entry(i);
        add(temp, length());//adds source elements to self
    }
    source.clear();//clears source

}// TransferFrom Function ---------------------------------------------------------------------------------------------------------------------------------------------

template <class T>
Sequence<T>& Sequence<T>::operator = (Sequence& rhs)
{
    clear();//clears self
    for (int i = 0; i < rhs.length(); i++)//traverses ehs
    {
        add(rhs.entry(i), length());//adds elements from rhs to self
    }
    return (*this);//returns self = rhs
}// Operator Function -------------------------------------------------------------------------------------------------------------------------------------------------


/*  Copy and paste PROPERLY LABELED (Must identify each and every output, what Sequence and what function being tested)
 */

 // You should use this main function to test you Sequence class. DO NOT CHANGE THIS MAIN!!!
 // If there are ERRORS, those are in your code you wrote! There are NO ERRORS in this main. 
 //----------- main function for Sequence class---------------------------
/*int main()
{

    Sequence<int> s1;
    Sequence<int> s2;
    Sequence<int> s3;
    int xi = 0;
    cout << "SEQUENCE ONE\nS1: ";
    s1.outputSequence();
    cout << "SEQUENCE ONE\nS1: ";
    cout << "\n\nTESTING ADD, OUTPUTSEQUENCE, LENGTH\nFilled S1 with <23, 14, 18, 31, 11>";
    xi = 23;
    s1.add(xi, 0);
    xi = 14;
    s1.add(xi, 1);
    xi = 18;
    s1.add(xi, 2);
    xi = 31;
    s1.add(xi, 3);
    xi = 11;
    s1.add(xi, 4);
    cout << "\nS1: ";
    s1.outputSequence();
    cout << "\nS1 size: " << s1.length() << "\n";

    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 17 to position 0";
    xi = 17;
    s1.add(xi, 0);
    cout << "\nS1: ";
    s1.outputSequence();
    cout << "\nS1 size: " << s1.length() << "\n";

    cout << "\n\nTESTING REMOVE\n+ OUTPUTSEQUENCE, LENGTH\nRemoved entry at position 3";
    s1.remove(xi, 3);
    cout << "\nElement removed: " << xi;
    cout << "\nS1: ";
    s1.outputSequence();
    cout << "\nS1 size: " << s1.length() << "\n";


    cout << "\n\nTESTING ENTRY\nS1[1]: " << s1.entry(1);
    cout << "\nS1[0]: " << s1.entry(0);

    cout << "\n\nTESTING CLEAR\n+ OUTPUTSEQUENCE\nClearing Sequence One\nS1:";
    s1.clear();
    s1.outputSequence();



    /* TESTING SEQUENCE TWO
        TESTED:
            ADD
            OUTPUTSEQUENCE
            LENGTH
            ENTRY
            REMOVE
            CLEAR
     */

     //Client does NOT abide by requires clauses
     //Goes over size


   /*cout << "\n\n\nSEQUENCE TWO\nS2: ";
    s2.outputSequence();

    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nFilled S2 with <1>";
    xi = 1;
    s2.add(xi, 0);
    cout << "\nS2: ";
    s2.outputSequence();
    cout << "\nS2 size: " << s2.length();

    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 3 to position 3";
    xi = 3;
    s2.add(xi, 3); //error because 3 > size
    cout << "\nS2: ";
    s2.outputSequence();
    cout << "\nS2 size: " << s2.length();

    cout << "\n\nENTRY\nS2[3]: ";
    cout << s2.entry(3); //error because 3 > size


    cout << "\n\nREMOVE, OUTPUTSEQUENCE\nRemoved entry at position 2";
    s2.remove(xi, 2);
    cout << "Element removed: " << xi;
    cout << "\nS2: ";
    s2.outputSequence();



    cout << "\n\nENTRY";
    cout << "\nS2[0]: ";
    cout << s2.entry(0);
    cout << "\nS2[1]: ";
    cout << s2.entry(1); //error because 1 = size
    cout << "\nS2[2]: ";
    cout << s2.entry(2); //error because 2 > size
    cout << "\nS2[3]: ";
    cout << s2.entry(3); //          ||

    cout << "\n\nCLEAR, OUTPUTSEQUENCE, LENGTH\nClearing Sequence Two";
    s2.clear();
    cout << "\nS2: ";
    s2.outputSequence();
    cout << "\nS2 size: " << s2.length();



    /* TESTING SEQUENCE THREE
       TESTED:
           ADD
           OUTPUTSEQUENCE
           LENGTH
           ENTRY
           REMOVE
           CLEAR
    */




    /*cout << "\n\n\nSEQUENCE THREE\nS3: ";
    s3.outputSequence();

    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nFilled S3 with <8, 23, 2000>";
    xi = 8; //08 => invalid octal digit ??
    s3.add(xi, 0);
    xi = 23;
    s3.add(xi, 1);
    xi = 2000;
    s3.add(xi, 2);
    cout << "\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();


    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 1 to position 0 + 6 to position 1 + 2002 to position 3>";
    xi = 1;
    s3.add(xi, 0);
    xi = 6;
    s3.add(xi, 1);
    xi = 2002;
    s3.add(xi, 2);
    cout << "\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();


    cout << "\n\nENTRY, REMOVE";
    cout << "\nS3[2]: " << s3.entry(2);
    cout << "\nRemoved entry at position 2";
    s3.remove(xi, 2);
    cout << "Element removed: " << xi;
    cout << "\nS3[2]: " << s3.entry(2);
    cout << "\nRemoved entry at position 2";
    s3.remove(xi, 2);
    cout << "Element removed: " << xi;
    cout << "\nS3[3]: " << s3.entry(2);


    cout << "\n\nOUTPUTSEQUENCE, LENGTH\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();


    cout << "\n\nCLEAR, OUTPUTSEQUENCE, LENGTH\nClearing Sequence Three";
    s3.clear();
    cout << "\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();


    cout << "\n\nADD, OUTPUTSEQUENCE, LENGTH\nAdded 6 to position 0, 2019 to position 1, and 25 to position 1";
    xi = 6;
    s3.add(xi, 0);
    xi = 2019;
    s3.add(xi, 1);
    xi = 25;
    s3.add(xi, 1);
    cout << "\nS3: ";
    s3.outputSequence();
    cout << "\nS3 size: " << s3.length();

    return 0;

} //main

/*
SEQUENCE ONE
S1: Error, Empty Sequence
SEQUENCE ONE
S1:

TESTING ADD, OUTPUTSEQUENCE, LENGTH
Filled S1 with <23, 14, 18, 31, 11>
S1: <23 , 14 , 18 , 31 , 11 , >
S1 size: 5


ADD, OUTPUTSEQUENCE, LENGTH
Added 17 to position 0
S1: <17 , 23 , 14 , 18 , 31 , 11 , >
S1 size: 6


TESTING REMOVE
+ OUTPUTSEQUENCE, LENGTH
Removed entry at position 3
Element removed: 18
S1: <17 , 23 , 14 , 31 , 11 , >
S1 size: 5


TESTING ENTRY
S1[1]: 23
S1[0]: 17

TESTING CLEAR
+ OUTPUTSEQUENCE
Clearing Sequence One
S1:Error, Empty Sequence



SEQUENCE TWO
S2: Error, Empty Sequence


ADD, OUTPUTSEQUENCE, LENGTH
Filled S2 with <1>
S2: <1 , >
S2 size: 1

ADD, OUTPUTSEQUENCE, LENGTH
Added 3 to position 3
 Invalid

S2: <1 , >
S2 size: 1

ENTRY
S2[3]: Invalid, please check!
1

REMOVE, OUTPUTSEQUENCE
Removed entry at position 2Invalid position
Element removed: 3
S2: <1 , >

ENTRY
S2[0]: 1
S2[1]: Invalid, please check!
1
S2[2]: Invalid, please check!
1
S2[3]: Invalid, please check!
1

CLEAR, OUTPUTSEQUENCE, LENGTH
Clearing Sequence Two
S2: Error, Empty Sequence

S2 size: 0


SEQUENCE THREE
S3: Error, Empty Sequence


ADD, OUTPUTSEQUENCE, LENGTH
Filled S3 with <8, 23, 2000>
S3: <8 , 23 , 2000 , >
S3 size: 3

ADD, OUTPUTSEQUENCE, LENGTH
Added 1 to position 0 + 6 to position 1 + 2002 to position 3>
S3: <1 , 6 , 2002 , 8 , 23 , 2000 , >
S3 size: 6

ENTRY, REMOVE
S3[2]: 2002
Removed entry at position 2Element removed: 2002
S3[2]: 8
Removed entry at position 2Element removed: 8
S3[3]: 23

OUTPUTSEQUENCE, LENGTH
S3: <1 , 6 , 23 , 2000 , >
S3 size: 4

CLEAR, OUTPUTSEQUENCE, LENGTH
Clearing Sequence Three
S3: Error, Empty Sequence

S3 size: 0

ADD, OUTPUTSEQUENCE, LENGTH
Added 6 to position 0, 2019 to position 1, and 25 to position 1
S3: <6 , 25 , 2019 , >
S3 size: 3
C:\Users\Branson\source\repos\Assignment 1\Debug\Assignment 1.exe (process 2676) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/





// ASSIGNMENT 2 OUTPUTS-------------------------------------------------------------------------------------------------------------------------------------------------
//**********************************************************************************************************************************************************************
/*
TESTING CLEAR-----------------

Code:

    q1.enqueue(x);
    q1.enqueue(y);
    q1.enqueue(z);
    q1.enqueue(a);
    q1.enqueue(b);

    q1.clear();

    q1.enqueue(x);
    q1.enqueue(y);

Output:
<2 , 4 , >



TESTING ENQUEUE----------------

Code:

  q1.enqueue(x);
  q1.enqueue(y);
  q1.enqueue(z);
  q1.enqueue(a);
  q1.enqueue(b);

Output:
<2 , 4 , 6 , 8 , 10 , >

TESTING DEQUEUE-----------------

Code:
  q1.enqueue(x);
  q1.enqueue(y);
  q1.enqueue(z);
  q1.enqueue(a);
  q1.enqueue(b);
  q1.dequeue(y);
  q1.dequeue(z);

Output:
<2 , 8 , 10 , >


TESTING LENGTH--------------------

Code:

  q1.enqueue(x);
  q1.enqueue(y);
  q1.enqueue(z);
  q1.enqueue(a);
  q1.enqueue(b);

  cout << "  \n  Queue1's Length is " + q1.length();

Output:
Queue1's Length is <2 , 4 , 6 , 8 , 10 , >


TESTING REPLACEFRONT--------------------

Code:

  q1.enqueue(x);
  q1.enqueue(y);
  q1.enqueue(z);
  q1.enqueue(a);
  q1.enqueue(b);
  q1.replaceFront(z);

Output:
<6 , 2 , 4 , 8 , 10 , >


C:\Users\Branson\source\repos\Assignment 2\Debug\Assignment 2.exe (process 28380) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/
