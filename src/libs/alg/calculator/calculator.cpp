#include <stdexcept>
#include <limits>

#include "calculator.h"

Calculator Calculator::get() {
    return Calculator();
}

Calculator& Calculator::operator<<(double val) {
    if (!this->op_left_assigned && !this->op_right_assigned && !this->op_assigned) {
        this->op_left = val;
        this->op_left_assigned = true;
    } else if (!this->op_right_assigned && this->op_left_assigned && this->op_assigned) {
        this->op_right = val;
        this->op_right_assigned = true;
    } else {
        throw std::invalid_argument("Invalid operator");
    }
}

Calculator& Calculator::operator<<(CalculatorOperation op) {
    if (this->op_left_assigned && !this->op_assigned && !this->op_right_assigned) {
        this->op = op;
        this->op_assigned = true;
    } else {
        throw std::invalid_argument("Invalid operator");
    }
}

double Calculator::operator<<(CalculatorOperationEnd op) {
    if (op == CalculatorOperationEnd::END) {
        if (!(this->op_assigned && this->op_left_assigned && this->op_right_assigned))
            throw std::invalid_argument("Expression incomplete");

        double res;

        switch (this->op) {
        case CalculatorOperation::PLUS:
            res = this->op_left + this->op_right;
            break;
        case CalculatorOperation::MINUS:
            res = this->op_left - this->op_right;
            break;
        case CalculatorOperation::MULTIPLY:
            res = this->op_left * this->op_right;
            break;
        case CalculatorOperation::DIVIDE:
            if (this->op_right == 0) throw std::domain_error("Can't divide by zero");

            res = this->op_left / this->op_right;
            break;
        default:
            throw std::invalid_argument("Unsupported operation");
        }

        if (res == std::numeric_limits<double>::infinity() || res == -std::numeric_limits<double>::infinity())
            throw std::overflow_error("Number is too big");

        return res;
    } else {
        throw std::invalid_argument("Unsupported operation");
    }
}
