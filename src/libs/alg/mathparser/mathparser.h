#ifndef MATHPARSER_H
#define MATHPARSER_H

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <math.h>
#include <sstream>


namespace MathParser {
    class Token {
    public:
        std::string val;
        bool is_op;
        bool is_bin;
        int priority;
        std::function<Token(Token, Token)> bin_op = [](Token, Token) {throw std::runtime_error("Unsupported"); return Token("");};
        std::function<Token(Token)> un_op = [](Token) {throw std::runtime_error("Unsupported"); return Token("");};;

        Token(std::string val, std::function<Token(Token, Token)> bin_op, int priority) : val(val), bin_op(bin_op), priority(priority) {
            this->is_op = true;
            this->is_bin = true;
        };

        Token(std::string val, std::function<Token(Token)> un_op, int priority) : val(val), un_op(un_op), priority(priority) {
            this->is_op = true;
            this->is_bin = false;
        };

        Token(std::string val, int operation) {
            this->priority = operation;
            this->is_op = false;
            this->is_bin = false;
            this->val = val;
        }

        Token(std::string val) {
            this->priority = -1;
            this->is_op = false;
            this->is_bin = false;
            this->val = val;
        }

        Token() : val(""), is_op(false), is_bin(false), priority(0) {};

        bool isNumber();
        bool isOpeningPar();
        bool isClosingPar();
        bool isOperation();
        bool isBinOp();
        int getPriority();
    };

    extern std::vector<Token> tokens;

    std::queue<Token> infixToPostfix(std::queue<Token> input);
    // Напечатать последовательность токенов
    std::string printSequence(std::queue<Token> q);
    std::string getStringNumber(std::string expr, int& pos);
    std::queue<Token> stringToSequence(const std::string &s);
    void evalOpUsingStack(Token op, std::stack<Token> &s);
    Token evaluate(std::queue<Token> expr);
    }

#endif // MATHPARSER_H
