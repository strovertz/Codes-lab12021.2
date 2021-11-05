#include <stdio.h>

int main()
{
	
	// cachorro - 4,00 - x salada - 4,50 - x bacon - 5,00 torrada simples - 2,00,  - refri - 1,50
	int pedido, qtd;
	float total;
	
	scanf("%d %d", &pedido, &qtd);
	
	switch(pedido)
	{
		case 1: 
			total=qtd*4.00;
			printf("Total: R$ %.2f\n", total);
			break;
		case 2: 
			total=qtd*4.50;
			printf("Total: R$ %.2f\n", total);
			break;
		case 3: 
			total=qtd*5.00;
			printf("Total: R$ %.2f\n", total);
			break;
		case 4:
			total=qtd*2.00;
			printf("Total: R$ %.2f\n", total);
			break;
		case 5:	
			total=qtd*1.50;
			printf("Total: R$ %.2f\n", total);
			break;
		}	
	
	return 0;
	
	
	
	
}
