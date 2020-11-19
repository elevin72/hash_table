#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include <cmath> 
#include "item.h"
// T=type of element, K=type of key. T and K are both elements of Item
template <class T, class K>
class Table {
  public:
    std::vector<Item<T,K>> arr; // Item has fields of types T and K.
    int size;
    Table(int m);  // Table will be of size prime greater than m
    ~Table();
    virtual int H1(K key)=0;
    virtual int H2(K key)=0;
    int Hash(int start, int jump, int i);
    int Search(K key);
    void Insert(T element);
    void Delete(T element);
    void Update(int i, T element);
  private: 
    int NextPrime(int m); // returns min prime > m
    bool isPrime(int n); 
};

template <class T, class K>
Table<T,K>::Table(int m){
  int nextP = NextPrime(m);
  size = nextP;
  arr.reserve(size);

}

template <class T, class K>
int Table<T,K>::NextPrime(int m) {
  for (int i = m+1; i <= 2*m; ++i){
    if (isPrime(i)) break;
  }
}

template <class T, class K>
bool Table<T,K>::isPrime(int n) {
  if (n==0 || n==1) {
    return false;
  }
  if (n==3) {
    return true;
  }
  if (n%2==0) {
    return false;
  }
  for (int i = 3; i*i < n; i+=2) {
    if(n%i == 0){
      return false;
    }
  }
  return true;
}

template <class T, class K>
int Table<T,K>::Hash(int start, int jump, int i) {
  return (start + (jump * i)) % size;
}

// NOTE: This only works if sequence < start, start + i*jump, ...>
// is a permuation of numbers (1,m-1).
// If it repeats numbers then it could return -1 even if the element exists
template <class T, class K>
int Table<T,K>::Search(K key) {
  int start = H1(key);
  int jump = H2(key);
  for(int i = 0; i < m; ++i) {
    int index = Hash(start, jump, i);
    if (arr[index].key == key) return index; 
  }
  return -1;
}

#endif 
