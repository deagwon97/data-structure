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
        error("���� ��ȭ ����");
    data[++top] = e;
}

Element pop(){
    if (is_empty())   
        error("���� ���� ����");
    return data[top--];
}

void print_stack(){
    int i;
    printf("���� ������ ũ�� : %d = [", size());
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
    s = get_student(2017440062, "ȫ�浿","������","010-2234-8756"); push(s);
    s = get_student(2012340062, "ȫ�ҵ�","��1��","010-1231-8756"); push(s);
    s = get_student(2017120062, "ȫ����","2����","010-1232-8756"); push(s);
    s = get_student(2017441262, "ȫ����","3����","010-1234-8156"); push(s);
    s = get_student(2017441162, "ȫ�е�","4����","010-1234-8726"); push(s);

    print_stack();
    pop();
    print_stack();
}