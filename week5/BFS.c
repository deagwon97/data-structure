#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef struct{
    int x;
    int y;
} Location2D;
typedef Location2D Element;

Element data[MAX_QUEUE_SIZE];
int front;
int rear;

void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}

void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear;; }
int is_full() { return (rear+1)%MAX_QUEUE_SIZE == front; }
int size() { return (rear-front+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE; }


void enqueue( Element val)
{
    if( is_full())
        error("ť ��ȭ ����");
    rear= (rear+1)% MAX_QUEUE_SIZE;
    data[rear]= val;
}

Element dequeue(){
    if( is_empty())
        error("ť ���� ����");
    front= (front+1)% MAX_QUEUE_SIZE;
    return data[front];
}

Element peek(){
    if( is_empty())
        error("ť ���� ����");
    return data[(front+1)% MAX_QUEUE_SIZE];
}


void init_deque( ) { init_queue( ); }
void add_rear(Element val) { enqueue( val);}
Element delete_front( ) { return dequeue(); }
Element get_front( ) { return peek(); }


void add_front( Element val ) {
    if( is_full() )
        error(" �� ��ȭ ����");
    data[front] = val;
    front = (front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Element delete_rear( ) {
    int prev = rear;
    if( is_empty() )
        error(" �� ���� ����");
    rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return data[prev];
}

Element get_rear( ){
    if( is_empty() )
        error(" �� ���� ����");
    return data[rear];
}

#define MAZE_SIZE 6
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};

void init_map(){
    char map_org[MAZE_SIZE][MAZE_SIZE] =  {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
    };

    for(int i = 0; i<MAZE_SIZE; i++){
        for(int j = 0; j<MAZE_SIZE; j++)
            map[i][j] = map_org[i][j];
    }
}

Location2D getLocation2D(int x, int y){
    Location2D p;
    p.x = x;
    p.y = y;
    return p;
}

int is_valid(int x, int y){
    if ( x < 0 || y < 0 || x >= MAZE_SIZE || y > MAZE_SIZE) return 0;
    else return map[y][x] == '0' || map[y][x] == 'x';
}

int BFS_org()
{
    int x, y;
    Location2D here;
    init_deque();
    add_rear(getLocation2D(0,1));
    printf("BFS_org: ");
    while(is_empty() == 0){
        here = delete_front();
        printf("(%2d, %2d)", here.x, here.y);
        x = here.x;
        y = here.y;
        if (map[y][x] == 'x') return 1;
        else {
            map[y][x] = '.';
            if (is_valid(x - 1, y)) add_rear(getLocation2D(x - 1, y));
            if (is_valid(x + 1, y)) add_rear(getLocation2D(x + 1, y));
            if (is_valid(x, y - 1)) add_rear(getLocation2D(x, y - 1));
            if (is_valid(x, y + 1)) add_rear(getLocation2D(x, y + 1));
        }
    }
    return 0;
}

int BFS_clockwise()
{
    int x, y;
    Location2D here;
    init_deque();
    add_rear(getLocation2D(0,1));
    printf("BFS_clockwise: ");
    while(is_empty() == 0){
        here = delete_front();
        printf("(%2d, %2d)", here.x, here.y);
        x = here.x;
        y = here.y;
        if (map[y][x] == 'x') return 1;
        else {
            map[y][x] = '.';
            // �ð���� Ž��
            if (is_valid(x, y-1)) add_rear(getLocation2D(x , y-1));
            if (is_valid(x+1, y)) add_rear(getLocation2D(x+1, y));
            if (is_valid(x, y+1)) add_rear(getLocation2D(x, y+1));
            if (is_valid(x-1, y)) add_rear(getLocation2D(x-1, y));
        }
    }
    return 0;
}
int BFS_8direc()
{
    int x, y;
    Location2D here;
    init_deque();
    add_rear(getLocation2D(0,1));
    printf("BFS_8direc: ");
    while(is_empty() == 0){
        here = delete_front();
        printf("(%2d, %2d)", here.x, here.y);
        x = here.x;
        y = here.y;
        if (map[y][x] == 'x') return 1;
        else {
            map[y][x] = '.';
            // 8���� Ž��
            if (is_valid(x, y-1)) add_rear(getLocation2D(x , y-1));
            if (is_valid(x+1, y)) add_rear(getLocation2D(x+1, y));
            if (is_valid(x, y+1)) add_rear(getLocation2D(x, y+1));
            if (is_valid(x-1, y)) add_rear(getLocation2D(x-1, y));
            if (is_valid(x+1, y+1)) add_rear(getLocation2D(x+1 , y+1));
            if (is_valid(x+1, y-1)) add_rear(getLocation2D(x+1 , y-1));
            if (is_valid(x-1, y+1)) add_rear(getLocation2D(x-1 , y+1));
            if (is_valid(x-1, y-1)) add_rear(getLocation2D(x-1 , y-1));

        }
    }
    return 0;
}

void print_map(){
    for(int i = 0; i<MAZE_SIZE; i++){
        for(int j = 0; j<MAZE_SIZE; j++)
            printf("%c ", map[i][j]);
        printf("\n");
    }
}

void main()
{
    int i, j;
    printf("[BFS_org]\n");
    init_map();
    printf("before\n");
    print_map();
    printf("->%s\n", BFS_org() ? "����" : "����");
    printf("after\n");
    print_map();
    printf("\n\n");


    printf("[BFS_clockwise]\n");
    init_map();
    printf("before\n");
    print_map();
    printf("->%s\n", BFS_clockwise() ? "����" : "����");
    printf("after\n");
    print_map();
    printf("\n\n");

    printf("[BFS_8direc]\n");
    init_map();
    printf("before\n");
    print_map();
    printf("->%s\n", BFS_8direc() ? "����" : "����");
    printf("after\n");
    print_map();
    printf("\n");
}






