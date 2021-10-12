#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    double Evaluate(const char* expression);
private:
    int precedence(const char& op) const;
    double arithmetic(const double& a, const double& b, const char& op) const;
};

#endif