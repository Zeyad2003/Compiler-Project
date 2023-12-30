#include <iostream>
#include "Parser.h"

using namespace std;

Parser::Parser(const vector<Token>& tokens) : tokens(tokens), current(0) {}

void Parser::parse() {
    stmt();
    if (current != tokens.size()) {
        throw runtime_error("Syntax Error: Extra tokens at the end");
    }
}

void Parser::stmt() {
    if (tokens[current].type == TokenType::KEYWORD && tokens[current].lexeme == "if") {
        match(TokenType::KEYWORD); // if
        cout << "if ";
        match(TokenType::SYMBOL); // (
        expr();
        match(TokenType::OPERATOR); // ==
        cout << "equals ";
        expr();
        match(TokenType::SYMBOL); // )
        cout << "then ";
        match(TokenType::SYMBOL); // {
        stmt_list();
        match(TokenType::SYMBOL); // }
        cout << "else ";
        match(TokenType::KEYWORD); // else
        match(TokenType::SYMBOL); // {
        stmt_list();
        match(TokenType::SYMBOL); // }
        cout << endl;
    } else if (tokens[current].type == TokenType::IDENTIFIER) {
        cout << tokens[current].lexeme << " ";
        match(TokenType::IDENTIFIER);
        cout << "= ";
        match(TokenType::OPERATOR); // =
        expr();
        match(TokenType::SYMBOL); // ;
        cout << endl;
    } else {
        throw runtime_error("Syntax Error: Expected statement");
    }
}

void Parser::expr() {
    if (tokens[current].type == TokenType::IDENTIFIER) {
        cout << tokens[current].lexeme << " ";
        match(TokenType::IDENTIFIER);
    } else if (tokens[current].type == TokenType::NUMBER) {
        cout << tokens[current].lexeme << " ";
        match(TokenType::NUMBER);
    } else {
        throw runtime_error("Syntax Error: Expected expression");
    }
}

void Parser::stmt_list() {
    while (tokens[current].type != TokenType::SYMBOL || tokens[current].lexeme != "}") {
        stmt();
    }
}

void Parser::match(TokenType type) {
    if (tokens[current].type == type) {
        current++;
    } else {
        throw runtime_error("Syntax Error: Unexpected token");
    }
}
