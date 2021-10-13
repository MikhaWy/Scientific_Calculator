#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
private:
    bool radian_mode = false;
public:
    double answer = 0;
public:
    double Evaluate(const char* expression);
    void SetMode(const bool& mode);
private:
    int precedence(const char& op) const;
    double arithmetic(const double& a, const double& b, const char& op) const;
    double exp_evaluate(const double& a, const char& op) const;

    char strexp_code(const char* expression, int* i, double* numeric);
};

#endif