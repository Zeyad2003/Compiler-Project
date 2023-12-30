#include <vector>
#include "Lexer.h"

class Parser {
private:
    std::vector<Token> tokens;
    int current;

    void stmt();
    void stmt_list(); // { stmt stmt stmt }
    void expr();
    void match(TokenType type);

public:
    Parser(const std::vector<Token>& tokens);
    void parse();
};