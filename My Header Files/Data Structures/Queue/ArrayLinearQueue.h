#include "Data.h"

struct Queue
{
    int rear;
    const unsigned int capacity;
    Data* queue;
} typedef Queue;

Queue CreateQueue(unsigned int capacity)
{
    Queue queue = {-1,capacity,(Data*)malloc(sizeof(Data)*capacity)};
    return queue;
}

int IsEmpty(Queue queue)
{
    if(queue.rear<0)
        return 1;
    else return 0;
}

int IsFull(Queue queue)
{
    if(queue.rear>=queue.capacity-1)
        return 1;
    else return 0;
}

int Enqueue(Queue* queue,Data data)
{
    if(IsFull(*queue))
        return 0;

    queue->queue[++queue->rear] = data;
    return 1;
}

//O(n) Dequeue operation
int Dequeue(Queue* queue,Data* data)
{
    if(IsEmpty(*queue))
        return 0;
    
    *data = queue->queue[queue->rear--];

    for (size_t i = 0; i < queue->rear; i++)
        queue->queue[i] = queue->queue[i+1];
            
    return 1;
}