#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class Stack
{
    struct node
    {   
        int data;
        node *link = NULL;
    };

    public:

    node *stackHead = (node *)malloc(sizeof(node));
    
    //Check whether the stack is empty or not.
    bool IsEmpty()
    {
        if(stackHead -> link == NULL)
        {
            return true;

        } else
        {
            return false;
        } 
    }

    /*
        Push a new element to the stack.
        This push function does not need check wether the stack is full or not because we use a linked list so the stack will never be full if the memory is still available.
    */
    void Push(int data)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> link = stackHead -> link;
        stackHead -> link = newNode;
    }   

    //Pop the most top element from the stack.
    int Pop()
    {
        if(!IsEmpty())
        {
            node *tempPointer = (node *)malloc(sizeof(node));
            tempPointer -> link = stackHead -> link -> link;
            int tempData = stackHead -> link -> data;
            free(stackHead -> link);
            stackHead -> link = tempPointer -> link;

            return tempData;

        } else
        {
            cout << "Stack is already empty!\n";

            return -1;  //-1 code means the stack is already empty
        }
    }

    //Check the most top element from the stack.
    int TopStack()
    {
        if(!IsEmpty())
        {
            return stackHead -> link -> data;

        } else
        {
            cout << "Stack is already empty!\n";

            return -1;
        }
    }

    //Print the contents of the stack. 
    void PrintStack()
    {
        node *stackPointer = (node *)malloc(sizeof(node));

        stackPointer -> link = stackHead -> link;

        cout << "||  Node Address  || " << "Node Data ||  " << "Next Node Address  ||\n";
        cout << "--------------------------------------------------------\n";

        while(stackPointer -> link != NULL)
        {
            cout << "||" << setw(15) << stackPointer -> link << " ||" << setw(8) << stackPointer -> link -> data;

            stackPointer -> link = stackPointer -> link -> link;

            cout << "   ||" << setw(18) << stackPointer -> link << "   ||" << "\n";
        }
    }
};

int main()
{
    int poolSize = 10;

    Stack theStack;
    theStack.stackHead -> link = NULL;

    //Push random numbers to the stacks.
    for(int i = 0; i < poolSize; i++)
    {
        theStack.Push((rand() % 1000000) + 1);
    }

    cout << "First Node Address: " << theStack.stackHead -> link << "\n\n";

    //Call a function to print the stack.
    theStack.PrintStack();

    cout << "\n";

    //Pop item from the stack.
    for(int i = 0; i < poolSize; i++)
    {
        cout << "Data popped out: " << theStack.Pop() << "\n";
    }

    cout << "All data have popped out!\n";
}