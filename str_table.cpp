#include "str_table.h"
#include <iostream>

int Str_Table::H1(std::string key) { 
    unsigned int n, upper;
    n = stringToInt(key);
    upper = n << 4;
    n = upper ^ n;
    return n % M;
}

int Str_Table::H2(std::string key) {
    int p = prevPrime(M);
    int q = stringToInt(key) % p;
    return p - q;
}

int Str_Table::stringToInt(std::string s) {
    unsigned int total = 0, length = s.length();
    for (int i = 0; i < length; ++i)
        total += s.at(i);
    total = (length * total);
    return total;
}

Str_Table::Str_Table(int m) : Table(m) {
    std::list<std::string> disc;
    for (int i = 0; i < M; ++i) {
        arr.at(i).data = disc;
    }
}

void Str_Table::deleteItem(std::string s) {
    int index = search(s);
    if (index != -1) {
        arr.at(index).data.clear();
        arr.at(index).flag = deleted;
    }
}

void Str_Table::update(int pos, std::string disc) {
    arr.at(pos).data.push_front(disc);
}
 
void Str_Table::addNewTopic(std::string topic, std::string disc) {
    int pos = search(topic);
    if (pos != -1) {
        update(pos, disc);
    }
    else {
        std::list<std::string> items;
        items.push_front(disc);
        Item<std::list<std::string>, std::string> item(items, topic, full);
        insert(item);
    }
}

void Str_Table::printTopic(std::string topic, int pos){
    std::list<std::string>::iterator end = arr.at(pos).data.end();

    for (std::list<std::string>::iterator it = arr.at(pos).data.begin();
    it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void Str_Table::printFirstNDisc(std::string topic, int pos, int N) {
    int count = 0;
    std::list<std::string>::iterator end = arr.at(pos).data.end();

    for (std::list<std::string>::iterator it = arr.at(pos).data.begin();
    it != end && count < N; ++it) {
        std::cout << *it << " ";
        count++;
    }
    std::cout << std::endl;
}

void Str_Table::printAllTopics() {
    for (int i = 0; i < M; ++i)
        if (arr.at(i).flag == full) {
            std::cout << arr.at(i).key << ":";
            printTopic(arr.at(i).key, i);
        }
}

void Str_Table::resetTable() {
    for (int i = 0; i < M; ++i) {
        arr.at(i).data.clear();
        arr.at(i).flag = empty;
    }
}
