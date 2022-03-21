#include "Data.h"

struct Node
{
    Data data;
    struct Node* next;
} typedef Node;

//Creates the head of a node with the given data and returns the pointer to it
Node* CreateNode(Data data)
{
    Node* node = (Node*)malloc(sizeof(Node));

    if(!node)
    {
        printf("Stack Overflow !\n");
        exit(1);
    }
    
    node->data=data;
    node->next=NULL;

    return node;
}

/*Adds a node onto another node and returns the pointer of it,
it also adds a node between two nodes if shifting is not set to 0 and the 
given node has a next node*/
Node* AddNode(Node* latestNode,Data data,int shifting)
{
    Node* newNode = CreateNode(data);
    if(shifting && latestNode->next!=NULL)
    {
        Node* temp = latestNode->next;
        latestNode->next=newNode;
        newNode->next=temp;
    }
    else
        latestNode->next=newNode;
    return newNode;
}

//Gets data from a node without changing the pointer to it,returns the success
int GetData(Node* node,Data* data)
{
    if(node!=NULL)
    {
        *data = node->data; 
        return 1;
    }
    else return 0;
}

//Gets the next node of the given node if it exists,returns the success
int GetNext(Node** node)
{
    if(*node==NULL)
        return 0;
    if((*node = (*node)->next)==NULL)
        return 0;
    
    return 1;
}

//Adds a node to the end of the list by using any node inside the list(Note:just keep a pointer to end of the list and avoid using this lol)
Node* AddNodeUnknown(Node* arbitraryNode,Data data)
{
    while (arbitraryNode->next!=NULL)
        arbitraryNode=arbitraryNode->next;

    Node* newNode = CreateNode(data);
    arbitraryNode->next=newNode;
    return newNode;
}

//Returns the reverse of the given list
Node* ReverseList(Node* header,Node* previous)
{
    Node* newHeader;

    if(header->next!=NULL)
        newHeader = ReverseList(header->next,header);
    else
        newHeader=header;
    
    header->next=previous;

    return newHeader;
}