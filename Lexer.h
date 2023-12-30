#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include <unordered_map>

enum TokenType {
    KEYWORD,    // 0
    IDENTIFIER, // 1
    NUMBER,     // 2
    OPERATOR,   // 3
    SYMBOL      // 4
};

struct Token {
    std::string lexeme;
    TokenType type;
};

const std::unordered_map<int, std::string> tokenTypeMap = {
        {0, "KEYWORD"},
        {1, "IDENTIFIER"},
        {2, "NUMBER"},
        {3, "OPERATOR"},
        {4, "SYMBOL"}
};

extern std::vector<Token> lexer(const std::string& sourceCode);

#endif
