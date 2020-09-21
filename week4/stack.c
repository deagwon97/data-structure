#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Element;//int와 동일한 자료형인 Element를 정의

Element data[MAX_STACK_SIZE];
int top;

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}


void init_stack(){
    top = -1;
}

int is_empty(){
    return top == -1;
}

int is_full(){
    return top == MAX_STACK_SIZE -1;
}
int size(){
    return top + 1;
}

void push(Element e)
{
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

void print_stack(){
    int i;
    printf("현재스택크기 : %d = [", size());
    for (i = 0; i<size(); i ++)
        printf("%2d", data[i]);
    printf("\n");
}

typedef struct Student {
    int id;
    char name[32];
    char dept[32];
} Student;

void main()
{
    int i;
    init_stack();
    push(10); 
    push(13); 
    push(5); 
    push(7); 
    push(3); 
    print_stack();
    printf("\tpop() --> %d\n", pop());
    printf("\tpop() --> %d\n", pop());
    printf("\tpop() --> %d\n", pop());
    print_stack();
}