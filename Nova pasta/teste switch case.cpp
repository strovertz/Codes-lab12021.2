#include <stdio.h>

int main()
{

	char alfabeto;

	printf("Digite um caracter\n");
	
	scanf("%c", &alfabeto);
	
	switch(alfabeto)
	{
		case 'l': printf("Mamaco");
		
		break;
		
		case 'u': printf("Camaleao");
		
		break;
		
		default: printf("Digita direito saporrai mermao");
		
		break;
		
		
	}
	
	
}
