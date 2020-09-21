#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insert(int array[], int loc, int value);
void delete(int array[], int loc);

int items = 10; // array길이

void main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;

    //insert(arr, 1, 10);
    delete(arr, 3);

    for(i = 0;i < items; i ++)
        printf("%d, ", arr[i]);
}



void insert(int array[], int loc, int value){
    int c;
    for (c = items - 1; c >= loc -1; c--)
        array[c +  1] = array[c];
    array[loc - 1] = value;
    items ++;
}

void delete(int array[], int loc){
    int c;
    for (c = loc ; c < (items - 1); c ++);
        array[c] = array[c + 1];
    array[items - 1] = 0;
    items --;
}

