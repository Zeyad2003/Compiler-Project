#include <iostream>
#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main() {
    string sourceCode = "if (x == 5) { y = 10; } else { y = 20; }";
    vector<Token> tokens = lexer(sourceCode);

    cout << "Tokens:" << endl;
    for (const auto& token : tokens) {
        cout << "Lexeme: " << token.lexeme << ", Type: " << tokenTypeMap.at(token.type) << endl;
    }

    cout << "\nSyntax Analysis:" << endl;
    Parser parser(tokens);
    parser.parse();
    cout << "Syntax Analysis Successful!!" << endl;

    return 0;
}

