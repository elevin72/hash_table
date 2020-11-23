#ifndef STR_TABLE_H
#define STR_TABLE_H

#include <vector>
#include <list>
#include <string>
#include "table.h"

class Str_Table : public Table<std::string, std::string> {
    using Table::Table; // illegal in c++11. Must define constructor for each class
    public:

    std::vector<std::list<Item<std::string, std::string>>> items;
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
    void printTopic(Item<std::string, std::string> topic, std::vector<std::list<Item<std::string, std::string>>> &items);
    void printFirstNDisc(Item<std::string, std::string> topic, int N);
    void printAllTopics();
    void resetTable();
    unsigned int stringToInt(std::string s) {
        int total = 0, length = s.length();

        for (int i = 0; i < length; ++i) {
            total += s.at(i);
        } 
        total = (length*total) - (s.front() + s.back()); // do some random shit
    }
};
#endif
