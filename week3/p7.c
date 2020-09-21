#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double real;
    double imag;
}Complex;

int items; // array길이

void insert(int array[], int loc, int value){
    int c;
    for (c = items - 1; c >= loc -1; c--){
        array[c +  1] = array[c];
    array[loc - 1] = value;
    items ++;
}
}


void main(){
    int array_int[10] = 0;
    int len = 10;
    int loc = 2;
    int value = 7;
    insert(array_int, loc, value);
}