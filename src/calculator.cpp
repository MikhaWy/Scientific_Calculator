#include <iostream>
#include <cstring>
#include <cmath>
#include <math.h>

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
        case '/': 
            if(b == 0){
                std::cout << "ERROR: Division by Zero" << std::endl;
                return 0;
            }
            return a / b;
        case '^': return pow(a, b);
        default:
            std::cout << "ERROR: Invalid syntax!" << std::endl;
            return 0;
    }
}

double Calculator::exp_evaluate(const double& a, const char& op) const {
    const double PI = 3.141592654;

    switch (op) {
        // 's' is sin, 'c' is cos, 't' is tan
        case 's': if (this->radian_mode) return sin(a); // Radian mode
                  else return sin(a * PI / 180);        // Deg mode (change deg to radian)
                  break;
        case 'c': if (this->radian_mode) return cos(a);
                  else return cos(a * PI / 180);
                  break;
        case 't': 
            if (!this->radian_mode && a == 90) {
                std::cout << "ERROR: Division by Zero" << std::endl;
                return 0;
            }
            else if (this->radian_mode && a == (PI / 2)) {
                std::cout << "ERROR: Division by Zero" << std::endl;
                return 0;
            }
            if (this->radian_mode) return tan(a);
            else return tan(a * PI / 180);
            break;
        case 'r': return pow(a, 0.5);       // Square root
        case 'e': return exp(a);            // Exp
        case 'l': return log10(a);          // Log base 10
        case 'n': return log(a);            // Log base n
        case 'a': return this->answer;      // Answer of previous expression
        default:
            std::cout << "ERROR: Invalid syntax!" << std::endl;
            return 0;
    }
}

char Calculator::strexp_code(const char* expression, int* i, double* numeric) {
    std::string str_command;
    char code;

    while (*i < strlen(expression) && expression[*i] != ')') {
        if (isalpha(expression[*i])) {
            str_command.push_back(expression[*i]);
        }
        else if (isdigit(expression[*i])) {
            double current_value = 0; // Loop till a non digit is reached
            int decimal_place = 0;
            while (*i < strlen(expression) && (isdigit(expression[*i]) || expression[*i] == '.')) {
                if (expression[*i] != '.') {
                    current_value = (current_value * 10.0) + (expression[*i] - '0');
                    (*i)++;
                    if (decimal_place > 0)
                        decimal_place++;
                }
                else {
                    decimal_place++;
                    (*i)++;
                }
            }
            if (decimal_place != 0)
                *numeric = current_value / pow(10, decimal_place - 1);
            else
                *numeric = current_value;
            (*i)--;
        }
        (*i)++;
    }

    // Return the appropriate char expression code for each string
    if (str_command.compare("sin") == 0)
        code = 's';
    else if (str_command.compare("cos") == 0)
        code = 'c';
    else if (str_command.compare("tan") == 0)
        code = 't';
    else if (str_command.compare("sqrt") == 0)
        code = 'r';
    else if (str_command.compare("exp") == 0)
        code = 'e';
    else if (str_command.compare("log") == 0)
        code = 'l';
    else if (str_command.compare("ln") == 0)
        code = 'n';
    else if (str_command.compare("ANS") == 0)  // If user wants to evaluate previous answer
        code = 'a';
    else
        code = '@'; // Returns a random char to throw an invalid syntax
    return code;
}

void Calculator::SetMode(const bool& mode){
    this->radian_mode = mode;
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
        // Current index is a string expression operator
        else if (isalpha(expression[i])) {
            double numeric_value;
            char c = strexp_code(expression, &i, &numeric_value);
            numbers.Enqueue(exp_evaluate(numeric_value, c));
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

    this->answer = numbers.Rear();
    return numbers.Rear();
}