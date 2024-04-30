
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

    void addTable(const Table& table);

    void createTable(const string& tableName, const vector<Column>& columns);

    void dropTable(const string& tableName);

    void addRowToTable(const string& tableName, const vector<string>& rowData);

    void updateRowInTable(const string& tableName, const size_t rowIndex, const vector<string>& rowData);

    void removeRowFromTable(const string& tableName, size_t rowIndex);

    void printDatabase();

    //<editor-fold desc="Getters">

    const string &getName() const;

    //</editor-fold>

};


#endif //ELEMENTAL_SQL_IMPLEMENTATION_DATABASE_H
