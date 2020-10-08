// deque
// 전단과 후단에서 삽입과 삭제가 가능한 큐
//add_front, delete_front, get_front
//add_rear, delete_rear, get_rear
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_QUEUE_SIZE 100
#define Element int
Element data[MAX_QUEUE_SIZE];
int front;
int rear;

void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear;; }
int is_full() { return (rear+1)%MAX_QUEUE_SIZE == front; }
int size() { return (rear-front+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE; }

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}


void enqueue( Element val)
{
    if( is_full())
        error("큐 포화 에러");
    rear= (rear+1)% MAX_QUEUE_SIZE;
    data[rear]= val;
}

Element dequeue(){
    if( is_empty())
        error("큐 공백 에러");
    front= (front+1)% MAX_QUEUE_SIZE;
    return data[front];
}

Element peek(){
    if( is_empty())
        error("큐 공백 에러");
    return data[(front+1)% MAX_QUEUE_SIZE];
}


void init_deque( ) { init_queue( ); }
void add_rear(Element val) { enqueue( val);}
Element delete_front( ) { return dequeue(); }
Element get_front( ) { return peek(); }


void print_queue(char msg[]) { print_queue(msg); }

void add_front( Element val ) {
    if( is_full() )
        error(" 덱 포화 에러");
    data[front] = val;
    front = (front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Element delete_rear( ) {
    Element ret;
    if( is_empty() )
        error(" 덱 공백 에러");
    ret = data[rear];
    rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return ret;
}

Element get_rear( ){
    if( is_empty() )
        error(" 덱 공백 에러");
    return data[rear];
}


void main()
{
    int i,  val;
    init_queue();

    enqueue(0);
    enqueue(1);

    printf("F(0) = 0\n");
    printf("F(1) = 1\n");
    for (i = 2; i<10; i++){
        val = dequeue() + peek();
        enqueue(val);
        printf("F(%d) = %d\n", i, val);
    }
}