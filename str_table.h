#ifndef STR_TABLE_H
#define STR_TABLE_H

#include <list>
#include <string>
#include "table.h"

class Str_Table : public Table<std::string, std::string> {
    using Table::Table;
    public:

    std::list<Item<std::string, std::string>> items;
    int H1(std::string key) {
        int upper = std::stoi(key) >> 2;
        int lower = std::stoi(key) << 2;
        int h = upper ^ lower;
        return h % arr.capacity();
    }
    int H2(std::string key) {
        int p = prevPrime(arr.capacity());
        return p - (std::stoi(key) % p);
    }
    
    void addNewTopic(std::string topic, std::string disc);
    void printTopic(std::string topic);
    void printFirstNTopics(std::string topic, int N);
    void printAllTopics();
    void resetTable();
};
#endif