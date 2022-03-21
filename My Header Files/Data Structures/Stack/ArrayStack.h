#include "Data.h"


struct Stack
{
    int top;
    const unsigned int capacity;
    Data* stack;
};


int IsEmpty(Stack stack)
{
    if(stack.top<0) return 1;
    else return 0;
}

int IsFull(Stack stack)
{
    if(stack.top+1 == stack.capacity) return 1;
    else return 0;
}

int Push(Stack* stack,Data newNode)
{
    if(IsFull(*stack)) return 0;

    stack->stack[++stack->top] = newNode;

    return 1;
}


int Pop(Stack* stack,Data* data)
{
    if(IsEmpty(*stack)) return 0;
    
    *data = stack->stack[stack->top--];

    return 1;
}

int Peek(Stack stack,Data* data)
{
    if(IsEmpty(stack)) return 0;

    *data = stack.stack[stack.top];

    return 1;
}