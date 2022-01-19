#include <iostream>

using namespace std;

class CTable {
private:
    string s_name;
    int *i_array;
    int i_size;

public:
    CTable();
    CTable(string sName, int iTableLen);
    CTable(CTable &pcOther);
    ~CTable();
    void vSetName(string sName);
    bool bSetNewSize(int iTableLen);
    int getSize();
    string getName();
    CTable *pcClone();
    void operator=(CTable &pcOther);
    CTable operator+(CTable &pcOther);
    bool vSetValueAt(int iOffset, int iNewVal);
    void vPrint();
};