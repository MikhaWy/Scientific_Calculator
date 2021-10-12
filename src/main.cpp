/************************************************
 * Edrick, Mikha, Roger                         *
 * Data Structures and ALgorithm                *
 * Mr. Fikri                                    *
 *                                              *
 * Scientific Calculator with Data Structures   *
 ************************************************/

#include <iostream>

#include "../includes/queue.h"
#include "../includes/linkedlist.h"

int main() {
    Queue queue(10);
    
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);

    std::cout << queue.Dequeue() << " dequeued from the queue." << std::endl;
    std::cout << queue.Pop() << " popped from the queue." << std::endl;
    std::cout << queue.Dequeue() << " dequeued from the queue." << std::endl;
    std::cout << queue.Pop() << " popped from the queue." << std::endl;

    return 0;
}