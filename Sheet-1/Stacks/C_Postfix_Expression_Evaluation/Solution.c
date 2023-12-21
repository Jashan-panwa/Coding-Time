#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int *arr;
    int size;
    int capacity;
};

bool isStackEmpty(struct Stack* s) {
    if (s->size == 0) return true;
    return false; 
}

void pushToStack(struct Stack* s, int x) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        int *temp = malloc(s->capacity * sizeof(int));
        for (int i = 0; i < s->size; i++) {
            temp[i] = s->arr[i];
        }
        s->arr = temp;
    }
    s->arr[s->size++] = x;
}

int popFromStack(struct Stack* s) {
    if (isStackEmpty(s)) return -1;
    return s->arr[s->size--];
}

void initializeStack(struct Stack* s) {
    s->size = 0;
    s->capacity = 1;
    s->arr = malloc(sizeof(int));
}

void emptyStack(struct Stack* s) {
    s->size = 0;
}

int peekStack(struct Stack* s) {
    return s->arr[s->size - 1];
}

int performOperation(int num1, int num2, char operator) {
    if (operator == '+') return num1 + num2;
    else if (operator == '-') return num2 - num1;
    else if (operator == '*') return num1 * num2;
    return num2 / num1;
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);
    getchar();

    while (test_cases != 0) {
        char expression[10000];
        fgets(expression, sizeof(expression), stdin);
        int len = strlen(expression);
        struct Stack* stack = malloc(sizeof(struct Stack));
        initializeStack(stack);
        char temp[10000];

        for (int i = 0; i < len; i++) {
            if (expression[i] == '?') break;
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
                int num1 = peekStack(stack);
                popFromStack(stack);
                int num2 = peekStack(stack);
                popFromStack(stack);
                pushToStack(stack, performOperation(num1, num2, expression[i]));
                i = i + 1;
            } else {
                int j = i;
                while (j < len - 1 && expression[j] != ' ') j++;
                temp[j - i] = '\0';
                for (int p = i; p < j; p++) temp[p - i] = expression[p];
                int number = atoi(temp);
                pushToStack(stack, number);
                i = j;
            }
        }
        printf("%d\n", peekStack(stack));
        test_cases--;
    }
    return 0;
}
