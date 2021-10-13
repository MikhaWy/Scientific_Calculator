#include <iostream>
#include <cstring>
#include <cmath>
#include "../includes/linkedlist.h"

int main() {
    LinkedList list;

    list.Append("history 1");
    list.Append("history 2");
    list.Append("history 3");
    list.Append("history 4");
    list.PrintList();
    list.Delete();
    list.Append("append 1");
    list.PrintList();
    return 0;
}