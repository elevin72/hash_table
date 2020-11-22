#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "item.h"

// T=type of element, K=type of key. T and K are both elements of Item
template <class T, class K>
class Table { 
  public:
    std::vector<Item<T,K>> arr; // Item has fields of types T and K.

    Table(int m);  // Table will be of size prime greater than m
    ~Table() {}

    virtual int H1(K key)=0;
    virtual int H2(K key)=0;
    int hash(int start, int step, int i) {
      return start + (step * i) % arr.capacity();
    }

    int Search(Item<T,K> element);
    void Insert(Item<T,K> element);
    void Delete(Item<T,K> element);
    void Update(int i, Item<T,K> element);

  protected: 
    int nextPrime(int m); // returns first prime > m
    int prevPrime(int m);
    bool isPrime(int n); 
};
#endif
