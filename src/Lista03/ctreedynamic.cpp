#include <iostream>
#include <vector>
#include "ctreedynamic.h"

using namespace std;

    CTreeDynamic::CTreeDynamic() {
        pc_root = new CNodeDynamic();
    }

    CTreeDynamic::~CTreeDynamic() {
        delete pc_root;
    }

    CNodeDynamic *CTreeDynamic::pcGetRoot() {
        return pc_root;
    }

    void CTreeDynamic::vPrintTree() {
        pc_root->vPrintAllBelow();
    }

    void CTreeDynamic::vSetRoot(CNodeDynamic *newRootNode) {
        pc_root = newRootNode;
    }

    bool CTreeDynamic::bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
        if((pcParentNode != NULL) && (pcNewChildNode != NULL)) {
            pcNewChildNode->vMove(pcParentNode);
            return true;
        }

        return false;
    }





    CNodeDynamic::CNodeDynamic() {
        i_val = 0;
        pc_parent_node = NULL;
    }

    CNodeDynamic::~CNodeDynamic() {
        for(int i = 0; i < v_children.size(); i++){
            delete v_children[i];
        }
    }

    void CNodeDynamic::vSetValue(int iNewVal) {
        i_val = iNewVal;
    }

    int CNodeDynamic::iGetChildrenNumber() {
        return v_children.size();
    }

    void CNodeDynamic::vAddNewChild(){
        CNodeDynamic *newNodeDynamic = new CNodeDynamic();
        newNodeDynamic->pc_parent_node = this;
        v_children.push_back(newNodeDynamic);
    }

    CTreeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if((iChildOffset >= 0) && (iChildOffset < v_children.size())) {
        CTreeDynamic *newTreeDynamic = new CTreeDynamic();
        newTreeDynamic->vSetRoot(v_children[iChildOffset]);
        return newTreeDynamic;
    }

    return NULL;
    }

    void CNodeDynamic::vPrint() {
        cout << " " << i_val;
    }

    void CNodeDynamic::vPrintAllBelow() {
        vPrint();
        for(int i = 0; i < v_children.size(); i++){
            v_children[i]->vPrintAllBelow();
        }
    }

    void CNodeDynamic::vMove(CNodeDynamic *newParent) {
        (newParent->v_children).push_back(this);
        if (pc_parent_node != NULL) {
            vector<CNodeDynamic *> *vParentChildren = &(pc_parent_node->v_children);

            for(int i = 0; i < vParentChildren->size(); i++){
                if (vParentChildren->at(i) == this) {
                    vParentChildren->erase(vParentChildren->begin() + i);
                }
            }
        }
        pc_parent_node = newParent;

    }





