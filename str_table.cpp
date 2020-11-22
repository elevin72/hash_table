#include "str_table.h"

void Str_Table::addNewTopic(std::string topic, std::string disc) {
    Item item(topic, disc, full);
    int pos = Search(item);
    if (pos == -1)
        Insert(item);
    else {
        // append item to list member of existing topic
    }
}

void Str_Table::printTopic(Item<std::string, std::string> topic, std::vector<std::list<Item<std::string, std::string>>> &items){
    int pos = Search(topic);
    if (pos != -1) {
    }
}

void Str_Table::printFirstNDisc(Item<std::string, std::string> topic, int N) {

}

void Str_Table::printAllTopics() {

}

void Str_Table::resetTable() {

}