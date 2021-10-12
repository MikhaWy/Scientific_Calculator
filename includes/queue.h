#ifndef QUEUE_H 
#define QUEUE_H 

template<typename T>
class Queue {
private:
    int front, rear, size;
    unsigned int capacity;

    T* array;
public:
    Queue(const unsigned int& capacity);
    ~Queue();
    
    bool IsEmpty() const;
    bool IsFull() const;

    void Enqueue(T item);
    T Dequeue();
    T Pop();

    int Size() const;
    T Front() const;
    T Rear() const;
};

#include "../src/queue.cpp"

#endif