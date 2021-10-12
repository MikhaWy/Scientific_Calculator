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
    std::cout << calc.Evaluate("12.3") << std::endl; 
    std::cout << calc.Evaluate("100.23") << std::endl; 
    std::cout << calc.Evaluate("1400") << std::endl; 
    std::cout << calc.Evaluate("1800.2") << std::endl; 

    return 0;
}