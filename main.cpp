#include "int_table.h"
#include <iostream>
using namespace std;

int main() {
    Int_Table table(20);
    Item<int, int> items[20];
    int numbers[] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69};
    for (int i = 0; i < 20; ++i) {
        items[i].data = items[i].key = numbers[i];
        items[i].flag = state::empty;
    }

    for (int i = 0; i < table.arr.capacity(); ++i) {
        table.Insert(items[i]);

    }
    for (int i = 0; i < table.arr.capacity(); ++i) {
        if (table.arr.at(i).flag == full){
            cout << i << ": ";
            cout << table.arr.at(i).data << "\n";
        }
    }
}
