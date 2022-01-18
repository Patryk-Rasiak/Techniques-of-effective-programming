#include <iostream>
#include "CTable.h"
using namespace std;

const string CTable::default_name = "Default name";
const int CTable::default_table_length = 5;

bool b_alloc_table_add_num(int iSize, int num) {
    if (iSize <  0) {
        cout << "Nieprawidłowy rozmiar tablicy" << endl;
        return false;
    }

    int * array = new int[iSize];

    for (int i = 0; i < iSize; i ++) {
        array[i] = i + num;
    }

    for (int i = 0; i < iSize - 1; i ++) {
        cout << array[i] << " ";
    }
    cout << array[iSize - 1] << endl;

    delete [] array;
    return true;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeY < 0 || iSizeX < 0) {
        return false;
    }
    else {
        *piTable = new int *[iSizeY];
        for (int i = 0; i < iSizeY; i++) {
            (*piTable)[i] = new int [iSizeX];
        }
        return true;
    }
}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeY) {
    for (int i = 0; i < iSizeY; i ++) {
        delete [] (*piTable)[i];
    }
    delete [] *piTable;
    return true;
}

void v_mod_table(CTable *pcTab, int iNewSize, string sNewName) {
    pcTab->bSetNewSize(iNewSize);
    pcTab->vSetName(sNewName);
}

void v_mod_table(CTable cTab, int iNewSize, string sNewName) {
    cTab.bSetNewSize(iNewSize);
    cTab.vSetName(sNewName);
}

int main() {
    b_alloc_table_add_num(10, 5);
    int **pi_table;
    b_alloc_table_2_dim(&pi_table, 5, 3);
    b_dealloc_table_2_dim(&pi_table, 3);
    CTable c_tab_1;
    CTable c_tab_2("Second Name", 3);
    CTable c_tab_3(c_tab_2);
    CTable * c_tab_4 = c_tab_1.pcClone();
    CTable c_tab_5("Third Name", 9);
    v_mod_table(c_tab_5, 0, "I wont change");
    v_mod_table(c_tab_2, 2, "Changed Name");
    c_tab_5.printName();
    c_tab_4->printName();

    delete c_tab_4;

    return 0;
}


