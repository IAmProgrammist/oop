#include "../libs/alg/calculator/calculator.h"

#include <iostream>

int main() {
    std::cout << (Calculator::get() << (Calculator::get() << 4 << Calculator::CalculatorOperation::DIVIDE << 2 << Calculator::CalculatorOperationEnd::END)
                                    << Calculator::CalculatorOperation::PLUS << 7 << Calculator::CalculatorOperationEnd::END) << std::endl;
    std::cout << (Calculator::get() << 3 << Calculator::CalculatorOperation::MULTIPLY << 1.3 << Calculator::CalculatorOperationEnd::END) << std::endl;
    std::cout << (Calculator::get() << 1 << Calculator::CalculatorOperation::PLUS << 0.9 << Calculator::CalculatorOperationEnd::END) << std::endl;
    std::cout << (Calculator::get() << 4 << Calculator::CalculatorOperation::MINUS << 2 << Calculator::CalculatorOperationEnd::END) << std::endl;
}
