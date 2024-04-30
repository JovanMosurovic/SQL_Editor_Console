
#ifndef ELEMENTAL_SQL_IMPLEMENTATION_DATABASE_H
#define ELEMENTAL_SQL_IMPLEMENTATION_DATABASE_H

#include <unordered_map>
#include "table/Table.h"
#include "exceptions/DatabaseExceptions.h"

class Database {
    string name;
    unordered_map<string, Table> tables;

public:
    Database(string name); //bez const?

    void addTable(const Table& table) {
        if(tables.find(table.getName()) != tables.end()) {
            throw TableAlreadyExistsException(table.getName());
        }
        tables.emplace(table.getName(), table);
    }

    void createTable(const string& tableName, const vector<Column>& columns) {
        try {
            regex tableName_pattern("^[A-Za-z]+$");
            if (!(regex_match(tableName, tableName_pattern))) {
                throw InvalidTableNameException(tableName);
            }

            auto it = tables.find(tableName);
            if (it != tables.end()) {
                throw TableAlreadyExistsException(tableName);
            }
            tables.emplace(tableName, Table(tableName, columns));
        } catch (const InvalidTableNameException& e) {
            cout << e.what() << endl;
        } catch (const TableAlreadyExistsException& e) {
            cout << e.what() << endl;
        } catch(const exception& e) {
            cout << red << "Unexpected exception caught:\n" << e.what() << resetColor << endl;
        }
    }

    void dropTable(const string& tableName) {
        try {
            auto it = tables.find(tableName);
            if (it == tables.end()) {
                throw TableDoesNotExistException(tableName);
            }
            tables.erase(it);
        } catch(const TableDoesNotExistException& e) {
            cout << e.what() << endl;
        } catch(const exception& e) {
            cout << red << "Unexpected exception caught:\n" << e.what() << resetColor << endl;
        }
    }

    void printDatabase() { // pomocna funkcija za ispis, ne treba za projekat
        cout << "Database: " << name << endl;
        cout << "Tables: " << endl;
        for(const auto& table : tables) {
            cout << " - " << table.first << endl;
            table.second.printTable();
            cout << endl;
        }
    }

    //<editor-fold desc="Getters">

    const string &getName() const;

    //</editor-fold>

};


#endif //ELEMENTAL_SQL_IMPLEMENTATION_DATABASE_H
