
#include "Table.h"

#include <utility>

Table::Table(string name, const vector<Column> &columns) : name(std::move(name)), columns(columns) {}

void Table::addRow(const vector<string> &rowData) {
    rows.emplace_back(rowData); // proveri ovo
}

void Table::removeRow(size_t rowIndex) {
    if(rowIndex >= rows.size()) {
        //todo throw "Row index out of range"
    }
    rows.erase(rows.begin() + rowIndex);
}

void Table::updateRow(size_t rowIndex, const vector<string> &newData) {
    if(rowIndex >= rows.size()) {
        //todo throw "Row index out of range"
    }
    if(newData.size() != columns.size()) {
        //todo throw "Invalid number of columns in new data"
    }
    rows[rowIndex].setData(newData);
}

void Table::printTable() {
    for (const auto &column : columns) {
        cout << column.getName() << " ";
    }
    putchar('\n');
    for (const auto &row : rows) {
        for (const auto &cell : row.getData()) {
            cout << cell << " ";
        }
        putchar('\n');
    }
}

//<editor-fold desc="Getters">

const vector<Column> &Table::getColumns() const {
    return columns;
}

const string &Table::getName() const {
    return name;
}

const vector<Row> &Table::getRows() const {
    return rows;
}

//</editor-fold>
