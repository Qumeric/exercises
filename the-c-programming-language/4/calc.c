#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void dup(void);
void print(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
int main(void)
{
    double a;   // your OWN variable (one is enough, isn't it?)
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case 'd': // duplicate
            dup();
            break;
        case 'p': // print
            print();
            break;
        case 's': // swap
            swap();
            break;
        case 'c': // clear
            clear();
            break;
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 'y': // sin
            push(sin(pop()));
            break;
        case 'x': // cos
            push(cos(pop()));
            break;
        case 'e': // exp
            push(exp(pop()));
            break;
        case '=': // set variable
            a = pop();
            break;
        case 'a': // get variable
            push(a);
            break;
        case '\n':
            //printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void dup(void)
{
    if (sp >= MAXVAL && sp >= 1)
        printf("error: stack full, can't duplicate\n");
    else if (sp < 1)
        printf("error: stack empty, nothing to print\n");
    else {
        val[sp] = val[sp-1];
        sp++;
    }
}

void print(void)
{
    if (sp >= 1)
    {
        for(int i = 0; i < sp; i++)
            printf("%g ", val[i]);
    } else
        printf("error: stack empty, nothing to print");
    putchar('\n');
}

void swap(void)
{   
    double temp;
    if (sp >= 2) {
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    } else
        printf("error: stack [almost] empty, nothing to swap\n");
}

void clear(void)
{
    sp = 0;
}

#include <ctype.h>
int getch(void);
void ungetch(int);
void ungets(char s[]);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/* get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    for (unsigned int i = strlen(s); s[i] > 0 ; i--)
        ungetch(s[i]);
}
