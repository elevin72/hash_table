#include "int_table.h"
#include "str_table.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void printTable(Int_Table table) { // we'll need to template the print function to handle any kind of table
    for(int i = 0; i < table.arr.capacity(); ++i) {
        cout << i << ": ";
        if(table.arr.at(i).flag == full ){
            cout << "-->" << table.arr.at(i).key;
        }
        cout << "\n";
    }
}
const int n = 90;
const int insertNum = 50;
int main() {
    srand(time(nullptr)); // why?
    Int_Table table(n);
    Item<int, int> items[n];
    int numbers[insertNum];
    for (int i = 0; i < insertNum; ++i) {
        numbers[i] = i + 200;
    }
    for (int i = 0; i < insertNum; ++i) {
        items[i].data = items[i].key = numbers[i];
        items[i].flag = state::empty;
    }

    cout << "capacity: "  << table.arr.capacity() << "\n";

    for (int i = 0; i < insertNum; ++i) {
        table.Insert(items[i]);
    }

    cout << "capacity: "  << table.arr.capacity() << "\n";

    printTable(table);
    
    cout << "capacity: "  << table.arr.capacity() << "\n";
}