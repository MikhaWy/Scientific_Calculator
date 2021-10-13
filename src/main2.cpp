#include <iostream>
#include <cstring>
#include <cmath>

struct LinkedList {
    std::string data;
    LinkedList* next;
};

void append(LinkedList** ref, std::string data) {
    LinkedList* new_list = new LinkedList();
    new_list->data = data;
    new_list->next = NULL;

    if (*ref == NULL) {
        *ref = new_list;
        return;
    }

    LinkedList* current_list = *ref;
    while (current_list->next != NULL) {
        current_list = current_list->next;
    }
    current_list->next = new_list;
}

void print_list(LinkedList* head) {
    while (head != NULL) {
        std::cout << head->data << std::endl;
        head = head->next;
    }
}

void get_end_index(const std::string& expression, int* i, double* num) {
    while (*i < expression.length() && expression[*i] != ')') {
        std::cout << expression[*i] << std::endl;
        (*i)++;
    }
    (*i)++;
    *num = 10.2;    
}

int main() {
    LinkedList* head = NULL;
    append(&head, "Hello World!");
    append(&head, "Hello World 1!");
    append(&head, "Hello World 2!");

    print_list(head);

    std::cout << (double)1 / 10 << std::endl;

    std::string test = "sin(10) + 10";
    double num = 0;
    for (int i = 0; i < test.length(); i++) {
        if (isalpha(test[i])) {
            get_end_index(test, &i, &num);
            std::cout << test[i] << std::endl;
        }
    }

    std::cout << num << std::endl;

    return 0;
}