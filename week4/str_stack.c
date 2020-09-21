#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef char Element;//int

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
    printf("현재 스택의 크기 : %d = [", size());
    for (i = 0; i<size(); i ++)
        printf("%c", data[i]);
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
    push('a'); 
    push('b'); 
    push('c'); 
    push('d'); 
    push('e'); 
    print_stack();
    printf("\tpop() --> %c\n", pop());
    printf("\tpop() --> %c\n", pop());
    printf("\tpop() --> %c\n", pop());
    print_stack();
}