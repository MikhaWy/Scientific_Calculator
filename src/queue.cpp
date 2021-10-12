#include "../includes/queue.h"

#include <iostream>
#include <limits.h>

Queue::Queue(unsigned int capacity) {
    this->capacity = capacity;
    this->front = this->size = 0;

    this->rear = capacity - 1; // We assign to 'capacity' to get the wrap around during enqueue
    this->array = new int[capacity];

    if (array == NULL) {
        std::cout << "ERROR: Failure in allocating memory!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

Queue::~Queue() {
    free(this->array);
    std::cout << "Queue Destroyed!" << std::endl;
}

bool Queue::is_empty() const {
    return (this->size == 0);
}

bool Queue::is_full() const {
    return (this->size == this->capacity);
}

void Queue::Enqueue(int item) {
    if (is_full()) {
        std::cout << "WARNING: Current instance of queue is already full!" << std::endl;
        return;
    }

    this->rear = (this->rear + 1) % this->capacity; // Wrap around
    this->array[this->rear] = item;
    this->size = this->size + 1;
}

int Queue::Dequeue() {
    if (is_empty()) {
        std::cout << "WARNING: Queue is empty!" << std::endl;
        return INT_MIN;
    }

    int data = this->array[this->front];
    this->front = (this->front + 1) % this->capacity; // Wrap around
    this->size = this->size - 1;
    return data;
}

int Queue::Pop() {
    if (is_empty()) {
        std::cout << "WARNING: Queue is empty!" << std::endl;
        return INT_MIN;
    }

    int data = this->array[this->rear];
    this->rear = this->rear - 1;
    this->size = this->size - 1;
    return data;
}

int Queue::Front() const {
    if (is_empty()) {
        std::cout << "WARNING: Queue is empty!" << std::endl;
        return INT_MIN;
    }
    return this->array[this->front];
}

int Queue::Rear() const {
if (is_empty()) {
        std::cout << "WARNING: Queue is empty!" << std::endl;
        return INT_MIN;
    }
    return this->array[this->rear];
}