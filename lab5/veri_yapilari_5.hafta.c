
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef struct {
    int top;
    char data[STACK_SIZE];
} stack;

void initialization(stack *stk) {
    stk->top = -1;
}

void push(stack *stk, char c) {
    if (stk->top == STACK_SIZE - 1) {
        printf("Stack is full...\n");
        return;
    }
    stk->data[++stk->top] = c;
}

char pop(stack *stk) {
    if (stk->top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    return stk->data[stk->top--];
}

int main() {
    char key;
    stack stk;
    initialization(&stk);
    FILE *fptr;
    if ((fptr = fopen("lab5.veri.txt", "r")) == NULL) {
        printf("The file was not found...\n");
        return 0;
    } else {
        while (!feof(fptr)) {
            key = getc(fptr);
            switch (key) {
                case '(':
                case '[':
                case '{':
                    push(&stk, key);
                    break;
                case ')':
                    if (stk.top == -1 || pop(&stk) != '(') {
                        printf("\n Error for () !!!\n");
                        exit(1);
                    }
                    break;
                case ']':
                    if (stk.top == -1 || pop(&stk) != '[') {
                        printf("\n Error for [] !!!\n");
                        exit(1);
                    }
                    break;
                case '}':
                    if (stk.top == -1 || pop(&stk) != '{') {
                        printf("\n Error for {} !!!\n");
                        exit(1);
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if (stk.top == -1) {
        printf("\n\n There is no error in the code...\n");
    } else {
        printf("\n Error...incorrect use of brackets!!\n");
    }
    fclose(fptr);
    return 0;
}






