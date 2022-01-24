#include "CTab.h"
#include <iostream>

CTab::CTab(const CTab& cOther)
{
    v_copy(cOther);
    std::cout << "Copy ";
}

CTab::~CTab()
{
    if (pi_tab != NULL) {
        delete pi_tab;
    }
    std::cout << "Destr ";
}

void CTab::v_copy(const CTab& cOther)
{
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for (int i = 0; i < cOther.i_size; i++) {
        pi_tab[i] = cOther.pi_tab[i];
    }
}

CTab CTab::operator=(const CTab& cOther)
{
    if (pi_tab != NULL) {
        delete pi_tab;
    }
    v_copy(cOther);
    std::cout << "op= ";
    return(*this);
}


void CTab::v_move(CTab& cOther){
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
}

CTab::CTab(CTab&& cOther) {
    v_move(cOther);
    std::cout << "Move ";
}


CTab CTab::operator=(CTab&& cOther) {
    if (pi_tab != NULL) {
        delete pi_tab;
    }
    v_move(cOther);
    return(*this);
}

bool CTab::bSetSize(int iNewSize){
    if (iNewSize < 0) {
        return false;
    }

    int* piTableHelper = new int[iNewSize];

    for (int i = 0; i < i_size; i ++) {
        piTableHelper[i] = pi_tab[i];
    }

    i_size = iNewSize;
    delete[] pi_tab;
    pi_tab = piTableHelper;
    return true;
}
