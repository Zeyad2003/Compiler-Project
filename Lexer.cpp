#include <regex>
#include "Lexer.h"

using namespace std;

Token createToken(const string &lexeme) {
    Token token;
    token.lexeme = lexeme;

    if (regex_match(lexeme, regex("if|else"))) {
        token.type = KEYWORD;
    } else if (regex_match(lexeme, regex("\\(|\\)|\\{|\\}|;"))) {
        token.type = SYMBOL;
    } else if (regex_match(lexeme, regex("==|="))) {
        token.type = OPERATOR;
    } else if (regex_match(lexeme, regex("\\d+"))) {
        token.type = NUMBER;
    } else {
        token.type = IDENTIFIER;
    }

    return token;
}

vector<Token> lexer(const string& sourceCode) {
    vector<Token> tokens;
    regex rgx("(\\bif\\b|\\belse\\b|\\w+|==|=|\\(|\\)|\\{|\\}|;)");
    smatch match;

    string s = sourceCode;
    while (regex_search(s, match, rgx)) {
        string lexeme = match.str();
        tokens.push_back(createToken(lexeme));
        s = match.suffix().str();
    }

    return tokens;
}
