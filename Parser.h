#include <vector>
#include "Lexer.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    void parse();

private:
    std::vector<Token> tokens;
    int current;

    void stmt();
    void stmt_list();
    void expr();
    void match(TokenType type);
};