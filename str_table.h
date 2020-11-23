#ifndef STR_TABLE_H
#define STR_TABLE_H
#include "table.h"

class Str_Table : public Table<std::list<std::string>, std::string> {
    public:

    std::vector<Item<std::list<std::string>, std::string> > items;
    int H1(std::string key) {
        int upper = stringToInt(key) >> 2;
        int lower = stringToInt(key) << 2;
        int h = upper ^ lower;
        return h % M;
    }
    int H2(std::string key) {
        int p = prevPrime(M);
        return p - (stringToInt(key) % p);
    }
    unsigned int stringToInt(std::string s) {
        unsigned int total = 0, length = s.length();
        for (int i = 0; i < length; ++i)
            total += s.at(i);
        total = (length * total);
        return total;
    }

    Str_Table(int m);
    void addNewTopic(std::string topic, std::string disc);
    void printTopic(std::string topic, int pos);
    void printFirstNDisc(std::string topic, int pos, int N);
    void printAllTopics();
    void resetTable();
};
#endif
