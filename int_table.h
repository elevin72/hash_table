#ifndef hash_int_h
#define hash_int_h

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

    std::vector<Item<int, int>> item;
};

int Int_Table::prevPrime(int m){

    std::vector<bool> prime(m, true);
    /* for (int i = 0; i < m; ++i) */
    /*     prime[i] = true; */

    for (int p = 2; p * p <= m; ++p)
        if (prime[p] == true)
            for (int i = p * p; i <= m; i += p)
                prime[i] = false;

    for (int i = m-1; i >= 0; --i)
        if (prime[i])
            return i;
}

/* int alternateHash(int key) { */
/*     int size = sizeof(key); */
/*     int upper = key >> (size * 4); */
/*     int lower = key; */
/*     int h = upper ^ lower; */
/*     h = h % arr.capacity(); */
    
/* } */

        /* return key % arr.capacity(); */ 
#endif
