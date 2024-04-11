#include "../libs/alg/mathparser/mathparser.h"

#include <iostream>
#include <string>
#include <windows.h>

using namespace MathParser;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::string expr;
    std::cout << "Input expression: ";
    std::cout.flush();
    while (true) {
        char in = getchar();
        if (in == '\n') break;

        expr += in;
    }

    std::queue<Token> input = stringToSequence(expr);

    std::queue<Token> output = infixToPostfix(input);
    Token res = evaluate(output);
    std::cout << res.val;

	return 0;
}
