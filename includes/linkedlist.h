#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

struct LLNode {
    std::string history;
    LLNode* next;
};

class LinkedList {
    private:
        LLNode* head = NULL;
        int size = 1;

    public:
        void Append(std::string history);
        void PrintList();
        void Delete();
        int Size();
};

#endif