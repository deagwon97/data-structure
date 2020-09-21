#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double real;
    double imag;
}Complex;


void print_complex(Complex c){
    printf("%4.1f + %4.1fi\n", c.real, c.imag);
}

void reset_complex(Complex c){
    c.real = c.imag = 0.0;
}

 Complex add_comple(Complex a, Complex b){
     Complex c;
     c.real = a.real + b.real;
     c.imag = a.imag + b.imag;
     return c; 
 }

 void main(){
      Complex a = { 1.0, 2.0 };
      Complex b = { 3.0, 5.0 };
      Complex c;
      reset_complex(c);
      c = add_comple(a, b);
      print_complex(c);
 }