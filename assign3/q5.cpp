#include <iostream>
#include <string.h>   
#include <cmath>      
using namespace std;

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void push(Stack *s, int value);
int pop(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
int evaluatePostfix(char exp[]);

int main() {
    char exp[MAX];
    cout << "Enter a postfix expression (operands as single digits): ";
    cin.getline(exp, MAX);

    int result = evaluatePostfix(exp);
    cout << "Result of Postfix Evaluation: " << result << endl;

    return 0;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow!" << endl;
    } else {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow!" << endl;
        return -1;
    } else {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

int evaluatePostfix(char exp[]) {
    Stack s;
    s.top = -1;

    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9') {
            push(&s, ch - '0');   
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int val2 = pop(&s);   
            int val1 = pop(&s);   
            int res;

            switch (ch) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                case '^': res = pow(val1, val2); break;
            }
            push(&s, res);
        }
    }
    return pop(&s);  
}
