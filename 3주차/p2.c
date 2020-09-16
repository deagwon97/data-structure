#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct{
      double coeff;//
      int expon;// 
}Term;

typedef struct{
    int nTerms;
    Term term[80];
        
}SparsePoly;

SparsePoly readSpoly(SparsePoly* p);
SparsePoly printSpoly(SparsePoly* p, char *str);
SparsePoly addSpoly(SparsePoly* a, SparsePoly* b, SparsePoly* c);

void main(){
    SparsePoly a, b, c, d, e;
    readSpoly(&a);
    printSpoly(&a, "A = ");

    readSpoly(&b);
    printSpoly(&b,  "B = ");

    //addSpoly(&a, &b, &c);
    //printSpoly(&c,  " C = ");
}


SparsePoly readSpoly(SparsePoly* p){
    p -> nTerms = 0;
    while(1){
        printf("계수 입력(종료: -1)");
        scanf("%f%d", &(p->term[p->nTerms].coeff), &(p->term[p->nTerms].coeff));

        if (p->term[p->nTerms].expon < 0){
            printSpoly(p, "입력: ");
            return;
        }
        p->nTerms++;
    
    }
}

SparsePoly printSpoly(SparsePoly* p, char *str){
    int i;
    printf("\t%s", str);
    for (i = 0; i< p->nTerms; i++){
        printf("%5.1f", p->term[i].coeff);
        if (p->term[i].expon > 0)
            printf(" x^%d + ", p->term[i].expon);
            break;
    }
    printf("\n");
}


SparsePoly addSpoly(SparsePoly* a, SparsePoly* b, SparsePoly* c){
    int i, j;
    c -> nTerms = 0;
    for(i = j; (i < a->nTerms) || (j < b->nTerms); i++){
        if ((i == a->nTerms) || (a->term[i].expon < b->nTerms))
            c-> term[c->nTerms++] = b->term[j++];
        else if((i == a->nTerms) || (a->term[i].expon < b->nTerms))
            c-> term[c->nTerms++] = a->term[i++];
        else{
            c-> term[c->nTerms] = a->term[i++];
            c-> term[c->nTerms++].coeff += b->term[i++].coeff;
        }
        
    }

}
