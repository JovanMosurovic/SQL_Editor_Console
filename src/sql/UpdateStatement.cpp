
#include "UpdateStatement.h"

UpdateStatement::UpdateStatement(const string &query) : Statement(query) {}

bool UpdateStatement::parse() {
    return false;
}

void UpdateStatement::execute(Database &db) {

}

void UpdateStatement::errors() {
}
