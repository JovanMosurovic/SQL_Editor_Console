
#ifndef ELEMENTAL_SQL_IMPLEMENTATION_SYNTAXREGEXPATTERNS_H
#define ELEMENTAL_SQL_IMPLEMENTATION_SYNTAXREGEXPATTERNS_H

#include <regex>

using namespace std;

namespace SyntaxRegexPatterns {
    // general regex
    const regex MUST_CONTAIN_PARENTHESES(R"(^.*\(.*\).*$)", regex_constants::icase);
    const regex MUST_CONTAIN_QUOTES(R"(^.*['"].*['"].*$)", regex_constants::icase);
    const regex VALID_QUOTE_REGEX(R"((?:[^'"]*('[^']*'|"[^"]*"))*[^'"]*$)");
    const regex PAIRED_BRACKETS_REGEX(R"(^([^()]*\([^()]*\))*[^()]*$)");
    const regex COLUMNS_SYNTAX_REGEX(R"(^([^,()]+(?:,[^,()]+)*)$)", regex_constants::icase);
    const regex MULTIPLE_KEYWORDS_REGEX(".*create.*create.*|.*select.*select.*|.*insert.*insert.*|.*drop.*drop.*|.*update.*update.*",regex_constants::icase);
}

#endif //ELEMENTAL_SQL_IMPLEMENTATION_SYNTAXREGEXPATTERNS_H
