#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef struct Student {
    int id;
    char name[32];
    char dept[32];
    char phone[13];
} Student;
typedef Student Element;
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
        error("스택 공백 에러");
    return data[top--];
}

void print_stack(){
    int i;
    printf("현재 스택의 크기 : %d = [", size());
    for (i = 0; i<size(); i ++)
        printf("\n\t%-15d %-10s %-20s %-13s",
                data[i].id,
                data[i].name,
                data[i].dept,
                data[i].phone);
    printf("\n");
}

Student get_student(int id, char name[], char dept[], char phone[])
{
    Student s;
    s.id = id;
    strcpy(s.name, name);
    strcpy(s.dept, dept);
    strcpy(s.phone, phone);
    return s;
}



void main()
{
    int i;
    init_stack();
    Student s;
    s = get_student(2017440062, "홍길동","전전컴","010-2234-8756"); push(s);
    s = get_student(2012340062, "홍닐동","전1컴","010-1231-8756"); push(s);
    s = get_student(2017120062, "홍딜동","2전컴","010-1232-8756"); push(s);
    s = get_student(2017441262, "홍릴동","3전컴","010-1234-8156"); push(s);
    s = get_student(2017441162, "홍밀동","4전컴","010-1234-8726"); push(s);

    print_stack();
    pop();
    print_stack();
}