#ifndef QUEUE_H 
#define QUEUE_H 

class Queue {
private:
    int front, rear, size;
    unsigned int capacity;
    int* array;
public:
    Queue(unsigned int capacity);
    ~Queue();
    
    bool is_full() const;
    bool is_empty() const;

    void Enqueue(int item);
    int Dequeue();
    int Pop();

    int Front() const;
    int Rear() const;
private:

};

#endif