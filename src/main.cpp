/************************************************
 * Edrick, Mikha, Roger                         *
 * Data Structures and ALgorithm                *
 * Mr. Fikri                                    *
 *                                              *
 * Scientific Calculator with Data Structures   *
 ************************************************/

#include <iostream>

#include "../includes/queue.h"
#include "../includes/linkedlist.h"
#include "../includes/calculator.h"

int main() {
    Calculator calc;
    std::cout << calc.Evaluate("(100 * ( 2 + 12 ))/ 13") << std::endl; 

    return 0;
}