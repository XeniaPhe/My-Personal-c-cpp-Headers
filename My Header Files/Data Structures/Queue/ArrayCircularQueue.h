#include "Data.h"

struct Queue
{
    unsigned int front;
    unsigned int rear;
    const unsigned int capacity;
    Data* queue;
} typedef Queue;

Queue CreateQueue(unsigned int capacity)
{
    Queue queue = {0,0,capacity,(Data*)malloc(sizeof(Data)*capacity)};
    return queue;
}

int IsEmpty(Queue queue)
{
    if(queue.rear==queue.front)
        return 1;
    else return 0;
}

int IsFull(Queue queue)
{
    if(queue.front==(queue.rear+1)%queue.capacity)
        return 1;
    else return 0;
}

int Enqueue(Queue* queue,Data data)
{
    if(IsFull(*queue))
        return 0;

    queue->queue[(++queue->rear)%queue->capacity] = data;
    return 1;
}

int Dequeue(Queue* queue,Data* data)
{
    if(IsEmpty(*queue))
        return 0;

    *data = queue->queue[(queue->front++)%queue->capacity];

    return 1;
}
