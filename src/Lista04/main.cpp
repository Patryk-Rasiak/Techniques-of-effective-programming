#include <iostream>
#include <vector>
#include "ctreedynamic.h"

using namespace std;

int main() {

    CTreeDynamic<int> dynamicTree;

    dynamicTree.pcGetRoot()->vSetValue(0);

    dynamicTree.pcGetRoot()->vAddNewChild();
    dynamicTree.pcGetRoot()->vAddNewChild();
    dynamicTree.pcGetRoot()->vAddNewChild();

    dynamicTree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    dynamicTree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    dynamicTree.pcGetRoot()->pcGetChild(2)->vSetValue(3);

    dynamicTree.pcGetRoot()->pcGetChild(2)->vAddNewChild();

    dynamicTree.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    CTreeDynamic<int> dynamicTree2;
    dynamicTree2.pcGetRoot()->vSetValue(50);

    dynamicTree2.pcGetRoot()->vAddNewChild();
    dynamicTree2.pcGetRoot()->vAddNewChild();

    dynamicTree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    dynamicTree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

    dynamicTree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    dynamicTree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();

    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    CTreeDynamic<string> dynamicTree3;

    dynamicTree3.pcGetRoot()->vSetValue("Root");

    dynamicTree3.pcGetRoot()->vAddNewChild();
    dynamicTree3.pcGetRoot()->vAddNewChild();
    dynamicTree3.pcGetRoot()->vAddNewChild();

    dynamicTree3.pcGetRoot()->pcGetChild(0)->vSetValue("One");
    dynamicTree3.pcGetRoot()->pcGetChild(1)->vSetValue("Two");
    dynamicTree3.pcGetRoot()->pcGetChild(2)->vSetValue("Three");

    dynamicTree3.pcGetRoot()->pcGetChild(2)->vAddNewChild();

    dynamicTree3.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue("Four");

    CTreeDynamic<string> dynamicTree4;
    dynamicTree4.pcGetRoot()->vSetValue("Fifty");

    dynamicTree4.pcGetRoot()->vAddNewChild();
    dynamicTree4.pcGetRoot()->vAddNewChild();

    dynamicTree4.pcGetRoot()->pcGetChild(0)->vSetValue("Fifty four");
    dynamicTree4.pcGetRoot()->pcGetChild(1)->vSetValue("Fifty five");

    dynamicTree4.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    dynamicTree4.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    dynamicTree4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("Fifty six");
    dynamicTree4.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("Fifty seven");

    dynamicTree4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();

    dynamicTree4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue("Fifty eight");


    // Printing int dynamic tree

    cout << "\n\n\nFirst dynamic tree vPrint: " << endl;
    dynamicTree.vPrintTree();

    cout << "\nSecond dynamic tree vPrint: " << endl;
    dynamicTree2.vPrintTree();

    cout << "\nMoving subtree.." << endl;
    dynamicTree.bMoveSubtree(dynamicTree.pcGetRoot()->pcGetChild(2), dynamicTree2.pcGetRoot()->pcGetChild(0));

    cout << "\nFirst dynamic tree after move vPrint: " << endl;
    dynamicTree.vPrintTree();

    cout << "\nSecond dynamic tree after move vPrint: " << endl;
    dynamicTree2.vPrintTree();

    // Printing string dynamic tree

    cout << "\n\n\nFirst dynamic tree vPrint: " << endl;
    dynamicTree3.vPrintTree();

    cout << "\nSecond dynamic tree vPrint: " << endl;
    dynamicTree4.vPrintTree();

    cout << "\nMoving subtree.." << endl;
    dynamicTree3.bMoveSubtree(dynamicTree3.pcGetRoot()->pcGetChild(2), dynamicTree4.pcGetRoot()->pcGetChild(0));

    cout << "\nFirst dynamic tree after move vPrint: " << endl;
    dynamicTree3.vPrintTree();

    cout << "\nSecond dynamic tree after move vPrint: " << endl;
    dynamicTree4.vPrintTree();
    return 0;
}

