#include <iostream>
using namespace std;

class CTable {
    private:
        const static string default_name;
        const static int default_table_length;
        string s_name;
        int * i_array;
    public:
        CTable() {
            s_name = default_name;
            cout << "bezp: " << s_name << endl;
            i_array = new int [default_table_length];
        }

        CTable(string sName, int iTableLen) {
            s_name = sName;
            cout << "parametr: " << s_name << endl;
            i_array = new int [iTableLen];
        }

        CTable (CTable &pcOther) {
            s_name = pcOther.s_name + "_copy";
            i_array = new int [sizeof(*i_array) / sizeof(i_array[0])];

            for (int i = 0; i < sizeof(*i_array) / sizeof(i_array[0]); i ++) {
                i_array[i] = pcOther.i_array[i];
            }
            cout << "kopiuj: " << s_name << endl;
        }

        ~CTable() {
            cout << "usuwam: " << s_name << endl;
            delete [] i_array;
        }

        void vSetName(string sName) {
            s_name = sName;
        }

        bool bSetNewSize(int iTableLen) {
            if (iTableLen < 0) {
                cout << "Nieprawidłowy rozmiar tablicy" << endl;
                return false;
            } else {
                int *i_array_temp = new int[iTableLen];
                int i_array_size = sizeof(*i_array) / sizeof(i_array[0]);
                if (iTableLen > i_array_size) {
                    for (int i = 0; i < i_array_size; i++) {
                        i_array_temp[i] = i_array[i];
                    }
                } else {
                    for (int i = 0; i < iTableLen; i++) {
                        i_array_temp[i] = i_array[i];
                    }
                }
                return true;
            }
        }

        CTable * pcClone() {
            return new CTable(* this);
        }

        void printName() {
            cout << "Nazwa tablicy: " << s_name << endl;
        }
};