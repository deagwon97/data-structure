#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int sumAlgorithmA(int num);
int sumAlgorithmB(int num);
int sumAlgorithmC(int num);
int sequential_search(int list[], int n, int key);


int sumAlgorithmA(int num)
{
    return num*(num + 1) / 2;
}



int sumAlgorithmB(int num)
{
    int sum = 0;
    int i;
    for (i = 1; i <= num; i++)
    {
        sum = sum + i;
    }
    return sum;
}


int sumAlgorithmC(int num)
{
    int sum;
    int i, j;
    for (i = 0; i <= num; i++){
        for (j = 1; j<=i; j++){
            sum = sum + 1;
        }
    }
    return sum;

}




int sequential_search(int list[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if(list[i] == key)
            return i;
    return -1;
}


void main()
{
    clock_t start, finish;
    double duration;
    int k = 0;
    int glist[10] = {5,6,7,8,10,12,1,0,12,18};

    int n_count = 1;
    int n = 200;
    for (n_count = 1; n_count<20; n_count++)
    {
        start = clock();
        for (k = 0; k<1000000; k++) sumAlgorithmA(n*n_count);
        //for (k = 0; k<100000; k++) sumAlgorithmB(n*n_count);
        //for (k = 0; k<100; k++) sumAlgorithmC(n*n_count);
        //for (k = 0; k<1000; k++) sequential_search(n*n_count);
        finish = clock();

        duration = (double)(finish - start) /  CLOCKS_PER_SEC; 
        printf("%f", duration);
        printf("\n");
    }
}