#include <stdio.h>

int main() {

    float salario, salariolimpo, imposto, imposto2, imposto3;
    double aux;
    scanf("%f", &salario);

    aux = salario;

    switch(aux >= 0.00 && aux <= 2000.00){

        case 1:
            printf("Isento\n");
    }
    switch (salario >= 2000.01 && salario <= 3000.00)
    {
        case 1:
            salariolimpo= salario-2000;
            imposto= salariolimpo*0.08;
            printf("R$ %.2f\n", imposto);
    }
    switch (salario >= 3000.01 && salario <= 4500.00)
    {
        case 1:
            imposto= 1000*0.08;
            salariolimpo=salariolimpo-1000.00;
            imposto2=((salario-3000.00)*0.18)+imposto;
            printf("R$ %.2f\n", imposto2);
    }
    switch (salario > 4500.00)
    {
        case 1:
            imposto= 1000*0.08;
            salariolimpo=salariolimpo-1000.00;
            imposto2=(1500*0.18)+imposto;
            salariolimpo=salario-4500.00;
            imposto3=((salario-4500)*0.28)+imposto2;
            printf("R$ %.2f\n", imposto3);
    }
    return 0;
}


