#include "../includes/queue.h"

#include <iostream>
#include <limits.h>

template<typename T>
Queue<T>::Queue(const unsigned int& capacity) {
    this->capacity = capacity;
    this->front = this->size = 0;

    this->rear = capacity - 1; // We assign to 'capacity' to get the wrap around during enqueue
    this->array = new T[capacity];

    if (array == NULL) {
        std::cout << "ERROR: Failure in allocating memory!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

template<typename T>
Queue<T>::~Queue() {
    free(this->array);
}

template<typename T>
bool Queue<T>::IsEmpty() const {
    return (this->size == 0);
}

template<typename T>
bool Queue<T>::IsFull() const {
    return (this->size == this->capacity);
}

template<typename T>
void Queue<T>::Enqueue(T item) {
    if (IsFull()) {
        std::cout << "WARNING: Current instance of queue is already full!" << std::endl;
        return;
    }

    this->rear = (this->rear + 1) % this->capacity; // Wrap around
    this->array[this->rear] = item;
    this->size = this->size + 1;
}

template<typename T>
T Queue<T>::Dequeue() {
    if (IsEmpty()) {
        std::cout << "WARNING: Queue is empty!" << std::endl;
        return (T)0;
    }

    T data = this->array[this->front];
    this->front = (this->front + 1) % this->capacity; // Wrap around
    this->size = this->size - 1;
    return data;
}

template<typename T>
T Queue<T>::Pop() {
    if (IsEmpty()) {
        std::cout << "WARNING: Queue is empty!" << std::endl;
        return (T)0;
    }

    T data = this->array[this->rear];
    this->rear = this->rear - 1;
    this->size = this->size - 1;
    return data;
}

template<typename T>
int Queue<T>::Size() const {
    return this->size;
}

template<typename T>
T Queue<T>::Front() const {
    if (IsEmpty()) {
        std::cout << "WARNING: Queue is empty!" << std::endl;
        return (T)0;
    }
    return this->array[this->front];
}

template<typename T>
T Queue<T>::Rear() const {
    if (IsEmpty()) {
        std::cout << "WARNING: Queue is empty!" << std::endl;
        return (T)0;
    }
    return this->array[this->rear];
}