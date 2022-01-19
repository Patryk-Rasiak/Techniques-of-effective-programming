#include "ctable.h"
using namespace std;

CTable::CTable() {
    s_name = "Domyślna nazwa";
    cout << "bezp: '" << s_name << "'" << endl;
    i_array = new int[10];
    i_size = 10;
}

CTable::CTable(string sName, int iTableLen) {
    s_name = sName;
    cout << "parametr: '" << s_name << "'" << endl;
    i_array = new int[iTableLen];
    i_size = iTableLen;
}

CTable::CTable(CTable &pcOther) {
    s_name = pcOther.s_name + "_copy";
    cout << "kopiuj: '" << s_name << "'" << endl;
    i_size = pcOther.i_size;
    i_array = new int[i_size];

    for(int i=0; i<i_size; i++){
        i_array[i] = pcOther.i_array[i];
    }

}

CTable::~CTable() {
    delete i_array;
}

void CTable::vSetName(string sName){
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if(iTableLen < 0)
        return false;
    else {
        int *temp = new int[iTableLen];
        if(iTableLen > i_size)
            for(int i=0; i<i_size; i++){
                temp[i] = i_array[i];
            }
        else
            for(int i=0; i<iTableLen; i++){
                temp[i] = i_array[i];
            }

        delete [] i_array;
        i_array = temp;
        i_size = iTableLen;
        return true;
    }
}

CTable *CTable::pcClone(){
    return new CTable(*this);
}

int CTable::getSize(){
    return i_size;
}

string CTable::getName(){
    return s_name;
}

void CTable::operator=(CTable &pcOther) {
    i_array = pcOther.i_array;
    i_size = pcOther.i_size;
}

//void CTable::operator=(CTable &pcOther) {
//    if(i_size != pcOther.i_size)
//        this->bSetNewSize(pcOther.i_size);
//    for(int i=0; i<pcOther.i_size; i++)
//        i_array[i] = pcOther.i_array[i];
//
//    i_size = pcOther.i_size;
//}

CTable CTable::operator+(CTable &pcOther) {

    CTable new_obj(s_name, i_size + pcOther.i_size);

    for(int i=0; i<i_size; i++)
        new_obj.i_array[i] = i_array[i];

    for(int i=0; i<pcOther.i_size; i++)
        new_obj.i_array[i+i_size] = pcOther.i_array[i];

    return new_obj;
}

bool CTable::vSetValueAt(int iOffset, int iNewVal) {
    if(iOffset < i_size && iOffset >= 0){
        i_array[iOffset] = iNewVal;
        return true;
    }
    return false;
}

void CTable::vPrint(){
    for(int i=0; i<i_size-1; i++){
        cout << i_array[i] << ", ";
    }
    cout << i_array[i_size - 1] << endl;
}