#include <stdio.h>

int main() {
    //double calculo_media;
    double nota_semestre_1, nota_semestre_2, solucao=0, calculo_da_media;
    int va = 1; 
    while(va == 1){
    	
    	scanf("%lf %lf",&nota_semestre_1, &nota_semestre_2);
    	
	while(nota_semestre_1 < 0.00 || nota_semestre_1 > 10.00)
	{
			printf("nota invalida\n");
			scanf("%lf", &nota_semestre_2);
	}
	while(nota_semestre_2 < 0.00 || nota_semestre_2 > 10.00){
			
			printf("nota invalida\n");
			scanf("%lf", &nota_semestre_2);
	}
	
    solucao = nota_semestre_1 + nota_semestre_2;
    calculo_da_media = solucao/2.00;
        
    printf("media = %.2lf\n",calculo_da_media);
    printf("novo calculo (1-sim 2-nao)\n");
    scanf("%d",&va);
    while(va != 1 && va != 2)
	{
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &va);
	}
}   

return 0;
}
