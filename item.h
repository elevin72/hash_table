#ifndef ITEM_H
#define ITEM_H
enum state {empty, full, deleted};

template <class T, class K>
class Item {
  public:
    T data;
    K key;
    state flag;
    Item(){ flag = empty; }
    Item(T d, K k, state f){ data=d; key=k; flag=f;}
};

#endif
