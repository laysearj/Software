#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>

int A[4]= {2 , 1, 5 , 7};
int B[2] = {11, 13};

double x1[11], x2[11];



int main () {
    int num_threads;
   // printf("Quantidade de Threads desejada:\n");
    //scanf("%d", &num_threads);
    x1[0] = 1;
    x2[0] = 1;

    int i = 0;

    for(i = 0; i<10; i++){

        x1[i+1] = 0.5 * (11 - x2[i]);

        x2[i+1] = 0.14 * (13 - (5 * x1[i]));

        
        printf("Resultado K = [%d]: x1: %.2lf    x2: %.2lf\n", i+1, x1[i+1], x2[i+1]);
    }
    return 0;
}

//colocar as barreiras