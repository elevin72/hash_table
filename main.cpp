#include "int_table.h"
#include <iostream>
using namespace std;

int main() {
    Int_Table table(5);
    Item<int, int> items[5];
    int numbers[] = {3, 56, 3, 87, 1};
    for (int i = 0; i < 5; ++i) {
        items[i].data = items[i].key = numbers[i];
        items[i].flag = state::empty;
    }

    for (int i = 0; i < table.arr.capacity(); ++i) {
        table.Insert(items[i]);
        if (table.arr.at(i).flag == full){
            cout << i << ": ";
            cout << table.arr.at(i).data;
        }
    }
}