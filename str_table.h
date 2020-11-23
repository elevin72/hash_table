#ifndef STR_TABLE_H
#define STR_TABLE_H
#include "table.h"

class Str_Table : public Table<std::list<std::string>, std::string> {
    public:
        std::vector<Item<std::list<std::string>, std::string> > items;
        int H1(std::string key);
        int H2(std::string key);
        int stringToInt(std::string s);
        void deleteItem(std::string s);
        void update(int pos, std::string disc);
        Str_Table(int m);
        void addNewTopic(std::string topic, std::string disc);
        void printTopic(std::string topic, int pos);
        void printFirstNDisc(std::string topic, int pos, int N);
        void printAllTopics();
        void resetTable();
};
#endif
