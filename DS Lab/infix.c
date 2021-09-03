#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

struct stack *createStack(int size)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->top = -1;
    st->size = size;
    st->arr = (int *)malloc(st->size * sizeof(int));
    return st;
}


int isEmpty(struct stack *st)
{
    return st->top == -1;
}

char peek(struct stack *st)
{
    return st->arr[st->top];
}

char pop(struct stack *st)
{
    if (!isEmpty(st))
    return st->arr[st->top--];
    return '$';
}

void push(struct stack *st, char op)
{
    st->arr[++st->top] = op;
}
int is_operand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch)
{
    switch (ch)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int infixToPostfix(char *exp)
{
    int i, k;
    struct stack *st = createStack(strlen(exp));
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (is_operand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(st, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(st) && peek(st) != '(')
                exp[++k] = pop(st);
            if (!isEmpty(st) && peek(st) != '(')
                return -1;
            else
                pop(st);
        }
        else
        {
        while (!isEmpty(st) && precedence(exp[i]) <= precedence(peek(st)))
            exp[++k] = pop(st);
        push(st, exp[i]);
        }
    }
    while (!isEmpty(st))
        exp[++k] = pop(st);
    exp[++k] = '\0';
    printf("%s\n", exp);
}

int main()
{
 char exp[700];
 printf("\nenter Infix expression:\n");
 scanf("%s",exp);
 infixToPostfix(exp);
 return 0;
}