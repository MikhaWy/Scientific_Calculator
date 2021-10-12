#include <iostream>
#include <cstring>
#include <cmath>

#include "../includes/calculator.h"
#include "../includes/queue.h"

int Calculator::precedence(const char& op) const {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}

double Calculator::arithmetic(const double& a, const double& b, const char& op) const {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default:
        std::cout << "ERROR: Invalid operator!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

double Calculator::Evaluate(const char* expression) {
    Queue<double> numbers(100); // Stores all the numeric values
    Queue<char> ops(100);       // Stores all the operators
    int i;

    for (i = 0; i < strlen(expression); i++) {
        // Ignore whitespace(s)
        if (expression[i] == ' ')
            continue;
        // Current index is an opening bracket
        else if (expression[i] == '(') {
            ops.Enqueue(expression[i]);
        }
        // Current index is a number
        else if (isdigit(expression[i])) {
            double current_value = 0; // Loop till a non digit is reached
            int decimal_place = 0;
            while (i < strlen(expression) && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] != '.') {
                    // - '0' is the same as -49 since ascii value for char '0' is 49
                    current_value = (current_value * 10.0) + (expression[i] - '0');
                    i++;

                    if (decimal_place > 0)
                        decimal_place++;
                }
                else {
                    decimal_place++;
                    i++;
                }
            }

            if (decimal_place != 0)
                numbers.Enqueue(current_value / pow(10, decimal_place - 1));
            else
                numbers.Enqueue(current_value);
            i--;
        }
        // Given string is a negative number: -1 {
        else if (expression[i] == '-' && isdigit(expression[i + 1])) {
            for (int j = i; j >= 0; j--) {
                if (expression[j] == ' ')
                    continue;
                else if (isdigit(expression[j])) {
                    std::cout << "ERROR: Expression is invalid!" << std::endl;
                    exit(EXIT_FAILURE);
                }
                else {
                    break;
                }
            }

            i++;
            double current_value = 0; // Loop till a non digit is reached
            int decimal_place = 0;
            while (i < strlen(expression) && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] != '.') {
                    current_value = (current_value * 10.0) + (expression[i] - '0');
                    i++;
                    if (decimal_place > 0)
                        decimal_place++;
                }
                else {
                    decimal_place++;
                    i++;
                }
            }

            if (decimal_place != 0)
                numbers.Enqueue(-1 * current_value / pow(10, decimal_place - 1));
            else
                numbers.Enqueue(-1 * current_value);
            i--;
        }
        // Solve the entire bracket if a closing bracket is found
        else if (expression[i] == ')') {
            while (!ops.IsEmpty() && ops.Rear() != '(') {
                double number2 = numbers.Pop();
                double number1 = numbers.Pop();
                char op = ops.Pop();

                numbers.Enqueue(arithmetic(number1, number2, op));
            }

            if (!ops.IsEmpty())
                ops.Pop();
        }
        // Current index is an operator
        else {
            // Calculate if the latest operator in the queue has a higher precedence than 
            // the current index
            while (!ops.IsEmpty() && (precedence(ops.Rear()) >= precedence(expression[i]))) {
                double number2 = numbers.Pop();
                double number1 = numbers.Pop();
                char op = ops.Pop();

                numbers.Enqueue(arithmetic(number1, number2, op));
            }

            ops.Enqueue(expression[i]);
        }
    }

    while (!ops.IsEmpty()) {
        double number2 = numbers.Pop();
        double number1 = numbers.Pop();
        char op = ops.Pop();

        numbers.Enqueue(arithmetic(number1, number2, op));
    }

    return numbers.Rear();
}