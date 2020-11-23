#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <list>
#include <string>
#include "item.h"

// T = type of data, K = type of key
template <class T, class K>
class Table { 
  public:
    int M;
    std::vector<Item<T,K>> arr;

    Table(int m);  // Table will be of size (first prime > m)
    ~Table() {}

    virtual int H1(K key) = 0;
    virtual int H2(K key) = 0;
    int hash(int start, int step, int i) {
      return ((start + (step * i)) % M);
    }

    int search(K key);
    void insert(Item<T,K> item);
    void deleteItem(K key);
    void update(int pos, std::string disc);

  protected: 
    int nextPrime(int m); // returns first prime > m
    int prevPrime(int m); // returns last prime < m
    bool isPrime(int n); 
};
#endif
