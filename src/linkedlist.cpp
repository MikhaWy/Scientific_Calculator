#include "../includes/linkedlist.h"

void LinkedList::Append(std::string history) {
    LLNode* new_history = new LLNode();
    new_history->history = history;
    new_history->next = NULL;

    if (this->head == NULL){
        this->head = new_history;
        return;
    }

    LLNode* next_history = this->head;
    while (next_history->next != NULL) {
        next_history = next_history->next;
    }
    next_history->next = new_history;
}

void LinkedList::Delete() {
    LLNode* current_node = this->head;
    LLNode* next_node = NULL;

    while (current_node != NULL) {
        next_node = current_node->next;
        delete current_node;
        current_node = next_node;
    }

    this->head = NULL;
}

void LinkedList::PrintList() {
    if (this->head == NULL){
        std::cout << "No history found." << std::endl;
        return;
    }

    LLNode* current_node = this->head;
    while (current_node != NULL) {
        std::cout << current_node->history << std::endl;
        current_node = current_node->next;
    }
}