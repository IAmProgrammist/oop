#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
public:
    enum CalculatorOperation {
        PLUS,
        MINUS,
        DIVIDE,
        MULTIPLY
    };

    enum CalculatorOperationEnd {
        END
    };

    bool op_left_assigned = false;
    double op_left;
    bool op_assigned = false;
    CalculatorOperation op;
    bool op_right_assigned = false;
    double op_right;

    static Calculator get();
    Calculator& operator<<(double val);
    Calculator& operator<<(CalculatorOperation op);
    double operator<<(CalculatorOperationEnd op);
private:
    Calculator() {

    };
};

#endif // CALCULATOR_H
