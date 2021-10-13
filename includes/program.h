#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>
#include "calculator.h"
#include "linkedlist.h"

class Program {
private:
    Calculator calculator;
    LinkedList* history_list;
public:
    void Init();
};

#endif