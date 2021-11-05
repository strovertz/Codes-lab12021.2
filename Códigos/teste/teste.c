#include <stdio.h>
#include <math.h>

int main(){

    double raiz, r=0;

    printf("insira um numero para calcular a raiz quadrada: \n");

    scanf("%lf", &raiz);
    if(raiz >= 0){

        r = sqrt(raiz);

        printf("%lf", r);
    }

    else {

        printf("Numero negativo n tem raiz quadrada");

    }
    return 0;
}