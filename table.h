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


/** PRIME NUMBER UTILITY FUNCTIONS **/
template <class T, class K>
bool Table<T,K>::isPrime(int n) {
  if (n == 0 || n == 1) { return false; }
  if (n == 3) { return true; }
  if (n % 2 == 0) { return false; }

  for (int i = 3; i * i <= n; i += 2)
    if(n % i == 0)
      return false;

  return true;
}

template <class T, class K>
int Table<T,K>::nextPrime(int m) {
  for (int i = m + 1; i <= 2 * m; ++i)
    if (isPrime(i)) return i;
}

template <class T, class K>
int Table<T,K>::prevPrime(int m){
    std::vector<bool> prime(m, true);
    for (int p = 2; p * p <= m; ++p)
        if (prime[p] == true)
            for (int i = p * p; i <= m; i += p)
                prime[i] = false;

    for (int i = m-1; i >= 0; --i)
        if (prime[i])
            return i;
}

/** CONSTRUCTOR/DESTRUCTOR **/
template <class T, class K>
Table<T,K>::Table(int m){ 
  M = (nextPrime(m));
  for (int i = 0; i < M; ++i){
    Item<T,K> item;
    arr.push_back(item);
  }  
}

// TODO: Build Destructor

/** C.R.U.D. FUNCTIONS **/
template <class T, class K>
int Table<T,K>::search(K key) {
  int index = H1(key);
  int step = H2(key);

  for(int i = 0; i < M && arr.at(index).flag != empty; ++i) {
    index = hash(index, step, i);
    if (arr.at(index).key == key)
      return index;
  }
  return -1;
}

template <class T, class K>
void Table<T,K>::insert(Item<T,K> item) {
  int index = H1(item.key);
  int step = H2(item.key);

  for (int i = 0; i < M; ++i) {
    index = hash(index, step, i);
    if (arr.at(index).flag != full) {
      arr.at(index) = item;
      arr.at(index).flag = full;
      return;
    }
  }

  // Exception: Hash Table is full
}

template <class T, class K>
void Table<T,K>::deleteItem(K key) {
  int index = search(key);
  if ( index != -1 ) {
    arr.at(index).data.clear();
    arr.at(index).flag = deleted;
  }

  // Exception: Item does not exist
}

template <class T, class K>
void Table<T,K>::update(int pos, std::string disc) {
    arr.at(pos).data.push_front(disc);
}
#endif
