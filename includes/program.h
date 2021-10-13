#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>
#include "calculator.h"

class Program {
private:
    Calculator calculator;
    std::string expression;
    bool radian_mode = false;
public:
    void Init();
    void Clear();

    void RadianMode();
    void DegreeMode();

    void AddHistory(const std::string& history);
    void DeleteHistoryIndex(const int& index);
    void DeleteHistory(const std::string& history);
    void PrintHistory();
};

#endif