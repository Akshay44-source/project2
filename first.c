#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the stack

// Structure to represent the stack
struct Stack {
    int items[MAX_SIZE];
    int top; // Index of the top element
};

// Initialize the stack
void initialize(struct Stack *s) {
    s->top = -1; // -1 indicates the stack is empty
}

// Check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Add an element to the top of the stack (Push)
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Remove an element from the top of the stack (Pop)
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1; // Return an error value
    } else {
        int poppedValue = s->items[s->top];
        s->top--;
        return poppedValue;
    }
}

// Display the elements of the stack
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate stack operations
int main() {
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    display(&myStack);

    int poppedItem = pop(&myStack);
    if (poppedItem != -1) {
        printf("Popped element: %d\n", poppedItem);
    }
    display(&myStack);

    push(&myStack, 40);
    push(&myStack, 50);
    push(&myStack, 60); // This will cause a stack overflow
    display(&myStack);

    return 0;
}