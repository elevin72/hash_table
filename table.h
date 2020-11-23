#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <list>
#include "item.h"

// T=type of element, K=type of key. T and K are both elements of Item
template <class T, class K>
class Table { 
  public:
    std::vector<std::list<Item<T,K>>> arr; // Item has fields of types T and K.

    Table(int m);  // Table will be of size prime greater than m
    ~Table() {}

    virtual int H1(K key)=0;
    virtual int H2(K key)=0;
    int hash(int start, int step, int i) {
      return start + (step * i) % arr.capacity();
    }

    int search(Item<T,K> element);
    void insert(Item<T,K> element);
    void deleteItem(Item<T,K> element);
    void update(int i, Item<T,K> element);

  protected: 
    int nextPrime(int m); // returns first prime > m
    int prevPrime(int m);
    bool isPrime(int n); 
};
#endif
