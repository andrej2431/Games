#include "database_manager.h"

Json::Value *DatabaseManager::get_table_json(const std::string &table_name) {
    auto *table_json = new Json::Value(Json::arrayValue);
    std::ifstream table_file("../database/tables/" + table_name + ".json");
    table_file >> *table_json;

    return table_json;
}

void DatabaseManager::write_to_table(const std::string &table_name, Json::Value &json_to_write) {
    std::ofstream table_file("../database/tables/" + table_name + ".json", std::ifstream::binary);
    table_file << json_to_write;
}

Json::Value DatabaseManager::get_list_entry(Json::Value &list, const std::string &key_name, unsigned int key) {
    for (auto &element: list) {
        if (element[key_name].asInt() == key) {
            return element;
        }
    }
    return Json::objectValue;
}

Json::Value DatabaseManager::get_list_entry(Json::Value &list, const std::string &key_name, const std::string &key) {
    for (auto &element: list) {
        if (element[key_name] == key)
            return element;
    }

    return Json::objectValue;
}