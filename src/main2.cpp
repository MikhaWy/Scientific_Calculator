#include <iostream>
#include <string>

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

int main() {
    LinkedList* head = NULL;
    append(&head, "Hello World!");
    append(&head, "Hello World 1!");
    append(&head, "Hello World 2!");

    print_list(head);

    return 0;
}