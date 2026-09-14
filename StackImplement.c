#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// ─────────────────────────────────
// STACK STRUCTURE
// ─────────────────────────────────
struct Stack {
    int arr[MAX];
    int top;
};

// ─────────────────────────────────
// 1. INITIALIZE STACK
// ─────────────────────────────────
void init(struct Stack* s) {
    s->top = -1;
}

// ─────────────────────────────────
// 2. IS EMPTY
// ─────────────────────────────────
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// ─────────────────────────────────
// 3. IS FULL
// ─────────────────────────────────
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// ─────────────────────────────────
// 4. PUSH
// ─────────────────────────────────
void push(struct Stack* s, int data) {
    if(isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
    printf("%d pushed\n", data);
}

// ─────────────────────────────────
// 5. POP
// ─────────────────────────────────
int pop(struct Stack* s) {
    if(isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}

// ─────────────────────────────────
// 6. PEEK / TOP
// ─────────────────────────────────
int peek(struct Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

// ─────────────────────────────────
// 7. DISPLAY
// ─────────────────────────────────
void display(struct Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for(int i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}

// ─────────────────────────────────
// MAIN
// ─────────────────────────────────
int main() {
    struct Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);   // overflow

    display(&s);

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    display(&s);

    printf("Top element: %d\n", peek(&s));

    return 0;
}