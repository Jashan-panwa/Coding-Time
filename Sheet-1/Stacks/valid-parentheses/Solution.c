struct Stack {
    char *arr; // Change int to char to store characters
    int size;
    int capacity;
};

// Function to initialize the stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = 0;
    stack->capacity = 1;
    stack->arr = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to add an element to the stack
void push(struct Stack* s, char x) { // Change parameter type to char
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->arr = (char*)realloc(s->arr, s->capacity * sizeof(char));
    }
    s->arr[s->size++] = x;
}

// Function to check if the stack is empty
int empty(struct Stack* s) {
    return s->size == 0;
}

// Function to remove an element from the stack
void pop(struct Stack* s) {
    if (!empty(s)) {
        s->size--;
    }
}

// Function to retrieve the top element of the stack
char top(struct Stack* s) {
    return s->arr[s->size - 1];
}

// Function to validate the string containing parentheses, square brackets, and curly braces
bool isValid(char* s) {
    struct Stack* st = createStack();

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            push(st, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (empty(st)) {
                free(st->arr);
                free(st);
                return false;
            }
            char t = top(st);
            if ((c == ')' && t != '(') || (c == ']' && t != '[') || (c == '}' && t != '{')) {
                free(st->arr);
                free(st);
                return false;
            }
            pop(st);
        }
    }

    int isValidString = empty(st);
    free(st->arr);
    free(st);
    return isValidString;
}
int main() {
    char input[100];
    printf("Enter a continuous string without spaces or newlines: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    if (isValid(input)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}
