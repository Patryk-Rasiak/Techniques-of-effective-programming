#include <iostream>
#include "ctable.h"

using namespace std;

int main() {

    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);

    /* initialize tables */
    c_tab_0.vSetValueAt(0, 1);
    c_tab_0.vSetValueAt(1, 2);
    c_tab_0.vSetValueAt(2, 3);
    c_tab_0.vSetValueAt(3, 4);
    c_tab_0.vSetValueAt(4, 5);
    c_tab_0.vSetValueAt(5, 6);

    c_tab_1.vSetValueAt(0, 51);
    c_tab_1.vSetValueAt(1, 52);
    c_tab_1.vSetValueAt(2, 53);
    c_tab_1.vSetValueAt(3, 54);

    cout << "\nc_tab_0 + c_tab_1: " << endl;
    (c_tab_0 + c_tab_1).vPrint();

    cout << "\nc_tab_0 przed zmianą: " << endl;
    c_tab_0.vPrint();

    cout << "c_tab_1 przed zmianą: " << endl;
    c_tab_1.vPrint();

    c_tab_0 = c_tab_1;
    c_tab_1.vSetValueAt(2, 123);

    cout << "\nc_tab_0 po zmianie: " << endl;
    c_tab_0.vPrint();

    cout << "c_tab_1 po zmianie: " << endl;
    c_tab_1.vPrint();


    return 0;
}
