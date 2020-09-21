#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef double Element;


Element data[MAX_STACK_SIZE];
int top;

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}


void init_stack(){ top = -1;}
int is_empty(){ return top == -1;}
int is_full(){ return top == MAX_STACK_SIZE -1;}
int size(){ return top + 1;}

void push(Element e){
    if (is_full())
        error("스택 포화 에러");
    data[++top] = e;
}

Element pop(){
    if (is_empty())   
        error("스택 포화 에러");
    return data[top--];
}

Element peek(){
    if (is_empty())   
        error("스택 포화 에러");
    return data[top];
}

// 중간고사 출제
// postfix를 계산하는 문제
// infix를 postfix로 변환하는 문제




double calc_postfix(char expr[])
{
    char c;
    int i = 0;
    double val, val1, val2;
    init_stack();
    while(expr[i] != '\0'){
        c = expr[i++];
        if ( c>= '0' && c <= '9'){
            val = c - '0';
            push(val);
        }
        else if ( c == '+' || c == '-' || c == '*' ||c == '/'){
            val2 = pop();
            val1 = pop();
            switch (c){
                case '+': push(val1 + val2);printf("+ 연산값 %5.2f push\n", val1+val2); break;
                case '-': push(val1 - val2);printf("- 연산값 %5.2f push\n", val1+val2); break;
                case '*': push(val1 * val2);printf("* 연산값 %5.2f push\n", val1+val2); break;
                case '/': push(val1 / val2);printf("/ 연산값 %5.2f push\n", val1+val2); break;
            }

        }
    }
    return pop();
}

void main()
{
    char expr[2][80] = {"82/3-32*+",
                         "12/4*14/*"};
    printf("수식 : %s = %1f\n", expr[0], calc_postfix(expr[0]));
    printf("수식 : %s = %1f\n", expr[1], calc_postfix(expr[1]));
}




