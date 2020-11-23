#include "str_table.h"
#include <iostream>

Str_Table::Str_Table(int m) : Table(m) {
    std::list<std::string> disc;
    for (int i = 0; i < M; ++i) {
        arr.at(i).data = disc;
    }
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
        if (arr.at(i).flag == full)
            printTopic(arr.at(i).key, i);
}

void Str_Table::resetTable() {
    for (int i = 0; i < M; ++i) {
        arr.at(i).data.clear();
        arr.at(i).flag = empty;
    }
}