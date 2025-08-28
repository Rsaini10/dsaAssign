#include <iostream>
#include <string.h>   
using namespace std;

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
int precedence(char c);
int isOperator(char c);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter an infix expression: ";
    cin.getline(infix, MAX);

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        cout << "Stack Overflow!" << endl;
    } else {
        s->top++;
        s->arr[s->top] = c;
    }
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    } else {
        char c = s->arr[s->top];
        s->top--;
        return c;
    }
}

char peek(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->arr[s->top];
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; 
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    s.top = -1;

    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }
    
        else if (ch == '(') {
            push(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); 
        }
        else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
        i++;
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; 
}
