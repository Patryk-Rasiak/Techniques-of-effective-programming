#include <iostream>
#include "ctreestatic.h"
#include "ctreedynamic.h"

using namespace std;

int main() {

    // First tree static

    CTreeStatic staticTree;

    staticTree.pcGetRoot()->vSetValue(0);

    staticTree.pcGetRoot()->vAddNewChild();
    staticTree.pcGetRoot()->vAddNewChild();
    staticTree.pcGetRoot()->vAddNewChild();

    staticTree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    staticTree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    staticTree.pcGetRoot()->pcGetChild(2)->vSetValue(3);

    staticTree.pcGetRoot()->pcGetChild(2)->vAddNewChild();

    staticTree.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    // Second tree static

    CTreeStatic staticTree2;

    staticTree2.pcGetRoot()->vSetValue(50);

    staticTree2.pcGetRoot()->vAddNewChild();
    staticTree2.pcGetRoot()->vAddNewChild();

    staticTree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    staticTree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

    staticTree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    staticTree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    staticTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    staticTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

    staticTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();

    staticTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    // First tree dynamic

    CTreeDynamic dynamicTree;

    dynamicTree.pcGetRoot()->vSetValue(0);

    dynamicTree.pcGetRoot()->vAddNewChild();
    dynamicTree.pcGetRoot()->vAddNewChild();
    dynamicTree.pcGetRoot()->vAddNewChild();

    dynamicTree.pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(1);
    dynamicTree.pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(2);
    dynamicTree.pcGetRoot()->pcGetChild(2)->pcGetRoot()->vSetValue(3);

    dynamicTree.pcGetRoot()->pcGetChild(2)->pcGetRoot()->vAddNewChild();

    dynamicTree.pcGetRoot()->pcGetChild(2)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(4);

    // Second tree static

    CTreeDynamic dynamicTree2;
    dynamicTree2.pcGetRoot()->vSetValue(50);

    dynamicTree2.pcGetRoot()->vAddNewChild();
    dynamicTree2.pcGetRoot()->vAddNewChild();

    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(54);
    dynamicTree2.pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(55);

    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetRoot()->vAddNewChild();
    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetRoot()->vAddNewChild();

    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(56);
    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(57);

    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vAddNewChild();

    dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(58);

    cout << "First static tree vPrint: " << endl;
    staticTree.vPrintTree();

    cout << "\nSecond static tree vPrint: " << endl;
    staticTree2.vPrintTree();

    cout << "\nMoving subtree.." << endl;
    staticTree.bMoveSubtree(staticTree.pcGetRoot()->pcGetChild(2), staticTree2.pcGetRoot()->pcGetChild(0));

    cout << "\nFirst static tree after move vPrint: " << endl;
    staticTree.vPrintTree();

    cout << "\nSecond static tree after move vPrint: " << endl;
    staticTree2.vPrintTree();

    // Printing dynamic tree

    cout << "\n\n\nFirst dynamic tree vPrint: " << endl;
    dynamicTree.vPrintTree();

    cout << "\nSecond dynamic tree vPrint: " << endl;
    dynamicTree2.vPrintTree();

    cout << "\nMoving subtree.." << endl;
    dynamicTree.bMoveSubtree(dynamicTree.pcGetRoot()->pcGetChild(2)->pcGetRoot(), dynamicTree2.pcGetRoot()->pcGetChild(0)->pcGetRoot());

    cout << "\nFirst dynamic tree after move vPrint: " << endl;
    dynamicTree.vPrintTree();

    cout << "\nSecond dynamic tree after move vPrint: " << endl;
    dynamicTree2.vPrintTree();

    return 0;
}

void v_tree_test() {
    CTreeStatic tree;

    tree.pcGetRoot()->vAddNewChild();
    tree.pcGetRoot()->vAddNewChild();


    tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);

    tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();

    tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    cout << "vPrintUp test: " << endl;
    tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();

    cout << "\nvPrintTree test: " << endl;
    tree.vPrintTree();

}
