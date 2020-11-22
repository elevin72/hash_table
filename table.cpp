#include "table.h"

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

template <class T, class K>
Table<T,K>::Table(int m){ 
  arr.reserve(nextPrime(m)); 
  for (int i = 0; i < arr.capacity(); ++i){
    Item<T, K> item;
    arr.push_back(item);
  }  
}

template <class T, class K>
int Table<T,K>::Search(Item<T,K> element) {
  int start = H1(element.key);
  int step = H2(element.key);
  int index;

  for(int i = 0; i < arr.capacity() && arr.at(index).flag != empty; ++i) {
    index = Hash(start, step, i);
    if (arr.at(index).key == element.key)
      return index; 
  }

  return -1;
}

template <class T, class K>
void Table<T,K>::Insert(Item<T,K> element) {
  int start = H1(element.key);
  int step = H2(element.key);
  int index = start;

  for (int i = 0; i < arr.capacity(); ++i) {
    index = Hash(start, step, i);
    if (arr.at(index).flag != full) {
      arr.at(index) = element;
      arr.at(index).flag = full;
      break;
    }
  }
}

template <class T, class K>
void Table<T,K>::Delete(Item<T,K> element) {
  int index = Search(element.key);
  if ( index != -1 )
    arr.at(index).flag = deleted;
}

template <class T, class K>
void Table<T,K>::Update(int i, Item<T,K> element) {
  if (Search(element) != -1)
    arr.at(i).data = element.data;
}