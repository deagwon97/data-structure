#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Element;//int�� ������ �ڷ����� Element�� ����

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
        error("���� ��ȭ ����");
    data[++top] = e;
}

Element pop(){
    if (is_empty())   
        error("���� ��ȭ ����");
    return data[top--];
}

Element peek(){
    if (is_empty())   
        error("���� ��ȭ ����");
    return data[top];
}

void print_stack(){
    int i;
    printf("���罺��ũ�� : %d = [", size());
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