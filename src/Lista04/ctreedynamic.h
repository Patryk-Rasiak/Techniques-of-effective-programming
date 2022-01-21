#include <iostream>
#include <vector>

using namespace std;

template <typename T> class CNodeDynamic {

private:
    vector<CNodeDynamic<T>*> v_children;
    CNodeDynamic<T> *pc_parent_node;
    T *pt_val;

public:
    CNodeDynamic();
    ~CNodeDynamic();

    void vSetValue(T iNewVal);
    int iGetChildrenNumber();
    void vAddNewChild();
    CNodeDynamic<T> *pcGetChild(int iChildOffset);

    void vMove(CNodeDynamic<T> *newParent);
    void vPrint();
    void vPrintAllBelow();

};

template <typename T> class CTreeDynamic {

private:
    CNodeDynamic<T> *pc_root;

public:
    CTreeDynamic();
    ~CTreeDynamic();

    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
    CNodeDynamic<T> *pcGetRoot();
    void vPrintTree();
    void vSetRoot(CNodeDynamic<T> *newRootNode);

};

template <typename T>
CTreeDynamic<T>::CTreeDynamic() {
    pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    delete pc_root;
}

template <typename U>
CNodeDynamic<U> *CTreeDynamic<U>::pcGetRoot() {
    return pc_root;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrintAllBelow();
}

template <typename T>
void CTreeDynamic<T>::vSetRoot(CNodeDynamic<T> *newRootNode) {
    pc_root = newRootNode;
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {
    if((pcParentNode != NULL) && (pcNewChildNode != NULL)) {
        pcNewChildNode->vMove(pcParentNode);
        return true;
    }

    return false;
}


template <typename T>
CNodeDynamic<T>::CNodeDynamic() {
    pt_val = new T;
    pc_parent_node = NULL;
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    for(int i = 0; i < v_children.size(); i++){
        delete v_children[i];
    }
}

template <typename T>
void CNodeDynamic<T>::vSetValue(T iNewVal) {
    *pt_val = iNewVal;
}

template <typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
    return v_children.size();
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(){
    CNodeDynamic<T> *newNodeDynamic = new CNodeDynamic<T>();
    newNodeDynamic->pc_parent_node = this;
    v_children.push_back(newNodeDynamic);
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if((iChildOffset >= 0) && (iChildOffset < v_children.size())) {
        return v_children[iChildOffset];
    }

    return NULL;
}

template <typename T>
void CNodeDynamic<T>::vPrint() {
    cout << " " << *pt_val;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for(int i = 0; i < v_children.size(); i++){
        v_children[i]->vPrintAllBelow();
    }
}

template <typename T>
void CNodeDynamic<T>::vMove(CNodeDynamic<T> *newParent) {
    (newParent->v_children).push_back(this);
    if (pc_parent_node != NULL) {
        vector<CNodeDynamic<T> *> *vParentChildren = &(pc_parent_node->v_children);

        for(int i = 0; i < vParentChildren->size(); i++){
            if (vParentChildren->at(i) == this) {
                vParentChildren->erase(vParentChildren->begin() + i);
            }
        }
    }
    pc_parent_node = newParent;

}