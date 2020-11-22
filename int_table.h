#ifndef INT_TABLE_H
#define INT_TABLE_H

#include <vector>
#include "table.h"

class Int_Table : public Table<int, int> {
    using Table::Table;
    public:

    int prevPrime(int m);
    int H1(int key) { 
        int upper = key >> 2;
        int lower = key << 2;
        int h = upper ^ lower;
        return h % arr.capacity();
    }
    int H2(int key) {
        int p = prevPrime(arr.capacity());
        return p - (key % p);
    }
    std::vector<Item<int, int>> items;

/********************************* 
int alternateHash(int key) {
    int size = sizeof(key);
    int upper = key >> (size * 4);
    int lower = key;
    int h = upper ^ lower;
    h = h % arr.capacity();
    return key % arr.capacity();
}
*********************************/
};
#endif
