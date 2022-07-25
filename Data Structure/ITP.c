#include <stdio.h>
#include "ITP.h"

int prec(char ch)
{
    switch(ch)
    {
        case '/':
        case '*':
        case '%':return 2;
        case '+':
        case '-':return 1;
        default :return 0;
    }
}

int opt(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
        case '/':
        case '*':
        case '%':return 1;
        default :return 0;
    }
}

void infix2postfix(char *infix, char *postfix)
{
    char ch, *output = postfix;
    STACK s;
    init(&s);
    printf("\n========================================\n");
    printf("I/P\t\tSTACK\t\tO/P");
    printf("\n========================================\n");


    while (*infix != '\0')
    {
        if (*infix == '(')
        {
            push(&s, *infix);
        }
        else if (*infix == ')')
        {
            while ((ch = pop(&s)) != '(')
            {
                *postfix = ch;
                postfix++;
            }
        }
        else if (opt(*infix))
        {
            while (prec(*infix) <= prec(peep(&s)))
            {
                *postfix = pop(&s);
                postfix++;
            }
            push(&s, *infix);   
        }
        else
        {
            *postfix = *infix;
            postfix++;
        }
        printf("%c\t\t", *infix);
        display(&s);
        printf("\t\t%s\n", output);
        printf("----------------------------------------\n");
        infix++;
    }
    while (!isEmpty(&s))
    {
        *postfix = pop(&s);
        postfix++;
    }
    *postfix = '\0';
    printf("%c\t\t", *infix);
    display(&s);
    printf("\t\t%s\n", output);
}

int main()
{
    char infix[50] = "", postfix[50] = "";
    printf("Enter Infix Expression :- ");
    scanf("%s", infix);
    infix2postfix(infix, postfix);
    printf("\n");
    printf("\n----------------------------------------\n");
    printf("Postfix Expression :- %s\n", postfix);
    return 0;
}