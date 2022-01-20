#include <iostream>

using namespace std;

class CTreeDynamic;

class CNodeDynamic {

private:
    vector<CNodeDynamic*> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;

public:
    CNodeDynamic();
    ~CNodeDynamic();

    void vSetValue(int iNewVal);
    int iGetChildrenNumber();
    void vAddNewChild();
    CTreeDynamic *pcGetChild(int iChildOffset);

    void vMove(CNodeDynamic *newParent);
    void vPrint();
    void vPrintAllBelow();

};

class CTreeDynamic {

private:
    CNodeDynamic *pc_root;

public:
    CTreeDynamic();
    ~CTreeDynamic();

    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
    CNodeDynamic *pcGetRoot();
    void vPrintTree();
    void vSetRoot(CNodeDynamic *newRootNode);

};