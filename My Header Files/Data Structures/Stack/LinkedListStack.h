#include "LinkedList/LinkedList.h"

int Push(Node** top,Node* newNode)
{
    if(!newNode) return 0;

    newNode->next=*top;
    *top = newNode;

    return 1;
}

int Pop(Node**top)
{
    if(IsEmpty(*top))
    {
        printf("Stack Underflow !\n");
        return 0;
    }

    Node* node;
    node = *top;
    *top = (*top)->next;
    free(node);

    return 1;
}

Data Peek(Node* top)
{
    if(IsEmpty(top))
    {
        printf("Stack is Empty\n");
        return defaultData;
    }

    return top->data;
}

Data PeekAndPop(Node** top)
{
    if(IsEmpty(*top))
    {
        printf("Stack Underflow !\n");
        return defaultData;
    }

    Data data = (*top)->data;
    *top = (*top)->next;
    return data;
}

int IsEmpty(Node* top)
{
    return top==NULL;
}