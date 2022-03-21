#include "LinkedList/LinkedList.h"

int Enqueue(Node** rear,Data data)
{
    if(*rear==NULL) return 0;
    *rear = AddNode(*rear,data,0);

    return 1;
}

int Dequeue(Node** front,Data* data)
{
    if(*front==NULL) return 0;

    *data = (*front)->data;
    *front = (*front)->next;
    return 1; 
}