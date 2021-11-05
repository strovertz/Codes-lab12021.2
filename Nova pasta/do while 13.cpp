#include <stdio.h>

int main()
{
	int x, y, soma = 0;
	
	scanf("%d %d", &x, &y);
	
	int aux; 
	
	if(x > y)
	{
		aux = x;
		x = y;
		y = aux;
	}
	
	int valor;
	
	valor = x;

	
		
	for(;;)
	{
		
		if(valor%13 != 0)
		{
			soma = valor+soma;
		}
			
		valor++;
		if(valor > y)
			break; 
	} 
	
	
	printf("%d\n", soma);
	
	return 0;
}
