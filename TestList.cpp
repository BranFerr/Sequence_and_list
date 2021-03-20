#include <iostream>
#include "List.hpp"

using namespace std;

int main() {

	typedef List1<int> IntegerList;

	IntegerList L1, L2, L3;// Creating lists 1-3

    // Variables
    int a = 7;
    int b = 15;
    int c = 355;
    int d = 420;
    int e = 21;
    int f = 69;
    int g = 87;

    // TESTING LIST OUTPUTS
    cout << "TESTING LIST 1 OUTPUT\n";
    cout << "L1 is empty\n";
    L1.outputList();
    cout << "L1 left length: " << L1.leftLength() << "\n";
    cout << "L1 right length: " << L1.rightLength() << "\n";
    cout << "\n";

    // TESTING ADD RIGHT FRONT FUNCTION 
    cout << "ADDING 4 VARIABLES TO RIGHT LIST\n";
    L1.addRightFront(a);
    L1.addRightFront(b);
    L1.addRightFront(c);
    L1.addRightFront(d);
    cout << "L1 \n";
    L1.outputList();
    cout << "L1 left length: " << L1.leftLength() << "\n";
    cout << "L1 right length: " << L1.rightLength() << "\n";
    cout << "\n";

    // TESTING REMOVE RIGHT FRONT FUNCTION
    cout << "REMOVING ONE VARIABLE FROM RIGHT LIST\n";
    L1.removeRightFront(a);
    cout << "L1 \n";
    L1.outputList();
    cout << "L1 left length: " << L1.leftLength() << "\n";
    cout << "L1 right length: " << L1.rightLength() << "\n";
    cout << "\n";

    // TESTING ADVANCE FUNCTION
    cout << "ADVANCING TWO VARIABLES FROM RIGHT FRONT TO LEFT REAR\n";
    L1.advance();
    L1.advance();
    cout << "L1 \n";
    L1.outputList();
    cout << "L1 left length: " << L1.leftLength() << "\n";
    cout << "L1 right length: " << L1.rightLength() << "\n";
    cout << "\n";

    // TESTING RIGHT FRONT FUNCTION
    cout << "TESTING THE RIGHTFRONT FUNCTION\n";
    cout << "Right front: " << L1.rightFront();
    cout << "\n";

    // TESTING CLEAR FUNCTION
    cout << "TESTING THE RIGHT CLEAR FUNCTION\n";
    L1.addRightFront(a);
    L1.addRightFront(b);
    L1.addRightFront(c);
    L1.addRightFront(d);
    cout << "L1 \n";
    L1.outputList();
    cout << "L1 left length: " << L1.leftLength() << "\n";
    cout << "L1 right length: " << L1.rightLength() << "\n";
    cout << "\n";
    
    cout << "CLEARING BOTH FUNCTIONS\n";
    L1.clear();
    cout << "PRINTING THE EMPTY LIST\n";
    L1.outputList();

    // TESTING THE REPLACERIGHTFRONT FUNCTION
    cout << "ADDING 3 VARIABLES TO RIGHT LIST\n";
    L1.addRightFront(b);
    L1.addRightFront(c);
    L1.addRightFront(d);
    cout << "L1 \n";
    L1.outputList();
    cout << "L1 left length: " << L1.leftLength() << "\n";
    cout << "L1 right length: " << L1.rightLength() << "\n";
    cout << "\n";

    cout << "NOW TESTING REPLACERIGHTFRONT FUNCTION\n";
    L1.outputList();
    L1.replaceRightFront(e);
    cout << "REPLACING D WITH E (420->21)\n";
    cout << "L1 \n";
    L1.outputList();
    cout << "L1 left length: " << L1.leftLength() << "\n";
    cout << "L1 right length: " << L1.rightLength() << "\n";
    cout << "\n";

    // TESTING SWAPRIGHTS FUNCTION
    cout << "TESTING SWAPRIGHTS FUNCTION\n";

    L2.clear();
    L3.clear();

    //Preparing for the swap
    cout << "Before: \n";
    cout << "L2:";
    L2.addRightFront(a);
    L2.outputList();
    cout << "\n";
    cout << "L3: ";
    L3.addRightFront(b);
    L3.outputList();
    cout << "\n";

    //Swapping
    cout << "After: \n";
    L2.swapRights(L3);
    cout << "L2:";
    L2.outputList();
    cout << "\n";
    cout << "L3: ";
    L3.outputList();
    cout << "\n";

    // TESTING MOVETOSTART FUNCTION
    cout << "TESTING MOVETOSTART FUNCTION\n";
    L2.addRightFront(d);
    L2.advance();
    cout << "L2 \n";
    L2.outputList();
    cout << "\n";

    cout << "NOW MOVING LIST FROM LEFT TO RIGHT (L->R)\n";
    L2.moveToStart();
    cout << "L2 \n";
    L2.outputList();
    cout << "\n";

    // TESTING MOVETOFINISH FUNCTION
    cout << "TESTING MOVETOFINISH FUNCTION\n";
    L3.moveToFinish();
    L3.addRightFront(f);
    cout << "L3 \n";
    L3.outputList();
    cout << "\n";

    cout << "NOW MOVING LIST FROM RIGHT TO LEFT (R->L)\n";
    L3.moveToFinish();
    cout << "L3 \n";
    L3.outputList();
    cout << "\n";

    // TESTING OPERATOR= FUNCTION
    cout << "TESTING THE OPERATOR= FUNCTION\n";
    L2.clear();
    cout << "Ensuring that List 2 is Empty...";
    L2.outputList();
    L2.operator=(L1);
    cout << "L1: ";
    L1.outputList();
    cout << "\n";
    cout << "Applying list 1 to list 2\n";
    cout << "L2: ";
    L2.outputList();
    cout << "\n";

    // TESTING TRANSFERFROM FUNCTION
    cout << "TESTING TRANSFERFROM FUNCTION\n";
    L3.transferFrom(L2);
    cout << "Placing the list from OPERATOR= FUNCTION (List 2) into TRANSFERFROM FUNCTION\n";
    cout << "L3: ";
    cout << "\n";
    L3.outputList();

}// END MAIN