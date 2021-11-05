#include <stdio.h>
 
int main() {
    float X, Y, media = 0.00;
    int Z=1;

    while (Z==1){

        scanf("%f %f", &X, &Y);
        while(X < 0.00 || X > 10.00){
            printf("nota invalida\n");
            scanf("%f", &X);
        }
        while(Y < 0.00 || Y > 10.00){
            printf("nota invalida\n");
            scanf("%f", &Y);
        } 
        media = (X + Y)/2;
        printf("media = %.2f\n", media);
        printf("novo calculo (1-sim 2-nao)\n"); 
        scanf("%d", &Z);


        while(Z != 1 && Z != 2){
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &Z);

            }
        }

    return 0;
}
