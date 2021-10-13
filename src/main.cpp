/************************************************
 * Edrick, Mikha, Roger                         *
 * Data Structures and ALgorithm                *
 * Mr. Fikri                                    *
 *                                              *
 * Scientific Calculator with Data Structures   *
 ************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "../includes/queue.h"
#include "../includes/linkedlist.h"
#include "../includes/program.h"
#include "../includes/calculator.h"

int main() {
    std::string expression;
    std::getline(std::cin, expression);

    Calculator calc;
    std::cout << std::setprecision(2) << std::fixed << calc.Evaluate(expression.c_str()) << std::endl;

    return 0;
}