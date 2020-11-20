#ifndef STR_TABLE_H
#define STR_TABLE_H

#include <list>
#include <string>
#include "table.h"

class Str_Table : public Table<std::string, std::string> {
    using Table::Table;
    public:

    std::list<Item<std::string, std::string>> items;
    int str_Hash(std::string key) {
        int upper = std::stoi(key) >> 2;
        int lower = std::stoi(key) << 2;
        int h = upper ^ lower;
        return h % arr.capacity();
    }
    
    void Insert(std::string topic, std::string disc);
    void printTopic(std::string topic);
    void printFirstN(std::string topic, int N);
    void printAll();
    void resetTable();
};

#endif