#include <iostream>
#include <vector>

using namespace std;

class CNodeStatic {
private:
    vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;

public:

    CNodeStatic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();
    void vAddNewChild();
    CNodeStatic *pcGetChild(int iChildOffset);

    void setParentNode(CNodeStatic * node);
    CNodeStatic *pcGetParent();
    void vRemoveChild(CNodeStatic *pcChild);
    void vMove(CNodeStatic *pcParent);

    void vPrint() ;
    void vPrintAllBelow();
    void vPrintUp();

};

class CTreeStatic {
private:
    CNodeStatic c_root;

public:

    CTreeStatic();
    CNodeStatic *pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
};

